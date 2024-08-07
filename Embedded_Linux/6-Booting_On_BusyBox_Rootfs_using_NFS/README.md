
# Booting on BusyBox Rootfs using NFS

This project demonstrates how to configure an NFS server on your host machine to provide the root filesystem for a BusyBox-based embedded Linux system.

## Steps Overview

1.  Install and set up the NFS server.
2.  Prepare the root filesystem.
3.  Configure network settings.
4.  Boot the kernel in QEMU with NFS as the root filesystem.

## Step-by-Step Guide

### 1. Install NFS Server

Install the NFS server on your host machine:

`sudo apt install nfs-kernel-server` 

### 2. Verify the NFS Server Status

Ensure that the NFS server is running properly: 
`systemctl status nfs-kernel-server` 


![NFS Server Status](/mnt/data/Screenshot from 2024-08-07 20-45-25.png)


### 3. Prepare the Root Filesystem

Create a mount point for the NFS share:

`sudo mkdir /srv/nfs-share` 

Copy the root filesystem to the NFS share:

`sudo cp -r ~/rootfs/* /srv/nfs-share/` 

### 4. Check IP Address of Your Host Machine

Check the IP address of your host machine: 
`ifconfig` 

![ifconfig Output](/mnt/data/Screenshot from 2024-07-28 13-11-42.png)

In this example, the host machine's IP address is `192.168.1.6`.

### 5. Edit the Exports File

Edit the `/etc/exports` file to export the `/srv/nfs-share` directory:


`sudo vim /etc/exports` 

Add the following line:


	/srv/nfs-share 192.168.1.50(rw,no_root_squash,no_subtree_check)

![Edit Exports File](/mnt/data/Screenshot from 2024-07-28 13-16-09.png)

-   `/srv/nfs-share`: The directory on the NFS server that you are sharing.
-   `192.168.1.50`: The client allowed to access the NFS share.
-   `(rw,no_root_squash,no_subtree_check)`: Options that control permissions and behavior.

### 6. Restart the NFS Server

Restart the NFS server to apply the changes:


`sudo systemctl restart nfs-kernel-server` 

### 7. Configure Network Tap Interface

Instead of `tapScript`, use `LinkScript.sh`:
                    
	#!/bin/bash

	sudo ip tuntap add dev $1 mode tap
	sudo ip addr add 192.168.1.6/24 dev $1
	sudo ip link set $1 up

### 8. Start QEMU

Start QEMU with the following command:

	sudo qemu-system-arm -M vexpress-a9 -nographic -net nic -net tap,script=LinkScript.sh -kernel u-boot -sd sd.img

### 9. Configure U-Boot

#### Set Server IP Address


`setenv serverip 192.168.1.6` 

#### Set Client IP Address

`setenv ipaddr 192.168.1.50` 

#### Edit the bootcmd Environment Variable

bash

Copy code

`editenv bootcmd` 

Add:

	tftp $Zimag_RAM_Add zImage;tftp $dtb_hardware_Add vexpress-v2p-ca9.dtb; bootz $kernel_addr_r - $fdt_addr_r
### 12. Verify the Configuration

#### Check the kernel address:

`md $zImage_RAM_addr` 

![Kernel Address Check](/mnt/data/Screenshot from 2024-07-28 13-48-18.png)

#### Check the device tree blob address:

`md $fdt_addr_r` 

![Device Tree Blob Address Check](/mnt/data/Screenshot from 2024-07-28 13-49-19.png)

#### Edit the bootargs Environment Variable

`editenv bootargs` 

Add:

	console=ttyAMA0 root=/dev/nfs ip=192.168.1.50:::::eth0 nfsroot=192.168.1.6:/srv/nfs-share,nfsvers=3,tcp rw init=/sbin/init

### 10. Save Environment Variables

`saveenv` 

### 11. Reboot QEMU

`reset` 



#### Final Boot Output:

![Final Boot Output](/mnt/data/Screenshot from 2024-07-28 13-55-44.png)

