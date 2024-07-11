#!/bin/bash

Path="$1"  
Doc_path="$Path/Documents"
Image_path="$Path/Images"
Other_path="$Path/Others"


if [ ! -d "$Doc_path" ]; then
    mkdir -p "$Doc_path"
fi

if [ ! -d "$Image_path" ]; then
    mkdir -p "$Image_path"
fi

if [ ! -d "$Other_path" ]; then
    mkdir -p "$Other_path"
fi


for file in "$Path"/*; do
    if [ -f "$file" ]; then  
        filename=$(basename "$file")
        extension="${filename##*.}" 
        
        case "$extension" in
            doc|txt|pdf)
                mv "$file" "$Doc_path/"
                echo "Moved $file to $Doc_path/"
                ;;
            jpg|png|gif)
                mv "$file" "$Image_path/"
                echo "Moved $file to $Image_path/"
                ;;
            *)  # Default case: move all other files to 'Others'
                mv "$file" "$Other_path/"
                echo "Moved $file to $Other_path/"
                ;;
        esac
    fi
done

