#!/bin/bash
a=0
b=1
i=1
echo "Enter the limit value"
read n
echo "The fibinocci series is"
while [ $i -le $n ]
do
echo "$a"
sum=$(($a+$b))
a=$b 
b=$sum
i=$(($i+1))
done
