#!/bin/bash

RED="\033[1;31m"
LRED="\033[0;31m"
GREEN="\033[1;32m"
LGREEN="\033[0;32m"
YELLOW="\033[1;33m"
LYELLOW="\033[0;33m"
BLUE="\033[1;34m"
LBLUE="\033[0;34m"
GREY="\033[1;37m"
NC="\033[0m"

test_ok()
{
	for file in maps/tests/ok*; do
		echo -e $LGREEN"Testing "$GREEN$file$NC
		./cub3d $file
		echo ""
		echo -en $LBLUE"Press any key to continue, or q to quit: "$NC
		read -a input
		if [ "$input" == "q" ] || [ "$input" == "Q" ]; then
			echo -e $RED"Quitting..."$NC
	    	exit 0
		fi
		echo ""
	done
}

test_invalid()
{
	for file in maps/tests/invalid*; do
		echo -e $LYELLOW"Testing "$YELLOW$file$NC
		./cub3d $file
		echo ""
		echo -en $LBLUE"Press any key to continue, or q to quit: "$NC
		read -a input
		if [ "$input" == "q" ] || [ "$input" == "Q" ]; then
			echo -e $RED"Quitting..."$NC
	    	exit 0
		fi
		echo ""
	done
}

echo -e $RED"Welcome to the cub3d map tester!"$LRED
echo -e 1- "Test valid maps"
echo -e 2- "Test invalid maps"
echo -e 3- "Test both"
read -p "Please enter the option you would like to test (1-3): " option
echo -e $NC
make re
if [ "$option" == "1" ]; then
	test_ok
elif [ "$option" == "2" ]; then
	test_invalid
elif [ "$option" == "3" ] || [ -z $option ]; then
	test_ok
	test_invalid
else
	echo -e $RED"Invalid option. Exiting..."$NC
	exit 1
fi