#!/bin/sh
# This script is for a wallet "Platinum". To enable POS-mining 
# open /.PLATINUM/platinum.config and add line "staking=1" after that,
# complite script PlatinumRun-unix.sh as a root user. If you haven't 
# root, open shell and type "sudo passwd root", and set any password
# (DON'T FORGET THAT PASS).
# That script make your daemon Platinumd autorun anytime after boot your system.
mv ./src/Platinumd /usr/bin/
cd /usr/bin
   touch PlatinumAutorun.sh
   chmod 755 PlatinumAutorun.sh
   echo '#!/bin/sh' > PlatinumAutorun.sh
   echo 'Platinumd -daemon' >> PlatinumAutorun.sh
cd /lib/systemd/system
   touch runplatinarun.service
   chmod 755 runplatinarun.service
   echo '[Unit]' > runplatinarun.service
   echo 'Description=PlatinumAutorunScript' >> runplatinarun.service
   echo 'After=multi-user.target' >> runplatinarun.service

   echo '[Service]' >> runplatinarun.service
   echo 'Type=forking' >> runplatinarun.service
   echo 'User=root' >> runplatinarun.service
   echo 'ExecStart=/usr/bin/PlatinumAutorun.sh' >> runplatinarun.service
   echo 'OOMScoreAdjust=-100' >> runplatinarun.service

   echo '[Install]' >> runplatinarun.service
   echo 'WantedBy=multi-user.target' >> runplatinarun.service

   systemctl enable runplatinarun
   systemctl start runplatinarun
   systemctl daemon-reload



