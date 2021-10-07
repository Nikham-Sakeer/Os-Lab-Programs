#!/bin/bash
clear
echo "Program to find Combination in Probability"
function fact {
         mul=1
         i=$1
         while [[ $i -gt 1 ]]
         do
         sub=`expr $i - 1`
         mul=`expr $mul \* $i`
         i=$sub
         done
         echo $mul
         }

echo "Enter value for n"
n= read n
a=`fact $n`
echo "Enter Value for r"
r= read r
b=`fact $r`
c=`expr "$n" - "$r"`
d=`fact $c`
t=`expr "$b" \* "$d"`
ans=`expr "$a" / "$t"`

echo "Answer For $n! / ($n - $r)!($r)! is"
echo "$ans"
