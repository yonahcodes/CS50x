# CS50x Week 5 - Data Structures

**Data structures** are ways of organizing and storing data in memory. **Abstract data structures** are conceptual data structures that we can visualize. Learning these when starting will make it easier to later understand how to implement more concrete data structures.

## Stacks and Queues 

`Queues` are a form of **abstract data structure** that follow a **FIFO** or "*first in first out*" principle (The first element added is the first one to be removed). Queues have specific actions associated with them:
- **enqueued** means that an item can join the line or queue.
- **dequeued** is when an item leaves the queue once it reaches the front of the line.

<br>

**Queues in code**:
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

`Stacks` have fundamentally different properties. They follow a **LIFO** or "*last in first out*" principle. Stacks too have specific actions associated with them:
-  **push** places something on top of a stack
- **Pop**  is removing something from the top of the stack.

<br>

**Stacks in code**:
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

**Let's explore this limited design in code**:
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

**Now let's see how we would implement the same idea using dynamically allocated memory**:
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

For the same reasons, (memory allocation overhead, manual element copying, potential memory waste and scalability issues), this is another **inefficient design** for the expansion of an **array**. A more efficient approach would be to use a **data structure** designed to handle **dynamic sizing**.

<br><br>

## Linked Lists

A **linked list** is one of the most powerful data structures in **C**. Linked lists are more **flexible** in using memory compared to arrays. They allow us to include values that are located at **different memory locations** (not contiguous) and allow us to **dynamically** grow and shrink the list as desired.

Remember these three primitives:
- `struct` is a user-defined data type that allows us to combine data items of different kind.

- `.` in *dot notation* allows us to access members of that structure variable.

- `*` operator is used to **declare** a pointer or **dereference** a pointer variable. 

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

**Structure of a linked list node in C**:
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

**Now that we have our node type defined, we can create a Linked List**:

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
> Before linking `list` to the new **node** and risking to **lose connection** to **node 1** (and potential memory leak), we have to link **node 1** to **node 2**.

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

**Let's implement these new ideas in code**:
```c
// Implements a list of numbers using a linked list
#include <stdio.h>
#include <stdlib.h>

// Define node structure
typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(int argc, char *argv[])
{
    // Declare pointer to be head of list
    node *list = NULL;

    // For each command line argument
    for (int i = 1; i < argc; i++)
    {
        // Convert c-l-arguments to int
        // with ASCI to integer function
        int number = atoi(argv[i]);

        // Allocate memory for first node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        // Dereference node pointers
        // Initialize number to number variable
        // Initialize next to NULL (prevent dangling pointers)
        n->number = number;
        n->next = NULL;

        // Prepend new node (add to beginning) to list
        // Link nodes to prevent orphaned memory
        n->next = list;
        list = n;
    }

    // To print whole list
    // Create a pointer that points to the list
    node *ptr = list;

    // So long that ptr points to something
    while (ptr != NULL)
    {
        // Print its member `number`
        printf("%i\n", ptr->number);
        // Set ptr to point to member `next`
        ptr = ptr->next;
    }

    // Free memory
    // Start ptr pointer at head of list
    ptr = list;
    // While we are not at the end of list
    while (ptr != NULL)
    {
        // Create pointer `next` to store next node
        node *next = ptr->next;
        // Release memory pointed at by `ptr`
        free(ptr);
        // update `ptr`to point to next node
        ptr = next;
    }
}
```
- First a `node structure` is declared and a **pointer** to a node called `list`, that will be the head of the list, is **initialized**. 

- The `for loop` is iterating through the user **inputs** at the command line (excluding filename), **converting** them to integers and **assigning** them to the member `number` of a node called `n`. Then the **node** is added to the `list`.

- To print the list, a new pointer `ptr` to the list is created and the `while loop` prints what `ptr` is pointing to and updates it to point to the `next` node.

- To avoid memory leaks, after the linked list completed its operation,  all the **memory** must **freed**. `ptr` is set to point to the beginning of the `list`, the `while loop` creates a pointer to store **next node**, releases current node, and updates `ptr` to next node. When `ptr` becomes `NULL`, all nodes have been **freed**.

<br><br>

The `upside` of **prepending** or *inserting* a new element at the **head** of a **linked list**, like implemented above, is the running time of `O(1)` **constant time complexity**. No matter how many nodes there are on the list, we are only **prepending** once.

