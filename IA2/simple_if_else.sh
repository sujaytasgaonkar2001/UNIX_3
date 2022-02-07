#!/bin/sh
# shell script to compare two numbers
echo "enter the 2 digits"
read a b
if [ $a -lt $b ] 
then
echo "$b is greater than $a "
else
echo "$a is greater than $b"
fi
