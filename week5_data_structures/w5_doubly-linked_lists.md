# Doubly-Linked Lists

**Singly-linked lists** really extend our ability to collect and organize data, but they suffer from a crucial **limitation**, they only allow **unidirectional** navigation. This limitation complicates operations that require access to previous node, like deleting a node. 

A **doubly-linked list**, by contrast, allows us to move **forward** and **backward** through the list by adding one extra pointer to our struct definition. This **bidirectional** traversal capability simplifies operations.

<br>

## Doubly-Linked Lists in C

```c
typedef struct dllist
{
    TYPE val;
    struct dllist* prev;
    struct dllist* next;
}
dllnode;
```
> Adding the `prev` previous pointer in doubly-linked lists does **increase the memory overhead** per node, but **enhances flexibility** for operations involving backward traversal and manipulation.

<br>

In order to work with **doubly-linked lists** effectively, like *singly-linked lists*, we need to understand a number of **operations**:

1. **Create** a linked list when it doesn't already exist.
2. **Search** through a linked list to find an element.
3. **Insert** a *new node* into the linked list.
4. **Delete** a *single element* from a linked list.
5. **Delete** an entire linked list.

<br>

Most operations on linked lists, whether singly or doubly-linked, share similar steps. **Deletion** and **insertion** of nodes have differences depending on the type of linked list. The **extra pointer** in doubly-linked lists typically makes these operations mode **straightforward**.

<br><br>

### Inserting a New Node in a Doubly-Linked List

```c
// Function Prototype
dllnode* insert(dllnode* head, TYPE val);
```
- The `insert()` function takes the head of the list `head` and a value of some type `TYPE val` as arguments and returns a pointer to a node `dllnode*`, which will be the new head of the list. 

<br>

```c
dllnode* insert(dllnode* head, TYPE val)
{
    // Dynamically allocate space for a new node dllnode
    dllnode* new_node = malloc(sizeof(dllnode));
    // Error check memory available
    if (new_node == NULL)
    {
        return NULL;
    }

    // Populate an insert the node at the beginning of the linked list
    new_node->val = val;
    new_node->prev = NULL;
    new_node->next = head;

    // Fix the prev pointer of the old head of the linked list
    if (head != NULL)
    {
        head->prev = new_node;
    }

    // Return a pointer to the new head of the linked list
    return new_node;
}
```
<br><br>

**Example:**

```c
list = insert(list, 12);
```
<br>

**1.** Dynamically **allocate memory** for the new node `dllnode* new_node = malloc(sizeof(dllnode));`
```txt
 new_node          list
    |               |
    v               v
|       |       |  NULL |     
|       |       |  15   | <---  |  prv  |      
|       |       |  nxt  | --->  |   9   | <---  |  prv  |      
                                |  nxt  | --->  |  13   | <---  |  prv  |
                                                |  nxt  | --->  |  10   | 
                                                                |  NULL |   
```

**2.** **Populate** new node values `new_node->val = 12;` / `new_node->prev = NULL;` / `new_node->next = list;`
```txt
 new_node
    |              list
    v               |
|  NULL |           v
|  12   |       |  NULL |     
|  nxt  | --->  |  15   | <---  |  prv  |      
                |  nxt  | --->  |   9   | <---  |  prv  |      
                                |  nxt  | --->  |  13   | <---  |  prv  |
                                                |  nxt  | --->  |  10   | 
                                                                |  NULL |   
```

**3.** Update **prev pointer** of old **head** to point to new node `list->prev = new_node;`
```txt
 new_node
    |              list
    v               |
|  NULL |           v
|  12   | <---  |  prv  |     
|  nxt  | --->  |  15   | <---  |  prv  |      
                |  nxt  | --->  |   9   | <---  |  prv  |      
                                |  nxt  | --->  |  13   | <---  |  prv  |
                                                |  nxt  | --->  |  10   | 
                                                                |  NULL |   
```

**4.** Set **new node** as **head** of the list. This step is done in the **function call** `list = insert(list, 12);`
```txt
   list
    |             
    v               
|  NULL |                                           
|  12   | <---  |  prv  |                           
|  nxt  | --->  |  15   | <---  |  prv  |           
                |  nxt  | --->  |   9   | <---  |  prv  |      
                                |  nxt  | --->  |  13   | <---  |  prv  |
                                                |  nxt  | --->  |  10   | 
                                                                |  NULL |   
```

<br><br>

### Deleting a Single Node from a Doubly-Linked List

```c
// Function Prototype
void delete(dllnode* target);
```
- The function `delete()` takes as an argument the exact node that needs to be deleted `dllnode* target`. It is assumed that another function took care of locating it beforehand.

<br>

```c
void delete(dllnode* target)
{
    if (target == NULL)
    {
        return;
    }

    // Fix the pointers of the surrounding nodes to "skip over" target
    if (target->prev != NULL)
    {
        target->prev->next = target->next;
    }
    
    if (target->next != NULL)
    {
        target->next->prev = target->prev;
    }
    
    // Free target
    free(target);
}
```
<br><br>

**Example**:
```c
delete(x);
```
<br>

**0.** Original list 
```txt
   list
    |             
    v                                               X
|  NULL |                                           |
|  12   | <---  |  prv  |                           v   
|  nxt  | --->  |  15   | <---  |  prv  |           
                |  nxt  | --->  |   9   | <---  |  prv  |      
                                |  nxt  | --->  |  13   | <---  |  prv  |
                                                |  nxt  | --->  |  10   | 
                                                                |  NULL |   
```
<br>

**1.** Change **surrounding pointers** to skip over target pointer `target->prev->next = target->next;` / `target-next->prev = target->prev;` 
```txt
   list
    |             
    v                                               
|  NULL |                                           
|  12   | <---  |  prv  |                     --------------
|  nxt  | --->  |  15   | <---  |  prv  |    |              |
                |  nxt  | --->  |   9   | <--   |       |   |  
                                |  nxt  | ---|  |  13   |   --- |  prv  |
                                             |  |       |  -->  |  10   | 
                                             |             |    |  NULL |   
                                              --------------

```
**2.** **Free** target node `free(x)`
```txt
   list
    |             
    v                                               
|  NULL |                                           
|  12   | <---  |  prv  |                     --------------
|  nxt  | --->  |  15   | <---  |  prv  |    |              |
                |  nxt  | --->  |   9   | <--               |  
                                |  nxt  | ---|              --- |  prv  |
                                             |             -->  |  10   | 
                                             |             |    |  NULL |   
                                              --------------

```
```txt
   list
    |             
    v                                               
|  NULL |                                           
|  12   | <---  |  prv  |                    
|  nxt  | --->  |  15   | <---  |  prv  |    
                |  nxt  | --->  |   9   | <---  |  prv  |
                                |  nxt  | --->  |  10   |
                                                |  NULL | 
```
<br>

**Linked lists**, of both **singly** and **doubly-linked** varieties, support very **efficient** insertion and deletion of elements. These operations can be done in **constant time**. However, to **access** an element from the list, we have to search the list one element at a time starting from one end, resulting in **linear time complexity**.
