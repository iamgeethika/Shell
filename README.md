                                                OSN 

                                           ASSIGNMENT - 3

                                           SYSTEM - LINUX


* We can compile this using 

* ``
make all
``

* And execute using

* ``
./main
``

* When the code is executed, a prompt shell which is similar to our terminal appears.

## ```SPECIFICATION-1``` ##

- This specification is handled in redirection.c and in main.c.
- I/O redirection is handled('>','<',>>').
- For commands like echo, sort, cat.. used execvp.


## ```SPECIFICATION-2``` ##

- This specification is handled in pipes.c and in main.c.
- Pipes are handled if it sees the symbol '|'.
- Doing the command "cat filename.txt | wc"
- Doing the command "cat filename.txt | head -7 | tail -5" ... For doing commands like this.

## ```SPECIFICATION-3``` ##

- This specification is handled in pipes.c and in main.c.
- Pipes are handled if it sees the symbol '|'.
- Doing the command "cat < filename.txt | wc".
- It should give the same output as "cat filename.txt | wc".

## ```SPECIFICATION-4``` ##

- JOBS : This specification is handled in jobs.c. and main.c.
jobs command prints a list of all currently running background processes in alphabetical order. 
- jobs -r prints running Processes.
- jobs -s prints Processes that are stopped.

- SIG : Takes the job number of a running job and sends the signal corresponding to the signal number to that process. 
- This specification is handled in sig.c

- FG and BG: This specification is handled in fgbg.c. 
- fg - Brings the running or stopped background job corresponding to job number to the foreground and changes its state to running.

- bg - Changes the state of a stopped background job to running.

## ```SPECIFICATION-5``` ##

- This specification is handled in main.c itself.

- CTRL-D : It logs out from the shell.

- CTRL-Z : It pushes any currently running foreground job into the background.
 And changes its states from running to stopped.

- CTRL-C : It interrupts any currently running foreground job.

