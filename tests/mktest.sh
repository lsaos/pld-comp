echo "Test ID;Return code validation;Out result;StdErr result;Return code of assembly execution; File creation result;Global result" >results.csv
nOk=0
nKo=0
nTotal=0
nMis=0

categorySuccess=(0 0 0 0 0 0)
categoryCount=(0 0 0 0 0 0)
categoryNames=(ReturnCode____ Output________ StdErr________ AssemblyReturn FileProduction Global)
directories=$(find . -type d | grep -e "Test[0-9][0-9]*")

for i in $directories
do
  ./test.sh $i results.csv
  result=$?
  if [ $result -eq 0 ]
  then
    let "nKo=$nKo+1"
  elif [ $result -eq 1 ]
  then
    let "nOk=$nOk+1"
  else
    let "nMis=$nMis+1"
  fi
  if [ $result -ne 2 ]
  then
    #Updating stats of results
    index=-1
    for value in $(tail -n 1 results.csv | tr ";" "\n")
    do
        if [[ $value =~ ^-?[0-9]+$ ]]
        then
        if [ $value -eq 1 ]
        then
          let "categorySuccess[$index]=${categorySuccess[$index]}+1"
          let "categoryCount[$index]=${categoryCount[$index]}+1"
        elif [ $value -eq 0 ]
        then
          let "categoryCount[$index]=${categoryCount[$index]}+1"
        fi
      fi
      let "index=$index+1"
    done
  fi
  let "nTotal=$nTotal+1"
done

i=0
while [ $i -lt 5 ]
do
  if [ ${categoryCount[$i]} -gt 0 ]; then
    echo "${categoryNames[$i]}   : ${categorySuccess[$i]} / ${categoryCount[$i]}"
  fi
  let "i=$i+1"
done
echo "-----------------------"
echo "Passed tests     : $nOk"
echo "Failed tests     : $nKo"
echo "Misformed tests  : $nMis"
echo "-----------------------"
echo "Total            : $nTotal"
