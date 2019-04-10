#!/bin/sh

if [ "$1" = "" ]; then
	echo "No relative path to the ./compiler executable has been given. Giving up wrapping operation."
	exit 1
fi

i=1
files=$(ls *.c)

while [ -d "Test$i" ]
do
	let "i=$i+1"
done
echo "Already $i Test folders existing"
for file in $files
do
	dir="Test$i"
	mkdir $dir
	cp $file $dir/$file
	echo "-3" > $dir/returncode
	echo "../$1 $file">$dir/run
	touch $dir/description
	rm $file
	let "i=$i+1"
done

echo "Job done, built $i test directories. Please complete dir/description file."
