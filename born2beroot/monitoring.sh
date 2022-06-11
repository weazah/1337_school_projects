# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    monitoring.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozahir <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/05 16:32:18 by ozahir            #+#    #+#              #
#    Updated: 2022/02/11 16:22:57 by ozahir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash
usedm=$(free -m | grep Mem | tr -s ' ' | cut -d ' ' -f 3)
totalm=$(free -m | grep Mem | tr -s ' ' | cut -d ' ' -f 2)
fdisk=$(lsblk | grep "sda " | tr -s ' ' | cut -d ' ' -f 4)
udisk=$(df -m | grep ^/dev/  | grep -v 'boot$'  | tr -s ' '| cut   -d\  -f 3 | awk '{ud += $0} END {print ud}')
full=$(df -Bm | grep ^/dev | grep -v 'boot'| tr -s ' ' | cut -d\  -f 3,4 | tr -d 'M' | awk '{u += $1} {f += $2} END {printf("%d"), u/f*100}')
revmac=$(ls /sys/class/net/ | grep -v 'lo')
wall "  #Architecture: $(uname -a)
        #CPU physical: $(cat /proc/cpuinfo | grep "physical id" | sort | uniq | wc -l)
        #vCPU: $(cat /proc/cpuinfo | grep processor | wc -l)
		#Memory Usage: $usedm/${totalm}MB $(echo $usedm $totalm | awk '{u = $1} {t = $2} END {printf("%.2f"), u/t*100}')%
        #Disk Usage: $udisk/${fdisk}b ($full%)
        #CPU load: $(top -bn1 | grep Cpu | tr "  " '\n' | head -n 3 | tail -n +3 )%
        #Last boot: $(who -b | tr -d "systemboot" | tr -s " ")
        #LVM use: $(lsblk | grep lvm | awk '{if ($1){ printf("yes")} else {printf("no")} exit}')
        #Connexions TCP: $(netstat -an |grep ESTABLISHED | wc -l) ESTABLISHED
        #User log: $(users | wc -w)
        #Network: IP $(hostname -I) $(cat /sys/class/net/$revmac/address)
        #Sudo: $(cat /var/log/sudo/sudo.log | grep COMMAND | wc -l) cmd "
