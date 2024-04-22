# CS50x Section 5 - Data Structures

**Data structures** are fundamental constructs in computer science that organize, manage and store data efficiently. Common operations on data structures include **insertion** (adding new elements), **deletion** (removing existing elements), and **search** (finding an element within the structure). 

<br>

## Linked lists

**Linked lists** are data structures consisting of a chain of **nodes** that are connected sequentially via **pointers**.

```txt
list  ------->  | "Hey!" |    
                |        |  ->   | "Hi!" |   
                                 | NULL  | 
```
<br>

### Nodes

Nodes are fundamental **elements** in various data structures, such as linked lists and trees, containing their *own data*, and *meta data* in the form of a **pointer** to the next **node**, forming the structure's interconnected framework.

```c
typedef struct node
{
  char *phrase;
  struct node *next;
}
node;
```
```txt
  node

| "Hi!" | phrase
| 0x123 | next

```
- `struct node` We are defining a **structure** called **node**.

- `string phrase` The structure will contain data of type **string** called **phrase**.

- `node *next` The structure will also contain a **pointer** called **next** that can store the **address** of another **node**.

- `typedef node` Creates an alias called **node** to refer to this new structure.

<br><br>

### Creating a Linked List

**1.** Define our `list` as a **pointer** to a **node** and **initialize** its value to **NULL** (so it does not point to a random memory location).

```c
node *list = NULL;
``` 
```txt
   list
|        |
```
<br>

**2.** Create the first **node** by dynamically allocating enough **memory** for one node and store its **address** in pointer variable `n`.

```c
node *n = malloc(sizeof(node));
```
```txt
   list
|        |  

                        
    n 
|        | ---------->  |        | 
                        |        | 
```
<br>

**3.** Define `phrase` member of the node and assign to it the value of string `Hi!`.

```c
// node *n = malloc(sizeof(node));

n->phrase = "Hi!";
```
```txt
   list
|        |  

                        
    n 
|        | ---------->  |  "Hi!" | 
                        |        | 
```
<br>

**4.** Define `next` member of the node and assign to it the value of `NULL`, to avoid *dangling pointers*.

```c
// node *n = malloc(sizeof(node));
// n->phrase = "Hi!";

n->next = NULL;
```
```txt
   list
|        |  

                        
    n 
|        | ---------->  | "Hi!"  | 
                        |  NULL  | 
```
<br>

**5.** Link previously defined `list` pointer to new pointer `n`, effectively setting `list` as **head** of our linked list.

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
|        | ------------>  | "Hi!"  | 
                          |  NULL  |
```
<br>

### Inserting Nodes

**6.** Create a new **node** by allocating **memory** for one node and store its **address** in pointer variable `n`. This will switch pointer `n` from pointing to *previous node* to this **new node**.

```c
node *n = malloc(sizeof(node));
```
```txt
   list 
|        | ----------->  | "Hi!"  | 
                         |  NULL  |  


    n 
|        | ---------->   |        | 
                         |        | 
```
<br>

**7.** Define `phrase` member of the new node and assign to it the value of string `Hey!`.

```c
// node *n = malloc(sizeof(node));

n->phrase = "Hey!";
```
```txt
   list 
|        | ----------->  | "Hi!"  | 
                         |  NULL  |  


    n 
|        | ---------->   | "Hey!" | 
                         |        | 
```
<br>

**8.** Define `next` member of the new node and make it point to `list` effectively **connecting** the new node to the chain.

```c
// node *n = malloc(sizeof(node));
// n->phrase = "Hey!";

n->next = list;
```
```txt
                                                   list 
                                                |        |
                                                     |
                                                     |
                                                     |
     n                                               v
|        | ---------->  | "Hey!" |              
                        |        |    ----------> | "Hi!" | 
                                                  |       | 
```
<br>

**9.** Now that both nodes are *connected*, update `list` to point at new node `n`, effectively setting `list` as **head** of our linked list.

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
|        | ---------->  | "Hey!" |              
                        |        |    ----------> | "Hi!" | 
                                                  |       | 
```
<br>

### Deallocating memory used by Linked List

After using **memory** allocated with `malloc()` for our **linked list**, we need to **release** it to ensure no **memory leakage** and maintaining stable system operation. 

Let's attempt to **free** the **linked list** by only releasing the **head** of the list (`list`):
```c
free(list);
```
```txt
   list    ---------->  |  free  |              
                        |  free  |                | "Hi!" | 
                                                  |       | 
```

> [!CAUTION]
> Notice that we only **freed** the first node. The **second node** was not explicitly freed and **still occupies memory**, which is no longer accessible or useful since the link to this node is lost.This leads to a **memory leak** and potentially **resource exhaustion**.

<br><br>

### Proper Technique for Releasing Memory in Linked Lists

<br>

**1.** Create **temporary** pointer variable `ptr` to represent the **next element** in the linked list.

```c
node *ptr = list->next;

free(list);
```
```txt
                                                     ptr
                                                      |
                                                      |
                                                      v
   list    ---------->  |  free  |                   
                        |  free  |                | "Hi!" | 
                                                  |       | 
```
- The temporary pointer `ptr` now points to the **second node** and allows us to *reference* it to **access** (even if we free list) and **release** the memory used by the second node.

<br>

**2.** Now that we regained access to second node, update `list` to point at `ptr`, so that we can *reference* the **second node** again.

```c
// node *ptr = list->next;

list = ptr;
```
```txt
                           ptr
                            |
                            |
                            v
   list    ---------->  | "Hi!" | 
                        |       | 
```
<br>

