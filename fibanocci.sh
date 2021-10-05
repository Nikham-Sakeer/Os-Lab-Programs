#!/bin/bash

echo -n -e "\nEnter the number of terms required: "
read num
a=0
b=1
for(( i=0;i<num;i++ ))
do
 echo -n "$a "
 fn=$(( a + b ))
 a=$b
 b=$fn
 done
 
