#!/bin/bash
echo "enter your lucky number"
read n
case $n in
101) echo "hurray...!!!you got first prize..!!!" ;;
500) echo "you got the second prize " ;;
999) echo "you got the third prize " ;;
*) echo " sorry...!! better luck next time";;
esac
