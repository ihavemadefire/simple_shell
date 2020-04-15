# Simple Shell :shell:

A simple UNIX command interpreter written as part of the year one curriculum at Holberton School.

## Description :speech_balloon:

**Simple Shell** is a UNIX command interpreter that reads commands from standard input and executes them.

## Installation :computer:
To install **Simple Shell** clone this repository into your local file directory and run

`gcc *.c -o shell`

This will compile the source code into an executable file named "shell".  It can be invoked by calling the executable at the command line as follows:

`userPS1 $./shell`

## Invocation and Usage :floppy_disk:
Once installed and compiled, **Simple Shell** can be invoked either interactively or non-interactively.  

### Interactively
To invoke **Simple Shell** interactively, call the shell executable at the command line as follows:

`userPS1 $./shell`


Once launched it will display a prompt.  From here **Simple Shell** can be used as the bash or sh shells are used. **Simple Shell** accepts both commands and flags for the commands called.
For example:

`simple_shell $
simple_shell $ls -l`

To print the current environmental variables, call `env` while the shell is running.

To exit, enter exit.  The user can supply a number after exit to indicate the exit status.  For example `exit 49` which could then be seen by calling echo $?

### Non-Interactively
To invoke **Simple Shell** non-interatively, echo a command and pipe it to the executable. For example:

`userPS1 $ echo "ls -l" | ./shell`


## authors :pencil2:
Jacob Ide Github: [ihavemadefire](https://github.com/ihavemadefire)

Gunter Pearson Github: [GunterPearson](https://github.com/GunterPearson)