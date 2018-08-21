#!/bin/bash/
echo "Installing libfcgi-dev"
echo "----------------------------------------"
apt-get install libfcgi-dev -y

echo "Installing spawn-fcgi"
echo "----------------------------------------"
apt-get install spawn-fcgi -y

echo "Installing nginx"
echo "----------------------------------------"
apt-get install nginx -y

echo "Installing curl"
echo "----------------------------------------"
apt-get install curl -y

echo "Installing sqlite3"
echo "----------------------------------------"
apt-get install sqlite3 -y
apt-get install libsqlite3-dev -y

mkdir -p /etc/nginx/smarthome
cp -r ./* /etc/nginx/smarthome
cd /etc/nginx/smarthome/

service nginx stop

cp -r ./nginx/* /etc/nginx/

#compile the native code (c++)
make

service nginx start

#add to corntab nginx service at every reboot
crontab cronjobs.txt

spawn-fcgi -p 8000 -n smart

chmod +x smart_home

