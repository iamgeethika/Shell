                                                OSN 

                                           ASSIGNMENT - 2

                                           SYSTEM - LINUX


* We can compile this using 

* ``
make all
``

* And execute using

* ``
./a.out
``

* When the code is executed, a prompt shell which is similar to our terminal appears.

## ```SPECIFICATION-1``` ##

(DISPLAY REQUIREMENT)

* If your current working directory is the directory from which your shell is invoked, then on executing the command "cd ..",
  your shell should display the absolute path of the current directory from the root.
* Example: /home/geethika/Desktop/SEM3
* Your shell should support a ‘;’.Used 'strtok' to tokenize the command.
* Your shell also accounts for random spaces and tabs.

## ```SPECIFICATION-2``` ##

(Builtin commands    (cd, echo, pwd))

* It handles tabs and spaces.
* For cd apart from the basic functionality, implement the flags: ‘.’, ‘..’, ‘-’, ‘~’.
* It is an error for a cd command to have more than one command-line argument.
* For "cd -", THE DIRECTORY WHICH WE INVOKE THE PROMPT WILL BE CONSIDERED AS HOME DIRECTORY.
* AND ITS PATH WILL BE PRINTED FROM HOME.. i.e, THE DIRECTORY WHICH WE INVOKE THE PROMPT.
* If no argument is present then you must cd into the home directory.
* "echo" command should also handle spaces.
* Example: echo Hello       World 
* It outputs Hello World
* The pwd command writes the full pathname of the current working directory to the standard output. 
* Basically, the absolute path of the directory


## ```SPECIFICATION-3``` ##

- ls is handled in ls.c and main.c.
- Implemented all cases of ls command.
- Colour coding is used.
- BLUE for directories
- GREEN for executables
- WHITE for regular files.


## ```SPECIFICATION-4``` ##

- This is handled in fbg.c and in main.c.
- (both foreground and background)
- Time taken by the foreground process is printed in the next prompt.
- sleep 1 ;sleep 2 when executed, time taken by sleep 1 and sleep 2 will be printed.
- '&' is treated as background command.
- Whenever a new background process starts, the PID of the newly created background process is printed.



## ```SPECIFICATION-5``` ##

- This specification is handled in pinfo.c
- pinfo prints the information about the shell program.
- If it is a foreground process,  "+" is added to status code.

## ```SPECIFICATION-6``` ##

- This specification is handled in main.c.
- If a background process is terminated, it prints a message on stderror(whether the process is terminated normally or abnormally)

## ```SPECIFICATION-7``` ##

- This specification is handled in discover.c
- '.' is used for current directoy

## ```SPECIFICATION-8``` ##

- This specification is handled in history.c
- A file history.txt is used to store last 20 commands.
- History prints last 10 commands.
