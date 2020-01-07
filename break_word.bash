#!/bin/bash
#*************************************************************************************
# script name: break_word
# Description: splits a string by character and prints the letters on separate lines
# Parameters: 1st parameter: string to split
# Return value: none
#*************************************************************************************
strng="$1"
for (( i=0; i<${#strng}; i++ )); do
  echo "${strng:$i:1}"
done