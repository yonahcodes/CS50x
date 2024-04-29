# Queues

A **queue** is a special type of structure than can be used to organize data. This data structure follows the **first in, first out** (**FIFO**) principle and is commonly implemented as an **array** or a **linked list**.

<br>

There are two operations that may legally be performed on a **queue**:

- **Enqueue**: **Add** a new element to the **end** of the queue.

- **Dequeue**: **Remove** the oldest element from the **front** of the queue.

<br>

## Array-based Implementation

```c
typedef struct _queue
{
    TYPE array[CAPACITY];
    int front;
    int size;
}
queue;
```
- Define a new structure `typedef struct` called `_queue`
- Composed by an **array** of some **capacity** and **type** `TYPE array[CAPACITY];`
- An **integer** called `front` to keep track of which element to **dequeue**.
- An **integer** called `size` to keep track of the number of elements **size** currently in the queue.

<br><br>

```c
// Declare a queue
queue q;

// Initialize variables
q.front = 0;
q.size = 0;
```
```txt
 ---------------------------------------
|   |   |   |   |   |   |   |   |   |   | ---> Array of 10 integers
 ---------------------------------------
| 0 |--> front of queue
 --
| 0 |--> size of queue
 --
```
<br>

### ENQUEUE - Add an element to the end of the queue

```c
// Function prototype
void enqueue(queue *q, TYPE data);
```
- The function `enqueue()` **adds** a new element to the queue.

- The function takes two arguments: a **pointer** to the queue `queue *q` and **data** to be added `TYPE data`.

<br>

```c
void enqueue(queue *q, TYPE data)
{
    // Check if queue is full
    if (q->size == CAPACITY)
    {
        printf("Queue is full\n");
        return;
    }

    // Calculate the index at which to add the new data
    int end = (q->font + q->size) % CAPACITY;

    // Add the data to the calculated index
    q->array[end] = data;

    // Change the size of the queue
    q->size++;
}
``` 
- The `end` index is calculated by adding the current `size` to the `front` index and then taking the **modulus** with `CAPACITY` to ensure that the index **wraps around** if it reaches the **end** of the array.

<br>

- The **modulus operation** `%` computes the remainder of division. If the sum of `front` and `size` exceeds `CAPACITY`, we apply **modulus** with `CAPACITY` (`(front + size) % CAPACITY`) to find how many times the divisor `CAPACITY` can fit into the dividend `front + size` and then take the **remainder**.

- **Modulus example** `front = 8`, `size = 3`, `CAPACITY = 10`.  ->  `(8 + 3) % 10`  ->  `11 \ 10` = `1` with a remainder of `1`  ->  `11 % 10 = 1`

- If the sum is < `CAPACITY` we simply use the sum as the index  -> `index[front + size]` 

<br><br>

**Example:**
```c
enqueue(&q, 28);
```
```txt
 ---------------------------------------
| 28 |   |   |   |   |   |   |   |   |   | ---> Array
 ---------------------------------------
| 0 |--> front
 --
| 1 |--> size
 --
```
- Notice that we passed the **address** of the queue `&q` to the function.  

- Since initially the `q` is **empty**, `front` is `0` and `size` is `0`, we place the data `28` in `index[0]`.

- Then **increment** the `size` to `1` (number of elements currently in the queue).

- `front` remains `0`, we always want to place new elements added at the **first** array location `index[0]` (Key to maintain **FIFO**).

<br><br>

```c
// enqueue(&q, 28);

enqueue(&q, 33);
```
```txt
 -----------------------------------------
| 28 | 33 |   |   |   |   |   |   |   |   | ---> Array
 -----------------------------------------
| 0 |--> front
 --
| 2 |--> size
 --
```
- Determine where to place new data `33`  ->  `(q->font + q->size) % CAPACITY`  ->  `(0 + 1) % 10` = `1`  ->  Place `33` in array `index[1]`.

- **Increment** size  ->  `size + 1` = `2` (`q` now holds **2** elements)

- `front` remains unchanged `0` (**FIFO** principle)

<br><br>

```c
// enqueue(&q, 28);
// enqueue(&q, 33);

enqueue(&q, 19);
```
```txt
 -----------------------------------------
| 28 | 33 | 19 |   |   |   |   |   |   |   | ---> Array
 -----------------------------------------
| 0 |--> front
 --
| 3 |--> size
 --
```
- Determine where to place new data `19`  ->  `(q->font + q->size) % CAPACITY`  ->  `(0 + 2) % 10` = `2`  ->  Place `19` in array `index[2]`.

- **Increment** size  ->  `size + 1` = `3` (`q` now holds **3** elements)

- `front` remains unchanged `0` (**FIFO** principle)

<br><br>

