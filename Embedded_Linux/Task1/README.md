## Session One: Disk Image Setup and Filesystem Creation
#### Objective: 
To understand and practice the steps involved in creating a disk image, partitioning it, setting up loop devices, and formatting partitions with different filesystems.
        
#### Steps and Explanation:
        
1.  **Creating a Disk Image using `dd`**:
            
            -   Command: `shada@shada:~$ dd if=/dev/zero of=sd.img bs=1M count=1024`
            -   **Explanation**:
                -   `dd`: A command-line utility for Unix and Unix-like operating systems used for low-level copying and conversion of raw data.
                -   `if=/dev/zero`: Input file is `/dev/zero`, a special file in Unix-like systems that provides as many null characters (zero value bytes) as are read from it.
                -   `of=sd.img`: Output file is `sd.img`, the name of the disk image being created.
                -   `bs=1M`: Sets the block size to 1 megabyte.
                -   `count=1024`: Specifies the number of blocks to copy. In this case, it copies 1024 blocks, creating a 1 GB disk image.
2.  **Partitioning the Disk Image using `cfdisk`**:
            
            -   Command: `shada@shada:~$ cfdisk sd.img`
            -   **Explanation**: The `cfdisk` command is used to create partitions on the disk image `sd.img`. `cfdisk` is a curses-based partitioning tool that provides a user-friendly interface to partition disks.
                -   Two partitions were created:
                    -   First partition: 200 MB, type FAT16, and set as bootable.
                    -   Second partition: 500 MB, type ext4.
3.  **Setting up Loop Device and Scanning for Partitions**:
            
            -   Command: `shada@shada:~$ sudo losetup -f --show --partscan sd.img`
            -   **Explanation**:
                -   `sudo losetup -f --show --partscan sd.img`: This command sets up a loop device for the disk image `sd.img` and scans for partitions.
                -   The `-f` option finds the first available loop device.
                -   The `--show` option shows the name of the created loop device.
                -   The `--partscan` option scans the partition table on the loop device and creates the corresponding devices.
                -   Output: `/dev/loop13` indicates that `/dev/loop13` has been created as the loop device.
4.  **Formatting the First Partition with `mkfs.vfat`**:
            
            -   Command: `shada@shada:~$ sudo mkfs.vfat -f 16 -n Boot /dev/loop13p1`
            -   **Explanation**:
                -   `sudo mkfs.vfat -f 16 -n Boot /dev/loop13p1`: This command attempts to format the first partition of the loop device (`/dev/loop13p1`) with the FAT16 filesystem.
                -   `-f 16` specifies FAT16 format.
                -   `-n Boot` sets the volume name to "Boot".
               
5.  **Formatting the Second Partition with `mkfs.ext4`**:
            
            -   Command: `shada@shada:~$ sudo mkfs.ext4 -L rootfs /dev/loop13p2`
            -   **Explanation**:
                -   `sudo mkfs.ext4 -L rootfs /dev/loop13p2`: This command formats the second partition of the loop device (`/dev/loop13p2`) with the ext4 filesystem.
                -   `-L rootfs` sets the volume label to "rootfs".
                -   The process involves creating the filesystem, allocating group tables, writing inode tables, creating a journal, and writing superblocks and filesystem accounting information.
6.  **Verifying the Disk Image with `cfdisk`**:
            
            -   Command: `shada@shada:~$ cfdisk sd.img`
            -   **Explanation**: Running `cfdisk` again on `sd.img` can be used to verify the partitions and ensure that the formatting was successful.
        
        #### Summary:
        
        In this session, we successfully created a disk image, partitioned it using `cfdisk` into two partitions (200 MB FAT16 bootable and 500 MB ext4), set up loop devices, and formatted the partitions with different filesystems (though the FAT16 formatting encountered an issue). These steps are fundamental in managing disk images and preparing them for use in various applications, such as virtual machines or embedded systems.
