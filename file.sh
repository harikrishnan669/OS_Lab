#!/bin/bash

# Check if filename and word are provided
if [ $# -ne 2 ]; then
    echo "Usage: $0 <filename> <word>"
    exit 1
fi

filename=$1
word=$2

# Check if the file exists
if [ ! -f "$filename" ]; then
    echo "File '$filename' not found."
    exit 1
fi

# Search for the word in the file
echo "Searching for '$word' in '$filename':"
grep -o -i "$word" "$filename" | wc -l
