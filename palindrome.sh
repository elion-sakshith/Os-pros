#!/bin/bash
echo "Enter a number:"

read n
original=$n
reversed=0

while [ $n -gt 0 ]
do 
    d=$((n % 10))
    reversed=$((($reversed * 10) + $d))  # Fixed the variable name from 'rev' to 'reversed'
    n=$((n / 10))
done

if [ $original -eq $reversed ]  # Fixed the missing space between the comparison
then
    echo "The given number $original is a palindrome."
else
    echo "The given number $original is not a palindrome."
fi

