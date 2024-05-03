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
<br>

Manually compiling **C** code without `make`:
```txt
clang -o hello hello.c -lcs50

./hello
```
<br>

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

**Python** allows you to **abstract away** programming that would be much more complicated within **C** and other **lower-level** programming languages.

<br><br>

## CS50 Library

Using the **CS50 library** in **Python**:

```py
from CS50 import get_float, get_int, get_string
```

Lecture 6 - 00:21:00
