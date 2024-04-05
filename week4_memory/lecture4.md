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

### "String" data type

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

### malloc

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

### free

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
- This error indicates a `memory leak`.

- In `line 6` we allocated `12 bytes` of memory that were lost. We never used `free` to *deallocate* `x`.

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

Lecture 1:24:00