#!/bin/bash
echo "enter a number"
read n
if [ $((n%2)) -eq 0 ];
then
	echo "the number $n is even"
else
	echo "the number $n is odd"
fi
