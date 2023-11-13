#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 <source_file>"
    exit 1
fi

source_file="$1"
output_file="${source_file%.c}_nocomments.c"

if [ -f "$source_file" ]; then
    # Remove single-line comments
    sed 's://.*$::' "$source_file" > "$output_file"

    # Remove multi-line comments
    sed '/\/\*/,/*\//d' "$output_file" > "$source_file"
else
    echo "Source file not found: $source_file"
    exit 1
fi

echo "Comments removed. Result saved in $output_file"
