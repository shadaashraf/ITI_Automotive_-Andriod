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

bash

Copy code

`cd /etc
mkdir rc2.d rc3.d` 

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

For run level 3:

`cd /etc/rc3.d
ln -s /etc/init.d/rcs3 S20hiApp` 

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

Make sure the `rc` script is executable:

`chmod +x /etc/init.d/rc` 

### 6. Update `inittab`

Modify the `inittab` file to use the custom `rc` script for managing run levels 2 and 3. Remove the default entries for these run levels and add the following line:

`2:2:wait:/etc/init.d/rc 2` 

` 3:3:wait:/etc/init.d/rc 3` 

## Usage

To manage the daemons, use the `rc` script with the desired run level:

-   To start and stop daemons in run level 2:
    
    `/etc/init.d/rc 2` 
    
-   To start and stop daemons in run level 3:

    `/etc/init.d/rc 3` 
    

## Notes

-   Ensure that all scripts are executable.
-   Verify that the `start-stop-daemon` command is available on your system.
-   The `rc` script assumes that symbolic links are named in a specific format (starting with `S` or `K`).
