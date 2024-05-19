# CS50x Section 6 - Python

**Python** is an interpreted, object-oriented, high-level programming language. Its syntax improves readability and its extensive standard library and other third-party libraries simplify the programming process.

<br>

## Strings

```c
// Strings in C

char *text = get_string("...");
```
```py
# Strings in Python

text = input("...")
```
- Notice the **semicolon** `:`, the **type declaration** `char *` are not needed in **Python**.

<br><br>

```c
// Comparing strings in C

if (strcmp(text, "hello") == 0)
{
    ...
}
```
```py
# Comparing strings in Python

if text == "hello":
    ...
```
- Notice the curly braces `{}` and parenthesis `()` are not needed, **Python** uses **indentation**.

- We also do not need to call our own function `strcmp`.

<br><br>

```c
// Indexing into string's characters in C

text[i]
```
```py
# Indexing into string's characters in Python

text[i]
```
- Indexing into a string is the same in **C** and in **Python**.

<br><br>

### Dot Notation - `strip()`

Imagine prompting the user for a **string**:
```py
text = input("...")
```
```txt
" In the great green room  "
```
- Notice that the user's string is **not clean**, it has **extra spaces**, that could cause problems when working with the data.

<br><br>

```py
text = input("...")
text.strip()
```
```txt
"In the great green room"
```
- Applying the `strip()` function to the **text**, will clean the data by taking out the **beginning** and **trailing** **white spaces**.

- Notice the **dot notation** syntax `text.strip()`.

<br><br>

### `lower()`

```py
text = input("...")
```
```txt
" IN thE great green rOom  "
```
- Notice that the user's string is **not clean**, it is not **capitalized** properly.

<br><br>

```py
text = input("...")
text.lower()
```
```txt
"in the great green room"
```
- Applying the `lower()` function to the **text**, will clean the data by making all characters **lowercase**.

- Notice the **dot notation** syntax `text.lower()`.

<br><br>

### `capitalize()`

```py
text = input("...")
```
```txt
" IN thE great green rOom  "
```
- Notice that the user's string is **not clean**, it is not **capitalized** properly.

<br><br>

```py
text = input("...")
text.capitalize()
```
```txt
"In the great green room"
```
- Applying the `capitalize()` function to the **text**, will clean the data by making the **first character only**.

- Notice the **dot notation** syntax `text.capitalize()`.

<br><br>

> [!CAUTION]
> When using `text.capitalize()`, to apply the **Capitalization** to the string, it is necessary to **reassign** the result back to the variable like so `text = text.capitalize()`.

<br><br>

### `str`

Unlike in **C**, **Python** strings are **objects** that not only represent the **value** they hold (sequence of characters), but also have associated behaviors through functions or **methods**. The **Python** documentation lists all the built-in **string methods**.

<br><br>

## Loops

```py
text = "In the great green room"

for c in text:
    print(c)
```
- This loop iterates through every **character** of the string `In the great green room` and **prints** it one character per line.

<br><br>

```py
text = "In the great green room"

words = text.split()
```
```txt
['In', 'the', 'great', 'green', 'room']
```
- The method `split()` will split the **string** into elements separated by the **whitespace**. 

<br><br>

```py
text = "In the great green room"

words = text.split()
for word in words:
    print(word)
```
```txt
In 
the
great
green
room
```
- The method `split()` is used to split the **string** into elements separated by **whitespace**. 

- The loop will iterate through the resulting list of `words` printing each of them `word` in a new line.

<br><br>

> Notice that we did not have to define the new elements `word` or the list `words`. **Python**'s `for/in` syntax helps you iterate through components of an **iterable** (string, list, etc.) while referring to them by a convenient **name**.

<br><br>

Let's combine different **loops** and **strings** syntax and see what the output would be:
```py
text = "In the great green room"

for word in text.split():
    print(word)
```
```txt
In
the
great
green
room
```
- Notice that in **Python** the default behavior of a **print statement** is to automatically append a **new line**.

- We can override this with the `end=" "` **named parameter** `print(word, end=" ")`.

<br><br>

```py
text = "In the great green room"

for word in text.split():
    for c in word:
        print(c)
```
```txt
I
n
t
h
r
g
r
e
...
```
- Notice that there are no more **spaces**, `text.split()` removed the spaces

- First **loop** iterates through the `words`, while the **indented loop** iterates through each **character** `c` and prints it.

<br><br>

```py
text = "In the great green room"

for word in text.split():
    if "g" in word:
        print(word)
```
```txt
great
green
```
- The **loop** iterates through every element `word` the **list**, and prints it if in contains **character** `g` (implements **linear search**).

<br><br>

```py
text = "In the great green room"

for word in text.split()[2:]:
    print(word)
```
```txt
great
green
room
```
- This code uses **bracket notation** `[]` to **index** into a specific element of the **list**. Remember how we used `word[0]` to access the `1st` element, `word[1]` to access the `2nd` element, etc.

- This new syntax `[2:]` means to **index** into the second element of the list `2` and the **colon** `:` means to **include** the **following elements** of the list after that point.

