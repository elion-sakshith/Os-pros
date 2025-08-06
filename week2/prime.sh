#!/bin/bash

echo "Enter a number:"
read number

# Handle numbers less than 2
if [ "$number" -lt 2 ]; then
    echo "$number is not a prime number."
    exit 0
fi

# Check for divisibility from 2 up to the square root of the number
i=2
max_check=$(echo "sqrt($number)" | bc) # Calculate square root using 'bc'

while [ "$i" -le "$max_check" ]; do
    if [ $((number % i)) -eq 0 ]; then
        echo "$number is not a prime number."
        exit 0
    fi
    i=$((i + 1))
done

echo "$number is a prime number."
