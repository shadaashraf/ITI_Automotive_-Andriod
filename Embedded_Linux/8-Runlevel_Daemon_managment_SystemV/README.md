# Run-Level Daemon Management

## Overview

This project demonstrates the management of daemons in different run levels using custom scripts. It sets up and controls two daemons, `hiApp` and `helloApp`, which run in different run levels. The setup involves creating run-level directories, custom scripts, and symbolic links to manage the daemons effectively.

## Project Structure

-   **/bin/hiApp**: A daemon script that runs in run level 3.
-   **/bin/helloApp**: A daemon script that runs in run level 2.
-   **/etc/init.d/rcs2**: Script to manage `helloApp` daemon.
-   **/etc/init.d/rcs3**: Script to manage `hiApp` daemon.
-   **/etc/init.d/rc**: Main script to control the start and stop of daemons based on the run level.

## Setup Instructions

### 1. Create Run-Level Directories

Create the necessary directories for managing the run levels:

`cd /etc
mkdir rc2.d rc3.d` 
![Screenshot from 2024-08-06 13-34-43](https://github.com/user-attachments/assets/396d197e-3b34-4b85-986e-46d8b50b9dab)


### 2. Create Daemon Scripts

Create the daemon scripts in `/bin`:

**/bin/hiApp**

`#!/bin/ash

while true; do
    echo "hi from run level 3"
    sleep 10
done` 


**/bin/helloApp**


`#!/bin/ash

while true; do
    echo "hello from run level 2"
    sleep 10
done` 

![Screenshot from 2024-08-06 13-34-15](https://github.com/user-attachments/assets/d0580ca9-a1fa-45e6-b06b-9dd17369ae72)
Make sure both scripts are executable:


`chmod +x /bin/hiApp
chmod +x /bin/helloApp` 



### 3. Create Initialization Scripts

Create the initialization scripts in `/etc/init.d`:

**/etc/init.d/rcs2**

`case "$1" in
  start)
    printf "Starting Your Daemon: "
    start-stop-daemon -S -n helloApp -a /bin/helloApp &
    [ $? = 0 ] && echo "OK" || echo "FAIL"
    ;;
  stop)
    printf "Stopping Your Daemon: "
    start-stop-daemon -K -n helloApp
    [ $? = 0 ] && echo "OK" || echo "FAIL"
    ;;
  *)
    echo "Usage: $0 {start|stop}"
    exit 1
    ;;
esac
exit $?` 

**/etc/init.d/rcs3**


`case "$1" in
  start)
    printf "Starting Your Daemon: "
    start-stop-daemon -S -n hiApp -a /bin/hiApp &
    [ $? = 0 ] && echo "OK" || echo "FAIL"
    ;;
  stop)
    printf "Stopping Your Daemon: "
    start-stop-daemon -K -n hiApp
    [ $? = 0 ] && echo "OK" || echo "FAIL"
    ;;
  *)
    echo "Usage: $0 {start|stop}"
    exit 1
    ;;
esac
exit $?` 

Make sure these scripts are executable:

`chmod +x /etc/init.d/rcs2
chmod +x /etc/init.d/rcs3` 

### 4. Create Symbolic Links

Create symbolic links to the initialization scripts in the respective run-level directories:

For run level 2: 

`cd /etc/rc2.d
ln -s /etc/init.d/rcs2 S20helloApp` 
![Screenshot from 2024-08-06 13-35-33](https://github.com/user-attachments/assets/015b2f0f-aaa4-4727-9dca-55a6f6171231)

For run level 3:

`cd /etc/rc3.d
ln -s /etc/init.d/rcs3 S20hiApp` 
![Screenshot from 2024-08-06 13-35-59](https://github.com/user-attachments/assets/e99dbc3b-06f2-4f0d-aba6-9782c5c32cd1)

### 5. Create the Main RC Script

**/etc/init.d/rc**

	`#!/bin/sh

	directory="$1"

	case "$directory" in
	    "2")
	        for i in /etc/rc2.d/S*; do
	            [ ! -f "$i" ] && continue
	            "$i" start 
	        done

        for i in /etc/rc2.d/K*; do
            [ ! -f "$i" ] && continue
            "$i" stop 
        done
        ;;
    "3")
        for i in /etc/rc3.d/S*; do
            [ ! -f "$i" ] && continue
            "$i" start 
        done

        for i in /etc/rc3.d/K*; do
            [ ! -f "$i" ] && continue
            "$i" stop 
        done
        ;;
    *)
        echo "Usage: $0 {2|3} (runlevel)"
        exit 1
        ;;
	esac

	exit 0` 
**Now i have rcs2 ,rcs3 ,rc in init.d**
![Screenshot from 2024-08-06 13-35-07](https://github.com/user-attachments/assets/c5ba3ac5-940d-45be-be12-f4b00f258f11)

Make sure the `rc` script is executable:

`chmod +x /etc/init.d/rc` 

### 6. Update `inittab`

Modify the `inittab` file to use the custom `rc` script for managing run levels 2 and 3. Remove the default entries for these run levels and add the following line:

`2:2:wait:/etc/init.d/rc 2` 

` 3:3:wait:/etc/init.d/rc 3` 
![Screenshot from 2024-08-05 15-30-00](https://github.com/user-attachments/assets/08ad06f1-ddd4-41e0-944f-67fe7bd30214)
**Note** remove the runlevels you created from rcS (rcS:145:wait:/etc/init.d/rcS)
## Usage

To manage the daemons, use the `rc` script with the desired run level:

-   To start and stop daemons in run level 2:
    
    `/etc/init.d/rc 2` 
    
-   To start and stop daemons in run level 3:

    `/etc/init.d/rc 3` 
    
![Uploading Screenshot from 2024-08-06 14-28-43.png…]()

## Notes

-   Ensure that all scripts are executable.
-   Verify that the `start-stop-daemon` command is available on your system.
-   The `rc` script assumes that symbolic links are named in a specific format (starting with `S` or `K`).