**Searching** for a node in a **linked list** however, has a **linear time complexity** of `O(n)`. In the worst case, we may need to examine every element (`n`) in the list to find the target node.

<br>

The `downside` is that **more memory** is required to keep track of the list compared to arrays. This is because each **node** stores not only its **value** but also the **address of the next node**. Unlike arrays we cannot index into a linked list, and the list in the code above must be **linearly searched** for a target element and **binary search** would not be possible in this case. 

<br>

### An alternative to prepending nodes is appending or adding nodes at the end of the list.

```c
// Appends numbers to a linked list

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(int argc, char *argv[])
{
    // Memory for numbers
    node *list = NULL;

    // For each command-line argument
    for (int i = 1; i < argc; i++)
    {
        // Convert argument to int
        int number = atoi(argv[i]);

        // Allocate node for number
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->number = number;
        n->next = NULL;

        // If list is empty
        if (list == NULL)
        {
            // This node is the whole list
            list = n;
        }

        // If list has numbers already
        else
        {
            // Iterate over nodes in list
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                // If at end of list
                if (ptr->next == NULL)
                {
                    // Append node
                    ptr->next = n;
                    break;
                }
            }
        }
    }

    // Print numbers
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }

    // Free memory
    node *ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}
```
Notice that to **append** the list, we added the following lines of code:

- If list is **empty** `list == NULL`
    - Set head of the list `list` to new node `n`.

<br>

- If list is **not empty** (it has at least one existing node), we use a `for loop` to iterate through **every node** in the list:

    1. `node *ptr = list` Initialize a temporary pointer `ptr` to point to the beginning of the list (and traverse the list).

    2. `ptr != NULL` Loop continues as long as list has not ended.

    3. `ptr = ptr->next` After each iteration, *traversal* `ptr` updates to point to next node.

    - If `ptr->next == NULL` next node is empty (end of the list):

        - `ptr->next = n` update `ptr-next` to point to this new node `n`, effectively **appending** the node to the end of the list.

        - `break` the loop.

<br><br>

> [!NOTE]
> To **append** or *insert* a new element at the **end** of a **linked list**, like implemented above, we will need to go through our entire list before we can add the final node. This means the code will have a running time of `O(n)` **linear time complexity**. 

<br><br>

### We could also change the logic of our program to sort the list as items are added:

```c
// Implements a sorted list of numbers using a linked list

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(int argc, char *argv[])
{
    // Memory for numbers
    node *list = NULL;

    // For each command-line argument
    for (int i = 1; i < argc; i++)
    {
        // Convert argument to int
        int number = atoi(argv[i]);

        // Allocate node for number
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->number = number;
        n->next = NULL;

        // If list is empty
        if (list == NULL)
        {
            list = n;
        }

        // If number belongs at beginning of list
        else if (n->number < list->number)
        {
            n->next = list;
            list = n; 
        }

        // If number belongs later in list
        else
        {
            // Iterate over nodes in list
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                // If at end of list
                if (ptr->next == NULL)
                {
                    // Append node
                    ptr->next = n;
                    break;
                }

                // If in middle of list
                if (n->number < ptr->next->number)
                {
                    n->next = ptr->next;
                    ptr->next = n;
                    break;
                }
            }
        }
    }

    // Print numbers
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }

    // Free memory
    node *ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}
```
Notice that to **sort** the nodes as we append them, we need to determine **where** to insert them:

<br>

- If the list is **Empty** `list == NULL`:

    - Set **head** of the list `list` to new node `n`.

<br><br>

- If **new node** belongs at the beginning of the List `n->number < list->number` (*new node number* is **smaller** than *current node number*):

    - `n->next = list` Make new node `next` member point to `list` (connect them to prevent memory leak).
    - `list = n` Make `list` point to `n` effectively making **new node** **head** of the list.

<br><br>

