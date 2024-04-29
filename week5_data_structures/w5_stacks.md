# Stacks

A **stack** is a special type of structure that can be used to organize data. This data structure follows the **last in, first out** (**LIFO**) principle and is commonly implemented as an **array** or a **linked list**.

<br>

There are two operations that may legally be performed on a **stack**:

- **Push**: **Add** a new element to the **top** of the stack.

- **Pop**: **Remove** the most recently-added element from the **top** of the stack.

<br>

## Array-based Implementation

```c
typedef struct _stack
{
    TYPE array[CAPACITY];
    int top;
}
stack;
```
- Define a new structure `typedef struct` called `_stack`
- Composed by an **array** of some **capacity** and **type** `TYPE array[CAPACITY];`
- An **integer** called `top` to keep track of which element was **added last**.

<br><br>

```c
// Declare a stack
stack s;

// Initialize variables
s.top = 0;
```
```txt
 ---------------------------------------
|   |   |   |   |   |   |   |   |   |   | ---> Array of 10 integers
 ---------------------------------------
| 0 |--> top
 ---
```
<br>

### PUSH - Add an element to the Top of the stack

```c
// Function prototype
void push(stack *s, TYPE data);
```
- The function `push()` **adds** a new element to the stack.

- The function takes two arguments: a **pointer** to the stack `stack *as` and **data** to be added `TYPE data`.

<br>

```c
void push(stack *s, TYPE data)
{
    // Check is stack is full
    if (s->top == CAPACITY)
    {
        printf("Stack is full\n");
        return;
    }

    // Add data to the top of the stack
    s->array[s->top] = data;

    // Change the location of the top of the stack
    s->top++;
}
```
- If array if **Full**, `s->top` would be the **last available index** in the array `index[CAPACITY]`.

- `s->array[s->top]` is the **top of the stack index**.

- `s->top++` Moves the **top** of the stack to the **next** index. 

<br><br>

**Example:**
```c
stack s;
s.top = 0;

push(&s, 28);
```
```txt
 ---------------------------------------
|   |   |   |   |   |   |   |   |   |   | ---> Array
 ---------------------------------------
| 0 |--> top
 ---
```
```txt
 ----------------------------------------
| 28 |   |   |   |   |   |   |   |   |   | ---> Array
 ----------------------------------------
| 1 |--> top
 ---
```
- Notice that we passed the **address** of the stack `&s` to the function `push()`.

- Since initially `s` is **empty**, `top` is `0`, we place the **data** `28` in the `index[0]`.

- Then **increment** `top` to `1`.

<br><br>

```c
// stack s;
// s.top = 0;
// push(&s, 28);

push(&s, 33);
```
```txt
 ----------------------------------------
| 28 |   |   |   |   |   |   |   |   |   | ---> Array
 ----------------------------------------
| 1 |--> top
 ---
```
```txt
 -----------------------------------------
| 28 | 33 |   |   |   |   |   |   |   |   | ---> Array
 -----------------------------------------
| 2 |--> top
 ---
```
- We place the new **data** `33` in the top of the stack `top` at `index[1]`.
- Then **increment** `top` to `2`.

<br><br>

```c
// stack s;
// s.top = 0;
// push(&s, 28);
// push(&s, 33);

push(&s, 19);
```
```txt
 -----------------------------------------
| 28 | 33 |   |   |   |   |   |   |   |   | ---> Array
 -----------------------------------------
| 2 |--> top
 ---
```
```txt
 ------------------------------------------
| 28 | 33 | 19 |   |   |   |   |   |   |   | ---> Array
 ------------------------------------------
| 3 |--> top
 ---
```
- We place the new **data** `19` in the top of the stack `top` at `index[2]`.
- Then increment `top` to `3`.

<br><br>

### POP - Remove most recent element from the top of the stack

```c
// Function prototype
TYPE pop(stack *s);
```
- The function `pop()` **removes** most recent element from the **top** of the stack.

- The function takes **one** argument: a **pointer** to the stack `stack *s` and returns the **element that was removed** from the stack.

<br>

```c
TYPE pop(stack *s)
{
    // Check if stack is empty
    if (s->top == 0)
    {
        printf("Stack is empty\n");
        return NULL;
    }

    // Change the location of the top of stack
    s->top--;

    // Retrieve the value at the top of the stack
    TYPE popped = s->array[s->top];

    // Return the value that was popped from stack
    return popped;
}
```
- Update `top` of the stack to point to **previous index** holding most recent element.

- Retrieve the **element to be popped** by accessing the `top` index of the stack and **storing** its value in a variable `TYPE popped` (to be returned if successfully removed).

- Return the removed element `TYPE popped`.

<br>

> [!NOTE]
> The popped element is **not** physically removed from memory but rather **ignored** by updating `top` to restructure the array's order.

<br><br>

**Example:**
```c
int x = pop(&s);
```
```txt
 ------------------------------------------
| 28 | 33 | 19 |   |   |   |   |   |   |   | ---> Array
 ------------------------------------------
| 3 |--> top
 ---
```
```txt
 ------------------------------------------
| 28 | 33 | xx |   |   |   |   |   |   |   | ---> Array
 ------------------------------------------
| 2 |--> top
 ---
```
- To **pop** the top of the stack, we simply decrease `top` from `3` to `2` to point at **last element added** to the stack `19`.

- We store `19` in variable `x`, to be **returned** if successfully removed.

- If a **new element** is added to the stack it will be placed at index `2` overriding `19`.

<br><br>

