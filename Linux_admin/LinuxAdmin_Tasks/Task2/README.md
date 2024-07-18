# Question2

**Q**:Move the binary file output to the directory /usr/local/bin with sudo permissions. Afterward, attempt to execute the binary from any working directory and explain the outcome. Provide a detailed explanation supported by evidence as to why the 
binary can be executed from any location.

**Answer:**
`~$ cd ./Task2_Q1/`
`~$ sudo mv a.out /usr/local/bin`
`~$ cd ~`
`~$ a.out`
The file **a.out** will execute because When you move a file to /usr/local/bin, you can execute it from anywhere because /usr/local/bin is part of the system's PATH environment variable by default. The PATH environment variable contains a list of directories that the shell searches through to find executable files.

# Na2na2a

 **Question 1:** List the available shells in your system.  
 **Answer:**`~$ cat /etc/shells`
 **Output:**`# /etc/shells: valid login shells
/bin/sh
/bin/bash
/usr/bin/bash
/bin/rbash
/usr/bin/rbash
/bin/dash
/usr/bin/dash
`

**Question 2** List the environment variables in your current shell.  
 **Answer:**`~$ env`
 **Output:**`SHELL=/bin/bash
LC_ADDRESS=ar_EG.UTF-8
LC_NAME=ar_EG.UTF-8
LC_MONETARY=ar_EG.UTF-8
PWD=/home/shadaasharf
LOGNAME=shadaasharf
HOME=/home/shadaasharf
`

**Question 3** Display your current shell name.  
   **Answer:**`~$ echo $0`
 **Output:**`bash`
 
**Question 4** Execute the following command : echo \ then press enter What is the purpose of \ ?  

  **Answer:**`~$ echo \ "If you press Enter after this line, the shell will show `>` because it interprets the backslash as an escape character and expects you to complete the command or provide more input to finish it properly so if you enter anything it will print it ". `
  
 **Output:**`shadaasharf@shadaasharf-VirtualBox:~$ echo \`
`> shada ashraf`
`shada ashraf`

 
**Question 5** Create a Bash shell alias named PrintPath for the “echo $PATH” command

  **Answer:**`~$ alias PrintPath=echo $PATH`
 **Output:**`shadaasharf@shadaasharf-VirtualBox:~$ PrintPath 
/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin`
