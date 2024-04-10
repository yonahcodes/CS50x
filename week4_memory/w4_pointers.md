# Pointers

**Pointers** are variables that store **memory addresses**, rather than actual data **values**. Pointers provide us with the ability to pass data **by reference** between functions. This means that any changes made in one function can impact the **variable** outside the function, since they both refer to the **same memory location**.

Files on a computer live on the **disk drive**, be it a **hard disk drive** `HDD` or a **solid-state drive** `SSD`. Disk drives are forms of **non-volatile memory** and are used as a **long-term storage** solution, we cannot directly work of execute programs on them.

Every piece of data actively manipulated and used by a computer resides in the **random access memory** `RAM`. **RAM** is a form of **volatile memory** that *temporarily* holds data and instructions for the `CPU` to process. Memory can be conceptualized as a vast **array** of individual storage units known and `bytes` (**8 bits**). These bytes are *sequentially organized*, creating a linear address space where each **byte** has a *unique address*. This structure allows the computer to efficiently store and retrieve program instructions, variables, or any other form of data.

<br>

|Data Type|Size (in bytes)|
|:-:|:-:|
|int|4|
|char|1|
|float|4|
|double|8|
|long long|8|
|string|?|

<br>

Similar to how *arrays* enable **random access** to data by indexing into specific locations, **memory** in a computer operates in the same manner, but instead of indices, it uses **addresses**.

Let's imagine declaring and assigning values to variables and visualize, in a simplified way, how the data might be stored in memory:
```c
char c = 'H';
int speedlimit = 65;
string surname = "Lloyd";
```
```txt
|      |       |       |       |   H   |       |       |       |               65              |   L   |   l   |   o   |   y   |    d   |    \0   |       |       |  
   0x0    0x1     0x2     0x3     0x4     0x5     0x6     0x7     0x8     0x9     0xA     0xB     0xC     0xD     0xE     0xF     0x10     0x11     0x12     0x13 
```  
<br><br>

> [!IMPORTANT]
> POINTERS ARE JUST ADDRESSES

<br><br>

## Declaring Variables and Pointers

Let's break down the process of declaring variables and pointers in `C`, exploring how they are allocated in memory:

```c
int k;
k = 5;
int* pk;
pk = &k;
```

<br>

- `int k;` Declares an **integer variable** called `k`, which is like allocating an empty box of **4 bytes** (integer size) in memory:

```txt
|       |
    k
```
<br><br>

- `k = 5;` Assigns the value of `5` to `k`, which is like putting `5` inside that `k` box:

 ```txt
|   5   |
     k
```
<br><br>

- `int* pk;` Declares a **pointer** to an integer named `pk`, which is like allocating an empty box of **8 bytes** (size of pointer) in memory:

```txt
|        |
    pk
```
<br><br>

- `pk = &k;` Assigns the **address** of `k` to **pointer** `pk`, which is like putting the address of `k` inside the `pk` box:

```txt
| 0x80C74820 |
      pk
```
```txt
pk ----------> |   5   |
                   k
```
<br>

> A **pointer** is a data item whose **value** is a **memory address** and **type** describes the **data** located at that memory address.

<br><br>

## Pointers in C

### NULL Pointer

The simplest **pointer** available to us in `C` is the `NULL` pointer. The `NULL` pointer points to nothing, and when creating a pointer and *not setting its value immediately*, we should always set the value of the pointer to `NULL`. 

We can check whether a pointer is **NULL** using the equality operator `==`.

<br>

### Address Extraction Operator `&`

Another easy way to create a pointer is to simply **extract** the address of an already existing variable. We can do this with the **address of** operator `&`. 

- If `int x;` is an int-type variable, then `&x` is a **pointer-to-int** whose value is the **address** of `x`.

- If `arr` is an array of doubles, then `&arr[i]` is a **pointer-to-double** whose value is the **address** of the **`i`th** element of `arr`. An array's *name*, then is actually just a *pointer* to its **first element**.

<br>

### Dereference Operator `*`

The main purpose of a **pointer** is to allow us to *modify* or *inspect* the **location** to which it points. We can do this by **dereferencing** the pointer or **"go to the reference"** and access the data at that memory location.

- If we have a **pointer-to-char** called `pc`, then `*pc` is the data that lives at the memory address stored inside the variable `pc`.

- If we try to **dereference** a pointer whose value us `NULL`, we will get a `Segmentation fault`. This is actually positive behavior. 

- If a pointer is **uninitialized** (meaning it has not been assigned a *meaningful value*), and we did not set it's value to `NULL` in the meantime, the computer will assign a random **garbage** value` to it. This value can be unpredictable, leading to undefined behavior and potentially causing errors.

<br>

```c
int* p;
```
- The value of `p` is an address
- We can **dereference** `p` with the `*` operator.
- If we do, we will find an `int`.

<br>

In **C** we can declare multiple **integer variables** in a *single line* as long as they are separated with **commas**. Each variable will have its own storage space to hold integer values:
```c
int x, y, z;
```
<br>

To declare multiple **pointers** in a *single line* we cannot do the following:
```c
int* px, py, pz;
```
- This line declares `px` as a pointer to an integer, but `py` and `pz` are declared as **regular integer variables**, not pointers.

<br>

To declare **multiple pointer variables** in a *single line*, we need to explicitly specify the pointer type for each variable:
```c
int *px, *py, *pz;
```

<br><br>

## Memory Size or Data Types and Pointers

Now that we understand what pointers are, we can better understand how data types and pointers take up space in memory. This information is crucial for efficient **memory management** in programming.  

<br>

|Data Type|Size (in bytes)|
|:-:|:-:|
|int|4|
|char|1|
|float|4|
|double|8|
|long long|8|
|char*, int*, float*, double*, ___*|4 or 8|

<br>

> [!NOTE]
> We know that in `C`, a `string` is a **pointer** to the *first element* of an **array of characters** that are stored in *consecutive* memory locations. In fact, a pointer to any data type, being a memory address, occupies `4 bytes` in a **32-bit** system or `8 bytes` in a **64-bit** system.

<br><br>

### Let's go back to our example about how variables and pointers are allocated in memory:

<br>

```c
int k;
k = 5;
int* pk;
pk = &k;

int m;
m = 4;
pk = &m;
```
<br>

We had a pointer `pk` to a variable `k` that holds the value of `5`:

```txt
pk ----------> |   5   |
                   k
```
<br><br>

- `*pk = 35` **Dereferences** pointer `pk` and assigns the value of `35`, changing the value stored at the memory location pointed to by `pk`, updating the value of `k`:

```txt
pk ----------> |   35   |
                    k
```
<br><br>

- `int m;` Declares a new **integer variable** called `m`, which is like allocating a new empty box of **4 bytes** (integer size) in memory:

```txt
|       |
    m
```
<br><br>

- `m = 4;` Assigns the value of `4` to `m`, which is like putting `4` inside that `m` box:

 ```txt
|   4   |
     m
```
<br><br>

- `pk = &m;` Assigns the **address** of `m` to **pointer** `pk`, which is like **redirecting** `pk` to point to now `m` instead of pointing to `k`:
```txt
pk ----X-----> |   35   |
                    k
```
```txt
pk ----------> |   4   |
                   m
```
