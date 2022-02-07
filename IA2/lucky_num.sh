#!/bin/sh
# lucky draw script
echo "enter your lucky number"
read n
if [ $n -eq 101 ];
then
echo " you got the first prize "
elif [ $n -eq 500 ];
then
echo " you got the second prize "
elif [ $n -eq 900 ];
then
echo " you got the third prize "
else
echo " Sorry...!!! better luck next time"
fi

