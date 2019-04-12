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

cd $Directory

if [ -r "description" ]
then 
  echo "-----------------------------------------------------------"
  echo "Description :"
  fold description -w 60 -s
  echo -e "\n-----------------------------------------------------------"
fi

nTestCount=0
nSuccesfulTests=0
nStrResult="$1 "

if [ -r "run" ]
then
  sRun=`cat run`
else
  echo "No run file found. Exiting."
  exit 2
fi

sRun="$sRun >temp.txt >temperr.txt"

# stdin has been specified
if [ -r "std.in" ]
then 
  sRun="$sRun <std.in"
fi

echo $sRun
# execute the command line
eval $sRun

returnCode=$?

resultGlobal=1

# compare return code if concerned
resultRC=2
if [ -r "returncode" ]
then 
  if [ "$returnCode" = `cat returncode` ]
  then
    echo "                                       Return Code : PASSED"
    resultRC=1
  else
    echo "                                       Return Code : FAILED"
    resultRC=0
    resultGlobal=0
  fi
fi

# stdout has been specified
if [ ! -r "std.out" ]
then 
  rm temp.txt
fi

# stderr has been specified
if [ ! -r "stderr.out" ]
then 
  rm temperr.txt
fi

# compare stdout if concerned
resultOut=2
if [ -r "std.out" ]
then 
  diff -wB temp.txt std.out >/dev/null
  if [ $? -eq 0 ]
  then
    echo "                                       Stdout      : PASSED"
    resultOut=1
  else
    echo "                                       Stdout      : FAILED"
    resultOut=0
    resultGlobal=0
  fi
  # clean temporary out file
  rm temp.txt
fi

# compare stderr if concerned
resultErr=2
if [ -r "stderr.out" ]
then 
  diff -wB temperr.txt stderr.out >/dev/null
  if [ $? -eq 0 ]
  then
    echo "                                       Stderr      : PASSED"
    resultErr=1
  else
    echo "                                       Stderr      : FAILED"
    resultErr=0
    resultGlobal=0
  fi
  # clean temporary out file
  rm temperr.txt
fi

#If assembly was produced, does it have the same output as a classic gcc ?
#Get filename:
resultRCComp=2
for i in *.s
do
	fileName=`basename $i .s`
	if [ -r "$fileName.s" ]; then
		as -o "$fileName.o" "$fileName.s" && gcc "$fileName.o" && ./a.out > putChar
		returnCodeAssembly=$?
		rm -f "$fileName.o" "a.out"
		gcc "$fileName.c" && ./a.out
		returnCodeGCC=$?
		rm -f "a.out"
		if [ "$returnCodeGCC" = "$returnCodeAssembly" ]
		then
	   		echo "                             Return Code (Assembly): PASSED"
	   		resultRCComp=1
	   	else
			echo "                             Return Code (Assembly): FAILED"
			resultRCComp=0
			resultGlobal=0
		fi
		if [ ! -r "$fileName.s.outfile" ] ; then
			rm "$fileName.s"
		fi
		if [ ! -r putChar.outfile ] ; then
			rm putChar
		fi
	fi
done

# compare files created if concerned
resultFiles=2
if ls *.outfile &> /dev/null
then
  number=1
  for i in *.outfile
  do
    fileName=`basename $i .outfile`
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
      rm $fileName
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

echo "                                       --------------------"
if [ $resultGlobal -eq 0 ]
then
  echo "                                       Global      : FAILED"
else
  echo "                                       Global      : PASSED"
fi
echo "-----------------------------------------------------------"
echo 

cd $execDir

# log result in $2 if filename provided
if [ "$2" != "" ]
then
  if [ ! -w "$2" ]
  then
    touch $2
  fi
  if [ -w "$2" ]
  then
    echo "$Directory;$resultRC;$resultOut;$resultErr;$resultRCComp;$resultFiles;$resultGlobal" >>$2
  fi
fi

exit $resultGlobal
