# CS50x Week 4 - Memory

This week, we will go into detail about pixels and zeros and ones that make up images. In particular, we will be going deeper into the fundamental building blocks that make up **files**.

Further, we will discuss how to access underlying data stored in **computer memory**.

## Pixels

**Pixels** are the smallest addressable elements in an image that are arranged on an up-down, left-right grid.

We can imagine an image as a map of bits, where zeros represent black and ones represent white.

![pixel smiley](../img/cs50Week4Slide015.png)

## RGB
Is a color model in which **numbers** representing the amount of **red**, **green** and **blue** primary colors are added together to reproduce a color.

![hex in photoshop](../img/cs50Week4Slide016.png)

In this photoshop color selector, the amount of **red**, **green** and **blue** will change the color selected.

> Notice the notation `#0000FF` representing the color blue.

- `R: 0` means no amount of red, and is represented by the first two digits `00....`
- `G: 0` means no amount of green, and is represented by the next two digits `..00..`
- `B: 255` means maximum amount of blue, and is represented by the last two digits `....FF`

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

**Hexadecimal** is useful because you can represent *4 bits* using a single digit or *8 bits* (1 byte) using just two digits:

```txt
F = 1111

FF = 11111111
```
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

<br>

The **C** language has to powerful operators that relate to memory:
- `&` The **address of** operator, provides the address of something stored in memory.

- `*` The **dereference operator**, instructs the compiler to go to a location in memory.

<br>

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
> [!IMPORTANT]
> There is a difference between the first and second `*p`. <br> `int *p` is syntax for **declaring** a pointer (a variable that will store an address). <br> `*p` on the *printf* line just means `go to location p`. 