#! /bin/bash

function walker(){
    echo "Current Index: "$1

    for file in "$1"/*
    do
    if [[ ! -d $file ]]; then
        echo $file
        suffix=`echo "${file##*.}"`
        if [[ $suffix == 'o' || $suffix == 'out' || $suffix == 'exe' || $suffix == 'txt' ]]; then
            echo "Are you sure running: rm ${file} (y/n)?"
            read yes
            if [[ $yes == 'y' ]]; then
                rm "$file"
            fi
        fi
    else
        echo $file" <= is a directory !"
        walker "$file"
    fi
    done
}

walker .
