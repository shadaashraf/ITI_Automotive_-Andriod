
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


![Screenshot from 2024-08-07 20-45-25](https://github.com/user-attachments/assets/f5474529-a522-41b8-b991-412862cd5eb9)


### 3. Prepare the Root Filesystem

Create a mount point for the NFS share:

`sudo mkdir /srv/nfs-share` 

Copy the root filesystem to the NFS share:

`sudo cp -r ~/rootfs/* /srv/nfs-share/` 

### 4. Check IP Address of Your Host Machine

Check the IP address of your host machine: 
`ifconfig` 



So, the host machine's IP address is `192.168.1.6`.
![Screenshot from 2024-07-28 13-11-42](https://github.com/user-attachments/assets/22bf38c4-0ea6-4cf3-ab5a-b77e5f088ceb)

### 5. Edit the Exports File

Edit the `/etc/exports` file to export the `/srv/nfs-share` directory:


`sudo vim /etc/exports` 

Add the following line:


	/srv/nfs-share 192.168.1.50(rw,no_root_squash,no_subtree_check)

![Screenshot from 2024-07-28 13-16-09](https://github.com/user-attachments/assets/527e8364-77e8-4efc-a29e-4b9d0c006de9)

**explination**
-   `/srv/nfs-share`: The directory on the NFS server that you are sharing.
-   `192.168.1.50`: The client allowed to access the NFS share.
-   `(rw,no_root_squash,no_subtree_check)`: Options that control permissions and behavior.

### 6. Restart the NFS Server

Restart the NFS server to apply the changes:


`sudo systemctl restart nfs-kernel-server` 

### 7. Configure Network Tap Interface

**LinkScript.sh**:
                    
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


**Check if this ip isn't used by Ping it**

![Screenshot from 2024-07-28 13-15-44](https://github.com/user-attachments/assets/e1e28ae6-4cf0-4ab3-9f12-9f5ffba10440)


#### Edit the bootcmd Environment Variable


`editenv bootcmd` 

Add:

	tftp $Zimag_RAM_Add zImage;tftp $dtb_hardware_Add vexpress-v2p-ca9.dtb; bootz $kernel_addr_r - $fdt_addr_r
### 12. Verify the Configuration

#### Check the kernel address:

`md $Zimag_RAM_Add` 


![Screenshot from 2024-07-28 13-48-18](https://github.com/user-attachments/assets/98c5bdd8-08ca-430a-b9d1-6f0420ff7775)

#### Check the device tree blob address:

`md $dtb_hardware_Add` 


![Screenshot from 2024-07-28 13-49-19](https://github.com/user-attachments/assets/a50452d0-0ea4-45b0-8782-7386caa1e990)

#### Edit the bootargs Environment Variable

`editenv bootargs` 

Add:

	console=ttyAMA0 root=/dev/nfs ip=192.168.1.50:::::eth0 nfsroot=192.168.1.6:/srv/nfs-share,nfsvers=3,tcp rw init=/sbin/init

### 10. Save Environment Variables

`saveenv` 

### 11. Reboot QEMU

`reset` 



#### Final Boot Output:



![Screenshot from 2024-07-28 13-55-06](https://github.com/user-attachments/assets/ae6f49e9-bc18-4d86-832a-6fffeda78ca0)
