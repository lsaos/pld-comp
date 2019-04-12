#!/bin/sh

if [ -f TestDescription.txt ]
then
	rm TestDescription.txt
fi

touch TestDescription.txt

directories=$(find . -type d | grep -e "Test[0-9][0-9]*")
for dir in $directories
do
	echo -e "-------------TEST : $dir\n" >> TestDescription.txt
	cat $dir/description >> TestDescription.txt
	echo -e "\n" >> TestDescription.txt
done