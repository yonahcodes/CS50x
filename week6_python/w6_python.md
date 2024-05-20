# Python

**Python** is an example of a very commonly-used modern programming language. In comparison to **C** that was first released in 1972, **Python** was released in 1991. **Python** is an excellent and versatile language choice for making complex **C** operations much simpler.

**Python** is also heavily inspired by **C** (its primary interpreter, **Cpython**, is actually written in **C**) and so the syntax should be a shallow learning curve.

## Variables
**Python** variables have two big differences from **C**:
- No **type** specifier
- Declared by **initialization** only.

<br>

```c
// C

int c = 54;
```
```py
# Python

x = 54
```
- Notice also that we no longer need the **semicolon** `;` in **Python**.

<br><br>

```c
// C

char *phrase = "This is CS50";
```
```py
# Python

phrase = "This is CS50"
```
- Note that **single quotes** `''`can be used also instead of **double quotes** `""`.

<br><br>

## Conditionals

All of the **C** conditionals are still available in **Python** with a slightly different syntax.

```c
// C

if (y < 43 || z == 15)
{
    // code goes here
}
```
```py
# Python

if y < 43 or z == 15:
    # code goes here
```
- Notice the use of `or` instead of `||`. Also notice use of **colon** `:` and **indentation** instead of the **curly braces** `{}`.

<br><br>

```c
// C

if (y < 43 && z == 15)
{
    // code block 1
}
else
{
    // code block 2
}
```
```py
# Python

if y < 43 and z == 15:
    # code block 1
else:
    # code block 2
```
- Notice the use of `and` instead of `&&`.

 <br><br>

 ```c
// C

if (coursenum == 50)
{
    // code block 1
}
else if (coursenum != 51)
{
    // code block 2
}
```
```py
# Python

if coursenum == 50:
    # code block 1
elif not coursenum == 51:
    # code block 2
```
- Notice the use of `not` instead of `!=`, and `elif` keyword representing `else if` in **C**.

<br><br>

 ```c
// C

char var = get_char();
bool alphabetic = isalpha(var) ? true : false;
```
- Prompt for a **char**, if the **char** is a letter it gets assigned **true** if not, **false**.
```py
# Python

letters_only = True if input().isalpha() else False
```
- Notice the use of `input()` function to prompt user for data. In **Python** `True/False` are capitalized.

<br><br>

## Loops

In **Python** there are **two** kind of **loops**, `while` and `for`.

 ```c
// C

int counter = 0;
while (counter < 100)
{
    printf("%i\n", counter);
    counter++;
}
```
```py
# Python

counter = 0
while counter < 100
    print(counter)
    counter += 1
```
- Notice the lack of **parenthesis** `()` in the **while loop**. Notice also there is no **placeholder** `%i` or **new line** `\n` in the print statement. The syntax `++` does not exist in **Python**, instead `+=` is used.

<br><br>

 ```c
// C

for (int x = 0; x < 100; x++)
{
    printf("%i\n", x);
}
```
```py
# Python

for x in range(100):
    print(x)
```
- Notice that in **Python** there is no need to **manage** the loop's functionality (initialize and increment manually).
- `range()` is a function is **Python** that gives us a list of numbers in this case from `0-99`

<br><br>

 ```c
// C

for (int x = 0; x < 100; x += 2)
{
    printf("%i\n", x)
}
```
```py
# Python

for x in range(0, 100, 2):
    print(x)
```
- Notice in **Python** to increment by `+2`, we need pass to the following arguments to the `range()` function `(0, 100, 2)`, `0` being the **starting point**, `100` the **range** (not including 100), `2` the **increment**.

<br><br>

## Arrays

Short 00:10:22
