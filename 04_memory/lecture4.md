# CS50x Week 4 - Memory

This week, we will go into detail about pixels and zeros and ones that make up images. In particular, we will be going deeper into the fundamental building blocks that make up **files**.

Further, we will discuss how to access underlying data stored in **computer memory**.

## Pixels

**Pixels** are the smallest addressable elements in an image that are arranged on an up-down, left-right grid.

We can imagine an image as a map of bits, where zeros represent black and ones represent white.

![pixel smiley](../img/cs50Week4Slide015.png)

<br>

## RGB
Is a color model in which **numbers** representing the amount of **red**, **green** and **blue** primary colors are added together to reproduce a color.

![hex in photoshop](../img/cs50Week4Slide016.png)

In this photoshop color selector, the amount of **red**, **green** and **blue** will change the color selected.

> Notice the notation `#0000FF` representing the color blue.

- `R: 0` means no amount of red, and is represented by the first two digits `00....`
- `G: 0` means no amount of green, and is represented by the next two digits `..00..`
- `B: 255` means maximum amount of blue, and is represented by the last two digits `....FF`

<br><br>

## Hexadecimal

**Hexadecimal** or **base-16** is a numeral system that represents numbers using 16 counting values:

```txt
0 1 2 3 4 5 6 7 8 9 a b c d e f 
```
<br>

When counting in *hexadecimal*, each column is a power of `16`.
<br>

```txt
| 16^1 | 16^0 | = | 16 | 1 |
|   #  |   #  |   |  0 | 0 |
```

|Number|Hexadecimal [16 - 1] |
|:-:|:-:|
|0|00|
|1|01|
|9|09|
|10|0A|
|15|0F|
|16|10|
|255|FF|

> [!IMPORTANT]
> 255 is the highest number you can count using two-digit hexadecimal system.

<br>

**Hexadecimal** is useful because you can represent *4 bits* using a single digit or *8 bits* (1 byte) using just two digits:

```txt
F = 1111

FF = 11111111
```
<br><br>

## Memory

In **hexadecimal** notation, number **16** is represented as `10`, number **17** is represented as `11` and number **25** is represented as `19`.

You can imagine how confusing this can be. To clarify things, by convention, all *hexadecimal* numbers are ofter represented with the `0x` prefix.
```txt
0x0 0x1 0x2 0x3 0x4 0x5 0x6 0x7 0x8 0x9 0xA 0xB 0xC 0xD 0xE 0xF 0x10 0x11 

0x12 0x13 0x14 0x15 0x16 0x17 0x18 0x19 0x1A 0x1B 0x1C 0x1D 0x1E 0x1F 0x20
```

<br>

Let's explore this in code:
```c
#include <stdio.h>

int main(void)
{
    int n = 50;
    printf("%i\n", n);
}
```
> Notice how `n` is stored in memory with the value of `50`.

<br>

We can visualize how the program stores this value as follows:
![hex 50](../img/cs50Week4Slide070.png)
> `0x123` being the hexadecimal address where the value is stored.

<br><br>

The **C** language has to powerful operators that relate to memory:
- `&` The **address of** operator, provides the address of something stored in memory.

- `*` The **dereference operator**, instructs the compiler to go to a location in memory.

<br><br>

Let's apply this to our code:
```c
#include <stdio.h>

int main(void)
{
    int n = 50;
    printf("%p\n", &n);
}
```
- `%p` is format code to print an **address**.

- `&n` is equivalent to `the address of n`.

<br>

This code returns the address in the computer memory where `n` is stored:
```txt
0x7ffd077b19dc
```
<br><br>

## Pointers

A **pointer** is a variable that stores the memory address of another variable as its value.

```c
int n = 50;

int *p = &n;
```
> `p` is a pointer that contains the memory address of an integer `n`.

<br>

```c
#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%p\n", p);
}
```
```txt
0x7ffd437f067c
```
> This code has the same effect as the previous code, but includes a **pointer**.

<br>

Let's explore the use of the `*` operator:
```c
#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%i\n", *p);
}
```
`printf` line request: Go to the address `*p` and print the integer value `%i` stored there:
```txt
50
```
<br>

> [!NOTE]
> There is a difference between the first and second `*p`.<br> `int *p` is syntax for **declaring** a pointer (a variable that will store an address). <br> `*p` on the *printf* line just means `go to location p`. 

<br><br>

Let's visualize how the code is stored: 

