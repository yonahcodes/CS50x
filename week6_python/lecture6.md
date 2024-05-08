# CS50x Week 6 - Python

In the previous weeks, we learned the fundamentals of programming in a **low-level** programming language called **C**. Python is a programming language that will build on top of what we learned with **C**.

**Python** is a high level interpreter language, where you need to separately compile your program. Instead, you run your program in the **Python Interpreter**.

<br>

## Compiling

To compile our programs in **C** we used the `make` command. Which had to be predefined to tell the **clang** compiler which steps to follow.
```txt
make hello      -> Compile

./hello         -> Run
```
<br><br>

Manually compiling **C** code without `make`:
```txt
clang -o hello hello.c -lcs50

./hello
```
<br><br>

Compiling **Python** code is done by running a program called `python` (**Python Interpreter**). The interpreter reads your code and follows the instructions:
```txt
python hello.py
```
<br><br>

## Hello

In **C** code:
```c
#include <stdio.h>

int main(void)
{
    printf("hello, world\n");
}
```
<br>

In **Python** code:
```c
print("hello, world")
```
- **Libraries** like `<stdio.h>` are no longer needed.
- No need for the `main()` function to tell the compiler what the main part of our program is.
- No need for extra syntax like the **semicolon** `;`.
- No need for the **new line** `\n` to move the cursor to the next line.

<br><br>

## Speller

To illustrate this simplicity, let's re-write last week's **Speller** problem code with **Python**:

```py
# Words in dictionary
words = set()

def check(word):
    """ return true if word is in dictionary else false"""
    return word.lower() in words

def load(dictionary):
    """Load dictionary into memory, returning true if successful else false"""
    with open(dictionary) as file:
        words.update(file.read().splitlines())
    return True

def size():
    """Returns number of words in dictionary if loaded else 0 if not yet loaded"""
    return len(words)

def unload():
    """Unloads dictionary from memory, returning true if successful else false"""
    return True
```
- `check()` simply returns **True** if a `word` is in the `words` set.

- `load()` dictionary file is **opened**. We split each line in that file and add it to `words`.

- `size()` simply returns `len` or length of `words`.

- `unload()` returns **True** because Python handles memory management on its own.

<br><br>

High level languages like **Python** exist to simplify writing code. However, **speed** is a tradeoff. **C** allows you to make decisions about memory management, and it may run faster than **Python**.

While **C** strictly follows instructions, running the code line by line, ***Python**, when using **built-in functions**, also runs additional processes in the background, **simplifying usage** but potentially **reducing speed**.

<br><br>

## Filter

To further illustrate this simplicity, let's re-write the `blur()` function of the **Filter** problem with **Python**:

```py
# Blurs an image

from PIL import Image, ImageFilter

before = Image.open("bridge.bmp")
after = before.filter(ImageFilter.BoxBlur(10))
after.save("out.bmp")
```
- This program takes an **input file** `bridge.bmp` and creates modified output file `out,bmp`.
- To modify the image, it uses imported modules `Image` and `ImageFilter` from a library called `PIL`. 

<br><br>

Now, let's implement `edges()`, a function that finds the edges of an image:
```py
# Finds edges in an image

from PIL import Image, ImageFilter

before = Image.open("bridge.bmp")
after = before.filter(ImageFilter.FIND_EDGES)
after.save("out.bmp")
```
- Notice that this code is a **small adjustment** to the `blur` code, but produces a dramatically different result.

<br><br>

Finally, we can even write a **face detection** program fairly simply:
```py
# Find faces in picture
# https://github.com/ageitgey/face_recognition/blob/master/examples/find_faces_in_picture.py

from PIL import Image
import face_recognition

# Load the jpg file into a numpy array
image = face_recognition.load_image_file("office.jpg")

# Find all the faces in the image using the default HOG-based model.
# This method is fairly accurate, but not as accurate as the CNN model and not GPU accelerated.
# See also: find_faces_in_picture_cnn.py
face_locations = face_recognition.face_locations(image)

for face_location in face_locations:

    # Print the location of each face in this image
    top, right, bottom, left = face_location

    # You can access the actual face itself like this:
    face_image = image[top:bottom, left:right]
    pil_image = Image.fromarray(face_image)
    pil_image.show()
```
- This program uses a **third-party library** `face_recognition`. This is enabled by running `pip install face_recognition` in the terminal window.

- With **libraries** we can leverage advanced functionalities with simple function calls, greatly simplifying coding efforts. 

<br>

>[!NOTE]
> **Python** allows you to **abstract away** programming that would be much more complicated within **C** and other **lower-level** programming languages.

<br><br>

## CS50 Library in Python

In **Python** when importing **functions** from **libraries**, we an specify which function or group of functions to import.

```py
from CS50 import get_float, get_int, get_string
```
<br><br>

## Strings

