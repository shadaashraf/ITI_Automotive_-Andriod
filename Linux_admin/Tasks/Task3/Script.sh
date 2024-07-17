#!/bin/bash

bashrc_file="$HOME/.bashrc"

if [ -f "$bashrc_file" ]; then
    echo "export HELLO=$HOSTNAME" >> "$bashrc_file"
    echo "LOCAL=\$(whoami)" >> "$bashrc_file"
fi

gnome-terminal &
