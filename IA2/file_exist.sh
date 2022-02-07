#!/bin/sh
filename=$1
if [ -f "$filename" ]; then
echo "file exists"
else
echo "file does not exist"
fi