`get_string()` in **C**:
```c
// get_string and printf with %s

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char *answer = get_string("What is you name? ");
    printf("hello, %s\n", answer);
}
```
<br><br>

`get_string` in **Python**:
```py
# get_string and print, with concatenation

from cs50 import get_string

answer = get_string("What's your name? ")
print("hello, " + answer)
```
- Notice that the variable types are no longer needed.
- The `+` sign concatenates `"hello, "` and `answer`

<br><br>

Alternative syntax:
```py
# get_string and print, with format strings

from cs50 import get_string

answer = get_string("What's your name? ")
print("hello,", answer)
```
- Notice we did not include a **space** between `"hello,"` and `answer`. By separating them with a `,` we tell python that they are two different arguments and it knows to automatically put a **space** between them.

<br><br>

Alternative syntax:
```py
# get_string and print, with format strings

from cs50 import get_string

answer = get_string("What's your name? ")
print(f"hello, {answer}")
```
- This method uses a **format string**. When we **prefix** a string in **Python** with an `f`, we can use curly braces `{}` to interpolate the value inside of them. `{}` acts as a placeholder.

<br><br>

In **Python**, especially when dealing with **string concatenation** and **formatting**, there are several ways to achieve the same output. Each method has its use cases and choosing one can also depend on **convention** and **style**. `F-strings` are generally preferred for their clarity and efficiency.

```py
# print("hello, " + answer)
# print("hello,", answer)
print(f"hello, {answer}")
```
<br><br>

### `input()`

In **C** programming, to simplify the process of prompting the user for a *string input*, we used the `get_string` function from the `cs50.h` library: 
```py
from cs50 import get_string

answer = get_string("What's your name? ")
print(f"hello, {answer}")
```
<br>

In **Python**, there is a built-in function called `input()`:
```py
answer = input("What's your name? ")
print(f"hello, {answer}")
```
- Notice that we did not need to include any **libraries**.

<br><br>

## Variables

**C** is a **statically typed** language. This means that when **declaring a variable** we need to include the **type** to inform the compiler about the amount of memory to allocate and how to interpret the data:
```c
int counter = 0;
```
<br>

**Python** is a **dynamically typed** language. **Variables** are declared the moment we assign a **value** to them. It is not needed to specify the **type** either, since it can change as the variable is reassigned a value of a different data type:
```py
counter = 0
```
<br><br>

### Incrementing a variable

To increment a variable by `1` in **C**, we used the following syntax:
```c
// counter = counter + 1;
// counter += 1;

counter++;
```
<br>

In **Python** the `counter++;` syntax is **not** used:
```py
# counter = counter + 1

counter += 1
```
<br><br>

## Types

In **C**, variables require explicit type declarations. Commonly used data types include:
```c
bool    // Boolean values (true or false)

char    // Single character

double  // Double-precision floating-point number 

float   // Single-precision floating-point number

int     // Integer

long    // Large integer

string  // Array of characters
```
<br><br>

**Data Types** in **Python** do not need to be explicitly declared. Commonly used **data types** include:
```py
bool    # Boolean values (true or false)

float   # Floating-point number (covers both *float* and *double*)

int     # Integer (automatically scales to *long* if needed)

str     # String of characters
```
>[!NOTE]
> Notice that **long** and **double** are missing. **Python** automatically handles adjustments during **runtime**. including what data type should be used for larger and smaller numbers.

<br><br>

Some other **data types** in **Python** include:
```py
range   # Generates a sequence of number

list    # A mutable, ordered sequence of elements

tuple   # An immutable, ordered sequence of elements

dict    # A collection of key-value pairs, with unique keys

set     # An unordered collection of unique elements
```
<br><br>

## Calculator

Let's implement two versions of a simple calculator. The first one in **C**, the second in **Python**.

Addition with int in **C**:
```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for x and y
    int x = get_int("x: ");
    int y = get_int("y: ");

    // Print addition
    printf("%i\n", x + y);
}
```
<br><br>

Addition with int (using `get_int`) in **Python**:
```py
from cs50 import get_int

# Prompt user for x and y
x = get_int("x: ")
y = get_int("y: ")

# print addition
print(x + y)
```
- Notice that the **data type** `int`, **semicolons** `;` and **main function** `main()` are gone.

<br><br>

Using `input()` instead of CS50's `get_int`:
```py
# Prompt user for x and y 
x = input("x: ") # suppose 1
y = input("y: ") # suppose 2

# Print addition
print(x + y)
```
```txt
12
```
> [!CAUTION]
> Notice how executing the code above returns `12` instead of `3`. The interpreter understood `x` and `y` to be strings and it is performing **concatenation** instead of **addition**.

<br><br>

`int()` function:
```py
x = int(input("x: "))
y = int(input("x: "))

print(x + y)
```
- Notice how the input `x` and `y` is passed to the `int()` function which **converts** it into an **integer**. Now, instead of **concatenating** the interpreter will know to **add** both integers.

