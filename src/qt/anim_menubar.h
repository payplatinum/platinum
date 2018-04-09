#ifndef ANIM_MENUBAR_H
#define ANIM_MENUBAR_H

#include <QWidget>

#include <QList>
#include <QPushButton>
#include <QGroupBox>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QToolBar>
#include <QAction>

namespace Ui {
class anim_menubar;
}

class anim_menubar : public QWidget
{
    Q_OBJECT

public:
    explicit anim_menubar(QWidget *parent = 0);
    ~anim_menubar();

private slots:
    void PlayAnimOpen(QGroupBox *Panel);
    void PlayAnimClose(QGroupBox *Panel);
    void AnimCloseOpen(QGroupBox *close, QGroupBox *open);


    //void tbOpen(QToolBar *tb);
    //void tbClose(QToolBar *tb);
    //void tbSwitch(QToolBar *tbClose, QToolBar *tbOpen);


    void on_menubarBtnOverview_clicked();
    void on_menubarBtnReceive_clicked();
    void on_menubarBtnSend_clicked();
    void on_menubarBtnTransactions_clicked();

private:
    Ui::anim_menubar *ui;

    QGroupBox *gbOverview;
    QGroupBox *gbReceive;
    QGroupBox *gbSend;
    QGroupBox *gbTransactions;
    QGroupBox *gbMasternodes;
    QGroupBox *gbMessages;
    QGroupBox *gbBlockExplorer;

    //QToolBar *tbArr[9];


    //QAction *overviewAction;
    //QAction *sendAction;
    //QAction *Act1;
    //QAction *Act2;


public:
    int HeightTopPanel;
    int startX, startY, startW, startH;
    bool SubPanelIsVisible;
    bool doubleCheck;

    bool b_stateOverview    ;
    bool b_stateReceive     ;
    bool b_stateSend        ;
    bool b_stateTransactions;
};

#endif // ANIM_MENUBAR_H