![pointer](../img/cs50Week4Slide078.png)

- The integer `50` stored in the variable `n` can be found at the address `0x123`.

- The pointer variable `p` storing the address of n = `&n` = `0x123`, can be found at *another location* on the memory and is usually stored as an `8-byte value`.

<br><br>

## Strings

No that we understand the concept of pointers, let's revisit **strings** and dive deeper into how they are stored.
```c
string s = "HI!"
```
<br>

We can visualize this string `s` stored as follows:
```
|   H   |   I   |   !   |   \0  |

   s[0]    s[1]    s[2]    s[3] 

   0x123   0x124   0x125   0x126
```

- In `string s = "HI!"`, `s` stores the address of the beginning of the string.

- `s` stores `0x123`.

- `s` is a **pointer** to the address of `s[0]` which holds the value of the *first element* of the string, `H`.

<br><br>

Now that we know that `s` is a **pointer** to an address, let's print out it's value using `%p`:
```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = "HI!";
    printf("%p\n", s);
}
```
```txt
0x564fed03a004
```
<br>

Let's also printout the **addresses** of the characters in `s` using the operator `&`:
```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = "HI!";
    printf("%p\n", s);
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);
}
```
```txt
0x564fed03a004  =   address of s

0x564fed03a004  =   address of H
0x564fed03a005  =   address of I
0x564fed03a006  =   address of !
0x564fed03a007  =   address of \0
```
<br>

> [!NOTE]
> The addresses corresponding to `s` and `s[0]` are the **same**. Remember that `s` points to the **first** character of the string (H). <br> 
Notice also the last digit of the addresses. It shows that the elements are next to each other on the memory, `1 byte` apart.

<br>

### `String` data type

The `string` data type is a `cs50.h` invention to introduce strings in a simplified way.
```c
string s = "HI!";
```
<br>

In raw `C` code, it looks like this:
```c
char *s = "HI!";
``` 
- `char *` replaces the `string` data type.

- `char` is data type for a **single character**.

- `*` is the *dereference operator* that tells the compiler to go to that address.

- `*s` is the address for the *first character* of the **string** called `s`.

<br><br>

Now, we can get rid of the `cs50.h` library and write the code in raw `C` and have the same result:
```c
#include <stdio.h>

int main(void)
{
    char *s = "HI!";
    printf("%s\n", s);
}
```
```txt
HI!
```

<br>

`string` data type was created with a single line of code, using a **typedef declaration**:
```c
typedef char *string
```
> This teaches the **compiler** that `string` is an alias of `char *`.

<br>

## Pointer Arithmetic

```c
#include <stdio.h>

int main(void)
{
    char *s = "HI!";
    printf("%c", s[0]);
    printf("%c", s[1]);
    printf("%c\n", s[2]);
}
```
```txt
HI!
```
The program above prints out the string `HI!` by printing out each `char` back-to-back.

<br><br>

```c
#include <stdio.h>

int main(void)
{
    char *s = "HI!";
    printf("%c", *s);
    printf("%c", *(s + 1));
    printf("%c\n", *(s + 2));
}
```
```txt
HI!
```
>[!NOTE]
> Since `*s` points to the 1st *char* of the string, we can determine that `*(s + 1)` is the location of the 2nd *char*, and `*(s + 2)` the 3rd.

<br><br>

## String Comparison

A string of characters is simply an *array of characters* identified by its first **byte**.

To compare integers, we used the `==` equality operator:

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get two integers
    int i = get_int("i: ");
    int j = get_int("j: ");

    // Compare integers
    if (i == j)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}
```

<br>

However, in the case of **strings**, we cannot compare two strings using the `==` operator:

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get two strings
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    // Compare strings' addresses
    if (s == t)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}
```

> [!IMPORTANT]
> Using the `==` operator to compare strings will attempt to compare the **memory locations** of the strings instead of the characters.

<br>

|s|t|
|:-:|:-:|
|s[0]|s[0]|
|0x123|0x456|

<br>

- Different *strings* are located in different memory addresses.

- String `s` could be located in address `0x123`, while string `t` might be located in address `0x456`.

- Typing the **HI!** as input to both prompts in the code above will still result in an output of `Different`.

<br><br>

Using `strcmp` function of the `string.h` library, we can correct our code:

```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Get two strings
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    // Compare strings
    if (strcmp(s, t) == 0)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}
```
> Notice that `strcmp` takes the strings as arguments and can return `0` if the strings are the same.

