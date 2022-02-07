#!/bin/sh
echo "enter  directory name "
read ndir
if [ -d "ndir" ]
then
echo "Directory exists"
else
`mkdir $ndir`
echo "directory created"
fi
