shasum Bort2beroot.vdi

# user password
sudo chage -l [username/root]

# ssh
sudo systemctl status ssh
ssh username@localhost -p 4242
ssh root@localhost -p 4242

# cron
sudo crontab -u root -e
sudo reboot

# os
cat /etc/os-release

# user & group
getent group sudo
getent group user42
sudo adduser [username]
sudo groupadd [group_name]
sudo usermod -aG [group_name] [username]
sudo deluser [username] [group_name]
sudo userdel [username]

# hostname
hostnamectl
sudo hostnamectl set-hostname [new_hostname]
sudo reboot

# logical structure
lsblk
dpkg -l | grep sudo
sudo visudo

# sudo
ls /var/log/sudo
cat /var/log/sudo/[log_file]

# ufw
sudo ufw status
sudo ufw status numbered
sudo ufw allow [port]
sudo ufw delete [rule_number]
