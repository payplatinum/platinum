apt-get install automake autoconf pkg-config libcurl4-openssl-dev libjansson-dev libssl-dev libgmp-dev make g++
git clone https://github.com/SazonovDV/cpuminer-multi
cd cpuminer-multi
U=$PWD
./build.sh
find / -name ".PLATINUM" > configs.txt
cp cpuminer /usr/bin
I=0
while read LINE
	do
	I=$[I + 1]
	US=`grep -E rpcuser ${LINE}/Platinum.conf | cut -d= -f2`
	PS=`grep -E rpcpassword ${LINE}/Platinum.conf | cut -d= -f2`
	touch /usr/bin/${US}${I}Run.sh
	chmod 755 /usr/bin/${US}${I}Run.sh
   		echo '#!/bin/sh' > /usr/bin/${US}${I}Run.sh
   		echo cpuminer -a X11 -o http://127.0.0.1:10201 --userpass=${US}:${PS} >> /usr/bin/${US}${I}Run.sh
	cd /lib/systemd/system
	touch ${US}${I}Run.service
   	chmod 755 ${US}${I}Run.service
   	echo '[Unit]' > ${US}${I}Run.service
   	echo 'Description=PlatinumAutorunScript' >> ${US}${I}Run.service
   	echo 'After=multi-user.target' >> ${US}${I}Run.service

   	echo '[Service]' >> ${US}${I}Run.service
   	echo 'Type=simple' >> ${US}${I}Run.service
   	echo 'User=root' >> ${US}${I}Run.service
   	echo  ExecStart=/usr/bin/${US}${I}Run.sh >> ${US}${I}Run.service
   	echo 'OOMScoreAdjust=-100' >> ${US}${I}Run.service
	echo 'TimeoutSec=30' >> ${US}${I}Run.service
   	echo '[Install]' >> ${US}${I}Run.service
   	echo 'WantedBy=multi-user.target' >> ${US}${I}Run.service
	systemctl enable ${US}${I}Run.service
   	systemctl start ${US}${I}Run.service
   	systemctl daemon-reload
	cd $U
done < configs.txt
rm configs.txt

