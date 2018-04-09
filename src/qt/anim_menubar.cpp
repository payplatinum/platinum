#include "anim_menubar.h"
#include "ui_anim_menubar.h"
#include "math.h"

anim_menubar::anim_menubar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::anim_menubar)
{
    ui->setupUi(this);
    startX = ui->gbLowerMenuBarPanel->pos().x();
    startY = ui->gbLowerMenuBarPanel->pos().y();
    startW = ui->gbLowerMenuBarPanel->size().width();
    startH = ui->gbLowerMenuBarPanel->size().height();

    if (parent != NULL)
        startW = parent->width();
    else
        startW = ui->gbLowerMenuBarPanel->width();
    startH = 20;

    HeightTopPanel = 50;

    // gbOverview - sub panel
    gbOverview = new QGroupBox(this); //ui->gbLowerMenuBarPanel);
    gbOverview->setObjectName("gbSubPanel");

    gbOverview->setStyleSheet("QPushButton:hover{\n	"
                              "background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,"
                              "stop:0 rgba(220, 220, 220, 255), stop:1 rgba(190, 190, 190, 255));\n"
                              "color:rgb(128,128,128);\n	border: none;\n}\n\nQPushButton::indicator{\n"
                              "/*width: 0;*/\n 	background: transparent;\n	/*width: 20px;*/\n}\n\nQPushButton "
                              "{\n	border: none;\n	min-width: 80px;\n	background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, "
                              "stop:0 rgba(250, 250, 250, 255), stop:1 rgba(220, 220, 220, 255));\n	color:rgb(196,196,196);\n	"
                              "font-size: 12px;\n	height: 20px;\n	text-align: center;\n}\n\nQPushButton:pressed {\n	"
                              "background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(211, 211, 211, 255), "
                              "stop:1 rgba(181, 181, 181, 255));\n	color:rgb(64, 64, 64);\n	"
                              "border: none;\n}\n\nQPushButton:on {\n	background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, "
                              "stop:0 rgba(231, 231, 231, 255), stop:1 rgba(201, 201, 201, 255));\n	color: rgb(32, 32, 32);\n	"
                              "border: none;\n}\n\nQPushButton:disabled {\n	background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, "
                              "stop:0 rgba(150, 150, 150, 255), stop:1 rgba(200, 200, 200, 255));\n	color: rgb(32, 32, 32);\n	"
                              "border: none;\n}\n\nQGroupBox{\n	background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, "
                              "stop:0 rgba(250, 250, 250, 255), stop:1 rgba(220, 220, 220, 255));\n	border: none;\n}");
    gbOverview->hide();
    PlayAnimClose(gbOverview);
    QPushButton *pbOverview01 = new QPushButton(tr("Balance"), gbOverview);
    pbOverview01->setCheckable(true);
    pbOverview01->setAutoExclusive(true);
    pbOverview01->setChecked(true);
    pbOverview01->setObjectName(tr("gbOverviewBtn"));

    QPushButton *pbOverview02 = new QPushButton(tr("Recent Transactions"), gbOverview);
    pbOverview02->setCheckable(true);
    pbOverview02->setAutoExclusive(true);
    pbOverview02->setObjectName(tr("gbOverviewBtn"));

    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->setContentsMargins(50,0,50,0);

    hbox->addWidget(pbOverview01);
    hbox->addWidget(pbOverview02);

    hbox->addStretch(0);
    hbox->addSpacing(0);
    gbOverview->setLayout(hbox);
    gbOverview->show();


    // gbRecevie - sub panel
    gbReceive = new QGroupBox(this); //ui->gbLowerMenuBarPanel);
    gbReceive->setObjectName("gbSubPanel");
    gbReceive->setStyleSheet("QPushButton:hover{\n	"
                              "background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,"
                              "stop:0 rgba(220, 220, 220, 255), stop:1 rgba(190, 190, 190, 255));\n"
                              "color:rgb(128,128,128);\n	border: none;\n}\n\nQPushButton::indicator{\n"
                              "/*width: 0;*/\n 	background: transparent;\n	/*width: 20px;*/\n}\n\nQPushButton "
                              "{\n	border: none;\n	min-width: 80px;\n	background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, "
                              "stop:0 rgba(250, 250, 250, 255), stop:1 rgba(220, 220, 220, 255));\n	color:rgb(196,196,196);\n	"
                              "font-size: 12px;\n	height: 20px;\n	text-align: center;\n}\n\nQPushButton:pressed {\n	"
                              "background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(211, 211, 211, 255), "
                              "stop:1 rgba(181, 181, 181, 255));\n	color:rgb(64, 64, 64);\n	"
                              "border: none;\n}\n\nQPushButton:on {\n	background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, "
                              "stop:0 rgba(231, 231, 231, 255), stop:1 rgba(201, 201, 201, 255));\n	color: rgb(32, 32, 32);\n	"
                              "border: none;\n}\n\nQPushButton:disabled {\n	background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, "
                              "stop:0 rgba(150, 150, 150, 255), stop:1 rgba(200, 200, 200, 255));\n	color: rgb(32, 32, 32);\n	"
                              "border: none;\n}\n\nQGroupBox{\n	background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, "
                              "stop:0 rgba(250, 250, 250, 255), stop:1 rgba(220, 220, 220, 255));\n	border: none;\n}");
    gbReceive->hide();
    PlayAnimClose(gbReceive);
    QPushButton *pbReceive01 = new QPushButton(tr("Receive 1"), gbReceive);
    pbReceive01->setCheckable(true);
    pbReceive01->setAutoExclusive(true);
    pbReceive01->setChecked(true);

    QPushButton *pbReceive02 = new QPushButton(tr("Receive 2"), gbReceive);
    pbReceive02->setCheckable(true);
    pbReceive02->setAutoExclusive(true);

    QHBoxLayout *hboxReceive = new QHBoxLayout;
    hboxReceive->setContentsMargins(50,0,50,0);

    hboxReceive->addWidget(pbReceive01);
    hboxReceive->addWidget(pbReceive02);

    hboxReceive->addSpacing(0);
    hboxReceive->addStretch(0);

    gbReceive->setLayout(hboxReceive);
    gbReceive->show();

    //for (int i = 0; i < 9; i++)
    //{
    //    tbArr[i] = new QToolBar(tr("toolbar_menubar"), this);
    //    tbArr[i]->setObjectName("menubar_subpanel");
    //    tbArr[i]->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    //    tbArr[i]->setContextMenuPolicy(Qt::PreventContextMenu);
    //    tbArr[i]->setStyleSheet("QToolButton:hover{\n	"
    //                            "background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,"
    //                            "stop:0 rgba(220, 220, 220, 255), stop:1 rgba(190, 190, 190, 255));\n"
    //                            "color:rgb(128,128,128);\n	border: none;\n}\n\nQToolButton::indicator{\n"
    //                            "/*width: 0;*/\n 	background: transparent;\n	/*width: 20px;*/\n}\n\nQToolButton "
    //                             "{\n	border: none;\n	min-width: 80px;\n	background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, "
    //                            "stop:0 rgba(250, 250, 250, 255), stop:1 rgba(220, 220, 220, 255));\n	"
    //                            "color:rgb(196,196,196);\n	font-size: 11px;\n	height: 20px;\n	text-align: "
    //                            "center;\n}\n\nQToolButton:pressed {\n	background: qlineargradient(spread:pad, "
    //                            "x1:0, y1:0, x2:0, y2:1, stop:0 rgba(211, 211, 211, 255), stop:1 rgba(181, 181, 181, 255));\n	"
    //                            "color:rgb(64, 64, 64);\n	border: none;\n}\n\nQPushButton:on {\n	background: qlineargradient(spread:pad, "
    //                            "x1:0, y1:0, x2:0, y2:1, stop:0 rgba(231, 231, 231, 255), stop:1 rgba(201, 201, 201, 255));\n	color: rgb(32, 32, 32);\n	"
    //                            "border: none;\n}\n\nQToolButton:disabled {\n	background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, "
    //                            "stop:0 rgba(150, 150, 150, 255), stop:1 rgba(200, 200, 200, 255));\n	color: rgb(32, 32, 32);\n	"
    //                            "border: none;\n}\n\nQToolBar{\n	background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, "
    //                            "stop:0 rgba(250, 250, 250, 255), stop:1 rgba(220, 220, 220, 255));\n	border: none;\n}");
    //    tbArr[i]->hide();
    //    tbClose(tbArr[i]);
    //    QHBoxLayout *hboxReceive = new QHBoxLayout;
    //    hboxReceive->setContentsMargins(50,0,50,0);
    //
    //    hboxReceive->addStretch(0);
    //    hboxReceive->addSpacing(0);
    //    tbArr[i]->setLayout(hboxReceive);
    //
    //    tbArr[i]->show();
    //}
    //
    //overviewAction = new QAction(tr("&Dashboard"), this);
    //overviewAction->setToolTip(tr("Show general overview of wallet"));
    //overviewAction->setCheckable(true);
    //overviewAction->setShortcut(QKeySequence(Qt::ALT + Qt::Key_1));
    //
    //sendAction = new QAction(tr("Balance"), this);
    //
    //
    //Act1 = new QAction(tr("Act01"), this);
    //Act2 = new QAction(tr("Act02"), this);
    //
    //
    //tbArr[0]->addAction(overviewAction);
    //tbArr[0]->addAction(sendAction);
    //
    //tbArr[1]->addAction(Act1);
    //tbArr[1]->addAction(Act2);


    SubPanelIsVisible = false;
    doubleCheck = false;
    b_stateOverview        = false;
    b_stateReceive         = false;
    b_stateSend            = false;
    b_stateTransactions    = false;
}