**3.** Now that `list` has direct access to **second node**, we update `ptr` to point to the **following node**, making sure that before we *free* current pointer, we have access with `ptr` to the **following node**.

```c
// node *ptr = list->next;
// list = ptr;

ptr = list->next;
```
```txt
  ptr   ---------->  NULL


  list  ----------> | "Hi!" | 
                    |       | 
```
- In this case, the second node was the **last** one in the list, `ptr` will point to `NULL`, which means that we reached the **End** or ouf linked list.

<br>

**4.** We can now safely proceed to **free** `list`.

```c
// node *ptr = list->next;
// list = ptr;
// ptr = list->next;

free(list);
```
```txt
  list  ----------> |  free  | 
                    |  free  | 
```
<br>

**5.** As an extra measure of safety, we update `list` to point to `ptr`, which is currently `NULL`. This step ensures all pointers in the linked list are set to **NULL** and **all memory** is **released** back to the system.

```c
// node *ptr = list->next;
// list = ptr;
// ptr = list->next;
// free(list);

list = ptr;
```
```txt
  list  ----------> 
```
<br><br>

### Linked lists in C 

Let's implement code to add a **node** to the linked list and complete the function `unload()` to **free** memory used.

```c
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    string phrase;
    struct node *next;
}
node;

#define LIST_SIZE 2

bool unload(node *list);
void visualizer(node *list);

int main(void)
{
    node *list = NULL;

    // Add items to list
    for (int i = 0; i < LIST_SIZE; i++)
    {
        string phrase = get_string("Enter a new phrase: ");

        // TODO: add phrase to new node in list
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }

        n->phrase = phrase;
        n->next = NULL;

        n->next = list;
        list = n;

        // Visualize list after adding a node.
        visualizer(list);
    }

    // Free all memory used
    if (!unload(list))
    {
        printf("Error freeing the list.\n");
        return 1;
    }

    printf("Freed the list.\n");
    return 0;
}

bool unload(node *list)
{
    // TODO: Free all allocated nodes
    node *ptr = list;

    while (ptr != NULL)
    {
        ptr = list->next;
        free(list);
        list = ptr;
    }

    return true;
}

void visualizer(node *list)
{
    printf("\n+-- List Visualizer --+\n\n");
    while (list != NULL)
    {
        printf("Location %p\nPhrase: \"%s\"\nNext: %p\n\n", list, list->phrase, list->next);
        list = list->next;
    }
    printf("+---------------------+\n\n");
}
```
<br><br>

## Hash Tables

**Hash tables** or **Dictionaries** are data structures that store **key-value pairs** and provides **fast** data retrieval by using a **hash function** to compute an **index** into an **array** of **buckets**, where we can **directly** find the target value. Hash tables can be thought of as **arrays of linked lists**.

```txt
|..||...|
| 7|| H | -> | "Hey!" | -> | "Hello!" |
| 8|| I |
| 9|| J | 
|10|| K |
|11|| L | -> | "Lo there!" |
|..||...|
```
```txt
"Hey!" -> | Hash Function | -> 7
```
<br>

### Hash tables in C

Let's implement code to complete the `hash()` function to return a number, 0-25, depending on the first character in the word (representing where in the table it should be stored).

```c
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    string phrase;
    struct node *next;
}
node;

node *table[26];

int hash(string phrase);
bool unload(node *list);
void visualizer(node *list);

int main(void)
{
    // Add items
    for (int i = 0; i < 3; i++)
    {
        string phrase = get_string("Enter a new phrase: ");

        // Find phrase bucket
        int bucket = hash(phrase);
        printf("%s hashes to %i\n", phrase, bucket);
    }
}

// TODO: return the correct bucket for a given phrase
int hash(string phrase)
{
    int bucket = toupper(phrase[0])- 'A';
    return bucket;
}
```
<br>

> [!NOTE]
> A good **hash function**: <br>
> Always gives you the same value for the same input.<br>
> Produces an even distribution across buckets.<br>
> Uses all buckets.

<br><br>

## Tries

**Tries**, also known as a **prefix trees**, are a **tree-like** data structure that efficiently stores and retrieves strings or sequences, where each **node** represents a common **prefix** shared by its **child nodes**.

```txt
        H
        |
        E
      /   \
     L     Y
    / \   
   L   P    
   |
   O
```

<br><br>

## Trade-offs

When deciding on the **data structure** to work with, we have to consider some **trade-offs**, particularly between **memory usage** and **access speed**. These considerations include how much memory the structure is using versus how fast operations like insertion, deletion, and search can be executed, impacting overall **system performance** and **efficiency**.

<br><br>

## Inheritance Problem Set

```txt
        Root
       person  ->   alleles
                   [ 0 , 1 ]
                   parents    --->  Gen 1
                   [*p , *p]

                    /     \
                   /       \
            alleles         alleles
            [AO, BO]        [AB, BO]
            parents         parents    --->  Gen 2
            [*p, *p]        [*p, *p]

            /     \        /     \
           /       \      /       \
       alleles alleles   alleles   alleles
       [A, O]  [B , O]   [A , B]   [B , O] 
       parents parents   parents   parents   --->  Gen 3
       [*p,*p] [*p,*p]   [*p, *p]  [*p, *p]

       /    \  /     \  /     \    /     \
      /      \/       \/       \  /       \
    NULL     NULL    NULL     NULL       NULL
```
<br>

```c

```

Section 5 minute 00:46:00
