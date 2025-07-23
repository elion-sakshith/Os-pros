#!/bin/bash
echo "Enter Number"
read n
original=$n
sum=0
while [ $n -gt 0 ]
do 
	d=$((n%10))
	sum=$((sum + d*d*d))
        n=$((n/10))
done

if [ $sum -eq $original ] 
then
	echo "$original is armstrong"
else
	echo "$original is not armstrong"
fi