anim_menubar::~anim_menubar()
{
    delete ui;
}

void anim_menubar::PlayAnimOpen(QGroupBox *Panel)
{
    QPropertyAnimation *anim = new QPropertyAnimation(Panel, "geometry");
    anim->setDuration(350);
    anim->setEasingCurve(QEasingCurve::InOutCubic);
    anim->setEndValue(QRectF(0, HeightTopPanel, startW, startH));
    anim->start(QAbstractAnimation::DeleteWhenStopped);
}

void anim_menubar::PlayAnimClose(QGroupBox *Panel)
{
    QPropertyAnimation *anim = new QPropertyAnimation(Panel, "geometry");
    anim->setDuration(350);
    anim->setEasingCurve(QEasingCurve::InOutCubic);
    anim->setEndValue(QRectF(0, HeightTopPanel, startW, 0));
    anim->start(QAbstractAnimation::DeleteWhenStopped);
}

void anim_menubar::AnimCloseOpen(QGroupBox *close, QGroupBox *open)
{
    QPropertyAnimation *anim_close = new QPropertyAnimation(close, "geometry");
    anim_close->setDuration(350);
    anim_close->setEasingCurve(QEasingCurve::InOutCubic);
    anim_close->setEndValue(QRectF(0, HeightTopPanel, startW, 0));
    //anim_close->start(QAbstractAnimation::DeleteWhenStopped);

    QPropertyAnimation *anim_open = new QPropertyAnimation(open, "geometry");
    anim_open->setDuration(350);
    anim_open->setEasingCurve(QEasingCurve::InOutCubic);
    anim_open->setEndValue(QRectF(0, HeightTopPanel, startW, startH));
    //anim_open->start(QAbstractAnimation::DeleteWhenStopped);

    QSequentialAnimationGroup *anim = new QSequentialAnimationGroup;
    anim->addAnimation(anim_close);
    anim->addAnimation(anim_open);
    anim->start();
}


