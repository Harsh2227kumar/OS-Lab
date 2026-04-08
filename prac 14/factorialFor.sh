#!/bin/bash

read -p "Enter a number: " n

factorial=1

for ((i=1; i<=n; i++))
do
    ((factorial *= i))
done

echo "Factorial of $n is $factorial"
