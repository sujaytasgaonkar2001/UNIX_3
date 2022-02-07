#!/bin/sh
echo " enter first number"
read x
echo " enter second number"
read y
sum_res=`expr $x + $y ` 
echo "result of addition of $x and $y is $sum_res"

