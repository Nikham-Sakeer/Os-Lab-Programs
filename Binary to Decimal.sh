#!/bin/bash

echo -n -e "Enter a binary number:"

read num

bin=$num

dec=0

base=1

while [ $num -gt 0 ]

do

rem=`expr $num % 10`

dec=`expr $dec + $rem \* $base`

num=`expr $num / 10`

base=`expr $base \* 2`

done

echo "Binary number is $bin"

echo "Decimal number is $dec"
