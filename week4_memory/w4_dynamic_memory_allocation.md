# Dynamic Memory Allocation

We've previously seen one way to work with pointers, pointing a **pointer variable** at another **variable** that already exists in our system. This requires us to know exactly **how much memory** our system will need at the moment our program is **compiled**.

Sometimes we cannot know how much memory we'll need at **compile-time**, particularly in scenarios where the size of the data may **vary** based on **user input**, and need to **access to new memory** while our program is running. 

`Dynamic memory allocation` provides a mechanism for accessing memory at **runtime**. To achieve this, we can use **pointers** to get access to a block of **dynamically-allocated memory** at runtime.

**Dynamically allocated memory** comes from a pool of memory known as the `Heap`. The **heap** is used for storing **objects** and **data structures** that are allocated during *runtime*. Different from the `Stack` which is a pool of memory used for **function call management**, parameters, local variable and return address storage. 

In memory, the **heap** typically resides above the stack, and grows *downward* towards it. The **stack** can be found at the bottom of the memory space and grows *upward* towards the **heap**.

<br>

## `malloc()`

We get this **dynamically-allocated memory** by making a call to the **C** standard library `<stdlib.h>` function `malloc()`, and passing as its *parameter* the number of **bytes** requested.

`malloc()` will then try and find a **contiguous** block of memory the size requested and return a **pointer** to that location. If the function cannot allocate memory (due to insufficient memory or other reasons), it wil return `NULL`.

<br>

> [!CAUTION]
> It is important to check the return value of `malloc()` to handle cases where the memory allocation **fails**. Attempting to use memory allocated with a `NULL` pointer can lead to runtime errors.

<br><br>

```c
// Statically obtain an integer

int x;
```
```c
// Dynamically obtain an integer

int *px = malloc(4);

OR

int *px = malloc(sizeof(int));
```
- `int *` Declares `px` as a **pointer** to an **integer**.
- `malloc(sizeof(int))` Dynamically allocates memory on the **heap** based on the **size of an integer**.

<br>

### Stack allocation

```c
// Get an integer from the user
int x = get_int();

// Declare array of floats of "user specified size" on the stack
float stack_array[x];
```

- This method of declaring a **variable-length-array** is not supported by all versions of `C`. It is generally recommended to avoid **VLAs** due to potential **stack overflow issues**.

<br>

### Heap allocation

```c
// Get an integer from the user
int x = get_int();

// Declare array of floats of "user specified size" on the heap
float *heap_array = malloc(x * sizeof(float));
```
- This is the correct way to **dynamically** allocates memory for an **array** of **floats** on the **heap** with a *size* determined by the *user's input* `x` (at runtime).

<br><br>

## `free()`

Unlike **stack-allocated memory**, **dynamically-allocated memory** is **not** automatically returned to the system for later use when the function in which it's created finishes the execution. Failing to return memory back to the system can results in a `memory leak`, which can compromise the system's performance. 

To **deallocate** dynamically-allocated memory, the `free()` function is used. It takes as its *argument* the **pointer** to the memory block previously allocated with `malloc()`.

<br>

```c
// We allocate memory for a 50 char long array
char *word = malloc(50 * sizeof(char));

// We work with `word` in our program

// After we are done working with the block
free(word);
```
**1.** Every block of memory that you `malloc()` must subsequently be `free()`d to avoid **memory leaks** and ensure **efficient** memory usage.

**2.** Only memory that you `malloc()` should be `free()`d. Attempting to free memory not allocated **dynamically** can lead to **undefined behavior** and program **crashes**.

**3.** Do not `free()` a block of memory more than once. Memory management errors, such as double freeing memory can cause serious issues like **memory corruption**.

<br><br>

## Dynamic Memory Management and Pointer Behavior

Let's analyze a few lines of code to visualize the process of managing dynamically allocated memory in `C`: 

```c
int m;
int* a;
int* b = malloc(sizeof(int));

a = &m;
a = b;
m = 10;
*b = m + 2;

free(b);

*a = 11;
```

<br>

- `int m;` Declares an **integer variable** called `m`, which is **statically allocating** an empty block of memory of **4 bytes** (integer size) on the **stack**:

```txt
Stack:  |       |
            m
```
<br><br>

- `int* a;` Declares a **pointer** to an **integer** called `a`, which is **statically allocating** a block of memory of **8 bytes** (size of pointers in 64-bit systems) on the **stack**:

```txt
Stack:  |              |
                a
```
<br><br>

- `int* b = malloc(sizeof(int));` Declares a **pointer** to an **integer** called `b`, which is **statically allocating** a pointer size block of memory on the **stack** `AND` **dynamically allocating** another empty block of integer size memory on the **heap**:

```txt
Stack:  |              |    
                b              
------------------------------

Heap:   |       |
            ?
```
<br><br>

- `a = &m;` Assigns the **address** of variable `m` to the **pointer** `a` (the **address of** operator `&` returns the address of `m`). **Dereferencing** `a` would give access to the value held by `m`:

```txt
a ----------> |       |
                  m
```
<br><br>

- `a = b;` Assigns the **address** of **pointer variable** `b` to the **pointer variable** `a`, which will redirect `a` to point at the *empty* block of memory dynamically allocated by `b` instead of pointing to `m`:

```txt
a ---------->       |       |
b ---------->           ?
```

<br><br>

- `m = 10;` Assigns the value of `10` to the variable `m`:

```txt
Stack:  |   10   |
            m
```

<br><br>

- `*b = m + 2;` **Dereference** pointer `b` (follow where `b` points), accessing the memory location it's pointing to and **storing there** the value of `m + 2` which is `12`:

```txt
a ---------->       |   12   |
b ---------->           ?
```
<br><br>

- `free(b);` **Deallocate** the memory that was dynamically allocated previously using `malloc()`, **releasing** it back to the system.

```txt
a ---------->      
b ---------->           
```
<br><br>

- `*a = 11;` Attempting to **dereference** pointer `a` and assign value of `11` to the *memory block* its pointing to. Note that by previously **deallocating** `b`, we released the memory block that both `b` and `a` were pointing to, making `a` a **"dangling"** pointer. **dereferencing** `a` is unsafe and can result in **unexpected behavior**.

```txt
a ---------->    ?      =           Unexpected Behavior
                 ?      =           --------------------
                 ?      =   Segmentation fault, Corruption of memory
b ---------->    ?      =   Seemingly "successful" execution 
```
