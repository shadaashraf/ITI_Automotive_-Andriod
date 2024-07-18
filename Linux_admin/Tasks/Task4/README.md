# Section 2

### Q1. Create a supplementary (Secondary) group called pgroup with group ID of 30000


**Answer:**
`sudo groupadd -g 30000 pgroup` 

----------

### Q2. Lock any user-created account so they can't log in

**Answer:**

`username="shada"`
`sudo usermod --expiredate 6 "$username"`


----------

### Q3. Delete user account

**Answer:**


`sudo userdel -r "$username"` 

----------

### Q4. Delete group account
**Answer:**

`sudo groupdel Ahraf` 

----------

### Q5. State the difference between adduser and useradd with example shown.

**Answer:**

-   **adduser**: Interactive and user-friendly command to add users with default settings.
    
    `adduser newuser` 
    
-   **useradd**: Low-level command-line utility for adding users with specific options.
    
    `useradd -m -s /bin/bash newuser`
