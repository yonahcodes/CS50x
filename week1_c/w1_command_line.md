# Linux Command Line

The CS50 IDE is a cloud-based machine running **Ubuntu**, one of the many flavours of the **Linux OS**.

Many modern Linux distributions have graphical user interfaces (**GUI**) to allow easy mouse-based navigation.

Still, as programmers we will likely be using the **terminal window** frequently, and we can do many of the same tasks with keyboard commands.

> These commands can be used in any **UNIX-based** system, which includes **macOS**.

## Using the Linux Command Line

**`ls`**<br>
Short for "**list**", this command will give you a readout of all the files and folders in your current directory.

**`cd`** **\<directory>**<br>
Short for "**change directory**", this command changes current directory to **\<directory>**, which you specify, in your *workspace* or on your *operating system*.
- The shorthand name for the current directory is `.`
- The shorthand name for the parent directory of the current directory is `..`
- If we want to know the name of the current directory, we can type `pwd` (present working directory).
- If we wanted to go all the way up the Home directory we can type `cd` only.

`mkdir` **\<directory>**<br>
Short for "**make directory**", this command will create a new subdirectory called **\<directory>** located in the current directory.

`cp` **\<source>** **\<destination>**<br> Short for "**copy**", this command will allow us to create a duplicate of the file we specify as **\<source>**, which it will save in the **\<destination>**.

If we wanted to copy entire directories, you'll need to modify the command slightly:
- `cp -r` **\<source directory>** **\<destination directory>**<br> 
The `-r` flag stands for *recursive*, and tells `cp` to dive down into the directory and copy everything inside of it (including any subdirectories it might contain).

`rm` **\<file>**<br>
Short for "**remove**", this command will delete **\<file>** after it sks you to confirm **(y/n)** you want to delete it.

- We can skip the confirmation by typing:<br> `rm -f` **\<file>**<br>
The `-f` flag stands for *force*, and tells `rm` to skip confirmation and delete.
- To delete entire directories, we need to use the `-r` flag:<br>
`rm -r` **\<directory>**
- We can also combine `-r` and `-f` flags into `-rf`

Be careful before using `-f`, there is no undo!

`mv` **\<source>** **\<destination>**<br>
Short for "**move**", this command will allow you to effectively rename a file, moving it from **\<source>** to **\<destination>**.

>We will discuss more basic command line utilities in the future in CS50. (chmod, ln, touch, rmdir, man, diff, sudo, clear, telnet, etc).