### DEQUEUE - Remove most recent element from the front of the queue

```c
// Function prototype
TYPE dequeue(queue *q);
```
- The function `dequeue()` **removes** most recent element from the front of the queue.

- The function takes **one** argument: a **pointer** to the queue `queue *q` and returns the **element that was removed** from the queue.

<br>

```c
TYPE dequeue(queue *q)
{
    // Check if queue is empty
    if (q->size == 0)
    {
        printf("Queue is empty\n");
        return 1;
    }

    // Retrieve the value at the from of the queue
    TYPE removed = q->array[q->front];

    // Change the location of the front of the queue
    q->front = (q->front + 1) % CAPACITY;

    // Decrease the size of the queue
    q->size--;

    // Return the value that was removed from the queue
    return removed;
}
```
- Retrieve the **element to be dequeued** by accessing the `front` index of the queue and **storing** its value in a variable `TYPE removed` (to be returned if successfully removed).

- Increase `front` index to point to **next element** and apply modulo `%` with `CAPACITY` to ensure that if `front` reaches the **end** of the array, it **wraps around** to the beginning.

- Decrease `size` of the queue by `1` (an element was removed).

- Return the removed element `TYPE removed`.

<br>

> [!NOTE]
> The dequeued element is not physically removed from memory but rather ignored by managing `front` and `size` to restructure the array's order.

<br><br>

**Example:**
```c
// enqueue(&q, 28);
// enqueue(&q, 33);
// enqueue(&q, 19);

int x = dequeue(&q);
```
```txt
 -----------------------------------------
| 28 | 33 | 19 |   |   |   |   |   |   |   | ---> Array
 -----------------------------------------
| 0 |--> front
 --
| 3 |--> size
 --
```
```txt
 ------------------------------------------
| xx | 33 | 19 |   |   |   |   |   |   |   | ---> Array
 ------------------------------------------
| 1 |--> front
 --
| 2 |--> size
 --
```
- Retrieve value stored in `front` -> `28` and **store** it in `int x`.

- Increase `front` to point to `index[1]`.

- Decrease size of the queue by `size - 1` = `2` (3 - 1 removed element).

- Return `x` (28).

<br><br>

**Dequeuing another element**:
```c
// enqueue(&q, 28);
// enqueue(&q, 33);
// enqueue(&q, 19);
// int x = dequeue(&q);

int x = dequeue(&q);
```
```txt
 ------------------------------------------
| xx | 33 | 19 |   |   |   |   |   |   |   | ---> Array
 ------------------------------------------
| 1 |--> front
 --
| 2 |--> size
 --
```
```txt
 ------------------------------------------
| xx | xx | 19 |   |   |   |   |   |   |   | ---> Array
 ------------------------------------------
| 2 |--> front
 --
| 1 |--> size
 --
```
- Retrieve value stored in `front` -> `33` and **store** it in `int x`.

- Increase `front` to point to `index[2]`.

- Decrease size of the queue by `size - 1` = `1` (2 - 1 removed element).

- Return `x` (33).

<br><br>

**Now let's enqueue a new element**:
```c
// enqueue(&q, 28);
// enqueue(&q, 33);
// enqueue(&q, 19);
// int x = dequeue(&q);
// int x = dequeue(&q);

enqueue(&q, 40);
```
```txt
 ------------------------------------------
| xx | xx | 19 |   |   |   |   |   |   |   | ---> Array
 ------------------------------------------
| 2 |--> front
 --
| 1 |--> size
 --
```
```txt
 ------------------------------------------
| xx | xx | 19 | 40 |   |   |   |   |   |   | ---> Array
 ------------------------------------------
| 2 |--> front
 --
| 2 |--> size
 --
```
- Determine where to place new data `40`  ->  `(q->font + q->size) % CAPACITY`  ->  `(2 + 1) % 10` = `3`  ->  Place `40` in array `index[3]`.

- **Increment** size  ->  `size + 1` = `2` (`q` now holds **2** elements)

- `front` remains unchanged `2` (**FIFO** principle)

<br><br>

## Linked List-based Implementation

```c
// Define linked list node structure
typedef struct _node
{
    TYPE data;
    struct _node *prev;
    struct _node *next;
}
node;

// Define queue structure
typedef struct _queue
{
    node *head;
    node *tail;
    int size;
}
queue;
```
- Define a new structure `typedef struct` called `_node`:
    - It contains **data** of some **type** `TYPE data`
    - **Pointers** to the **previous** and **next** nodes in the list `struct _node *prev` and `struct _node *next` 

<br>

- Define another structure `typedef struct` called `_queue`:
    - A **pointer** to the **first node** `head`
    - A **pointer** to the **last node** `tail`
    - An **integer** `size` to keep track of the **number of elements** currently in the queue.

