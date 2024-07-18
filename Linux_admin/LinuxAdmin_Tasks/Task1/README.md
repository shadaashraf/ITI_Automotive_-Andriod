# Task1 Linux Admin
### Q1.  List three Linux Distributions:
  **Answer:**   
    -   Ubuntu
    -   Red Hat Enterprise Linux (RHEL)
    -   Debian
### Q2.  From the slides what is the man command used for?
   **Answer:**  
    -   The `man` command is used to display the manual pages (documentation) for various commands in Linux.
### Q3.  What is the difference between rm and rmdir using man command?
  **Answer:**
    -   `rm`: Removes files or directories. If directories are to be removed, the `-r` option is used for recursive removal.
    -   `rmdir`: Removes empty directories.
### Q4.  Create the following hierarchy under your home directory:
 
    `dir1
    ├── dir11
    ├── docs
    ├── dir12
    ├── mycv (file)
    ├── Documents
    ├── OldFiles (file)
    └── file1` 
  **Answer:** 
 **a**-failed to remove dir11 because it’s not empty, to overcome it will use -r to remove in recursive way 
**b**-He can’t see the oldfiles
**c:**
    -   Relative path for `mycv`: `home/shadaashraf/docs/myCv absolute: ./docs/myCv`
    - Absolute path for `mycv`: `./docs/myCv`
### Q5.  Copy the `/etc/passwd` file to your home directory and name it `mypasswd`:
 **Answer:**
    
    `cp /etc/passwd ~/mypasswd` 
    
### Q6.  Rename `mypasswd` to `oldpasswd`: 
 **Answer:**
    `mv ~/mypasswd ~/oldpasswd` 
    
### Q7.  List four ways to go to your home directory (`/home/user`) from `/usr/bin`:
   **Answer:** 
    -   `cd`
    -   `cd ~`
    -   `cd $HOME`
    -   `cd /home/user`
### Q8.  List Linux commands in `/usr/bin` that start with letter `w`:
   **Answer:**  `ls /usr/bin/w*` 
    
### Q9.  What command types are used for? (from the slide)
    
 **Answer:**   This likely refers to the `type` command, which is used to show how a command name is interpreted by the shell.
   
### Q10.  Show 2 types of command files in `/usr/bin` that start with letter `c`:
 **Answer:**   a-  `ls /usr/bin/c*` 

 
    
### Q11.  Using `man` command, find the command to read files:
**Answer:**   `man read` 
**Output:** Open the manual Page of read command

### Q12.  What is the usage of `apropos` command?
    
   **Answer:**  The `apropos` command is used to search the manual page names and descriptions for the given keyword.


### Q13.
**1.Create a directory called "myDirectory" in your home folder.**
**2.Inside "myDirectory," create another directory named "secondDirectory."**
**3.Within "secondDirectory," create a file named "myNotePaper."**
**4.Copy "myNotePaper" from "secondDirectory" to "myDirectory."**
**5.Rename the copied file in "myDirectory" to "myOldNotePaper."**



