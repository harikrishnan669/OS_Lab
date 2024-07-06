#!/bin/bash


if [ $# -ne 2 ]; then
    echo "Usage: $0 <number1> <number2>"
    exit 1
fi


is_palindrome() {
    num=$1
    reverse=$(echo $num | rev)
    if [ $num -eq $reverse ]; then
        return 0 
    else
        return 1 
    fi
}


num1=$1
num2=$2


if [ $num1 -gt $num2 ]; then
    temp=$num1
    num1=$num2
    num2=$temp
fi

echo "Palindrome numbers between $num1 and $num2:"
for ((i=num1; i<=num2; i++)); do
    if is_palindrome $i; then
        echo $i
    fi
done
