echo "Test ID;Return code validation;Out result;StdErr result;Return code of assembly execution; File creation result;Global result" >results.csv
nOk=0
nKo=0
nTotal=0
nMis=0

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
  let "nTotal=$nTotal+1"
done

echo "Passed tests     : $nOk"
echo "Failed tests     : $nKo"
echo "Misformed tests  : $nMis"
echo "-----------------------"
echo "Total            : $nTotal"
