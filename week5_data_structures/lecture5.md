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

Now let's see how we would implement the same idea using dynamically allocated memory:
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

For the same reasons, (memory allocation overhead, manual element copying, potential memory waste and scalability issues) this is another **inefficient design** for the expansion of an **array**. A more efficient approach would be to use a **data structure** designed to handle **dynamic sizing**.

<br><br>

## Linked Lists

A **linked list** is one of the most powerful data structures in **C**. Linked lists are more **flexible** in using memory compared to arrays. They allow us to include values that are located at **different memory locations** (not contiguous) and allow us to **dynamically** grow and shrink the list as desired.

Remember these three primitives:
- `struct` is a user-defined data type that allows us to combine data items of different kind.

- `.` in *dot notation* allows us to access members of that structure variable.

- `*` operator is used to **declare** a pointer or **dereference** a variable. 

<br>

In **linked lists** we will introduce the `->` operator (arrow). `->` is a shorthand for **dereferencing** a pointer to a **structure** and accessing a **member** of that structure. Combining the use of `*` and `.`

<br>

Imagine three values stored at three different locations in memory:
```txt
| 1 |   |   |   |   |
|   |   | 2 |   |   |
|   |   |   |   | 3 |
|   |   |   |   |   |
```

```txt
|   1   |    
| 0x123 |    |   2   |   
             | 0x456 |    |   3   |
                          | 0x789 |
```
- Value `1` is stored at address `0x123`
- Value `2` is stored at address `0x456`
- Value `3` is stored at address `0x789`

<br><br>

Linked list elements, commonly called **nodes** contain their *own data*, and *meta data* in the form of a **pointer** to the next **node**:
```txt
| 0x123 |  ->   |   1   |    
                | 0x123 |       |   2   |   
                | 0x456 |  ->   | 0x456 |       |   3   |
                                | 0x789 |  ->   | 0x789 |
                                                |  NULL |
```
- The **first node** contains the address `0x123` of the value it stores `1` and a pointer `0x456` to the next **node** in the list.

- The **second node** contains the address `0x456` of the value it stores `2` and a pointer `0x789` to the next **node** in the list.

- The **last node** contains the address `0x789` of the value it stores `3` and a pointer to a `NULL` value (preventing pointing to a garbage value) to terminate the list.

- By convention, we also use an extra **pointer** `0x123` to the **first node** on the list.

<br><br>

Structure of **linked list node**:
```c
typedef struct node
{
    int number;
    struct node *next;
}
node;
```
- `typedef` creates an **alias** (`node`) to use instead of a more complicated type.

- `struct` defines new **data structure**.

- `node` declares the **name** of this structure type.

- `int number;` declares an **integer member** called `number` inside the structure.

- `struct node *next;` declares a **pointer** (`next`) to the next `struct node` in the list.

- `node;` Allows to create nodes in the list by declaring them as **node** instead of **struct node**.

<br><br>

### Now that we have our node type defined, we can create a Linked List:

<br>

**1.** Declare a **pointer** `list` that will eventually link to first node, and **initialize** its value to `NULL` (so that it does not point to a *garbage value*):
```c
node *list = NULL;
```
```txt
   list
|        |  
```
<br><br>

**2.** Dynamically allocate memory of size "**node**" and store its address in a pointer variable `n`:
```c
node *n = malloc(sizeof(node));
```
```txt
   list
|        |  

                        
    n 
|        | ---------->  |  Grb  | number
                        |  Grb  | next
```
> Notice that when the memory is allocated, it first hold **garbage values** (Grb).

<br><br>

**3.** **Dereference** pointer `n` to access member (`number`) of the node, and assign to it the value of `1`:
```c
(*n).number = 1;


//Alternative syntax
n->number = 1;
```
```txt
   list
|        |  

                        
    n 
|        | ---------->  |   1   | number
                        |  Grb  | next
```
<br><br>

**4.** **Dereference** pointer `n` to access the member (`next`) of the node, and assign to it the value of `NULL` (so that it does not point to a garbage value):
```c
(*n).next = NULL;


//Alternative syntax:
n->next = NULL;
```
```txt
   list
|        |  

                        
    n 
|        | ---------->  |   1   | number
                        |       | next
```
> [!IMPORTANT]
> It is crucial that each new node starts with its `next` pointer ser to `NULL` to avoid **dangling pointers**.

<br><br>

**5.** Assign the address of pointer `n` to `list`. Both `list` and `n` now point to the **same memory location**. This is used to set `list` as the **head** of the linked list.
```c
list = n;
```
```txt
   list
|        |
    |
    |
    |        
    v   

    n               
|        | ------------>  |   1   | number
                          |       | next
```
<br><br>

**6.** Dynamically allocate memory for a new **node** and store its address in pointer variable `n`:
```c
node *n = malloc(sizeof(node));
```
```txt
   list 
|        | ----------->  |   1   | number
                         |       | next  


    n 
|        | ---------->   |  Grb  | number
                         |  Grb  | next
```
> Notice that both members of new node contain garbage values for now.

<br><br>

**7.** **Dereference** pointer `n` to access member (`number`) of the node, and assign to it the value of `2`:
```c
(*n).number = 2;


//Alternative syntax
n->number = 2;
```
```txt
    list 
|        | ----------->  |   1   | number
                         |       | next  


     n 
|        | ---------->   |   2   | number
                         |  Grb  | next
```
<br><br>

**8.** **Dereference** pointer `n` to access the member (`next`) of the node, and assign to it the value of `NULL` (so that it does not point to a garbage value):
```c
(*n).next = NULL;


//Alternative syntax:
n->next = NULL;
```
```txt
    list 
|        | ----------->  |   1   | number
                         |       | next  


     n 
|        | ---------->   |   2   | number
                         |       | next
```
<br><br>

**9.** **Dereference** pointer `n` to access the member (`next`) of the node, and make it point to the same memory location as `list`.
```c
(*n).next = list;


//Alternative syntax:
n->next = list;
```
```txt
                                                         list 
                                                      |        |
                                                           |
                                                           |
                                                           |
     n                                                     v
|        | ---------->   |   2   | number              
                         |       | next    ----------> |   1   | number
                                                       |       | next
```
> [!CAUTION]
> Before linking `list` to the new **node** and risking to **lose connection** and access to **node 1**, we have to link **node 1** to **node 2**.

<br><br>

**10.** Now that both **nodes** are **linked**, we can update `list` to point at `n`.
```c
list = n;
```
```txt
   list 
|        |
    |                                                       
    |
    |                                                      
    v
                                                        
    n                                                    
|        | ---------->   |   2   | number              
                         |       | next    ----------> |   1   | number
                                                       |       | next
```
```txt

    list                                                    
|        | ---------->   |   2   | number              
                         |       | next    ----------> |   1   | number
                                                       |       | next
```

<br><br>

Lecture 00:55:00
