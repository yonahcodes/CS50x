# CS50x Section 5 - Data Structures

**Data structures** are fundamental constructs in computer science that organize, manage and store data efficiently. Common operations on data structures include **insertion** (adding new elements), **deletion** (removing existing elements), and **search** (finding an element within the structure). 

<br>

## Linked list

**Linked lists** are a data structure consisting of a chain of **nodes** that are connected sequentially via **pointers**.

```txt
list  ------->  | "Hey!" |    
                |        |  ->   | "Hi!" |   
                                 | NULL  | 
```
<br>

## Hash Tables

**Hash tables** are a data structure that stores **key-value pairs** and provides fast data retrieval by using a **hash function** to compute an **index** into an **array** of slots, where we can find the target value. Hash tables can be thought of as **arrays of linked lists**.

```txt
|...|
| H | -> | "Hey!" | -> | "Hello!" |
| I |
| J | 
| K |
| L | -> | "Lo there!" |
|...|
```
<br>

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

<br>

## Trade-offs

When deciding on the **data structure** to work with, we have to consider some **trade-offs**, particularly between **memory usage** and **access speed**. These considerations include how much memory the structure is using versus how fast operations like insertion, deletion, and search can be executed, impacting overall **system performance** and **efficiency**.

<br>

## Nodes

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

## Creating a Linked List

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

## Inserting Nodes

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

## Deallocating memory used by Linked List

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
<br>

