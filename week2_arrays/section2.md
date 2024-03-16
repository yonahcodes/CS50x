# CS50 Section 2 - Arrays
Welcome to my personal notes of CS50's second section! The goal of sections is to help us bridge the gap between lectures and problem sets.

In the previous week, we learned about **C** programming language. This week, we are going to take a deeper look at additional building-blocks that will support our understanding of **C**. We will learn about compiling, arrays, strings and command-line arguments.

## Compilation
Converting the *source code* written in **C** to *machine code* the computer understands.

1. Source code 
```c
int main(void)
{
    printf("Hello");
}
```
2. Assembly code
```assembly
main:
# @main
    .cfi_startproc
# BB#0:
    push    %rbp
.Ltmp0:
    .cfi_def_cfa_offset 16
```
3. Binary
```
01111111010001010100110001000110
00000010000000010000000100000000
00000000000000000000000000000000
00000000000000000000000000000000
00000001000000000011111000000000
00000001000000000000000000000000
00000000000000000000000000000000
00000000000000000000000000000000
00000000000000000000000000000000
```
> In CS50 we use the pre-programmed `make filename.c` command to compile our code.

## Arrays

An **array** is a *data structure* that stores a collection of elements, such as integers or characters, back-to-back in the computer's memory. This optimizes data storage and makes it easier to search, sort and iterate over the data.

Using **variables** only to store a wide range of data is **not** appropriate design. We would store each element separately, and it would be difficult to scale and keep track of the data.

```c
night1 = 7
night2 = 8
night3 = 6
night4 = 7
night5 = 8
```
|night1|night2|night3|night4|night5|
|:-:|:-:|:-:|:-:|:-:|
|7|8|6|7|8|

We can use an **array** to optimize the storing of this data:

|nights|
|:-:|
|7 8 6 7 8|

```c
nights[0] = 7
nights[2] = 8
nights[3] = 6
nights[4] = 7
nights[5] = 8
```
Arrays are **"zero-indexed"**, meaning that the first element in the array is located at index zero `[0]`. In other words, when we access elements in an array, we start counting from zero.

In **C** arrays, we need to specify the following:
- Data type `int`
- Name `nights`
- Size (How many elements?) `[5]`

```c
int nights[5]
```
If we wanted to not only *declare* the array, but also *initialize it* with values:
```c
int nights[5] = {7, 8, 6, 7, 8};
```
> In **C** once you have declared the size of an array, it cannot be changed.

### Doubling Up
Let's create an **array** of *integers* in which: 
- Each integer is `2` times the value of the previous integer. 
- The first element is `1`.
- Print the array, integer by integer

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Declare the array
    int sequence[5];

    // Declare and print the first element of the array
    sequence[0] = 1;
    printf("%i\n", sequence[0]);

    // loop that iterates through the indexes
    // i = index of array we are trying to set
    for (int i = 1; i < 5; i++)
    {
       // Multiply the values by 2
       sequence[i] = sequence[i - 1] * 2;
       // Print each value
       printf("%i\n", sequence[i]);
    }
}
```
This code will return:
```
1
2
4
8
16
```
We can also modify the main function to declare a variable called `size` to make it easier to change:
```c
int main(void)
{
    int size = 8;
    int sequence[size];

    sequence[0] = 1;
    printf("%i\n", sequence[0]);

    for (int i = 1; i < size; i++)
    {
       sequence[i] = sequence[i - 1] * 2;
       printf("%i\n", sequence[i]);
    }
}
```
This code will return:
```
1
2
4
8
16
32
64
128
```
We could also prompt the user for the size of the array:
```c
int main(void)
{
    int size = get_int("Enter size: ");
    int sequence[size];

    sequence[0] = 1;
    printf("%i\n", sequence[0]);

    for (int i = 1; i < size; i++)
    {
       sequence[i] = sequence[i - 1] * 2;
       printf("%i\n", sequence[i]);
    }
}
```
## Strings
A **string** is an array, where the elements are characters `char`.

HELLO

```c
phrase[0] = H
phrase[1] = E
phrase[2] = L
phrase[3] = L
phrase[4] = O
```

### In **C** we use **ASCII** to represent letters of the alphabet by integers

|Character|Integer|
|:-:|:-:|
|A|65|
|B|66|
|C|67|
|...|...|

|phrase|
|:-:|
|H E L L O|
|72 69 76 76 79|

### Alphabetical
Let's create a program to check if an array of characters is in alphabetical order.
- Assume the characters ar all uppercase

```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string phrase = get_string("Enter a phrase: ");
    int length = strlen(phrase);

    for (int i = 0; i < length; i++)
    {
        printf("%i ", phrase[i]);
    }
    printf("\n");
}
```
or
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string phrase = get_string("Enter a phrase: ");

    // If the first variable is of type "int", it is implied that the one after the coma is too
    for (int i = 0, length = strlen(phrase); i < length; i++)
    {
        printf("%i ", phrase[i]);
    }
    printf("\n");
}
```
- If we input `hello`, we will get `104 101 108 108 111`
- If we input `HELLO`, we will get `72 69 76 76 79`

