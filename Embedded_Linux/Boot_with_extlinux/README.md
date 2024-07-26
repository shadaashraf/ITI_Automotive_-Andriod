

# Booting the Kernel "zImage" through QEMU using extlinux Config

This guide explains how to boot a Linux kernel (`zImage`) using QEMU with an extlinux configuration. At the end, the init process is a simple C program that prints "hello, it's shada".

## Requirements


## Steps

### 1. Prepare the Init Program

First, create a simple C program that will be used as the init process.

`
#include <stdio.h>`
`#include <unistd.h>`
`int main(void) {`
   ` printf("hello, it's shada\n");`
   ` while (1) {
        sleep(1);
    }`
   ` return 0;
}`

**Compile the program:**

` ~/x-tools/arm-cortexa9_neon-linux-musleabihf/bin/arm-cortexa9_neon-linux-musleabihf-gcc -static main.c -o init
` 


### 2. Prepare the SD Card

Assuming you have an SD image, mount it to the appropriate directories:


`
 sudo mount /dev/loop15p1 /mnt/Boot/
 sudo mount /dev/loop15p2 /mnt/Rootfs/
` 

Place the necessary files in the boot partition:

`/mnt/Boot
├── extlinux
│   └── extlinux.conf
├── uboot.env
├── vexpress-v2p-ca9.dtb
└── zImage` 

Your `extlinux.conf` file should look like this:


`# /mnt/Boot/extlinux/extlinux.conf
DEFAULT linux
LABEL linux
    KERNEL /zImage
    FDT /vexpress-v2p-ca9.dtb
 `

### 3. Copy the Init Program to Rootfs

Copy the compiled `init` program to the root filesystem:

`cp init /mnt/Rootfs` 


### 5. Boot with QEMU

Use QEMU to boot the kernel with the created SD image. 



`sudo qemu-system-arm -M vexpress-a9 -nographic -kernel u-boot -sd sd.img ` 

**Set the `bootargs` and `bootcmd` environment variables correctly:**
`editenv bootargs 'console=ttyAMA0 root=/dev/mmcblk0p2 rw init=/init
' `
`editenv bootcmd 'bootflow scan' ` 

### 6. Verify

If everything is set up correctly, QEMU should boot the kernel, and you should see the message:

rust

Copy code

`hello, it's shada`
### 6. Output
/home/shada/Pictures/Screenshot from 2024-07-26 14-43-26.png
