# C - Conditional Statements

**Conditional expressions** allow your programs to make decisions and take different forks in the road, depending on the values of variables or user input.

**C** provides a few different ways to implement conditional expressions (also known as **branches**) in your programs.

```c
if (boolean-expression)
{

}
```
- If the **boolean-expression** evaluates to **true**, all the lines of code between the curly braces will execute in order from top-to-bottom.
- If the **boolean-expression** evaluates to **false**, those lines of code will not execute.

```c
if (boolean-expression)
{

}
else
{

}
```
- If the **boolean-expression** evaluates to **true**, all the lines of code between the curly braces will execute in order from top-to-bottom.
- If the **boolean-expression** evaluates to *false*, all lines of code between the second set of curly braces `else` will execute in order from top-to-bottom.

In **C** it is possible to create an **if-else** chain. Each branch is mutually exclusive.

```c
if (boolean-expr1)
{
    // first branch
}
else if (boolean-expr2)
{
    // second branch
}
else if (boolean-expr3)
{
    // third branch
}
else
{
    // fourth branch
}
```

It is possible to create a chain of **non-mutually exclusive** branches.
```c
if (boolean-expr1)
{
    // first branch
}
else if (boolean-expr2)
{
    // second branch
}
else if (boolean-expr3)
{
    // third branch
}
else
{
    // fourth branch
}
```
> In the example above only the *third* and *fourth* branches are **mutually exclusive**. the `else` binds to the nearest `if` only.

## Switch statement
C's `switch()` statement is a conditional statement that permits enumeration of discrete cases, instead of relying on **Boolean expressions**.

> Note that the `get_int` function is created by CS50 and can be accessed including `#include <cs50.h> library`.

```c
int x = get_int();
switch(x)
{
    case 1:
    printf("One!\n");
    break;
    case 2:
    printf("Two!\n");
    break;
    case 3:
    printf("Three!\n");
    break;
    default:
    printf("Sorry!\n");
}
```
The program prompts user for an integer, if user types **1**, it prints "**One!**". If user types **2**, it prints "**Two**!", etc.

> It's important to `break;` between each case or you will "fall through" each case and print "**One! Two! Three! Sorry!**" (unless that is desired behavior).

```c
int x = get_int();
switch(x)
{
    case 5:
    printf("Five, ");
    case 4:
    printf("Four, ");
    case 3:
    printf("Three, ");
    case 2:
    printf("Two, ");
    case 1:
    printf("One, ");
    default:
    printf("Blast-off!\n");
}
```
When the user types **4**, the program will print "**Four, Three, Two, One, Blast-off!**".

## Ternary Operator
The **ternary operator** `?:` is mostly a cute trick, but is useful for writing trivially short conditional branches. Be familiar with it, but know that you won't need to write it if you don't want to.

```c
int x;
if (boolean-expr)
{
    x = 5;
}
else
{
    x = 6;
}
```
Now let's use `?:` to create a snippet of code that will act identically.

```c
int x = (expr) ? 5 : 6;
```
If the expression is **true**, assign to `x` the value of `5`, if it's **false**, assign to `x` the value of `6`. 












