# Call Stacks

A **call stack** is a fundamental concept used to keep track of active **functions** in a program. Call stacks are useful when **debugging**, they allow us to trace the sequence of function calls that lead to the **bug**.

When *calling a function*, the system allocates a memory block on the `stack`. A new **stack frame** containing information about the function (parameters, local variables, etc) is then added to the call stack. Each stack frame also includes the `return address`, which indicated where the program execution should continue once the function completes.

<br>

Multiple function's stack frames may exist in memory at a given time. If in a program, `main()` calls `move()`, which then calls `direction()`, all three functions have **open frames**. These **frames** are arranged in a `stack`. The frame for the *most recently called function* is always on **Top** of the stack. When a new function is called, a new frame is `pushed` onto the top of the stack and becomes the **active frame**.

When a **function** completes its operation, its frame is `popped` off of the stack and the frame *immediately below it* becomes the new **active function** on the top of the stack, resuming from its stored **return address**.

<br>

A common error called `Stack Overflow` can occur when too many functions are called, exceeding the stack's memory capacity. This often happens in cases of **infinite recursion**, where a function keeps calling itself without a **base case** to stop the recursion.

<br><br>

## Understanding the Call Stack with Recursive Factorial Function

```c
int fact(int n)
{
    if (n == 1)
        return 1;
    else
        return n * fact(n - 1);
}

int main(void)
{
    printf("%i\n", fact(5));
}
```
<br>

Let's see how this process takes place in the **call stack**:

<br>

In every `C` program, the `main()` function serves as the **starting point** for program execution.
```txt
main() ----> Active frame
```
<br>

The first thing `main()` does is call the `printf()` function, which in turn requires the result ot `fact(5)` to complete its operation. This initiates the *sequence of calls*.
```txt
printf() ----> Becomes the active frame
main()
```
<br>

`printf()` indirectly calls `fact(5)` to evaluate its argument, pushing `fact(5)` onto the stack.
```txt
fact(5) ----> Becomes the active frame
printf()
main()
```
<br>

`fact(5)` then goes to work asking if `5 == 1` **NO**, so it proceeds to next line and calls itself with an updated parameter: `fact(5 - 1)`.
```txt
fact(4) ----> Becomes the active frame
fact(5)
printf()
main()
```
<br>

`fact(4)` then goes through the same process and calls itself with an updated parameter: `fact(4 - 1)`
```txt
fact(3) ----> Becomes the active frame
fact(4)
fact(5)
printf()
main()
```
<br>

`fact(3)` then goes through the same process and calls itself with an updated parameter: `fact(3 - 1)`
```txt
fact(2) ----> Becomes the active frame
fact(3)
fact(4)
fact(5)
printf()
main()
```
<br>

`fact(2)` then goes through the same process and calls itself with an updated parameter: `fact(2 - 1)`
```txt
fact(1) ----> Becomes the active frame
fact(2)
fact(3)
fact(4)
fact(5)
printf()
main()
```
<br>

`fact(1)` then goes to work asking `1 == 1` **YES**, we reached the **base case**, it can proceeds to return `1`. Its frame is `popped` off of the stack and the frame *immediately below it* becomes the new **active function**
```txt
fact(2) ----> Becomes the active frame
fact(3)
fact(4)
fact(5)
printf()
main()
```
<br>

We now go back up the stack with `fact(2)` asks `2 == 1` **NO**, and proceeds to calculate its return value `2 * fact(1)` returning `2`. Its frame is `popped` off of the stack and the frame *immediately below it* becomes the new **active function**
```txt
fact(3) ----> Becomes the active frame
fact(4)
fact(5)
printf()
main()
```
<br>

`fact(3)` asks `3 == 1` **NO**, and proceeds to `3 * fact(2)` returning `6`. Its frame is `popped` off of the stack and the frame *immediately below it* becomes the new **active function**
```txt
fact(4) ----> Becomes the active frame
fact(5)
printf()
main()
```
<br>

`fact(4)` asks `4 == 1` **NO**, and proceeds to `4 * fact(3)` returning `24`. Its frame is `popped` off of the stack and the frame *immediately below it* becomes the new **active function**
```txt
fact(5) ----> Becomes the active frame
printf()
main()
```
<br>

`fact(5)` asks `5 == 1` **NO**, and proceeds to `5 * fact(4)` returning `120`. Its frame is `popped` off of the stack and the frame *immediately below it* becomes the new **active function**
```txt
printf() ----> Becomes the active frame
main()
```
<br>

`printf()` was waiting on `fact(5)` return the value. It can now proceed to **print** `120` and completes its operation. Its frame is `popped` off of the stack and the frame *immediately below it* becomes the new **active function**
```txt
main() ----> Becomes the active frame
```
<br>

When `printf()` completes its operation, the `main()` resumes control and completes its operation, gets `popped` the stack as well and the program **successfully ends**.
