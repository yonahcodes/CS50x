# CS50 Section 1 - C
<!-- this is an invisible comment -->
Welcome to my personal notes of CS50's very first section!

The goal of sections is to help us bridge the gap between lectures and problem sets.

In this introductory week, we delve into the fundamentals of the C programming language, covering essential concepts like variables, types, input/output, loops, and functions. Let's demystify the basics of C programming.

## Variables and Types
A **variable** is container paired with a symbolic name for some value that can change

```c
int calls = 3;
```

The code above creates an integer names calls that gets the value 3.

Breaking it down:

- `int` is the integer type variable

- `calls` is the name of the variable

- `3` is the value of the variable

- `=` is the assignment operator

```c
int country_code = 65;
```

the code above creates an integer names country_code that gets the value 65.

> We specify the type of variable `int`. 65 is stored as binary value **01000001** by the computer.

```c
char country_code = 65;
```
In this case the binary vale of 01000001 is stored as a `char` (character) equivalent to "A"

We can use **syntactic sugar** to make the code shorter in C :
```c
int calls = 4;
calls = calls + 2;
calls = calls - 1;
calls = calls * 2;
calls = calls / 2;
```
When we run the code above, the result is 5.
```c
int calls = 4;
calls += 2;
calls -= 1;
calls *= 2;
calls /= 2;
```
When we run the code, the result is **4 instead of 4.5**. Any decimal result is **"Truncated"**, not rounded.

> Integers are whole numbers, they do not store decimal values.

## Input and Printing
```c
int calls = get_int("Calls: "); 
```
`get_int("Calls: ");` is a **function call**.
> `get_int` is a function created by cs50 

When the user is prompted to enter a **value**, it is stored in the variable. If user enters "**4**":

`int calls = 4`

```c
int calls = 4;
printf("calls is %i\n", calls);
```

The code above will return "**calls is 4**"

Breaking it down:

- The `f` in the `printf` function stands for **formatted**

- `%i` is the placeholder for the value of the variable `calls`

- The value of the *variable* that follows the coma `,` will be stored in the placeholder: 

- **printf("calls is %i\n", `calls`);**

## Types and format codes
- int `%i`

- float `%f`

- char `%C`

- string `%s`

```c
#include <stdio.h>

int main(void)
{
    printf("Hello, world.\n");
}
```

Breaking it down:

- `#include <stdio.h>` Includes header file stdio C library 

- the `main` function serves as the entry point of every C program.

- `int` specifies the return type of the "main" function.

- `(void)` This part specifies the parameter list of the main function. "void" means the function does not expect any command-line arguments.

## Getting input from user

Using the CS50 library `<cs50.h>`, we can easily obtain user input:

```c
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What is your name? ");
    printf("Hello, %s\n", name);
}
```

`#include <cs50.h>` give us access to the cs50 library that includes The `get_string` function we are using.

- We declare a variable of type **string** called "name"

- We assign to it an input from user with function `get_string("What is your name? ");`

- The function prompts user for his name and stores it in the variable.

-  `printf("Hello, %s\n", name);` function prints "Hello, user-input"

- `%s` is a string type placeholder for the string type variable prompted by user

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string first_name = get_string("What is your first name? ");
    string last_name = get_string("What is your last name? ");
    printf("Hello, %s %s\n", first_name, last_name);
}
```
> In this program we prompt the user for two inputs that we store in 2 different variables.

`printf("Hello, %s %s\n", first_name, last_name);` Function uses 2 placeholders and after the coma specifies which values should replace the placeholders in the result.

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What is your name? ");
    int age = get_int("What is your age? ");
    string phone = get_string("What is your phone number? ");

    printf("Name: %s\n", name);
    printf("Age: %i\n", age);
    printf("Phone: %s\n", phone);
}
```
In the program above we prompt the user for 3 inputs (name, age, phone number) and we display contact information.
>We chose **string type** for the phone number to include a variation of entries. 

## Functions, Loops and Conditionals
### While Loops

These **loops** are useful when not sure when the condition will be true.

```c
int j = 0;
While (j < 4)
{
    printf("#");
    j++;
}
printf("\n");
```

The code above will return "####" by repeatedly executing the loop until `j` is no longer less than 4.

- `int j = 0;` Creates variable called j and stores value of 0 in it

- `While (j < 4) {}` While the condition is True (value of j is less than 4)

- `printf("#");` Print a single #

- `j++;` Increase value of j by 1

- *The loop then goes back to the top with new value to reassess the condition, and runs the loop over and over until the condition returns false (j = 4).*

- `printf("\n");` Move to a new line

### For Loops
These next **loops** are useful when wanting to specify how many times we want to iterate.

```c
for (int j = 0; j < 4; j++)
{
    printf("#");
}
printf("\n");
```

`for (int j = 0; j < 4; j++)` achieves the same result as the *while loop* in a more compact form with the following order:

- Create a variable called **j** and assign value of "**0**" to it.
- Ask **0 < 4** ? Yes, so we move to j++ and becomes j = 1
- Print out "#"

- Goes back up to ask **1 < 4** ? Yes, so we move to j++ and becomes j = 2
- Print out "##"

- Goes back up to ask **2 < 4** ? Yes, so we move to j++ and becomes j = 3
- Print out "###"

- Goes back up to ask **3 < 4** ? Yes, so we move to j++ and becomes j = 4
- Print out "####"

- Goes back up to ask **4 < 4** ? No
- We move to printf("\n");

### Nested Loops

We can create patterns using nested loops, such as a 4x4 grid of `#`

```c
for (int i = 0; i < 4; i++)
{
    for (int j = 0; j < 4; j++)
    {
        printf("#");
    }
    printf("\n");
}
```
The code above will return:
```
####
####
####
####
```
We can create a 4 x 4 # grid (superposed 4 lines of 4 #) by nesting the same for loop in the original for loop.
> Note that we need to make variables different in both loops

```c
int get_int(string prompt)
{
    // Get int from user
}
```
>`get_int` function is defined by cs50. It prompts user with a string to enter integer value in the example: `int height = get_int("Height: ");`

Defining and using functions is a key aspect of C programming. Here's an example:

```c
void print_row(int length);

int main(void)
{
    int height = get_int("Height: ");
    for (int i = 0; i < height; i++)
    {
        print_row(i + 1);
    }
}

void print_row(int bricks)
{
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    printf("\n");
}
```
This program prompts the user for the height of a pyramid and prints the corresponding rows.

- First loop sets what will be the height or how many rows will the code print using user's input.
- Second loop `print_row` defines how many `#` will be printed in each line.

>Before calling a function we need to define it. If it's defined below where it is called, the program will not run. 
> - We need to include above the call a function prototype (its name, input, and return value) ex: `void print_row(int length);`

### Parameters VS Arguments

```c
#include <stdio.h>

// Function declaration with parameters
int addNumbers(int a, int b) {
    int sum = a + b;
    return sum;
}

int main() {
    // Function call with arguments
    int result = addNumbers(5, 7);

    // Print the result
    printf("Sum: %d\n", result);

    return 0;
}
```

In this example,  `a` and `b`  are parameters declared in the function `addNumbers`

`5` and `7` are the arguments passed during the function call in `main`.

This concludes my notes of the essential concepts of Section 1. I hope these notes will be useful as you tackle the projects for this week.

In Week 2 we will be learning about **arrays** - understanding how to store and manipulate data efficiently in a computer's memory. Happy coding!
