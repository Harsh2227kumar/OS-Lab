#!/bin/bash

read -p "Enter a number: " n

factorial=1
i=1

while [ $i -le $n ]
do
    ((factorial *= i))
    ((i++))
done

echo "Factorial of $n is $factorial"
