echo "-----------------------------------------------------------"

execDir=`pwd`

if [ "$1" = "" ]
then
	echo "No directory given, default to current"
	Directory="."
else
	echo "| Test id : $1"
	if [ -d "$1" ]
	then
		Directory="$1"
	else
		echo "$1 is not a directory. Exiting."
		exit 2
	fi
fi

if [ "$2" = "" ]
then
	echo "No specified compiler executable, trying with the default one : ./compiler"
	Exec="compiler"
else
	if [ -e "$2" ]
	then
		Exec="$2"
	else
		echo "The specified compiler $2 doesn't exist in this directory"
		exit 2
	fi
fi	

if [ -r "$Directory/description" ]
then
	echo "-----------------------------------------------------------"
	echo "Description :"
	fold description -w 60 -s
	echo "-----------------------------------------------------------"
fi

sRun="./$Exec $Directory/test.c 2>$Directory/std.err"
echo $sRun

eval $sRun
returnCode=$?

resultGlobal=1
resultRC=2
resultRCComp=2

#Was a return code expected ?
if [ -r "$Directory/returncode" ]
then
	if [ "$returnCode" = `cat $Directory/returncode` ]
	then
   		echo "                                       Return Code : PASSED"
   		resultRC=1
   	else
    	echo "                                       Return Code : FAILED"
    	resultRC=0
    fi
fi

# compare files created if concerned
resultFiles=2
if ls $Directory/*.outfile &> /dev/null
then
  number=1
  for i in $Directory/*.outfile
  do
    fileName=$Directory/`basename $i .outfile`
    echo "$i"
    echo "$fileName"
    if [ -r $fileName ]
    then
      diff -wB $i $fileName
      if [ $? -eq 0 ]
      then
        echo "                                       File #$number     : PASSED"
      else
        echo "                                       File #$number     : FAILED"
        resultFiles=0
        resultGlobal=0
      fi
    else  
      echo "                                       File #$number     : FAILED"
      resultFiles=0
      resultGlobal=0
    fi
    let "number=$number+1"
  done
  if [ $resultFiles -eq 2 ]
  then
    resultFiles=1
  fi
fi

#If assembly was produced, does it have the same output as a classic gcc ?
if [ -e "$Directory/test.s" ]
then
	as -o "$Directory/test.o" "$Directory/test.s"
	gcc "$Directory/test.o"
	./a.out
	returnCodeAssembly=$?
	rm -f "$Directory/test.o" "$Directory/a.out" "$Directory/test.s"
	gcc "$Directory/test.c"
	./a.out
	returnCodeGCC=$?
	rm -f "a.out"
	if [ "$returnCodeGCC" = "$returnCodeAssembly" ]
	then
   		echo "                             Return Code (Assembly): PASSED"
   		resultRCComp=1
   	else
    	echo "                             Return Code (Assembly): FAILED"
    	resultRCComp=0
    fi
    #FIXME Later : expecting an exact .s file
fi

resultErr=2
if [ -s "$Directory/std.err" ]
then
	if [ -e "$Directory/test.s" ]
	then
		resultErr=0
		resultGlobal=0
		echo "                                       CompilationError : FAILED"
	else
		resultErr=1
		echo "                                       CompilationError : PASSED"
	fi
else
	resultErr=1
	echo "                                       CompilationError : PASSED"
	rm -f "$Directory/std.err"
fi

rm -f "$Directory/test.s"

echo "                                       --------------------"
if [ $resultGlobal -eq 0 ]
then
  echo "                                       Global      : FAILED"
else
  echo "                                       Global      : PASSED"
fi
echo "-----------------------------------------------------------"
echo

# log result in $2 if filename provided
if [ "$3" != "" ]
then
  if [ ! -w "$3" ]
  then
    touch $3
  fi
  if [ -w "$3" ]
  then
    echo "$Directory;$resultRC;$resultRCComp;$resultErr;$resultFiles;$resultGlobal" >>$3
  fi
fi

exit $resultGlobal