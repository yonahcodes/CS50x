# Debugging

A **bug** is a error in code which results in a program either crashing, or exhibiting a result that is different from what we expected. Debugging is the process of trying to identify and fix bugs that exist in code. Programmers will often do this by making use of a program called a **debugger**.

## Using *debug50*

`debug50` is a program that was created by **CS50** that runs a built-in graphical debugger in the CS50 **IDE**. Before running `debug50` we need to set at least one **breakpoint**. It way be wise to set a breakpoint a few lines before there, so that we can see what's happening in our program as it moves into the section that we believe is causing the problem. If not sure at all, we can set a breakpoint at the first line of the **main** function so that we can *step through* the entire code from the beginning.

>To use a **breakpoint**, click the space to the left of the line number of you program. A **red dot** should appear in that space and it will be added to the list of all your breakpoints at the bottom of the graphical debugger window.

Once we set up our *breakpoints*, we can run the program with `debug50 ./program_name` and any command line arguments. The program will run, and automatically **stop** at any breakpoints.
<br><br>

### Play/Continue

- The first button, the blue triangle, allows you to **start** or **continue** the execution of the program from the current breakpoint. If there are no breakpoints set, it starts the program from the beginning.

### Step Over

- This button, the curved arrow, executes the current line of code and **moves to the next line**. If the current line contains a function call, it executes the entire function and stops at the next line after the function call returns.

### Step Into

- The **down arrow** button steps into the execution of the current line of code. If the current line contains a function call, it enters the function and stops at the first line of the function.

### Step Out

- The **up arrow** button allows you to step out of the current function. It continues the execution of the program until it exits the current function and stops at the line after the function call

### Restart

- This button restarts the debugging session, resetting the program's state and starting from the beginning.

### Stop

- This button terminates the debugging session, stopping the execution of the program.<br><br>

> **Sidenote**: In **C** we cannot compare two strings using `==`. In this example: `phrase == password` will not execute. We need to use a function called `strcmp` and give it the two strings as arguments: `strcmp(phrase, password) == 0`.