<br><br>

`library.function()`
```py
import cs50

x = cs50.get_int("x: ")
y = cs50.get_int("x: ")

print(x + y)
```
- Imagine we imported two **identically named functions** from different **libraries** in our program. In **Python** we can specify the library in the **function call** `cs50.get_int` to specify which function we want to use.

<br><br>

## Conditionals

Let's compare different **conditional statements** in **C** and **Python**:

```c
// C

if (x < y)
{
    printf("x is less than y\n");
}
```
```py
# Python

if x < y:
    print("x is less than y")
```
- The `()` around the conditional `(x < y)` are not needed in **Python** (Can be used if needed, but not mandatory).

- No need for curly braces `{}`. In **Python**, a colon `:` and **indentation** are used to define blocks.

- The **semicolon** `;` and the **new line** separator `\n` are also omitted.

<br><br>

```c
// C

if (x < y)
{
    printf("x is less than y\n");
}
else
{
    printf("x is not less than y\n");
}
```
```py
# Python

if x < y:
    print("x is less than y")
else:
    print("x is not less than y")
```
- Again, for the **else** statement in **Python**, curly braces `{}` and semicolons `;` are gone. Colons `:` and **indentation** are used to define blocks.

<br><br>

```c
// C

if (x < y)
{
    printf("x is less than y\n");
}
else if (x > y)
{
    printf("x is greater than y\n");
}
else
{
    printf("x is equal to y\n");
}
```
```py
# Python

if x < y:
    print("x is less than y")
elif:
    print("x is greater than y")
else:
    print("x is equal to y")
```
- In **Python** `else if` is shortened to `elif` to save extra typing.

<br><br>

Now, let's see how we can integrate these conditionals in **C** and **Python** programs:
```c
// Conditionals in C

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for integers
    int x = get_int("What's x? ");
    int y = get_int("What's y? ");

    // Compare integers
    if (x < y)
    {
        printf("x is less than y\n");
    }
    else if (x > y)
    {
        printf("x is greater than y\n");
    }
    else
    {
        printf("x is equal to y\n");
    }
}
```
<br>

```py
# Conditionals in Python

from cs50 import get_int

x = get_int("What's x? ")
y = get_int("What's y? ")

if x < y:
    print("x is less than y")
elif x > y:
    print("x is greater than y")
else:
    print("x is equal to y")
```

<br><br>

Comparing **strings** `str`:
```py
# Comparing strings in Python

s = input("s: ")
t = input("t: ")

if s == t:
    print("Same")
else
    print("Different")
```
- Remember that in **C**, **strings** `char *` are **pointers** to the memory address holding the **first character** of the string. 

- Attempting to **compare two strings** in **C** with the **equality operator** `==` will always return **different**. This is because two different strings point to two different addresses.

- In **Python** however, comparing **strings** using the **equality operator** `==` works like it would with **integers**.

<br><br>

Further looking at comparisons, let's consider the following **C** code:
```c
// Logical operators in C

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user to agree
    char c = get_char("Do you agree? ");

    // Check whether agreed
    if (c == 'Y' || c == 'y')
    {
        printf("Agreed.\n");
    }
    else if (c == 'N' || c == 'n')
    {
        printf("Not agreed.\n");
    }
}
```
- The program above prompts the user to **agree** by typing `Y or y` or **disagree** by typing `N or n`.

<br><br>

```py
# Logical operators in Python

from cs50 import get_string

# Prompt user to agree
s = get_string("Do you agree? ")

# Check whether agreed
if s == "Y" or s == "y":
    print("Agreed.")
elif s == "N" or s == "n":
    print("Not agreed.")
```
- Notice that the two vertical bars `||` in **C** are replaced with `or`.

<br><br>

Imagine the user typing `Yes` instead of `Y` or `y`. In **Python** we can use a `list` to express multiple keywords:
```py
s = input("Do you agree? ")

if s in ["y", "yes"]:
    print("Agreed")
elif s in ["n", "no"]:
    print("Not Agreed")
```
- If the string `s` is included `in` the **list** `["y", "yes"]`, the program prints **Agreed**.

- If the string `s` is included `in` the **list** `["n", "no"]`, the program prints **Not Agreed**.

<br><br>

We introduced a `list` as a potential solution to include different **user inputs** into our **conditionals**, but this is still not the most **efficient** solution. To attempt to include every potential user input we will have to create **extensive lists** `["y", "Y", "yes", "YES", "Yes", "YeS", ...]`.

<br><br>

## Object-Oriented Programming

**OOP** allows variables to not only have values with certain properties or attributes, but also have functions built into them. In **Python** they are known as **objects**.

In **C** we had the ability to create a **struct** where we could associate multiple variables inside a single self-created data type. In **Python** we can include functions in a self-created data type called **methods**.