<br><br>

We can see that these two strings are located in *different* addresses using the `%p` placeholder in the print statement:

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get two strings
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    // Print strings
    printf("%p\n", s);
    printf("%p\n", t);
}
```
```txt
0x56211767d6b0
0x56211767d6f0
```

> [!NOTE]
> We do not need to use the `&s` or `&t` like in other data types, because we now know that **strings** are already `pointers` and hold the address of the first character of the string. 

<br><br>

## Copying

Let's try and copy one string to another:
```c
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("s: ");

    string t = s;

    t[0] = toupper(t[0]);

    printf("%s\n", s);
    printf("%s\n", t);
}
```
The program above attempts to:
- Copy string `s` into string `t`.
- Then Capitalize the first character of string `t`.
- And print out both strings.

<br>

Theoretically, if we input `hi!` into the prompt, the program should print out:
```txt
hi!
Hi!
```
<br>

But this will not work, because `string t = s` copies the address of `s` to `t`. 

Both strings now hold the **same address** and *point* to the same block in memory `t[0] == s[0]`. The output will be the following:

```txt
Hi!
Hi!
```

<br><br>

Before we address this bug, we can add a security layer and make sure the string `t` has *at least one character* before attempting to capitalize its first letter. This will prevent a `segmentation fault` from happening and our program crashing.

```c
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Get a string
    string s = get_string("s: ");

    // Copy string's address
    string t = s;

    // Capitalize first letter in string
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    // Print string twice
    printf("s: %s\n", s);
    printf("t: %s\n", t);
}
```
- `if (strlen(t) > 0)` This condition checks is the length of the string `t` (number of characters) is greater than `0`.

<br>

### `malloc`

To be able to make an **authentic copy** of the **string**, we will need to use two new building blocks:
- `malloc` allows us to allocate a block of a specific size of memory.
- `free` allows us to tell the compiler to *free up* that block of memory we previously allocated.

```c
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // Get string s
    char *s = get_string("s: ");

    // Allocate memory for another string
    char *t = malloc(strlen(s) + 1);

    // Copy string into memory, including "\0"
    for (int i = 0, n = strlen(s); i <= n; i++)
    {
            t[i] = s[i];
    }

    // Capitalize copy
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    // Print strings
    printf("%s\n", s);
    printf("%s\n", t);
}
```
<br>

> [!IMPORTANT]
> We have to ensure that we include the null `\0` character in our copied string. 

<br>

- `malloc(strlen(s) = 1)` creates a block of memory that is the length of the string `s` **plus 1**. This ensures the inclusion of the **null** `\0` character.

- The `for` loop iterates through string `s` indexes and assigns each value to the same locations on string `t`.

- To prevent running a function over and over again, in the **for loop**, we did not call the `strlen(s)` function in the middle of the condition like so `i <= strlen(n)`.

- Instead, we declared `n = strlen(s)` and used the condition `i <= n`. This ensures `strlen` only runs once.

<br><br>

If something goes wrong and we are **out of memory** in the computer, both `malloc` and `get_string` functions return `NULL`. 

We can check for this condition and exit the program early, adding a layer of safety as follows:
```c
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");

    // Check for NULL
    if (t == NULL)
    {
        return 1;
    }

    char *t = malloc(strlen(s) + 1);

    // Check for NULL
    if (t == NULL)
    {
        return 1;
    }

    for (int i = 0, n = strlen(s); i <= n; i++)
    {
            t[i] = s[i];
    }

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("%s\n", s);
    printf("%s\n", t);
}
```

 <br><br>

The `C` language has a **built-in** function to copy strings called `strcpy`. It can replace ouf `for loop` as follows:
```c
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");
    if (t == NULL)
    {
        return 1;
    }

    char *t = malloc(strlen(s) + 1);
    if (t == NULL)
    {
        return 1;
    }

    // Copy string into memory
    strcpy(t, s);

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("%s\n", s);
    printf("%s\n", t);
}
```
<br><br>

### `free`

In **C**, the `free` function is used to **deallocate memory** that was previously allocated using the function `malloc`.

This is crucial to **prevent memory leaks** and efficiently managing memory in **C** programs.
```c
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");
    if (t == NULL)
    {
        return 1;
    }

    char *t = malloc(strlen(s) + 1);
    if (t == NULL)
    {
        return 1;
    }

    strcpy(t, s);

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("%s\n", s);
    printf("%s\n", t);

    // Free memory allocated to `t`
    free(t);
    return 0;
}
```
> [!NOTE]
> The program execution is complete once the `printf` statements are executed. After that the program terminates, making `t` no longer needed for future operations.<br>
`t` can now be safely deallocated using the `free` function.

<br><br>

## Valgrind 

**Valgrind** is a tool that we can use to spot memory-related issues. Specifically if we effectively `free` memory previously allocated in the program with `malloc`.

<br>

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *x = malloc(3 * sizeof(int));
    x[1] = 72;
    x[2] = 73;
    x[3] = 33;
}
```
- `int *x` Declares the address of an integer.

