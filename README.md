# Project: Custom setfacl and getfacl

---

# Description
This project provides custom implementations of `setfacl` and `getfacl`, which are commands used to manipulate file permissions in Unix-like systems.

---

# my_setfacl

## Usage
```bash
my_setfacl [option] [path]...


Options
-m:[u|g]:[<username>|<groupname>]:[rwx]: Modify permissions
-x:[u|g]:[<username>|<groupname>]: Remove permissions
-p:[u|g]:[<username>|<groupname>]:[rwx]: Set new permissions, removing previous ACL
-R: Recursively traverse directories
```


### Implementation Details
The my_setfacl tool allows modification, removal, and setting of file permissions. It supports recursive traversal of directories. Below are key components of the implementation:

- __Modify Permissions__: Modifies permissions based on user or group and the specified access rights.
- __Remove Permissions__: Deletes specific permissions for a user or group.
- __Set New Permissions__: Sets new permissions, replacing the previous Access Control List (ACL).
- __Recursive Traversal__: Allows traversal of directories to apply permissions recursively.
---
# my_getfacl

## Usage
```bash
my_getfacl [path]...
```

### Implementation Details
The my_getfacl tool allows the user to view the permissions of a file or directory. Below are key components of the implementation:

The my_getfacl tool displays detailed information about file permissions, similar to the output of the standard getfacl command:

- Displays file name, owner, and group information.
- Shows setuid, setgid, and sticky bits.
- Retrieves and displays ACL using getxattr.
- If no ACL exists, displays traditional file mode permissions.

---


Usage
```bash
g++ -std=c++17 -o my_setfacl my_setfacl.cpp
g++ -std=c++17 -o my_getfacl my_getfacl.cpp

./my_setfacl [option] [path]...
./my_getfacl [path]...

 
```

Examples

```bash
./my_setfacl -m:u:root:rwx -m:g:root:rwx -m:g:student:rwx -R /home/user
./my_getfacl /home/user
```

---

# Team
<mark>

Liliana Hotsko: https://github.com/NaniiiGock

Anna Polova: https://github.com/Annnnya

</mark>

    
