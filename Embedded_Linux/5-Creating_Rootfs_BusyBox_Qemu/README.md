
# Creating a BusyBox Root Filesystem QEMU

## Prerequisites

Before you begin, ensure that BusyBox is successfully built and installed on your machine. This guide assumes you have a working BusyBox installation available. If BusyBox is not yet installed, refer to its [official documentation](https://busybox.net/downloads/) for installation instructions.

## Introduction

This guide outlines the steps to create a BusyBox-based root filesystem  in QEMU. The process includes setting up the root filesystem, configuring initialization scripts, and running the system in an emulated environment.

## Steps to Create the Root Filesystem

### 1. Prepare the Root Filesystem Directory

1. **Exit BusyBox Directory**

   Navigate out of the BusyBox installation directory:

   ```bash
   cd ..
   ```

2. **Create the Root Filesystem Directory**

   Set up a new directory for the root filesystem:

   ```bash
   mkdir rootfs
   ```

3. **Copy BusyBox Installation Files**

   Transfer BusyBox’s installation files to the `rootfs` directory:

   ```bash
   cp -rp ~/busybox/_install/ ~/rootfs
   ```

4. **Change to the Root Filesystem Directory**

   ```bash
   cd rootfs
   ```

5. **Create Essential System Directories**

   Establish the necessary directories inside `rootfs`:

   ```bash
   mkdir -p dev proc sys etc boot root home mnt srv
   ```

### 2. Configure System Initialization

1. **Set Up Initialization Scripts**

   - **Create `init.d` Directory**

     ```bash
     mkdir -p etc/init.d
     ```

   - **Create and Edit the `rcs` Script**

     Create the `rcs` initialization script to mount essential filesystems:

     ```bash
     touch etc/init.d/rcs
     ```

     Add the following script to `rcs`:

     ```bash
     #!/bin/sh
     # Mount essential filesystems
     mount -t proc proc /proc
     mount -t sysfs sys /sys
     mount -t devtmpfs dev /dev
     ```

   - **Make `rcs` Script Executable**

     ```bash
     chmod +x etc/init.d/rcs
     ```

2. **Configure System Initialization**

   - **Create `inittab` File**

     ```bash
     touch etc/inittab
     ```

   - **Edit `inittab` for System Initialization**

     Add configuration to `inittab` for managing system processes:

     ```bash
     ::sysinit:/etc/init.d/rcs
     ttyAMA0::askfirst:-/bin/sh
     ::restart:/sbin/init
     ```


3. **Adjust Permissions**

   Change ownership of the `rootfs` directory to `root`:

   ```bash
   chown -R root:root ~/rootfs
   ```

4. **Transfer Files to SD Partition**

   Copy the prepared root filesystem to the SD card:

   ```bash
   cp -rp ~/rootfs/* /mnt/shada/rootfs
   ```

## Booting in QEMU

### 1. Launch QEMU

   Start the QEMU emulator with the following command:

   ```bash
   sudo qemu-system-arm -M vexpress-a9 -nographic  -kernel u-boot -sd sd.img
   ```

### 2. Configure Boot Commands

1. **Modify Boot Command**

   Edit the `bootcmd` environment variable to specify the boot sequence:

   ```bash
   editenv bootcmd
   fatload mmc 0:1 $kernel_addr_r zImage; fatload mmc 0:1 $fdt_addr_r vexpress-v2p-ca9.dtb; bootz $kernel_addr_r - $fdt_addr_r
   ```

2. **Set Boot Arguments**

   Configure `bootargs` to define kernel parameters:

   ```bash
   editenv bootargs
   console=ttyAMA0 root=/dev/mmcblk0p2 rootfstype=ext4 rw rootwait init=/sbin/init
   ```

   - `console=ttyAMA0` directs console output to the serial port.
   - `root=/dev/mmcblk0p2` designates the root filesystem location.
   - `rootfstype=ext4` specifies the filesystem type.
   - `rw` enables read-write mode.
   - `rootwait` waits for the root filesystem to be ready.
   - `init=/sbin/init` sets the initial program to execute.

3. **Save Configuration**

   Save your changes to the environment variables:

   ```bash
   saveenv
   ```

4. **Reboot the System**

   Restart QEMU to apply the new settings:

   ```bash
   reset
   ```

![Screenshot from 2024-07-28 10-36-29](https://github.com/user-attachments/assets/ac5831f3-732e-4e10-af83-b7130ce2ff1f)

   
![Screenshot from 2024-07-28 12-05-18](https://github.com/user-attachments/assets/dd1bdd78-9535-47fc-b92d-8033421a5d6f)


**yeaaay it's working  💃**
---







This README now includes a prerequisite section to ensure BusyBox is built before proceeding with the steps. If you need any more adjustments, just let me know!
