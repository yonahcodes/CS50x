# Singly-Linked Lists

In the course we started by learning about **structs** and **arrays** for organizing collections of similar values. **Structs** allow us to group together different types of data under a single name. **Arrays** are great for element *lookup* but **inserting** a new element, unless it is at the very end of the array, is quite **costly**. Arrays also suffer from great **inflexibility** if we need to expand them.

Through use of **pointers**, **dynamic memory allocation** and **structs**, we can develop a new kind of data structure that gives us the ability to **grow** and **shrink** a collection of similar values to fit our needs.

<br>

**Singly-linked lists** consist of a series of elements called **nodes** linked together in one direction from the **first** node (**head**) to the **last** node (**tail**), where each node is a **struct** with two members:

- **Data** of some type (int, char, float...)
- Metadata as a **pointer** to another node of the same type. 

<br><br>

## Singly-Linked Lists in C

```c
typedef struct sllist
{
    TYPE val;
    struct sllist *next;
}
sllnode;
```
> Notice that we first defined a **temporary** name for the structure `sllist` to be able to use it inside the definition. When we officially name the struct in the last line `sllnode`, this name takes over.

<br>

In order to work with **linked lists** effectively, there are a number of **operations** that we need to understand:
1. **Create** a linked list when it doesn't already exist.
2. **Search** through a linked list to find an element.
3. **Insert** a *new node* into the linked list.
4. **Delete** an entire linked list.
5. **Delete** a *single element* from a linked list.

<br>

### 1. Create a Linked List

```c
// Function prototype
sllnode* create(TYPE val);
```
- The function `create()` takes an arbitrary **value** of some **type** `TYPE val` as an **argument** and returns a **pointer** to a singly-linked list node `sllnode*`. 

<br>

```c
sllnode* create(TYPE val)
{
    // Dynamically allocate memory for a new node
    sllnode* new_node = malloc(sizeof(sllnode));

    // Error check for available memory
    if (new_node == NULL)
    {
        return NULL;
    }

    // Initialize node's val field
    new_node->val = val;

    // Initialize node's next field 
    new_node->next = NULL;

    // Return a pointer to the newly created sllnode
    return new_node;
}
```
<br>

**Example**:

```c
sllnode* new = create(6);
```
```txt
new_node ------> |   6   |
                 |       |
```

<br><br>

### 2. Search Through a Linked List

```c
// Function prototype
bool find(sllnode* head, TYPE val);
```
- The function `find()` searches the linked list for a specific value and returns **True** if a value was found and **False** if no value exists.

- The function takes two arguments: a **pointer** to the first element of the list `sllnode* head` and the specific value we want to find `TYPE val`.

<br>

```c
bool find(sllnode* head, Type val)
{
    // Create a traversal pointer pointing to the list's head
    sllnode* current = head;

    // Search the list as long as it has values
    while (current != NULL)
    {
        // If the current node's val is what we are looking for, report success
        if (current->val == val)
        {
            return true;
        }
        // If not set the traversal pointer to the next pointer in the list and repeat
        current = current->next;
    }

    // If we reached the end of the list and no value was found, report failure
    return false;
}
```

<br>

**Example**:
```c
bool exists = find(list, 6);
```
```txt
    list
     |
     |
     v
                                                trav
|   2   |                                        |
|       | ---> |   3   |                         v
               |       | ---> |   5   |          
                              |       | ---> |   6   |
                                             |       | ---> |   8   |
                                                            |  NULL |
```
- This function will use the **traversal pointer** to perform a linear search of the preexisting linked list and return `true` when it gets to the **node** that stores the value of `6`.

<br><br>

If the value does not exist in the linked list:
```c
bool exists = find(list, 6);
```
```txt
    list
     |
     |
     v

|   2   |                                                      trav
|       | ---> |   7   |                                        |
               |       | ---> |   5   |                         v
                              |       | ---> |   3   |
                                             |       | ---> |   8   |
                                                            |  NULL |
```
- This function will use the **traversal pointer** to perform a linear search of the preexisting linked list and return `false` when it gets to the last **node** that points to `NULL`.

<br><br>

### 3. Insert a New Node into the Linked List

```c
// Function prototype
sllnode* insert(sllnode* head, TYPE val);
```
- The function `insert()` adds a node to the linked list and returns a **pointer** to the **new head** of the linked list.

- The function takes two arguments: a **pointer** to the first element of the list `sllnode* head` and the specific value we want to add to the list `TYPE val`.

<br>

```c
sllnode* insert(sllnode* head, TYPE val)
{
    // Dynamically allocate space for a new sllnode
    sllnode* new_node = malloc(sizeof(sllnode));

    // Check to make sure we didn't run out of memory
    if (new_node == NULL)
    {
        return NULL;
    }

    // Populate and insert the node at the beginning of the linked list (For constant time complexity)
    // Set the value of the new node
    new_node->val = val;
    // Connect new node to the list (avoid orphaned node)
    new_node->next = head;
    // Update head of the list to point to new node (setting it as head of the list)
    head = new_node;

    // Return a pointer to the new head of the linked list
    return new_node;
}
```
> It is crucial to **connect** the new node to the list BEFORE setting it as the head of the list to avoid **dangling** pointers and **memory leaks**.

<br>

**Example**:
```c
sllnode* insert(list, 12);
```
```txt
 new_node         list
    |              |
    |              |
    v              v
         
|  12   |       |  15   |                                           
|       |       |       | ---> |   9   |                                        
                                |       | ---> |  13   |                         
                                               |       | ---> |  10   |
                                                              |  NULL |
```
```txt
   list        
    |              
    |              
    v              
|  12   | 
|       | --->  |  15   |                                           
                |       | ---> |   9   |                                        
                               |       | ---> |  13   |                         
                                              |       | ---> |  10   |
                                                             |  NULL |
```
<br><br>

### 4. Delete an entire Linked List

```c
// Function prototype
void destroy(sllnode* head);
```
- The function `destroy()` **frees** all the memory used by the linked list.

- The function takes one argument: The **pointer** to the first element of the list `sllnode* head`.

<br>

```c
void destroy(sllnode* head)
{
    // If reaching a null pointer (end of the list), stop
    if (head == NULL)
    {
        return;
    }

    // Delete the rest of the list (recursively delete next nodes first)
    destroy(head->next);

    // Free the current node
    free(head);
}
```
> Notice that `head == NULL` is the **base case** for the recursion. Also we do not want to free the **head** of the list first because we will loose access to the rest of the nodes which will result in a **memory leak**.

<br><br>

### 5. Delete a Single Element from a Linked List

Deleting a **single element** from a singly linked list is a complex process. We need to find the node, access the previous node (singly linked list do not provide an easy way to backtrack to a previous node), adjust the pointers to maintain list integrity and manage the memory. 

This makes the operation **error-prone** and **time-consuming**. In contrast, a **doubly linked list** has pointers to both the **next** and the **previous** nodes, simplifying and speeding up the deletion process. 
