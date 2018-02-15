#!/bin/sh
apt install git build-essential libtool automake autotools-dev autoconf pkg-config libssl-dev libgmp3-dev libevent-dev bsdmainutils libboost-all-dev libminiupnpc-dev
add-apt-repository ppa:bitcoin/bitcoin
apt update
apt install libdb4.8-dev libdb4.8++-dev
git clone https://github.com/payplatinum/platinum
cd platinum/src
#add -jN (where N number of CPU cores) after makefile.unix
make -f makefile.unix
mv ./Platinumd /usr/bin/
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