- If new node belongs **later in the list**, use a `for loop` to iterate through **nodes** in the list:

    1. `node *ptr = list` Initialize a temporary pointer `ptr` to point to the beginning of the list (and traverse the list).
    2. `ptr != NULL` Loop continues as long as list has not ended.
    3. `ptr = ptr->next` After each iteration, *traversal* `ptr` updates to point to next node.

    *Option 1* - **Insert at the End** If `ptr->next == NULL` next node is empty (`ptr` points to the last node in the list):

    - `ptr->next = n` Append new node `n` after `ptr`.
    - `break` loop.

    *Option 2* -  **Insert in the Middle** If `n->number < ptr->next->number` *new node number* is **less than** the *next node number* after `ptr`:

    - `n->next = ptr->next` Set *next pointer* of **new node** to point to *next node* after `ptr` (`n` positioned to follow `ptr`).

    - `ptr->next = n` Update *next pointer* of current node `ptr` to directly point to `n`. This inserts `n` between `ptr` and what was before `ptr->next`.

    - `break` loop.

<br><br>

> [!NOTE]
> To **insert** a new element in a **specific order**, like implemented above, the running time will still be `O(n)` **linear time complexity**. In the worst case scenario, we will need to go through all current elements.

<br><br>

## Trees

**Trees** are non-linear data structures consisting of one **root node**, and a set of nodes organized in a tree structure that can have zero or more **child** nodes. One of the most common types of trees is **binary search tree**.

<br>

### Binary search trees

Let's imagine a sorted sequence of numbers:

```txt
| 1 | 2 | 3 | 4 | 5 | 6 | 7 |
```

<br>

Now imagine the *center value* as the **top** of a tree, with the lesser values on the left and the higher values on the right:
```txt
            | 4 |

    | 2 |           | 6 |

| 1 |   | 3 |   | 5 |   | 7 |
```
- In order to connect these nodes we can use **two pointers**, one for each child.
```txt
        4
      /   \
     2     6
    / \   / \
   1   3 5   7
  ```
<br>

This structure is a **recursive data structure**. Each node in a *binary search tree* could itself be viewed as the **root** of a smaller **subtree**, containing a left and right **child**, each of which are also **roots** of their respective **subtrees**.

<br><br>

**Structure of a binary search tree in C**:
```c
typedef struct node
{
    int number;
    struct *left;
    struct *right;
}node;
```
<br><br>

Let's implement a **function** that **searches** the tree and returns **True** if target number is found and **False** if not found:
```c
bool search(node *tree, int number)
{
    if (tree == NULL)
    {
        return false;
    }
    else if (number < tree->number)
    {
        return search(tree->left, number);
    }
    else if (number > tree->number)
    {
        return search(tree->right, number);
    }
    else if (number == tree->number)
    {
        return true;
    }
}
```
- `search()` takes two arguments: A **pointer** to the root of the tree `node *tree`, and the **target** number `int number`.

- If the **tree node** is NULL `if (tree == NULL)`, the function returns `false` (number not found). This is the **base case** for the *recursion*.

- If number is **smaller** than the *root* `number < tree->number`:
    - Recursively search the **left** subtree `search(tree->left, number)`

- If number is **larger** than the *root* `number > tree->number`:
    - Recursively search the **right** subtree `search(tree->right, number)`

- If number is **equal** to the **root** `number == tree->number`:
    - `return true;` (found)    

<br><br>

> [!NOTE]
> To search for a specific element in this **binary search tree**, we will traverse from the **root**, and each step of the search process **halves** the tree's size. Given the balanced nature of the tree, the running time for search operations is of `O(log n)` **logarithmic time complexity**.<br>
However, in the case that the tree is not balanced, a **degenerate tree** (linked list), running time can degrade to `O(n)`.

<br><br>

## Dictionaries

**Dictionaries** are *unordered* data structures composed by key-value pairs, where each unique **key** is associated with a specific **value**. Dictionaries allow for the ultimate access efficiency through **hashing** offering a **constant time complexity** `O(1)`.

<br>

![time complexity](../img/cs50Week5Slide151.png)

<br><br>

## Hashing and Hash Tables

**Hashing** is the process of converting a **key** into a numerical index using a **hash function**, which determines the position in an array (**hash table**) where the associated **value** is stored.

A **hash function** is an algorithm that takes in an **input key** and returns an **integer** representing the array **index** in which the item should be stored.

**Hash tables** are combinations of **arrays** (for direct indexing) and **linked lists** to handle collisions when multiple keys hash to the same index. Hash tables can be thought of as **array of pointers to nodes**.

<br>

