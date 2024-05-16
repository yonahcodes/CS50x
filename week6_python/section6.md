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

### Dot Notation

### `strip()`

Imagine prompting the user for a **string**:
```py
text = input("...")
```
```txt
" In the great green room  "
```
- Notice that the user's string is **not clean**, it has **extra spaces**, that could cause problems when working with the data.

<br>

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

<br>

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

<br>

```py
text = input("...")
text.capitalize()
```
```txt
"In the great green room"
```
- Applying the `capitalize()` function to the **text**, will clean the data by making the **first character only**.

- Notice the **dot notation** syntax `text.capitalize()`.

<br>

> [!CAUTION]
> When using `text.capitalize()`, to apply the **Capitalization** to the string, it is necessary to **reassign** the result back to the variable like so `text = text.capitalize()`.

<br><br>

### `str`

Unlike in **C**, **Python** strings are **objects** that not only represent the **value** they hold (sequence of characters), but also have associated behaviors through functions or **methods**. The **Python** documentation lists all the built-in **string methods**.

<br>

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

Section 00:36:00