- `= malloc(3 * sizeof(int));` Assigns to it enough space for an **array** of size **3 integers**.

- `sizeof(int)` Instead of guessing how many **bytes** does an *integer* take in a specific machine, this function will take care of that for us.

- Then proceeds to assign values to the indexes of the **array**.

<br><br>

If we compile the code and type `valgrind ./file_name`, we will get a **report** that will indicate the following **errors**:

```txt
==18341== Invalid write of size 4
==18341==    at 0x109170: main (memory.c:9)
==18341==  Address 0x4bb404c is 0 bytes after a block of size 12 alloc'd
==18341==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==18341==    by 0x109151: main (memory.c:6)
```
- In `line 9` we attempted to assign the value of `33` at the **4th** position of the array, but we only allocated an array of size `3`. We should have started to assign values at the first index `x[0]`.

<br>

```txt
==18341== 12 bytes in 1 blocks are definitely lost in loss record 1 of 1
==18341==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==18341==    by 0x109151: main (memory.c:6)
```
- This error indicates a `memory leak`. In `line 6` we allocated `12 bytes` of memory that were lost. We never used `free` to *deallocate* `x`.

<br><br>

We can fix the program by modifying the code as follows:
```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *x = malloc(3 * sizeof(int));
    x[0] = 72;
    x[1] = 73;
    x[2] = 33;
    free(x);
}
```
<br>

And if we run `valgrind ./file_name` again:
```txt
==27591== HEAP SUMMARY:
==27591==     in use at exit: 0 bytes in 0 blocks
==27591==   total heap usage: 1 allocs, 1 frees, 12 bytes allocated
==27591== 
==27591== All heap blocks were freed -- no leaks are possible
```

<br><br>

## Garbage Values

**Garbage** values, are values stored in a variable or memory location that has not been **explicitly initialized** or assigned with a **meaningful value**.

When you ask the **compiler** for a *block of memory*, there is no guarantee that this memory will be empty. It's very possible that this memory contains a **garbage value**.

```c
#include <stdio.h>

int main(void)
{
    int scores[1024];

    for (int i = 0; i < 1024; i++)
    {
        printf("%i\n", scores[i]);
    }
}
```
When we run this code, some of the values (not all 1024) returned below:
```txt
0
1685382482
4
2185456
0
2189552
0
2189552
0
14096
0
14096
```
- In this program we allocated `1024` locations in memory for our array.

- The values in this array have not been initialized.

- When running the program, we notice that it prints some **garbage values** and not just `0s`. 

<br><br>

Let's see another problematic scenario:
```c
int main(void)
{
    int *x;
    int *y;

    x = malloc(sizeof(int));

    *x = 42;
    *y = 13;

    y = x;

    *y = 13
}
```
- In this function, we declared `*x` and `*y` pointers.

- Only allocated memory for `*x`.

- We dereference `*x` to store in it the value`42`.

- But then, attempted to dereference `*y`  to assign to it the value `13`.

- Since we never **initialized** `*y`, it most likely contains a `garbage value`. 

- Attempting to assign `13` to `*y` could lead to a `segmentation fault` or another **unexpected behavior** because we don't know where `*y` points.

- We then assign the value of **x** to **y** with `y = x`. This means that the random memory allocated for `y` (if any) is lost, leading to a **memory leak**.

<br>

The simple solution here that will make this code correct is simply removing line `*y = 13;`. This would make next line `y = x;` valid and `*x` and `*y` point to the **same location**. Assigning value of `13` to `*y` in the last line will change the value stored in the **common** memory location.
```txt
1. Pointer and pointee (memory location) are separate - don't forget to set up a pointee.

2. Pointer dereferencing (assign value) to access its pointee.

3. Pointer assignment (=) makes pointers point to the same memory location.
```
<br><br>

