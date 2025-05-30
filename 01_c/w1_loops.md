# C - Loops

**Loops** allow your programs to execute lines of code repeatedly, saving you from needing to copy and paste or otherwise repeat lines of code.

**C** provides a few different ways to implement **loops** in your program.

## Infinite Loops

In an **infinite** loop, the lines of code between the curly braces will execute repeatedly from top-to-bottom, until and unless we break out of it (as with a `break;` statement) or otherwise will our program `Ctrl + c`.

### While Loop

Useful when we want the loop to repeat an unknown number of times, and possibly not at all.

```c
while (true)
{

}
```

```c
while (boolean-expression)
{

}
```

- If the **boolean-expr** evaluates to **true**,  all lines of code between the curly braces will execute repeatedly, in order from top-to-bottom, until **boolean-expression** evaluates to **false**.

### Do-While Loop

Useful when we want a loop to repeat an unknown number of times, but at least once.

```c
do
{

}
while (boolean-expression)
```

- This **loop** will execute all lines of code between the curly braces once, and then, if the **boolean-expr** evaluates to **true**, will go back and repeat that process until **boolean-expr** evaluates to **false**.

> **do-while** loops are guaranteed to run at least one time.

<br><br>

## For Loops

**For loops** are used to repeat the body of a loop a specified number of times, in this example `10`.

Useful when we want a loop to repeat a discrete number of times, though you may not know the number at the moment the program is compiled.

```c
for (int i = 0; i < 10; i++)
{

}
```

The process undertaken in a **for loop**:

- The *counter variable(s)* is set `int i = 0`
- The *Boolean expression* is checked `i < 10`
  - If it evaluates to **true**, the body of the loop executes.
  - If it evaluates to **false**, the body of the loop does not execute.
- The *counter variable* is incremented `i++` and then the *Boolean expression* is checked again.

```c
for (initialization; condition; update)
{
    // code to repeat
}
```

- The statement(s) in **initialization** are executed
- The **condition** is checked
  - If *true*, the body of the loop executes
  - If *false*, the body of the loop does not execute
- The statement(s) in **update** are executed, and then the **condition** is checked again, etc.
