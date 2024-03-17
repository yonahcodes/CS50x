# C - Data Types
### `int` data type is used for variables that will store integers.

- Integers always take up **4 bytes of memory (32 bits).** 
- This means the range of values they can store is necessarily limited to 32 bits worth of information.
- Integer range: -2pw31 to 2pw31 (-1) ~ 2 billion
<br><br>
### `unsigned int` is a qualifier that can be applied to certain types (including int).

- It doubles the positive range of variables of that type, at the cost of disallowing any negative values.

- Integer range: 0 to 2pw32 (-1) ~ 4 billion
<br><br>
### `char` data type is used for variable that will store single characters.
- Characters always take up **1 byte of memory (8 bits)**.

- This means the range of values they can store is necessarily limited to 8 bits worth of information.

- Thanks to ASCII, we've developed a mapping of characters like A, B, C, etc... to numeric values in the positive side of this range.

- Character Range: -128 to 127

- Example: "A" = 65, "a" = 97, "0" = 48
<br><br>
### `float` data type is used for variables that will store floating-point values, also known as *real numbers*.

- Floating points values always take up **4 bytes of memory (32 bits)**.

- It's a little complicated to describe the range of float, but suffice it to say with 32 bits of precision, some of which might be used for an integer part, we are limited in how **precise** we can be.

- Example: 3.14159 We need to be able to represent the integer part and the decimal part. 
- If the integer part is big we will lose precision with the decimal part.
<br><br>
### `double` data type is used for variables that will store floating-point values, also known as *real numbers*.

- The difference is that doubles are *double precision*.
- They always take up **8 bytes of memory (64 bits)**.

- With an additional 32 bits of precision relative to a *float*, doubles allow us to specify much more precise real numbers.
<br><br>
### `void` is a type, but not a data type.

- Functions can have a void return type, which just means they don't return a value.

- The *parameter list* of a function can also be **void**. It simply means the function takes no parameters `int main (void)`.

- For now, think of **void** more as a placeholder for "nothing". It's more complex than that, but this should suffice for now.
<br><br>
## CS50 Specific Data Types

### `bool` data type is used for variables that will store a *Boolean* value.
- More precisely, they are capable only of storing one of two values: **true** and **false**.

- Be sure to `#include <cs50.h>` atop you programs if you wish to use the bool type.
<br><br>
### `string` data type is used for variables that will store a series of characters, which programmers typically call a **string**.

- Strings include things such as **words**, **sentences**, **paragraphs**, and the like.

- Be sure to `#include <cs50.h>` atop your programs if you wish to use the **string** type.

Later we'll also encounter structures (**structs**) and defined types (**typedefs**) that afford great flexibility in creating data types you need for your programs.

## Creating a variable

To bring a `variable` into existence, you need to simply **specify the data type** of the variable and **give it a name**.

```c
int number;
char letter;
```

If you wish to create `multiple variables` of the **same type**
- Specify the type name once, and then list as many variables of that type as you want.

```c
int height, width;
float sqrt2, sqrt3, pi;
```

In general, it's good practice to **only declare variables when you need them**.
<br><br>
## Using a variable

After a variable has been declared, **it's no longer necessary to specify that variable's type**. (In fact, doing so has some unintended consequences!)

```c
int number; // declaration
number = 17 // assignment

char letter; // declaration
letter = 'H' // assignment
```
If you are **simultaneously** declaring and setting the value of a variable (sometimes called **initializing**), you can consolidate this to one step.

```c
int number = 17; // initialization
char letter = 'H' // initialization
```