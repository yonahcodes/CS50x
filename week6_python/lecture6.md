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

In **Python**, especially when dealing with **string concatenation** and **formatting**, there are several ways to achieve the same output. Each method has its use cases and choosing one can also depend on **convention** and **style**. **F-strings** are generally preferred for their clarity and efficiency.

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
- Notice that we did not need to include any libraries.

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

Lecture 00:34:00