<br>

Strings `str` in Python have built-in **methods**:
```py
# Prompt user to agree
s = input("Do you agree? ").lower()

# Check whether agreed
if s in ["y", "yes"]:
    print("Agreed.")
elif s in ["n", "no"]:
    print("Not agreed.")
```
- The code takes the **user input** and immediately applies the `.lower()` method to convert it to **lowercase**.

- This ensures that no matter what is the **capitalization** of the **user input**, it will be treated the same.

<br><br>

## Loops

**Loops** in **Python** are very similar to **C**, but require less setup and manual control of **iteration variables** and **conditions**.

<br>

### While Loops

```c
// While loop in C

int i = 0;
while (i < 3)
{
    printf("meow\n");
    i++;
}
```
<br>

```py
# While loop in Python

i = 0
while i < 3:
    print("meow")
    i += 1
```
- Notice that the **Python** *while loop* is more **concise**.

<br><br>

### For Loops

```c
// For loop in C

for (int i = 0; i < 3; i++)
{
    printf("meow\n");
}
```
<br>

```py
# For loop in Python

for i in [0, 1, 2]:
    print("meow")
```
- The code above works but it's **not efficient**, particularly as the list increases.

<br>

```py
# For loop in Python - Alternative syntax

for i in range(3):
    print("meow")
```
- This **for loop** is mode **efficient**. The `range()` function returns a **range** of values as they are needed. To change the number of values we can simply change the **argument** to `range()`.

<br>

> [!IMPORTANT]
> Notice that `i` is never explicitly used. In **Python** we do not have to **manage** the **iteration variable** `i`, it is incremented **automatically**. It is common practice to use placeholder **underscore** `_` as an iteration variable, signaling that the focus is in the code's **operation**, enhancing clarity and maintainability.

```py
# For loop in Python - Alternative syntax

for _ in range(3):
    print("meow")
```

<br><br>

### Forever Loops

```c
// Forever loop in C

while (true)
{
    printf("meow\n");
}
```
<br>

```py
# Forever loop in Python

while True
    print("meow")
```
- In **Python** **True** and **False** are **capitalized**.

<br><br>

### `uppercase.py`

To further our understanding of **loops** and **iteration** in **Python**, let's implement a program to uppercase characters:
```py
# Uppercase string one character at a time

before = input("Before: ")
print("After: ")
for c in before:
    print(c.upper())
```
```txt
Before: cat
After:
C
A
T
```    
- Notice that the **capitalization** is achieved, but there are a couple of problems. The `After:` string prints in a **separate line** followed by the capitalized characters are printed **one per line**. 

- Unlike **C**, **Python** handles creating a **new line** automatically, there is no need to add the `\n`. However, sometimes, like our example, it could not be desirable.

<br><br>

To fix the this code we have to introduce **named parameters**:

```py
# Uppercase string one character at a time

before = input("Before: ")
print("After: ", end="")
for c in before:
    print(c.upper(), end="")
```
```txt
Before: cat
After: CAT$
```    
- **Python** uses an **abstracted** process to automatically move to the **next line** at the end of every line using the default character `"\n"` (`end="\n"`).

- To override that and prevent the program from jumping to the next line, we can **modify** the **named character** `end=`, and set it equal to **nothing** `end=""`. 

- Also notice that the **cursor** `$` was **not** moved to the next line. 

<br><br>

We can move the **cursor** to the next line by adding an extra **empty** `print()` line:
```py
# Uppercase string one character at a time

before = input("Before: ")
print("After: ", end="")
for c in before:
    print(c.upper(), end="")
print()
```
```txt
Before: cat
After: CAT
$
```
- With the version above, we achieved the desired outcome of the program, but some of the steps we implemented are **not necessary**. 


<br><br>

In **Python**, strings `str` come with **built-in** **methods**, one of them is `upper()`. We do not need to **loop** through and call `upper()` on every character of the string. Instead we can call it on the **entire string** `before.upper()`:

<br>

```py
# Uppercase string all at once

before = input("Before: ")
print("After: ", end="")
print(before.upper())
```
<br><br>

We can optimize the **design** and **logic** of the code by using a **formatted string** `f-string`:

```py
# Alternative syntax
before = input("Before: ")
after = before.upper()
print(f"After: {after}")
```
- We created a variable called `after`, which is the **uppercase** version of the `before` variable.

- In the `print` statement, we created a **f-string** composed of a string and an **embedded** variable `{after}`.

<br><br>

We can achieve the same result and make the code even more **concise** by removing the need to create the `after` variable and instead **embedding** the expression `before.upper()` between the formatted string's **curly braces**:

```py
# Alternative syntax
before = input("Before: ")
print(f"After: {before.upper()}")
```

<br><br>

## Abstraction

Lecture 1:14:00