//void anim_menubar::tbOpen(QToolBar *Panel)
//{
//    QPropertyAnimation *anim = new QPropertyAnimation(Panel, "geometry");
//    anim->setDuration(350);
//    anim->setEasingCurve(QEasingCurve::InOutCubic);
//    anim->setEndValue(QRectF(0, HeightTopPanel, startW, startH));
//    anim->start(QAbstractAnimation::DeleteWhenStopped);
//}
//
//void anim_menubar::tbClose(QToolBar *Panel)
//{
//    QPropertyAnimation *anim = new QPropertyAnimation(Panel, "geometry");
//    anim->setDuration(350);
//    anim->setEasingCurve(QEasingCurve::InOutCubic);
//    anim->setEndValue(QRectF(0, HeightTopPanel, startW, 0));
//    anim->start(QAbstractAnimation::DeleteWhenStopped);
//}
//
//void anim_menubar::tbSwitch(QToolBar *tbclose, QToolBar *tbopen)
//{
//    QPropertyAnimation *anim_close = new QPropertyAnimation(tbclose, "geometry");
//    anim_close->setDuration(350);
//    anim_close->setEasingCurve(QEasingCurve::InOutCubic);
//    anim_close->setEndValue(QRectF(0, HeightTopPanel, startW, 0));
//
//    QPropertyAnimation *anim_open = new QPropertyAnimation(tbopen, "geometry");
//    anim_open->setDuration(350);
//    anim_open->setEasingCurve(QEasingCurve::InOutCubic);
//    anim_open->setEndValue(QRectF(0, HeightTopPanel, startW, startH));
//
//    QSequentialAnimationGroup *anim = new QSequentialAnimationGroup;
//    anim->addAnimation(anim_close);
//    anim->addAnimation(anim_open);
//    anim->start();
//}



void anim_menubar::on_menubarBtnOverview_clicked()
{
    b_stateReceive      = false;
    b_stateSend         = false;
    b_stateTransactions = false;
    if (SubPanelIsVisible && b_stateOverview)
    {

        //tbSwitch(tbArr[1], tbArr[0]);
        AnimCloseOpen(gbReceive, gbOverview);
    }
    else
    {
        //tbClose(tbArr[0]);
        PlayAnimClose(gbOverview);
    }
    SubPanelIsVisible = !SubPanelIsVisible;
    b_stateOverview = true;
}

void anim_menubar::on_menubarBtnReceive_clicked()
{
    b_stateOverview     = false;
    b_stateSend         = false;
    b_stateTransactions = false;
    if (SubPanelIsVisible && b_stateReceive)
    {
        //tbSwitch(tbArr[0], tbArr[1]);
        AnimCloseOpen(gbOverview, gbReceive);
    }
    else
    {
        //tbClose(tbArr[1]);
        PlayAnimClose(gbReceive);
    }
    SubPanelIsVisible = !SubPanelIsVisible;
    b_stateReceive      = true;
    //PlayAnimClose(gbOverview);
    //PlayAnimClose(gbReceive);
    //if (ui->menubarBtnReceive->isChecked())
    //{
    //   SubPanelIsVisible = !SubPanelIsVisible;
    //}
    //
    //if (SubPanelIsVisible)
    //{
    //    PlayAnimOpen(gbReceive);
    //}
    //else
    //{
    //    PlayAnimClose(gbReceive);
    //{
}

void anim_menubar::on_menubarBtnSend_clicked()
{

}

void anim_menubar::on_menubarBtnTransactions_clicked()
{

}