**Popping another element**:
```c
// int x = pop(&s);

int x = pop(&s);
```
```txt
 ------------------------------------------
| 28 | 33 | xx |   |   |   |   |   |   |   | ---> Array
 ------------------------------------------
| 2 |--> top
 ---
```
```txt
 ------------------------------------------
| 28 | xx | xx |   |   |   |   |   |   |   | ---> Array
 ------------------------------------------
| 1 |--> top
 ---
```
- To **pop** top of the stack, again we decrease `top` from `2` to `1` to point at **last element added** to the stack `33`.

- We store `33` in variable `x`, to be **returned** if successfully removed.

- If a **new element** is added to the stack it will be placed at index `1` overriding `33`.

<br><br>

**Now let's push a new element to the stack**:

```c
// int x = pop(&s);
// int x = pop(&s);

push(&s, 40);
```
```txt
 ------------------------------------------
| 28 | xx | xx |   |   |   |   |   |   |   | ---> Array
 ------------------------------------------
| 1 |--> top
 ---
```
```txt
 ------------------------------------------
| 28 | 40 | xx |   |   |   |   |   |   |   | ---> Array
 ------------------------------------------
| 2 |--> top
 ---
```
- We place the new **data** `40` in the top of the stack `top` at `index[1]`.
- Then increment `top` to `2`.

<br><br>

## Linked List-based Implementation

```c
// Define linked list node structure
typedef struct _node
{
    TYPE data;
    struct _node *next;
}
node;

// Define stack structure
typedef struct _stack
{
    node *top;
}
stack;
```
- Define a new structure `typedef struct` called `node`:
    - It contains **data** of some **type** `TYPE data`
    - **Pointer** to the **next** node in the list `struct _node *next` 

<br>

- Define another structure `typedef struct` called `stack`:
    - That contains **pointer** to the **top** of the stack `top`.

<br><br>

```c
// Declare the stack
stack s;

// Initialize variables
s.top = NULL;
```
```txt
stack s
   |
   v
  NULL
```
<br>

> [!IMPORTANT]
> Make sure to always maintain a pointer to the **head** of the linked list. It's a good idea to declare it as a **global variable**. In our case this is the **top** of the stack `top`.

<br><br>

### PUSH - Add an element to the top of the stack

```c
// Function prototype
void push(stack *s, TYPE data);
```
- The function `push()` **adds** a new element to the stack.

- The function takes two arguments: a **pointer** to the stack `stack *s` and **data** to be added `TYPE data`.

<br><br>

```c
void push(stack *s, TYPE data)
{
    // Dynamically allocate memory for a new node
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        return;
    }

    // Populate and insert new node to the top of the stack
    // Set its next pointer to point to current head of the list
    new_node->data = data;
    new_node->next = s->top;

    // Move head pointer to the new node
    s->top = new_node;
}
```
<br><br>

**Example**:

Imagine we wanted to **push** the integer `12` in a previously established **stack** of 4 elements.
```c
push(&s, 12);
```
```txt
   top
    |
    v

|  15   |
|  nxt  | --->  |   9   |
                |  nxt  | --->  |  13   |
                                |  nxt  | --->  |  10   |
                                                |  NULL |
```
```txt
 new_node          top
    |               |
    v               v

|  12   |       |  15   |
|       |       |  nxt  | --->  |   9   |
                                |  nxt  | --->  |  13   |
                                                |  nxt  | --->  |  10   | 
                                                                |  NULL |   
```
```txt
   top
    |
    v
|  12   |
|  nxt  | --->  |  15   |
                |  nxt  | --->  |   9   |
                                |  nxt  | --->  |  13   |
                                                |  nxt  | --->  |  10   | 
                                                                |  NULL |   
```
- Dynamically allocate memory `malloc()` for a **new node**.

- Populate the **data** field of the new node with `12`.

- Connect `new_node->next` member to the head of the list `top` (to avoid dangling pointers).

- Update `top` to point to the **new node**. Effectively setting it as new **top of the stack**.

<br><br>

### POP - Remove most recent element from the top of the stack

```c
// Function prototype
TYPE pop(stack *s);
```
- The function `pop()` **removes** most recent element from the **top** of the stack.

- The function takes **one** argument: a **pointer** to the stack `stack *s` and returns the **element that was removed** from the stack.

<br><br>

```c
void pop(stack *s)
{
    // Check if stack is empty
    if (s->top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    // Traverse to the second element in the stack
    node *trav = NULL;
    trav = s->top->next;

    // Free the head of the list
    free(s->top);
    s->top = NULL;

    // Move the top pointer to the former second element
    s->top = trav;
}
```
<br>

> [!NOTE]
> The **popped** element is **removed from memory**, unlike in an array where the element is ignored by managing indices.

<br><br>

**Example**:

Imagine we wanted to **pop** the **top** of the stack in our previous **example**:
```c
pop(&s);
```
```txt
   top
    |
    v
|  12   |
|  nxt  | --->  |  15   |
                |  nxt  | --->  |   9   |
                                |  nxt  | --->  |  13   |
                                                |  nxt  | --->  |  10   | 
                                                                |  NULL |   
```
```txt
   top
    |             trav
    v               |
|       |           v
|       |       |  15   |
                |  nxt  | --->  |   9   |
                                |  nxt  | --->  |  13   |
                                                |  nxt  | --->  |  10   | 
                                                                |  NULL |   
```
```txt
   top
    |
    v
|  15   |
|  nxt  | --->  |   9   |
                |  nxt  | --->  |  13   |
                                |  nxt  | --->  |  10   | 
                                                |  NULL |   
```