- The **loop** basically **starts** iterating through the **list** at element`[2]`.

<br>

>[!NOTE] 
> This special syntax allows us to decide which elements of the list we want to **include**. `list[inclusive : exclusive]`. Let's imagine this scenario `list[1:4]`.<br>
This means to **start** including elements at index `1` and **exclude** element `4` and beyond, resulting in a list of elements `1, 2 and 3`.

<br><br>

## Dictionaries

**Dictionaries** are unordered, mutable data structures that allow you to store **key-value** pairs, where each key is unique and used to access its corresponding value.

<br>

Let's see an example of a **dictionary** called `authors` where the **key** is the *title* of a book, and the **value** the *author*:

|Key|Value|
|:-:|:-:|
|Goodnight Moon|Margaret Wise Brown|
|Corduroy|Don Freeman|
|Curious George|H.A. Ray|

<br>

We could also create one dictionary per `book`, holding information in several **key-value** combinations:

|Key|Value|
|:-:|:-:|
|Title|Goodnight Moon|
|Author|Margaret Wise Brown|

<br><br>

```py
# In Python 

book = dict()

book["title"] = "Corduroy"
book["author"] = "Don Freeman"
```
- Declares a **dictionary** called `book`.

- `book["title"]` Declares the **key**.

- `= "Corduroy"` Assigns the **value** to the key.

<br><br>

```py
book = dict()

book["title"] = "Corduroy"
book["author"] = "Don Freeman"

print(book["title"])
```
```txt
Corduroy
```
- `book["title"]` Placing the **key** inside the print statement will print the associated **value** of the book.

<br><br>

```py
book = dict()

book["title"] = "Corduroy"
book["author"] = "Don Freeman"

print(book["Corduroy"])
```
```txt
KeyError: 'Corduroy'
```
- Notice in the print statement, we put the **value** `Corduroy` inside the brackets `[]` instead of the **key** `title`. Attempting to print a **value** this way will result in an error `KeyError`.

<br><br>

Let's explore other syntax for creating **dictionaries**:
```py
# Alternative syntax

book = {
    "title": "Goodnight Moon",
    "author": "Margaret Wise Brown"
}
```
- This syntax allows us to create the **dictionary** and enter all the **data** upfront.

<br><br>

### List of Dictionaries

<br>

We could also create a **list** of **dictionaries**:
```py
books = [{"title": "Goodnight Moon",...},
{"title": "Corduroy",...},
{"title": "Curious George",...}]
```
- Inside the brackets `[]` is a **list** of **dictionaries**.

- Individual **dictionaries** are inside the curly braces `{}` and separated by comas `,`. Different dictionaries can have the same **key**.

<br><br>

|Title (key)|Author (Value)|
|:-:|:-:|
|Goodnight Moon|Margaret Wise Brown|
|Corduroy|Don Freeman|
|Curious George|H.A. Ray|

<br><br>

```py
# Create an empty list of books
books = []

# Add three books to shelf
for i in range(3):
    book = dict()
    book["author"] = input("Enter an author: ")
    book["title"] = input("Enter a title: ")
    books.append(book)

# Print list of books
for book in books:
    print(book)
```
```txt
{'author': 'Margaret Wise Brown', 'title': 'Goodnight Moon'}
{'author': 'Don Freeman', 'title': 'Corduroy'}
{'author': 'H.A. Ray', 'title': 'Curious George'}
```
- The **loop** creates `3` dictionaries called `book` by prompting the user for the **key** `author` and the **value** `title` and **appends** the book to the **list** called `books`.

- Notice the syntax `books.append(book)`. The method `append()` will add elements to the end of the list. `list.append(element)`.

- the second **loop** will print each dictionary `book` in a different line with its **keys** and **values** between `{}`.

<br><br>

Alternative **print statement**:
```py
# Print list of books
for book in books:
    print(f"{book['author']} wrote {book['title']}.")
```
```txt
Margaret Wise Brown wrote Goodnight Moon
Don Freeman wrote Corduroy
H.A. Ray wrote Curious George
```
- Notice the `f` **f-string** syntax in the print statement, allowing us to **embed** the **keys** inside **string literals** `{book['author']}` to access the **values**.

<br><br>

## Libraries and Modules

In the previous example we saw how to prompt the user to enter **data** **manually**, but this method can be strenuous when using a **large data set**. To make this processes more efficient we can also **read data** from a **spreadsheet**.

<br><br>

1. **Spreadsheet**: 

    <br>

    |Title (key)|Author (Value)|
    |:-:|:-:|
    |Goodnight Moon|Margaret Wise Brown|
    |Corduroy|Don Freeman|
    |Curious George|H.A. Ray|
    |Winnie-the-pooh|A.A. Milne|
    |Fantastic Mr. Fox|Roald Dahl|
    |Charlotte's Web|E.B. White|
    |...|...|

<br><br>

