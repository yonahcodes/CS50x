# Functions

So far, we have been writing programs inside of the `main()` function. It has been working for now, but it could be a problem when our programs become bigger and more difficult to manage.

**C** and nearly all languages developed since allow us to write **functions**, sometimes also known as *procedures*, *methods*, or *subroutines*.

**Functions** are "*black box*" modules of code that accomplish a specific task by taking `0+` inputs and generating `1` output.

```
add(3, 6, 7)
```
- Function: `add()`
- Input: `3, 6, 7`
- Output: `16`

```
mult(4, 5)
```
- Function: `mult()`
- Input: `4, 5`
- Output: `20`

> We refer to a **function** as a *black box* because, in most cases, we didn't write the functions ourselves and don't need to know the underlying implementation.

In the previous example: `mult(a, b)` could be defined as **"output a * b"** or it could be defined as follows: **"set counter to 0, repeat b times, add a to counter, output counter"**.

That's part of the contract of using functions. The behavior is typically predictable based on the **name**. That is why most functions have clear names, and are well-documented.

### Why use functions?
- **Organization**: Functions help us break up a complicated problem into more manageable subparts.
- **Simplification**: Smaller components tend to be easier to design, implement, and debug.
- **Reusability**: Functions can be recycled; you only need to write them once, but can use them as often as you need!<br><br>

## Declaring Functions

The first step in creating a function is to **declare it**. This gives the *compiler* a heads-up that a user-written function appears in the code. 

Function declarations should always go atop your code, before the `main()` function.

```
return-type name(argument-list);
```
- `return-type` is the kind of variable the function will output.
- The `name` is what you call the function.
- The `argument-lists` is the **comma-separated** set of inputs to your function, each of which has a type and a name.

```c
int add_two_ints(int a, int b);
```
- `int` The sum of two integers is going to be an integer as well.
- `add_two_ints()` Given what this function does, it has an appropriate name.
- `int a, int b` There are two inputs to this function, and we need to name each of them for the purposes of the function. 

```c
float mult_two_reals(float x, float y);
```
- `float` The product of two **floating point** numbers (real numbers) is also a floating point number.
- `mult_two_reals` is a relevant name.
- `float x, float y` the names of these particular inputs don't seem to be important, we can call them anything simple.<br><br>

## Defining Functions

Now that we have declared the function it is time to **define** it. This allows for predictable behavior when the function is *called* with inputs.

Let's define `mult_two_reals()`:
```c
float mult_two_reals( float x, float y);
```
The beginning of a function *definition* looks **almost** identical to a function *declaration*, with a small change: `;`
```c
float mult_two_reals(float x, float y);
{
    float product = x * y;
    return product;
}
```
- Inside the curly braces `{}` is where we define what the function does.
- We define a *variable* `product` and assign to it the value of `x * y`.
- We then `return` the variable's value as an output.<br><br>

Another simpler way of achieving the same result is the following:
```c
float mult_two_reals(float x, float y)
{
    return x * y;
}
```

Now let's define `add_two_ints()`:

```c
int add_two_ints(int a, int b);
```
```c
int add_two_ints(int a, int b)
{
    int sum;        // declare variable
    sum = a + b;    // calculate the sum
    return sum;     // give result back 
}
```
Or
```c
int add_two_ints(int a, int b)
{
    int sum = a + b;    
    return sum;    
}
```
Or
```c
int add_two_ints(int a, int b)
{
    return a + b;     
}
```
## Calling Functions

To call a function, simply pass it appropriate **arguments** and assign its return value to something of the correct **type**.

```c
#include <cs50.h>
#include <stdio.h>

// Declare the function
int add_two_ints(int a, int b);

int main(void)
{
    // Call the function, give it arguments
    // And store its value in variable "s"
    int s = add_two_ints(5, 7);

    // Print value of "s"
    printf("Result is: %i\n", s);
}

// Define the function
int add_two_ints(int a, int b)
{
    int sum = a + b;
    return sum;
}
```

Another example prompting user to enter *integers* to be used as **arguments** in the function:
```c
#include <cs50.h>
#include <stdio.h>

int add_two_ints(int a, int b);

int main(void)
{
    int x = get_int("Enter an integer: ");
    int y = get_int("Enter another integer: ");

    int z = add_two_ints(x, y);

    printf("Result of %i + %i = %i\n", x, y, z);
}

int add_two_ints(int a, int b)
{
    int sum = a + b;
    return sum;
}
```
- Functions can sometimes take no inputs. In that case, we declare the function as having a **void** argument list `int function(void)`.<br>

- Functions sometimes don't have an output. In that case, we declare the function as having a **void** return type `void function()`

## Practice Problem

Declare and write a function called `valid_triangle` that takes **three real numbers** representing the lengths of the three sides of a triangle as its arguments, and outputs either **true** or **false**, depending on whether those three lengths are capable of making a triangle.

Rules about triangles: 
- A triangle may only have sides with **positive** length. 
- The sum of the length of any two sides of the triangle must be **greater** than the length of the third side.

```c
#include <cs50.h>
#include <stdio.h>

// Declare function
bool valid_triangle(float x, float y, float z);

int main(void)
{
    // Define arguments to be used in function
    float x = get_float("Enter side 1: ");
    float y = get_float("Enter side 2: ");
    float z = get_float("Enter side 3: ");

    // Call function and print True/False 
    if (valid_triangle(x, y, z))
    {
        printf("True\n");
        return 0;
    }
    else
    {
        printf("False\n");
        return 1;
    }
}

// Define function
bool valid_triangle(float x, float y, float z)
{
    if ((x <= 0) || (y <= 0) || (z <= 0))
    {
        return false;
    }

    if ( (x + y <= z) || (x + z <= y) || (y + z <= x))
    {
        return false;
    }
    return true;
}
```
