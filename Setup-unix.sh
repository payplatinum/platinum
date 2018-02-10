#!/bin/bash

apt install build-essential libtool automake autotools-dev autoconf pkg-config libssl-dev libgmp3-dev libevent-dev bsdmainutils libboost-all-dev libminiupnpc-dev libqt5gui5 libqt5core5a libqt5dbus5 qttools5-dev qttools5-dev-tools libprotobuf-dev protobuf-compiler libqrencode-dev 
add-apt-repository ppa:bitcoin/bitcoin
apt update
apt install libdb4.8-dev libdb4.8++-dev
git clone https://github.com/payplatinum/platinum
cd platinum
U=$PWD
#chmod -R 755 /root
  cd /usr/share/applications
  touch Platinum.desktop
   chmod 755 Platinum.desktop
        echo '[Desktop Entry]' > Platinum.desktop
        echo 'Version=1.0' >> Platinum.desktop
        echo 'Terminal=false' >> Platinum.desktop
        echo 'Type=Application' >> Platinum.desktop
        echo 'Name=Platinum Wallet' >> Platinum.desktop
        echo 'Comment=Platinum wallet' >> Platinum.desktop
        echo Exec=$U/Platinum-qt >> Platinum.desktop
        echo Path=$U >> Platinum.desktop
        echo Icon=$U/src/qt/res/icons/Platinum.png >> Platinum.desktop
        echo 'Categories=Application;' >> Platinum.desktop

        grep -E -v  "[a-zA-Z]\:[0-9]{1,3}\:" /etc/passwd | cut -d: -f1 > deskkk.txt
        file="deskkk.txt"
        while read  line
        do
        if [[ $line != "nobody" ]]
	then
	cp Platinum.desktop /home/${line}
	chmod 755 /home/${line}/Platinum.desktop
	chown ${line} /home/${line}/Platinum.desktop
        fi
	done < $file
     rm deskkk.txt

cd $U
chmod -R 755 *
qmake -qt=qt5
#add -jN (where N number of CPU cores) after make
make
