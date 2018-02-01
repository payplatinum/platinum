#!/bin/bash
#That script create a shortcut for launching wallet "Platinum".

#After that, a shortcut will be created in your home directory. The first time

#a shortcut is launched, the system may ask you that you are sure for running

#this questionable shortcut. If so, click "Yes." This operation should be done only once,

#after that you can safely copy the shortcut to the desktop or leave it as it is.

U=$PWD

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
