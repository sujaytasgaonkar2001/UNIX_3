#!/bin/sh
filename=$1
if [ -f "$filename" ]; then
echo "file exists"
else
` cat>$filename`
echo "As the file does not exist,we created  the file $1"
echo "`cat $1`"
fi
