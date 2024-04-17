# CS50x Week 5 - Data Structures

**Data structures** are ways of organizing and storing data in memory. **Abstract data structures** are conceptual data structures that we can visualize. Learning these when starting will make it easier to later understand how to implement more concrete data structures.

## Stacks and Queues 

`Queues` are a form of **abstract data structure** that follow a **FIFO** or "*first in first out*" principle (The first element added is the first one to be removed). Queues have specific actions associated with them:
- **enqueued** means that an item can join the line or queue.
- **dequeued** is when an item leaves the queue once it reaches the front of the line.

<br>

Queues in code:
```c
const int CAPACITY = 50;

typedef struct
{
    person people[CAPACITY];
    int size;
}
queue;
```
> Notice that `int size;` is added to keep track of the current number of elements in the queue to manage *enqueue* and *dequeue* operations.

<br><br>

`Stacks` have fundamentally different properties. They follow a **LIFO** or "*last in first out*" principle.Stacks too have specific actions associated with them:
-  **push** places something on top of a stack
- **Pop**  is removing something from the top of the stack.

<br>

Stacks in code:
```c
cont int CAPACITY = 50;

typedef struct
{
    person people[CAPACITY];
    int size;
}
stack;
```
> Notice that a **stack** is implemented almost as identically as a **queue**. The difference is going to be in the **code** used to manipulate the data structure with its specific **properties**.

<br>

The code above has a **limitation**. Since the **capacity** of the array is always **predetermined**, the stack may always be **oversized** (Imagine using 1 place in a stack of 5000).

<br><br>

## Resizing Arrays

Remember that arrays are a fundamental data structure used to store data in **contiguous** memory locations.

Let's imagine an array of three integers:
```c
int arr[3];
```
```txt
| 1 | 2 | 3 |
```
These values are stored *contiguously* in memory but around them, there are values being stored by other programs, functions, and variables. Many of these may be unused **garbage values**.

<br>

```txt
|  X  |  X  |  X  |  H  |  I  |
| \0  |  1  |  2  |  3  |  X  |
|  D  |  O  | \0  |     |     |
|     |  X  |  X  |     |  X  |
```
> This is an example of how the memory space might be used around our **array**. We can see *strings* from other functions and *garbage values* represented with an `x`.

<br>

If we wanted to store a fourth value `4` in our array, we would need to allocate a **new area of memory** and **move the old array** to a new one.

```txt
|  X  |  X  |  X  |  H  |  I  |
| \0  |  1  |  2  |  3  |  X  |
|     |     |     |     |     |
|     |  1  |  2  |  3  |  4  |
```
<br>

This design is **inefficient**, especially if we might have do add mode values in the future. This process involves multiple memory operations and the **time** spent to allocate new memory, read and write each element and manage the old array's memory can be significant. 

<br>

Let's explore this limited design in code:
```c
// Implements a list of numbers with an array of fixed size

#include <stdio.h>

int main(void)
{
    // Statically allocated list of size 3
    int list[3];

    // Initialize list with numbers
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // Print list
    for (int i = 0; i < 3; i++)
    {
        printf("%i\n", list[i]);
    }
}
```
<br><br>

Let's explore how we would implement the same idea using dynamically allocated memory:
```c
// Implements  list of numbers with an array of dynamic size

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Dynamically allocated list of size 3
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

    // Initialize list with numbers
    // Compiler knows to allocate sequence of 4bits per integer in list
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // Dynamically allocated list of size 4
    int *tmp = malloc(4 * sizeof(int));
    if (tmp == NULL)
    {
        // Free original list before exiting program
        // To prevent memory leaks
        free(list);
        return 1;
    }

    // Copy list of size 3 into list of size 4
    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list [i];
    }

    // Add number to list of size 4
    tmp[3] = 4;

    // Free list of size 3 that we do not need anymore
    free(list);

    // Update `list` pointer to point to new size 4 list
    list = tmp;

    // Print list
    for (int i = 0; i < 3; i++)
    {
        printf("%i\n", list[i]);
    }

    // Free list
    free(list);
    return 0;
}
```
<br>

For the same reasons, memory allocation overhead, manual element copying, potential memory waste and scalability issues, this is another **inefficient design** for the expansion of an **array**. A more efficient approach would be to use a **data structure** designed to handle **dynamic sizing**.

<br><br>

## Linked Lists

Lecture 00:31:06
