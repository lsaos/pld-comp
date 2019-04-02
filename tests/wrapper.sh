#!/bin/sh

i=1
files=$(find . -type f | grep -e ".*[.]c")
for file in $files
do
	dir="Test$i"
	mkdir $dir
	cp $file $dir/$file
	echo "0" > $dir/returncode
	rm $file
	let "i=$i+1"
done