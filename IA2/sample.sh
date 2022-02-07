#!/bin/sh
echo "Today's date : `date`"
echo "this month's calendar:"
cal `date "+%m 20%y"`
echo "My Shell :$SHELL"

