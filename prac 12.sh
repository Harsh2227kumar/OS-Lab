#!/bin/bash

while true; do
    echo
    echo "Select an option:"
    echo "1) Hello World"
    echo "2) Addition"
    echo "3) Age"
    echo "4) Country"
    echo "5) Subtraction"
    echo "6) Multiplication"
    echo "7) Largest of 2 numbers"
    echo "8) Largest of 3 numbers"
    echo "9) Division"
    echo "10) Even or Odd"
    echo "11) Leap Year"
    echo "12) Display Grade"
    echo "13) Exit"
    read -p "Enter your choice (1-13): " choice

    case $choice in
        1)
            echo "Hello World"
            ;;
        2)
            read -p "Enter first number: " a
            read -p "Enter second number: " b
            echo "Sum = $((a + b))"
            ;;
        3)
            read -p "Enter your age: " age
            echo "Your age is $age"
            ;;
        4)
            read -p "Enter your country: " country
            echo "Your country is $country"
            ;;
        5)
            read -p "Enter first number: " a
            read -p "Enter second number: " b
            echo "Subtraction = $((a - b))"
            ;;
        6)
            read -p "Enter first number: " a
            read -p "Enter second number: " b
            echo "Multiplication = $((a * b))"
            ;;
        7)
            read -p "Enter first number: " a
            read -p "Enter second number: " b
            if [ $a -gt $b ]; then echo "$a is largest"; else echo "$b is largest"; fi
            ;;
        8)
            read -p "Enter first number: " a
            read -p "Enter second number: " b
            read -p "Enter third number: " c
            largest=$a
            for num in $b $c; do
                if [ $num -gt $largest ]; then largest=$num; fi
            done
            echo "Largest number is $largest"
            ;;
        9)
            read -p "Enter numerator: " a
            read -p "Enter denominator: " b
            if [ $b -ne 0 ]; then echo "Division = $((a / b))"; else echo "Error: Division by zero"; fi
            ;;
        10)
            read -p "Enter a number: " a
            if [ $((a % 2)) -eq 0 ]; then echo "$a is Even"; else echo "$a is Odd"; fi
            ;;
        11)
            read -p "Enter a year: " year
            if [ $((year % 400)) -eq 0 ] || { [ $((year % 4)) -eq 0 ] && [ $((year % 100)) -ne 0 ]; }; then
                echo "$year is a Leap Year"
            else
                echo "$year is not a Leap Year"
            fi
            ;;
        12)
            read -p "Enter marks: " marks
            if [ $marks -ge 90 ]; then grade="A+" 
            elif [ $marks -ge 80 ]; then grade="A"
            elif [ $marks -ge 70 ]; then grade="B"
            elif [ $marks -ge 60 ]; then grade="C"
            elif [ $marks -ge 50 ]; then grade="D"
            else grade="F"
            fi
            echo "Grade = $grade"
            ;;
        13)
            echo "Exiting..."
            break
            ;;
        *)
            echo "Invalid choice. Try again."
            ;;
    esac
done
