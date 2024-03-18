# Arrays
**Arrays** are fundamental **data structures** that store a collection of values of the same type at contiguous memory locations. 

Let's analogize the notion of arrays by comparing them to a post office boxes:

|Arrays|Post Office Boxes|
|:-:|:-:|
|An **array is a block of contiguous space in memory...|A **mail bank** is a large space on the wall of the post office...|
|...which has been partitioned into small, identically-sized blocks of space called **elements**...|...which has been partitioned into small, identically-sized blocks of space called **post-office boxes**...|
|...each of which can store a certain amount of **data**...|...each of which can hold a certain amount of **mail**...|
|...all of the same data type such as **int** or **char**...|...all of a similar type such as **letters** or **small packages**...|
|...and which can be accessed directly by an **index**.|...and which can be accessed directly by a **mailbox number**.|

<br><br>

## Indexing
In **C**, the elements of an array are *indexed* starting from `0`. (This is one of the major reasons we start counting from **zero**.)

If an **array** consists of `n` elements, the first element is located at `index 0` and the last element is located at `index (n-1)`.
<br><br>

> *C* is very lenient. It will not prevent you from going **"out of bounds"** of your array. It will result in a **Segmentation fault**; be careful!

<br><br>

## Array Declarations

```c
type name[size];
```
- `type` is what kind of variable each element of the array will be.
- `name[]` is what we call the array.
- `size` is how many elements you would like your array to contain.

```c
int student_grades[40];
```
- `int` tells us this is an array of integers.
- `student_grades[]` is the array name.
- `40` is the number of grades contained in the array.
<br><br>

If you think of a single element of an array of type `data-type` the same as you would any other variable of type `data-type` (which it is) then all the familiar operations make sense.

```c
bool truthtable[10];

truthtable[2] = false;
if(truthtable[7] == true)
{
    printf("TRUE!\n");
}
truthtable[10] = true;
```
- `truthtable[2] = false;` assigns value of *true* to `index[2], the **THIRD** element.
- `truthtable[10] = true;` uses `index[10]` which is out of the array's range of `0 to 9`.
<br><br>

When **declaring** and **initializing** and array simultaneously, there is a special syntax that may be used to fill up the array with its starting values:

```c
// instantiation syntax
bool truthtable[3] = { false, true, true };

// Or
bool truthtable[] = { false, true, true };
```
```c
// individual element syntax
bool truthtable[3];
truthtable[0] = false;
truthtable[1] = true;
truthtable[2] = true;
```
<br><br>
## Multi-Dimensional Arrays
**Arrays** can consist of more than a single **dimension**. You can have as many size specifiers as you wish.

```c
bool battleship[10][10];
```
- You can think of this as a `10x10` grid of cells.
- In the memory though, it's really just a `100-element` **one-dimensional** array.
- *Multi-dimensional* arrays are great **abstractions** to help visualize game boards or other complex representations.
<br><br>


## Passing Arrays to Functions
We can treat individual **elements** of arrays as variables, but we cannot treat entire arrays themselves as variables. In **C**, we **cannot**, for instance, assign one array to another using the assignment operator:

```c
int foo[5] = { 1, 2, 3, 4, 5 };
int bar[5];

bar = foo;
```
<br><br>
Instead, we must use a **loop** to copy over the elements one at a time:

```c
int foo[5] = { 1, 2, 3, 4, 5 };
int bar[5];

for(int j = 0; j < 5; j++)
{
    bar[j] = foo[j];
}
```
<br><br>
Recall that most *variables* in **C** are `passed by value` in function calls. This means that the function calling the variable is getting a "**copy**" of the variable to work with.

**Arrays** do not follow this rule. Rather, they are `passed by reference`. The "callee" receives the **actual array**, NOT a copy of it.

```c
void set_array(int array[4]);
void set_int(int x);

int main(void)
{
    // variable a is declared
    int a = 10;
    // Array b is initialized
    int b[4] = { 0, 1, 2, 3 };

    // set_int function is called with "a" as an argument
    set_int(a);
    // set_array function is called with the array "b"
    set_array(b);

    // Values of "a" and "b" are printed
    printf("%d %d\n", a, b[0]);
}

// Sets first element of the array to "22"
void set_array(int array[4])
{
    array[0] = 22
}

// Sets local variable x to "22"
void set_int(int x)
{
    x = 22;
}
```
The output of this code will be:
```
10, 22
```
- The value of `a` remains unchanged at `10`, since local variables are **passed by value**, the `set_int()` function only modifies its **local variable** `x`.

- However, the value of `b[0]` changes to `22` because arrays are **passed by reference**, so modifications made to the array elements inside the `set_array()` function will affect the original array `b` in the `main()` function.