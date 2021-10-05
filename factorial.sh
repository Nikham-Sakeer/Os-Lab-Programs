#!/bin/bash
echo -n "Enter a number: "
read num                     
number=$num
fact=1                    

for((i=2;i<=num;i++))
{
  fact=$((fact * i)) 
}

echo "Factorial of $number is $fact"