2. **Export** the data from the **spreadsheet** into a **CSV** (Comma-Separated Values) file, a common file format used for it's simplicity and portability.

    <br>

    **books.csv**:
    ```txt
    title,author
    Goodnight Moon,Margaret Wise Brown
    Corduroy,Don Freeman
    Curious George,H.A. Ray
    Winnie-the-pooh,A.A. Milne
    Fantastic Mr. Fox,Roald Dahl
    Charlotte's Web,E.B. White
    ...,...
    ```
<br><br>

3. **Read/Write** from the **CSV** file. **Python** has a built-in **CSV module** that provides **methods** for reading and writing.

    <br>

    ```py
    import csv
    ```
    - Placing this line at the top of our **Python** file will import the **entire** `CSV` **module**, including all of its **methods** (**DictReader()**, **DictWriter()**, **reader()**, **writer()**, etc.).

    <br>

    ```py
    csv.DictReader(...)
    csv.reader(...)
    ```
    - To access a specific **method** in the `CSV` **module** we have to use the **dot notation** `module prefix.method()`

    <br><br>

    We can also choose to **only** import a **specific method** in the `CSV` **module**:
    ```py
    from csv import DictReader
    ```
    - Placing this line at the top of our **Python** file will only import the `DictReader()` **method** from the `CSV` **module**.

    <br>

    ```py
    from csv import DictReader

    DictReader(...)
    ```
    - Notice that we did not have to include the **module prefix** `csv.` when calling `DictReader()`. This is because we imported the method **directly**.

    <br><br>

## File I/O

**Python** provides powerful and efficient **functions** for **file handling**. These functions allow us to **open**, **read** from, **write** to and **close** files.

<br>

1. **Opening** a file:

    ```py
    with open(FILENAME) as file:
    ```
    - `with` starts the **context manager** that will manage the file resource.

    - `open()` opens the file `FILENAME` in **read** mode by default.

    - `as file` Assigns the **opened file object** to the **variable** `file` (to be used to perform operation on the file).

<br><br>

2. **Reading** from a file:

    ```py
    # Reading from a text file

    with open(FILENAME) as file:
        text = file.read()
    ```
    - The code **inside** the `with` **block** will be executed with the **file open** and assigned to the `file` variable. (`with` will also automatically **close** the file as soon as we are no longer **indented** in the block).

    - `text = file.read()` **Reads** the **entire data** in the file into the variable `text`.

    - This works really well for plain text **.txt** files.

    <br><br>

    For **CSV** files, it is better suited to use Python's `CSV` **module**:
    ```py
    # Reading from a csv file

    with open(FILENAME) as file:
        file_reader = csv.DictReader(file)
        for row in file_reader:
            ...
    ```
    - `file_reader = csv.DictReader(file)` Creates a `DictReader` object named `file_reader`, that reads each **row** of the **CSV** file as a **dictionary**.

    - The **keys** of the dictionary are derived from the **first row** (**header**) of the `csv` file.

    - `for row in file_reader` This line starts a **loop** that will iterate over each **row** (dictionary) in the `file_reader`.

<br><br>

### `reads.py`

```py
import csv

with open("books.csv") as file:
    text = file.read(file)
    print(text)
```
```txt
title,author
Goodnight Moon,Margaret Wise Brown
Corduroy,Don Freeman
Curious George,H.A. Ray
Winnie-the-Pooh,A.A. Milne
Fantastic Mr. Fox,Roald Dahl
Charlotte's Web,E.B. White
...
```
- Notice that **reading** from a **CSV** file with `read()` will read **all** the content of the file **row by row**.

<br><br>

Now, let's use **CSV** module specific **methods**:
```py
import csv

with open("books.csv") as file:
    reader = csv.DictReader(file)
    for row in reader:
        print(row)
```
```txt
{'title': 'Goodnight Moon', 'author': 'Margaret Wise Brown'}
{'title': 'Corduroy','author': 'Don Freeman'}
{'title': 'Curious George', 'author': 'H.A. Ray'}
{'title': 'Winnie-the-Pooh', 'author': 'A.A. Milne'}
{'title': 'Fantastic Mr. Fox', 'author': 'Roald Dahl'}
{'title': 'Charlotte's Web', 'author': 'E.B. White'}
```
- Notice now that **reading** from the same **CSV** file using `csv.DictReader` will create **dictionaries** for each **row** using the first row `title, author` to make the **keys**.

<br><br>

Let's complete the program above:
```py
import csv

books = []

# Add books to the shelf by reading from books.csv
with open("books.csv") as file:
    reader = csv.DictReader(file)
    for row in reader:
        books.append(row)

# Print books
for book in books:
    print(book)
```
1. Import the `csv` module.

2. Create an empty **list** named `books`.

3. **Open** `books.csv` content and store it in `file`.

4. **Read** from `file` using `DictReader()`, which will create a **iterable object** of **dictionaries**, one for each **row** of `file`. Store this **iterable** in **object** `reader`.

5.  **Loop** through each **row** of `reader` (each **dictionary**) and use `append()` to **add** it to the **list** named `books`.

6. **Print** each element (`book`) of the `books` list.

<br><br>