<br><br>

```c
// Declare the queue
queue q;

// Initialize variables
q.head = NULL;
q.tail = NULL;
q.size = 0;
```
```txt
head ---> NULL

NULL <--- tail
```
<br>

> [!IMPORTANT]
> Make sure to always maintain pointers to the **head** and **tail** of the linked list. It's a good idea to declare them as **global variables**.

<br><br>

### ENQUEUE - Add an element to the end of the queue

```c
// Function prototype
void enqueue(queue *q, TYPE data);
```
- The function `enqueue()` **adds** a new element to the queue.

- The function takes two arguments: a **pointer** to the queue `queue *q` and **data** to be added `TYPE data`.

<br><br>

```c
void enqueue(queue *q, TYPE data)
{
    // Dynamically allocate new node
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        return 1;
    }

    // Populate and insert new node to end of the queue
    // Set its next pointer to NULL, set its prev pointer to the tail
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = q->tail;
    

    // Set the tail's next pointer to the new node
    if (q->tail != NULL)
    {
        q->tail->next = new_node;
    }

    // Move the tail pointer to the newly-created node
    q->tail = new_node;

    // If queue was empty
    // Set the head to the new node as well
    if (q->head == NULL)
    {
        q->head = new_node;
    }
}
```
<br><br>

**Example**:

Imagine we wanted to **enqueue** the integer `10` in a previously established **queue** of 4 elements.
```c
enqueue(tail, 10);
```
```txt
   head
    |
    v
|  NULL |                                          tail
|  12   | <---  |  prv  |                           |           
|  nxt  | --->  |  15   | <---  |  prv  |           v             
                |  nxt  | --->  |   9   | <---  |  prv  |
                                |  nxt  | --->  |  13   |
                                                |  NULL |
```
```txt
   head
    |
    v
|  NULL |                                          tail                new
|  12   | <---  |  prv  |                           |                   |  
|  nxt  | --->  |  15   | <---  |  prv  |           v                   v
                |  nxt  | --->  |   9   | <---  |  prv  |           |       |  
                                |  nxt  | --->  |  13   |           |  10   |
                                                |  NULL |           |       |
```
```txt
   head
    |
    v
|  NULL |
|  12   | <---  |  prv  |                                         tail
|  nxt  | --->  |  15   | <---  |  prv  |                           |             
                |  nxt  | --->  |   9   | <---  |  prv  |           v
                                |  nxt  | --->  |  13   | <---  |  prv  |
                                                |  nxt  | --->  |  10   | 
                                                                |  NULL |   
```
<br><br>

### DEQUEUE - Remove most recent element from the front of the queue

```c
// Function prototype
dequeue(queue *q);
```
- The function `dequeue()` **removes** most recent element from the front of the queue.

- The function takes **one** argument: a **pointer** to the queue `queue *q`.

<br>

```c
void dequeue(queue *q)
{
    // Check if queue is empty
    if (q->head == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    // Traverse to the second element
    node *trav = NULL;
    trav = q->head->next;

    // Free the head of the list
    free(q->head);

    // Move the head pointer to the (former) second element
    q->head = trav;

    // Make node's prev pointer point to NULL
    if (q->head != NULL)
    {
        q->head->prev = NULL;
    }
}
```
<br>

> [!NOTE]
> The dequeued element is **removed from memory**, unlike in an array where the element is ignored by managing indices. This approach in a doubly-linked list is more memory **efficient** and appropriate for dynamic data structures.

<br><br>

**Example**:

Imagine we wanted to **dequeue** the **head** of the queue in our previous **example**:
```c
dequeue(head);
```
```txt
   head
    |
    v
|  NULL |
|  12   | <---  |  prv  |                                         tail
|  nxt  | --->  |  15   | <---  |  prv  |                           |             
                |  nxt  | --->  |   9   | <---  |  prv  |           v
                                |  nxt  | --->  |  13   | <---  |  prv  |
                                                |  nxt  | --->  |  10   | 
                                                                |  NULL |   
```
```txt
  head
    |              trav
    v               |
|       |           v
|       |       |  prv  |                                         tail
|       |       |  15   | <---  |  prv  |                           |             
                |  nxt  | --->  |   9   | <---  |  prv  |           v
                                |  nxt  | --->  |  13   | <---  |  prv  |
                                                |  nxt  | --->  |  10   | 
                                                                |  NULL |   
```
```txt
   head
    |
    v
|  NULL |                                         tail
|  15   | <---  |  prv  |                           |             
|  nxt  | --->  |   9   | <---  |  prv  |           v
                |  nxt  | --->  |  13   | <---  |  prv  |
                                |  nxt  | --->  |  10   | 
                                                |  NULL |   
```
