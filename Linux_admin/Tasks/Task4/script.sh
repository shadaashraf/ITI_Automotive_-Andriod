#!/bin/bash

username="Shada"
groupname="Ashraf"

if ! id "$username" &>/dev/null; then
    sudo useradd -m "$username"
    echo "User '$username' created."
fi

if ! grep -q "^$groupname:" /etc/group; then
    sudo groupadd "$groupname"
    echo "Group '$groupname' created."
fi

sudo usermod -aG "$groupname" "$username"
echo "User '$username' added to group '$groupname'."

echo "--- User Information ---"
id "$username"

echo "--- Group Information ---"
getent group "$groupname"