> Our exercise asks us to assume that the characters are all in *uppercase*.

```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string phrase = get_string("Enter a phrase: ");

    for (int i = 0, length = strlen(phrase); i < length - 1; i++)
    {
        // Check if characters are NOT alphabetical
        if (phrase[i] > phrase[i + 1])
        {
            printf("Not in alphabetical order\n");
            return 0;
        }
    }
    printf("Alphabetical order!\n");
    return 0;
}
```
Notice that the last `printf` function is outside of the `for loop`. This is done to respect the *scope* and for the program to go through every character of the string.

## Command-Line Arguments

We're going to explore the idea of running programs and giving them input not while they run, but before they run, using the **command line**.

We are used to running programs, and only when prompted give an input:

```c
int main(void)
{
    int height = get_int("Height: ");
}
```
The terminal would look like this:
```
$ ./mario
Height: 8
```
Now, we are going to transition and allow the user to give input **before** the program runs:
```
$ ./mario 8
```
To allow this, we have to change the code and instead of `(void)`, add **arguments** to our `main` function:

```c
int main(void)
{
    
}
```

### Let's breakdown `int main(void)`:<br>
`int` tells us the **exit status code**: If `0`, the program was executed successfully.<br>
`main` is the name of the function<br>
`(void)` means the function takes no arguments.<br>
To run the program user only types `./mario`

No let's add arguments to the **main** function:

```c
 int main(int argc, string argv[])
 {

 }
```
### Let's break down `int main(int argc, string argv[])`,<br>
`argc` is an argument of type integer and its value is equivalent to the number of arguments the program receives at the command line: `./mario 8` would mean `argc = 2`.<br>
`argv[]` is an array of strings at the command line. In `./mario 8` it contains `2` strings: The name of the program `./mario` and the input that user gave `8`.

### Argv

If we wanted to create a program that reveals what is inside `argv[]`:

```c
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    // argc here tells us the number of inputs
    for (int i = 0; i < argc; i++)
    {
        // Print each argv[] index and its value
        printf("argv[%i] is %s\n", i, argv[]);
    }
}
```
When we type `./argv 1 2 3`, the program will return:
```
argv[0] is ./argv
argv[1] is 1
argv[2] is 2
argv[3] is 3
```

### Error

`Segmentation fault (core dumped)` error happens when we look **beyond** the bounds of the array. When checking for values, make sure to index within the range of the array.

To make sure user inputs the correct format we can implement a **conditional function** that will return an error before the program crashes:

```c
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./mario number\n");
        return 1;
    }

    // using the "atoi" function from <stdlib.h> we convert argv[] in int
    int height = atoi(argv[1]);
}
```

This concludes my notes of the essential concepts of Section 2. I hope these notes will be useful as you tackle the projects for this week.

In Week 3 we will be learning about **algorithms**. We'll explore techniques like Linear search and Binary search, along with various sorting methods such as Bubble sort, Selection sort and Merge sort. Additionally we'll delve into asymptotic notation and recursion. Happy coding!