## Swap

A common need in programming is to **swap** the **values** of two variables. An important step in this process is to **temporarily hold space**.

Let's see this process in action:
```c
#include <stdio.h>

void swap(int a, int b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(x, y);
    printf("x is %i, y is %i\n", x, y);
}

void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
```
- After printing the values of `x` and `y` a first time.

- This program **attempts** to swap the values of `x` and `y` using the swap function.

- `swap()` 
    1. Assigns the value of `x` in a temporary variable `tmp` to free up space in `x`.
    2. Assigns the value of `y` to `x`.
    3. Now that `y` is free, it assigns to it the old value of `x` stored in `tmp`.
    4. Theoretically achieving to swap `x` and `y`.

<br>

But there is an **issue** here, when we run the program it **fails** to swap the values:
```txt
x is 1, y is 2
x is 1, y is 2
```

This is an issue of `scope`. Remember that **local variables** are `passed by value` and changes made to them in another function `swap()`, **do not** affect the original variables in the calling function `main()`.

When we used the `swap()` function we swapped **"copies"** of `x` and `y`.

<br><br>

### Memory segments

To illustrate this, let's breakdown how information in stored in the computer's memory:

![stack and heap](../img/cs50Week4Slide163.png)

- `Machine code` At the **lowest level** we have machine code or **instructions** that have been compiled and represent the operations to be performed by the **CPU**.

- `Global variables` Variables that are initialized before the program starts, **outside** of the `main()` function and every other function. These **variables** are accessible from anywhere in the program and stored in **global memory**.

- `Heap` The **heap** is a region of memory used for **dynamic memory allocation**. Memory allocated on the heap using `malloc` persists until it is explicitly deallocated with `free`.

- `Stack` is the region of memory used for **function call** management and **local variable** storage. Each time a function is created, a new `stack frame` is created containing all the information related to the function call (parameters, local variables, return address, etc).

<br>

![frames](../img/cs50Week4Slide167.png)

> [!NOTE]
> The `main()` function and the `swap()` function have two different **stack frames** in the memory. When passing variables as arguments to a function in `C`, that function receives **copies**. Therefore, modifying theses **copies** inside the function does not affect the **original variables** in the caller's context.

<br>

### Passing by reference

To enable `swap()` to modify the **original variables** passed to it, we need to `pass by reference` using **pointers**. This way, the function can *dereference* the pointers and access the **actual memory location** of the variables.
```c
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
```
- By adding the `*` operator to the arguments, we make them **pointers** and `swap()` has access to the **addresses** of `x` and `y`and not just a copy of their values. 

- `*a` points to `x` and `*b` points to `y`.

<br>

We also need to add the `&` operator to `x` and `y` in the function call, to ensure that we pass their **addresses** as arguments.
```c
swap(&x, &y);
```
<br>

Now that `swap()` can access the actual **memory location** of `x` and `y`, the changes it makes are reflected in the `main()` function and the output of the program is the following:
```txt
x is 1, y is 2
x is 2, y is 1
```

<br><br>

## Overflow

`Heap overflow` occurs when a program writes data beyond the memory allocated to it on the heap, touching areas of memory it is not supposed to. Typically happens when we **dynamically allocate** `malloc()` memory but write **more data** than the allocated.

`Stack overflow` is when too many functions are **called**, overflowing the amount of memory available on the stack.<br>
Each time a function is **called** a new **stack frame** is added to the **call stack**. If a program *recursively* calls a function without **proper termination** condition, it can lead to **stack overflow**. 

<br><br>

## `scanf`

In **CS50** functions like `get_int` and `get_string` have been created to simplify the act of getting **user input**. In **C** we can use the `scanf` built-in function to get user input.

<br>

### `get_int` 

Let's implement the function using raw **C** code:
```c
#include <stdio.h>

int main(void)
{
    int n;
    printf("n: ");
    scanf("%i", &n);
    printf("n: %i\n", n);
}
```
- `scanf("%i", &n)` stores the user input value of `n` at the location `&n`.

<br>

### `get_string`

Let's try to implement this function using raw **C** code:
```c
#include <stdio.h>

int main(void)
{
    char *s;
    printf("s: ");
    scanf("%s", s);
    printf("s: %s\n", s);
}
```
> Notice that no `&` is required because strings are already represented using **pointers** to the first character of the string.

