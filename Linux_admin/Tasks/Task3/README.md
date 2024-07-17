# Section 2 

## Question 1
   **List the user commands and redirect the output to /tmp/commands.list.**
   
   **Answer:** ` $ compgen -c > /tmp/commands.list`
## Question 2
   
   **Edit your profile to display the date at login and change your prompt permanently.**
   
   **Answer:**

1.  Edit your `.profile` file to display the date at login:
    `$ vim ~/.profile`
 `echo "Welcome! Today's date is $(date)" `
 ` $ vim ~/.bashrc `
  `export PS1="\u@\h:\w $ "`

## Question 3

**What is the command to count the words in a file or number of files in a directory?**

**Answer:**

-   **Count Words in a File:**
    
    `wc -w filename` 
    
-   **Count number of files in a directory:**
   
    `find directory_path -type f | wc -l` 
    
-   **Count the number of user commands:**

    `compgen -c | wc -l`
## Question 4

**What happens if you execute the following commands:**

**a.** `cat filename1 | cat filename2`

-   Executes `cat filename2` because `cat` reads directly from filenames, not from piped input.

**b.** `ls | rm`

-   Outputs `rm: missing operand` as `rm` expects filenames directly, not from standard input.

**c.** `ls /etc/passwd | wc –l`

-   Outputs `1` as `ls /etc/passwd` lists one file (`/etc/passwd`), counted by `wc -l`.
## Question 5

**Write a command to search for all files on the system named `.profile`.**

**Answer:**
`$ sudo find / -name .profile`

## Question 6

**List the inode numbers of `/`, `/etc`, and `/etc/hosts`.**

**Answer:**

`$ ls -id / /etc /etc/hosts` 
**Output:**
`2 /  21233665 /etc  21233830 /etc/hosts`

## Question 7

**Create a symbolic link of `/etc/passwd` in `/boot`.**

**Answer:**
`$ sudo ln -s /etc/passwd /boot`

## Question 8
**Create a hard link of `/etc/passwd` in `/boot`. Could you? Why?**

**Answer:**


`$ sudo ln /etc/passwd /boot` 

Yes, because they are on the same filesystem.

## Question 9

**Echo `\` will jump to the next line and print `>`. Notice the prompt `>` - what does it indicate and how can you change it to `:`?**

**Answer:** The `>` prompt indicates it expects additional input to complete a command. To change it to `:`, add this line to `.bashrc`:

`export PS2=":"`
