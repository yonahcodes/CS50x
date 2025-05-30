# Recursion

We might describe an implementation of an algorithm as being particularly "elegant" if it solves a problem is a way that is both interesting and easy to visualize.

The technique of `recursion` is a very common way to implement such an "elegant" solution.

The definition of a **recursive function** is one that, as part of its execution, **calls itself**.

## Factorial function

The **factorial function** `n!` is defined over all positive integers. 

`n!` equals all of the positive integers less than or equal to `n`, multiplied together. 

Thinking in terms of programming, we'll define the mathematical function `n!` as `fact(n)`.

```txt
fact(1) = 1
fact(2) = 2 * 1
fact(3) = 3 * 2  * 1
fact(4) = 4 * 3 * 2 * 1
fact(5) = 5 * 4 * 3 * 2 * 1
```
If we pay attention to the pattern here we can observe the following:
```txt
fact(1) = 1
fact(2) = 2 * fact(1)
fact(3) = 3 * fact(2)
fact(4) = 4 * fact(3)
fact(5) = 5 * fact(4)
```
<br>

The **factorial** of any number can be expressed with the formula: `fact(n) = n * fact(n-1)`.

This forms a basis for the **recursive definition** of the factorial function.

Every function has two cases that could apply, given any input:

- The `base case`, which when triggered will terminate the recursive process.
- the `recursive case`, which is where the recursion will actually occur.

```txt
fact(1) = 1 -> Is the base case
fact(2) = 2 * fact(1)
fact(3) = 3 * fact(2)
fact(4) = 4 * fact(3)
fact(5) = 5 * fact(4)
```

<br>

Let's try and implement a **recursive** version of this function in **C**:

```c
int fact(int n)
{
    // Base case
    if (n == 1)
    {
        return 1;
    }

    // Recursive case
    else
    {
        return n * fact(n - 1);
    }
}
```

> When we have **single line** loops or conditional branches, we can get rid of the *curly braces* `{}` around them.

```c
int fact(int n)
{
    if (n == 1)
        return 1;

    else
        return n * fact(n - 1);
}
```
- In the **base case**, the function checks if `n == 1`, if **true** the program stops.

- If `n != 1`, the function calls itself **recursively** with the argument `n - 1`.

- This process **decreases** the value of `n` until it reaches the **base case** where `n == 1`.

- Now that `n` has a set value of `1`, it can solve the previous recursive calls.

- It then returns the results back up the **call stack** multiplying the values to compute the final factorial.

<br>

In general, but not always, recursive functions replace **loops** in `non-recursive functions`:

```c
int fact2(int n)
{
    int product = 1;
    while (n > 0)
    {
        product *= n;
        n--;
    }
    return product;
}
```
<br>

## Multi-base and Multi-recursive cases

It's also possible to have more than one **base** or **recursive** case, if the program might recurse or terminate in different ways, depending on the input being passed in.

- **Multiple base cases**: `The Fibonacci number sequence` is defined as follows:
```txt
The first element is 0.
The second element is 1.
The Nth element is the sum of the (N - 1)th and (N - 2)th elements.
```
<br>

- **Multiple recursive cases**: `The Collatz conjecture` applies to positive integers and speculates that it is always possible to `back to 1` if you follow these steps:
```txt
If N is 1, stop.
Otherwise, if N is even, repeat this process on N/2.
Otherwise, if N is odd, repeat this process on 3N + 1.
```
<br>

Let's visualize the process of counting the steps needed to return `1`:

|n|collatz(n)|Steps|
|:-:|:-:|:-|
|1|0|1|
|2|1|2 -> 1|
|3|7|3 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1|
|4|2|4 -> 2 -> 1|
|5|5|5 -> 16 -> 8 -> 4 -> 2 -> 1|
|6|8|6 -> 3 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1|
|7|16|7 -> 22 -> 11 -> 34 -> 17 -> 52 -> 26 -> 13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1|
|8|3|8 -> 4 -> 2 -> 1|
|15|17|15 -> 46 -> 23 -> 70 -> ... -> 8 -> 4 -> 2 ->  1|
|27|111|27 -> 82 -> 41 -> 124 -> ... -> 8 -> 4 -> 2 -> 1|
|50|24|50 -> 25 -> 76 -> 38 -> ... -> 8 -> 4 -> 2 -> 1|

<br>

Now let's write a **recursive function** `collatz(n)` that calculates how many steps it takes to get to `1` if we start from `n` and recurse as indicated above:

```c
int collatz(int n)
{
    // Base case
     if (n == 1);
     {
        return 1;
     }

    // Even numbers
     else if ( n % 2 == 0)
     {
        return 1 + collatz(n/ 2);
     }

    // Odd numbers
     else
     {
        return 1 + collatz(3 * n + 1);
     }
}
```
- `collatz(int n)` function takes `n` as an argument.

- In the **base case**, the function checks if `n == 1`, if **true**, it returns `0` (No steps were taken to return to 1).

- Otherwise we have **two** recursive cases:

    **1.** If `n % 2 == 0` (`n mod 2` returns **0** == `n / 2` doesn't have a **remainder** == `n` is an **even** number):
 
        Return 1 (minimum step) + `collatz(n/2)` (result of the function called recursively with `n/2`).

    **2.** If `n` is an **odd** number:
 
        Return 1 (minimum step) + `collatz(3 * n + 1)` (result of the function called recursively with `3 * n + 1`).
