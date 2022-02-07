#!/bin/sh
# shell script to compare three numbers and printout msg regading the greatest number
echo "enter the 3 digits"
read a b c
if [ $a -gt $b && $a -gt $c ] ;then
echo "$a is greatest among $a ,$b and $c "
elif [ $b -gt $a && $b -gt $c ] ;then
echo "$b is greatest among $a ,$b and $c "
else
echo "$c is greatest among $a ,$b and $c "
fi
