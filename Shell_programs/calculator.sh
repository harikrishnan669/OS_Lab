#!/bin/bash_
result=0
i=1
while [ $i = 1 ]
do
echo "Enter the first number"
read num1
echo "Enter the second number"
read num2
echo "MENU"
echo "1-Addition"
echo "2-Subtraction"
echo "3-Division"
echo "4-Multiplication"
echo "5-Modulus"
echo "Enter your choice"
read ch
case $ch in
1)
result=$(($num1+$num2))
echo "Result is = $result";;
2)
result=$(($num1-$num2))
echo "Result is = $result";;
3)
result=$(($num1/$num2))
echo "Result is = $result";;
4)
result=$(($num1*$num2))
echo "Result is = $result";;
5)
result=$(($num1%$num2))
echo "Result is = $result";;
esac
echo "Do you want to continue(press 1 to continue and O to exit)"
read i
if [ $i = 0 ]
then
exit
fi
done
