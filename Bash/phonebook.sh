#!/bin/bash

linenum=0 
alpha="d"

if [ -e /etc/phonebook ]
then
	cd /etc/phonebook
	if [ -e .phonebookDB.txt ]
	then
	echo "The DataBase exists"
	else
	sudo touch .phonebookDB.txt
	sudo chmod a+rw .phonebookDB.txt
	fi

else
	cd /etc
	sudo mkdir phonebook
	cd phonebook
	sudo touch .phonebookDB.txt
	sudo chmod a+rw .phonebookDB.txt
	echo "The DataBase Created Successfully"
fi 


case $1 in 
"-i")
	read -p "please insert the new contact name: " cname
	read -p "please insert the new contact number: " cnum
	echo $cname  $cnum >> .phonebookDB.txt;;	

"-v")
	cat .phonebookDB.txt;;

"-s")
	read -p "please insert the first name of the contact you're searching for: " sname

	grep "^$sname" .phonebookDB.txt ;;

"-e")
	echo "" > .phonebookDB.txt;;

"-d")
	read -p "please insert the contact name you wanna delete: " dname
	sudo touch .temp
	sudo chmod a+rw .temp
	if ( grep "^$dname" .phonebookDB.txt; )
	then 
		#linenum=`grep -n "^$dname" .phonebookDB.txt | grep -Eo '^[^:]+'`
		#linenum=`grep -n "^$dname" .phonebookDB.txt | cut -f1 -d: | sort -u`
		linenum=`grep -n "^$dname" .phonebookDB.txt | awk -F: '{ print $1 }' | sort -u`

		echo $linenum
		dnum="${linenum: -1}"
		echo $dnum
		#dnum=$linenum$alpha
		sed "${dnum}d" .phonebookDB.txt >> .temp
		sudo rm .phonebookDB.txt
		sudo touch .phonebookDB.txt
		sudo chmod a+rw .phonebookDB.txt
		sudo cat .temp >> .phonebookDB.txt

	else 
		echo "no such contact"
	fi
	sudo rm .temp;;

*)
	echo "you have not choose any option to run,"
	echo " please pick one out of the following menu"
	echo "Insert new contact name and number, with the option "-i" "
	echo "View all saved contacts details, with the option "-v""
	echo "Search by contact name, with the option "-s""
	echo "Delete all records, with "-e""
	echo "Delete only one contact name, with "-d"";;

esac
