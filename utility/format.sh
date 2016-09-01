#!/bin/bash

# check if stdout is a terminal...
if test -t 0; then

    # see if it supports colors...
    ncolors=$(tput colors)

    if test -n "$ncolors" && test $ncolors -ge 8; then
	bold="$(tput bold)"
	underline="$(tput smul)"
	standout="$(tput smso)"
	normal="$(tput sgr0)"
	black="$(tput setaf 0)"
	red="$(tput setaf 1)"
	green="$(tput setaf 2)"
	yellow="$(tput setaf 3)"
	blue="$(tput setaf 4)"
	magenta="$(tput setaf 5)"
	cyan="$(tput setaf 6)"
	white="$(tput setaf 7)"
    fi
fi

echo "${yellow}Formatting source files with${normal} ${white}CLANG-FORMAT${normal}"
for FILE in $(find ./src ./clients/ -type f -name "*.cpp" -or -name "*.h"); do echo "formatting${green}" ${FILE}${normal}; clang-format -i ${FILE}; done
echo
#echo "${yellow}Formatting AIML files with${normal} ${white}XMLLINT${normal}"
#for FILE in $(find ./src/ -type f -name "*.aiml"); do echo "formatting${green}" ${FILE}${normal}; xmllint -format -recover ${FILE} > ${FILE}.linted; mv ${FILE}.linted ${FILE}; done
#echo
echo "${yellow}Formatting AIML files with${normal} ${white}TIDY{normal}"
for FILE in $(find ./src/ -type f -name "*.aiml"); do echo "formatting${green}" ${FILE}${normal}; tidy -xml -i -m --wrap 0 ${FILE}; done