<br>

If we succeed in compiling this program, we will get an **error**:
```txt
Segmentation fault (core dumped)
```
- We declared the *pointer variable* `s` without **initializing** it (allocating memory to it). This means that it does not point to any **valid memory address**. Instead, it contains a `garbage value` (it points to some random memory location which may not be accessible or safe to use). 

<br><br>

To fix this, we can modify the code as follows: 
```c
#include <stdio.h>

int main(void)
{
    char s[4];
    printf("s: ");
    scanf("%s", s);
    printf("s: %s\n", s);
}
```
- However, we had to **pre-allocate** a certain amount of memory, in this case `s[4]`. This is only a *guess*, because we cannot know what **size** string the user is going to input.

- Declaring the string as `s[4]`, we allocated enough memory to hold **four characters** of `1 byte` each (s[0], s[1], s[2]) including the **null terminator** `\0` (s[3]). Totaling `4 bytes`.

<br>

If the user provides a **longer string** as an input, we will step out of the bounds of the **memory allocated** resulting in an error:
```txt
Segmentation fault (core dumped)
```
<br>

It is risky to use the `scanf` function in general and especially with **strings**, because it lacks the memory error handling and can lead to **buffer overflows**. CS50's `get_string` function uses `malloc` *recursively* to resize and allocate more data depending on the user input.

<br><br>

## File I/O

**File Input/Output** refers to the operations of reading from and writing to files on a computer's storage system.

```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Open csv file
    FILE *file = fopen("phonebook.csv", "a");

    // Get name and number
    char *name = get_string("Name: ");
    char *number = get_string("Number: ");

    // Print to file
    fprintf(file, "%s,%s\n", name, number);

    // Close file
    fclose(file);
}
```
> Notice that the program uses **pointers** to access the file.

- We can create a file called `phonebook.csv` before running this program. After running, the program will prompt user for a `name` and `number` that it will write in the CSV file.

- `FILE *file` is a **pointer** to the file in memory.

-  `fopen()` function opens the file.

- With `"a"`, we specify that we want to **append** the file.

- `fprintf()` prints to the file two strings (name and number).

- `fclose()` closes the file.

<br><br>

If we want to ensure that `phonebook.csv` exists prior to running the program, we can modify our code as follows:
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Open csv file
    FILE *file = fopen("phonebook.csv", "a");

    // Check if file exists
    // Alternative -> if (file == NULL)
    if (!file)
    {
        return 1;
    }

    // Get name and number
    char *name = get_string("Name: ");
    char *number = get_string("Number: ");

    // Print to file
    fprintf(file, "%s,%s\n", name, number);

    // Close file
    fclose(file);
}
```
- The `if (!file)` condition protects the program against a `NULL` pointer by invoking `return 1`.

<br><br>

Let's implement our own **copy** program for files:
```c
#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    FILE *src = fopen(argv[1], "rb");
    FILE *dst = fopen(argv[2], "wb");

    BYTE b;

    while (fread(&b, sizeof(b), 1, src) !=0)
    {
        fwrite(&b, sizeof(b), 1, dst);
    }

    fclose(dst);
    fclose(src);
}
```
- `typedef uint8_t BYTE` means give me an **"unsigned"** (no negative number), **8 bit** value inside a new type called **BYTE**.

- `FILE *src = fopen(argv[1], "rb");` Declare a **pointer** variable called **src** of type **FILE**, and **open** the file specified in the **2nd** command line argument to **read binary**.

- `FILE *dst = fopen(argv[2], "wb");` Declare a second **pointer** variable called **dst** of type **FILE**, and **open** the file specified in the **3rd** command line argument to **write binary**.

- `BYTE b` store **1 byte** declared earlier in a variable called **b**.

- `while(...) !=0` While **fread()** is successful continue.

- `fread(&b, sizeof(b), 1, src` Read bites and store them in address of **b**, of size **1 bite**, **one byte** at a time from the **src** file.

- `fwrite(&b, sizeof(b), 1, dst);` Write bites stored in address of **b**, of size **1 byte**, **one bite** at a time, to **dst** file.

- `fclose` close files **dst** and **src**.

<br>

With this simple but powerful copy program implemented in **C** we can now copy the contents of any binary file to another file byte per byte. 

In the problem sets we will be manipulating **Bitmap Image Files** (BMPs).
