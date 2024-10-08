# Load files From FAT to RAM and from TFTP server to RAM

## Overview

This project involves configuring a system to load boot files either from an MMC card or via TFTP, and setting up a network link between an x86 host and a QEMU virtual machine. The configuration includes creating a BootScript and setting up the necessary boot commands in QEMU.



## File Descriptions

-   `boot.txt`: Script to check and load files from MMC or via TFTP.
-   `LinkScript.sh`: Script to establish a network link between x86 and QEMU.

## Creating the BootScript

1.  **Prepare the `boot.txt` file**:
   
    
    `
    if load mmc 0:1 $loadaddr zImage; then
        load mmc 0:1 $fdtaddr dtb_file.dtb
    else
        tftp $loadaddr zImage
        tftp $fdtaddr dtb_file.dtb
    fi
    EOF` 
    
2.  **Convert `boot.txt` to BootScript**:
    

    `mkimage -A arm -T script -C none -n "Boot script" -d boot.txt boot.scr` 
    

## Setting Up the Network Link

1.  **Create `LinkScript.sh` file**:
    
 `  #!/bin/bash`
` sudo ip tuntap add dev $1 mode tap`
`sudo ip addr add 192.168.0.1/24 dev $1`
`sudo ip link set $1 up`


    
2.  **Make `LinkScript.sh` executable**:
    
    `chmod +x LinkScript.sh` 
    



## Open QEMU


    `sudo qemu-system-arm -M vexpress-a9 -nographic -net nic -net tap,script=./LinkScript.sh -kernel ./u-boot -sd ./sd.img"  ` 
 ### Some configrations in QEMU:
  ` 1-editenv ipadd '192.168.0.2'   ` 
  ` 2-editenv serverip '192.168.0.1'   ` 
  ` 3-editenv bootcmd 'fatload mmc 0:1 0x60003000 boot.scr; source 0x60003000' `
  `4-saveenv
  5-reset` 
  ### Output:
**From mmc to RAM**
![Screenshot from 2024-07-26 17-00-30](https://github.com/user-attachments/assets/23ff82e4-4076-4b57-9a46-9fa8dc98618e)

**From TFTP server to RAM**
![Screenshot from 2024-07-26 22-55-38](https://github.com/user-attachments/assets/af806e1c-41ce-4939-926b-45fb3b52d6f3)
