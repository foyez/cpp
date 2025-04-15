# Born2beroot

## VirtualBox vs UTM vs Docker vs Dualboot

All four—VirtualBox, UTM, Docker, and Dualboot—are ways to run multiple operating systems or environments, but they each serve different purposes and have different strengths.

0. VirtualBox vs UTM vs Docker vs Dualboot
1. What is signature?
1. you will install the minimum of services.
2. You must choose as an operating system either the latest stable version of Debian (no testing/unstable),
1. Setting up Rocky is quite complex. Therefore, you don’t have to set up KDump.
2. SELinux must be running at startup and its configuration has to be adapted for the project’s needs.
3. AppArmor for Debian must be running at startup too.
4. You must create at least 2 encrypted partitions using LVM. (lsblk)

1. About the choosed os (Debian)
2. aptitude vs apt
3. SELinux or AppArmor

1. An SSH service will be running on the mandatory port 4242 in your virtual machine. For security reasons, it must not be possible to connect using SSH as root. (What will be happened if we connect using SSH as root.)
2. How does SSH work?
3. You have to configure your operating system with the UFW (or firewalld for Rocky) firewall and thus leave only port 4242 open in your virtual machine.
4. Your firewall must be active when you launch your virtual machine. For Rocky, you have to use firewalld instead of UFW.

1. The hostname of your virtual machine must be your login ending with 42 (e.g., wil42). You will have to modify this hostname during your evaluation.
2. You have to implement a strong password policy.
3. You have to install and configure sudo following strict rules.
4. In addition to the root user, a user with your login as username has to be present.
5. This user has to belong to the user42 and sudo groups.
6. During the defense, you will have to create a new user and assign it to a group.
7. password policies:
    - Your password has to expire every 30 days.
    - The minimum number of days allowed before the modification of a password will be set to 2.
    - The user has to receive a warning message 7 days before their password expires.
    - Your password must be at least 10 characters long. It must contain an uppercase letter, a lowercase letter, and a number. Also, it must not contain more than 3 consecutive identical characters.
    - The password must not include the name of the user.
    - The following rule does not apply to the root password: The password must have at least 7 characters that are not part of the former password.
    - your root password has to comply with this policy.
    - After setting up your configuration files, you will have to change all the passwords of the accounts present on the virtual machine, including the root account.

1. sudo group configuaration requirements:
    - Authentication using sudo has to be limited to 3 attempts in the event of an incorrect password.
    - A custom message of your choice has to be displayed if an error due to a wrong password occurs when using sudo.
    - Each action using sudo has to be archived, both inputs and outputs. The log file has to be saved in the /var/log/sudo/ folder.
    - The TTY mode has to be enabled for security reasons.
    - For security reasons too, the paths that can be used by sudo must be restricted.
      Example: /usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin

1. you have to create a simple script called monitoring.sh. It must be developed in bash.
2. At server startup, the script will display some information (listed below) on all terminals and every 10 minutes (take a look at wall). The banner is optional. No error must be visible.
3. script must always be able to display the following information:
    - The architecture of your operating system and its kernel version.
    - The number of physical processors.
    - The number of virtual processors.
    - The current available RAM on your server and its utilization rate as a percentage.
    - The current available storage on your server and its utilization rate as a percentage.
    - The current utilization rate of your processors as a percentage.
    - The date and time of the last reboot.
    - Whether LVM is active or not.
    - The number of active connections.
    - The number of users using the server.
    - The IPv4 address of your server and its MAC (Media Access Control) address.
    - The number of commands executed with the sudo program.
4. During the defense, you will be asked to explain how this script works. You will also have to interrupt it without modifying it. Take a look at cron.
5. To check os info: `head -n 2 /etc/os-release`

## Bonus part

1.
2. Set up a functional WordPress website with the following services: lighttpd, MariaDB, and PHP.
3. Set up a service of your choice that you think is useful (NGINX / Apache2 excluded!). During the defense, you will have to justify your choice.
4. To complete the bonus part, you have the possibility to set up extra services. In this case, you may open more ports to suit your needs. Of course, the UFW/Firewalld rules have to be adapted accordingly.

To get this signature:
    - first have to open the default installation folder (it is the folder where your VMs are saved)
      MacM1: ~/Library/Containers/com.utmapp.UTM/Data/Documents/
      MacOS: ~/VirtualBox VMs/
    - Then, retrieve the signature from the ".vdi" file (or ".qcow2" for UTM users) of your virtual machine in sha1 format.
      For Mac M1: shasum rocky.utm/Images/disk-0.qcow2
      MacOS: shasum rocky_serv.vdi
      Signature example: 6e657c4619944be17df3c31faa030c25e43e40af
    - Please note that your virtual machine’s signature may be altered after your first evaluation. To solve this problem, you can duplicate your virtual machine or use save state.

Note: The use of snapshots is FORBIDDEN.