**Let's visualize a hash table**:
```txt
A | |
B | | -> | Birdo    | |
C | |
D | | -> | Daisy    | |
E | |
F | |
G | | -> | Goomba   | |
H | |
I | | -> | Isabelle | |
J | |
K | | -> | King Boo | |
L | | -> | Luigi    |--> | Lakitu   |--> | Link     | |
M | | -> | Mario    | |
N | |
O | |
P | | -> | Peach    | |
Q | |
R | | -> | Rosalina | |
S | | -> | Shy Guy  | |
T | | -> | Toad     | |
U | |
V | |
W | | -> | Wario    | |
X | |
Y | | -> | Yoshi    | |
Z | | -> | Zelda    | |
```
- This is an **array** of *size 26* that is assigned each value of the **alphabet**.

- At each location of the array, a pointer to a **liked list** is stored to track the values stored.

- The **linked lists** resolve the **collisions** than could happen when adding a value to an index that is already storing something by **appending** the **new value** to the end of the list.

<br>

The running time of the **hash table** above is `O(n)` **linear time complexity** because in the *worst case scenario*, where the value we are looking for is stored in an **index** with **multiple values**, we have to go through the `n` elements of the list to find it.

<br><br>

**Structure of the hash table in C**:
```c
typedef struct node
{
    char *name;
    char *number;
    struct node *next;
}node;
```
```c
node *table[26];
```

<br><br>

There is a way to reduce the **collisions** and optimize the running time by better programming the **hash table** and **hash algorithm**:
```txt
    | |
    | | 
    | |
Laa | | 
Lab | |
Lac | |
Lad | | 
Lae | |
Laf | | 
Lag | |
Lah | | 
Lai | | 
Laj | |
Lak | | -> | Lakitu   | |
... | |
Lim | |
Lin | | -> | Link     | |
Lio | | 
... | | 
Luh | | 
Lui | | -> | Luigi    | |
Luj | |
    | |
    | |
    | | 
    | | 
```
> [!NOTE]
> By expanding the **array**, we eliminated the potential for **collisions** and the need for **link lists**, allowing us to go back to a **constant time complexity** `O(1)`. However, the amount of **memory used** to achieve this performance is significantly **higher** (26^3).

<br><br>

**Hash algorithm example in C**:
```txt
Luigi -> | Hash function | -> 11
```
```c
#include <ctype.h>

unsigned int hash(const char *word)
{
    return toupper(word[0] - 'A');
}
```
- `hash()` function takes a constant variable of type **string** `char *word` as argument and returns an unsigned (positive) **integer**.

- `toupper(word[0] - 'A')` takes the **first letter** of the word `word[0]`, **capitalizes** it and **subtracts** the ASCI value `- 'A'`, effectively **mapping** the word to the right **index**.

<br><br>

Working with **hash tables** we have to make the decision of using **more memory** to have a large **hash table** and potentially *reducing search time* or using **less memory** and potentially *increasing search time*.

<br><br>

## Tries

**Trie** data structures are a combination of **trees** and **arrays**. Tries are always searchable in **constant time** `O(1)`. However, they tend to take up **large amounts of memory**. In a **trie**, every **node** is an **array** and every **index** in that array, generally represents a **letter** of the alphabet.

![tries](../img/cs50Week5Slide207.png)

- The **root node** is an **array** of size 26 locations, all initially **null**.

- To **insert** words into a **trie**, we hash again and again, creating one **array** for every **letter** in the word.

- To store `Toad` we create a node in the index for `T`, node `T` points to location for `O`, where we create a second node and so forth until `D`.

- At the last letter `D`, a special marker is used to denote the **end** of the string.

<br><br>

> [!NOTE]
> Notice that we need 26 x 4 = `104` **nodes** just to store **Toad**.

<br><br>

**Structure of the trie in C**:
```c
typedef struct node
{
    struct node *children[26];
    char *number;
}node;
```
```c
node *trie;
```
- Every **node** in this trie is redefined as an **array of size 26** `children[26]`. This structure allows for branching to further letters in a word.

- In each **node** there is room for a **string** `char *number` holding a phone number.

<br><br>

Searching, inserting and deleting from a **trie** depends on the **length** of the **string** being processed. For each **character** in the string, we need to either access an existing node or create a new node. The operation involves a **constant** amount of work for each character. The **downside** of this structure is the huge amount of **resources** required to use it.
