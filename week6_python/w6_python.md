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

**Python** **arrays** (more appropriately known as **lists**) are **dynamic** and not fixed in size; they can grow and shrink as needed and we can add and remove elements easily.

<br>

### Declaring a list
```py
nums = []
```
- Creates an empty **list**.

<br>

```py
nums = [1, 2, 3, 4]
```
- Creates a **list** of **integers** with `4` elements.

<br>

```py
nums = [x for x in range(500)]
```
- Notice the **for loop** inside the list declaration, this is known as a **list comprehension**. It creates a list of **integers** from 0 to 499.

<br>

```py
nums = list()
```
- Creates a **list** using the `list()` function. If no value is passed to the function it will create an **empty** list.

<br><br>

### Tacking on to a list
```py
nums = [1, 2, 3, 4]
nums.append(5)
```
- The `append()` function, adds element `5` to the **end** of the **list**

<br>

```py
nums = [1, 2, 3, 4]
nums.insert(4, 5)
```
- The `insert()` function, adds element `5` to the `4th` **index** of the **list**. Remember the **first** element of the list `1` is in **index** `0`. 

<br>

```py
nums = [1, 2, 3, 4]
nums[len(nums):] = [5]
```
- Using **slice assignment** to **append** the element `5` to the end of `nums`.

- `len(nums)` returns the length of list `nums`, which is `4`.

- `nums[len(nums):]` (`nums[4:]`) is a **slice** of the list starting at index `4`, which is an **empty** index following the last element of the list.

- `=[5]` Assigns the list `[5]` to empty index `4` of `nums`, effectively merging both lists.

<br><br>

## Tuples

**Tuples** are **ordered**, **immutable** sets of data; they are useful and efficient when associating collections of data, similar to **structs** in **C**, but where the values are **unlikely to change**.

<br>

### Creating a List of Tuples

```py
presidents = [
    ("George Washington", 1789),
    ("John Adams", 1797),
    ("Thomas Jefferson", 1801),
    ("James Madison", 1809)
]
```
- This is a **list** `presidents`, of **4 tuples** each declared between **parenthesis** `()` and separated by a **coma** `,`.

<br><br>

This **list** of **tuples** is **iterable**:
```py
for prez, year in presidents:
    print("In {1}, {0} took office".format(prez,year))
```
- Notice that we use the **tuple**'s format (**prez, year**) in the **for loop** to iterate through the **list** `presidents`.

- In the **print statement** we use the `format()` function and **placeholders**, similar to `%s` in **C**, in this case `{1}, {0}` to specify the **order** in which we want the **parameters** of the **tuple** to be printed.

- `{1}` represents **second parameter** `format(..., year)`, while `{0}` represents **first parameter** `format(prez,...)`. 

- If we take the example of the **first tuple**, this will result in printing `"In 1789, George Washington took office"`.

<br><br>

## Dictionaries

**Dictionaries** are unordered, mutable data structures that allow you to store **key-value** pairs, where each key is unique and used to access its corresponding value.

**Python** has built-in support for **dictionaries**, allowing you to access an associated **value** in a **list** using **keywords** as an **index**, instead of **integers**, which we were restricted to in **C**.

<br>

```py
pizzas = {
"cheese": 9,
"pepperoni": 10,
"vegetable": 11,
"buffalo chicken": 12
}
```
- This is a **dictionary** called `pizzas` holding **4** **key-value** pairs separated by **comas** `,`.

- `"key" : value` The **key** is between **quotes** `""`, followed by a **colon** `:` separator, followed by the **value**.

<br>

### Changing the value associated to a key

```py
pizzas["cheese"] = 8
```
- We can access and update a specific **value** using the **key** to index into the dictionary. 

- `pizza["cheese"]` will access the **index** represented by the **key** `cheese` and assign to it new **value** `8`.

<br><br>

```py
if pizzas["vegetables"] < 12:
    # Do something
```
- We could use **conditionals** and **Boolean** expressions to access **values** and perform operations with them.

<br><br>

```py
pizzas["pineapple"] = 14
```
- We can use the same syntax to add a new **key-value** pair that does not exist in the **dictionary**.

<br><br>

## Loops (redux)

To **iterate through** the elements of a **dictionary** we cannot use an **integer** index range `[0, n-1]`. The **for loop** in **Python** is extremely flexible and can include **keywords**.

```py
for pie in pizzas:
    # Do something
```
- Notice what we used `pie` as the **loop variable**, which is an **arbitrary name** we decided to use, we are not limited to the classic `i`.

<br><br>

```py
for pie in pizzas:
    print(pie)
```
```txt
cheese
pepperoni
vegetable
buffalo chicken
```
- This **loop** will iterate through every element in the dictionary `pizza` and print out all the `keys` represented by **loop variable** `pie`.

<br><br>

```py
for pie, price in pizzas.items():
    print(price)
```
```txt
12
10
9
11
```
- We can iterate through the **key-value pairs** of the dictionary using `pie, price` (key, value) as a two parameter **loop variable**.

- Notice the use of `pizza.items()`: Adding the `.items()` **method** to the dictionary will allow us to iterate over all the associated **key-value** pairs.

- The `.items()` **method** returns a view object that displays a list of a dictionary's **key-value** pairs, allowing us to access and print the **values**.

<br>

> Note that the in this process, we are **not guaranteed** that the dictionary is going to maintain its **original order**.

<br><br>

```py
for pie, price in pizzas.items():
    print("A whole {} pizza costs ${}".format(pie, price))
```
```txt
A whole buffalo chicken pizza costs $12
A whole cheese pizza costs $9
...
```
- If we want to print both the **keys** and the **values**, we change the **print statement** using the function `format()`.

- Notice that the placeholders `{}` representing the **parameters** `pie, price` have no **index** specified. This is because we are printing the **key** first and the **value** second in order.

<br>

> Again, remember that the order in which the dictionaries are printed is not guaranteed. The key-value pairs are always respected.

<br><br>

## Printing and Variable Interpolation

```py
print("A whole {} pizza costs ${}".format(pie, price))
```

- `format()` allows us to **interpolate** variables into our print statements in a way that is similar to **C**'s **printf**. 

<br><br>

We can also achieve the same result using other syntax:
```py
print("A whole " + pie + " pizza costs $" + str(price))
```
- Here we used the `+` sign to **concatenate** the **strings** with the **variables**. Notice that we had to convert the format of the `price` variable, which had **integer** values to **string** using the `string()` function.

<br><br>

```py
print("A whole %s pizza costs $%2d" % (pie, price))
```
- Although this syntax is very similar to **C**, it is better to **avoid**. It is now deprecated in **Python 3**.

<br><br>

## Functions

**Python functions** are introduced using the `def` keyword, and like variables, they do not require specifying the **return type** or the **data types** of the **parameters**. Additionally, it is not required to define a `main()` function, as the **interpreter** reads the code from top to bottom. 

In **Python**, it is still possible to **define** a `main()` function if the structure of our program requires it, but if `main()` is not the **first function** in the program, we must tell the **interpreter** to **prioritize** it by including this line at the end of our code:
```py
if __name__ == "__main__":
    main()
```

<br><br>

### Defining Functions

```py
def square(x):
    return x * x
```
- `def` Defines the `square()` function, which takes one **parameter** `x` and **returns** the result of the operation in the **indented block**.

<br><br>

```py
def square(x):
    return x ** 2
```
- This code achieves the same result as before using the **built-in** **exponentiation operator** `**` to raise `x` to the `2`nd power.

<br><br>

```py
def square(x):
    result = 0
    for i in range (0, x):
        result += x
    return result

print(square(5))
```
- We could also use a **for loop** to achieve this.

- The variable `result` is **initialized** at `0`. It will be used to **accumulate the result** of the operation.

- `range(0, x)`The loop will **iterate** through `0` to `x-1`.

- `result += x` During each iteration `x` is **added** to the result.

- `return result` After the loop completes, the function returns the updated `result`.

- The print statement **calls** the `square()` function with parameter `5` (which replaces `x`).

<br><br>

## Objects

**Python** is an **object-oriented** programming language. An **object** is analogous to a **C** **structure**. **C** **structures** contain a number of **fields** or **properties**, but the properties cannot exist independently.

<br>

```c
// Struct definition in C

struct car
{
    int year;
    char *model;
}

// Creating an instance and setting properties 

struct car herbie;
herbie.year = 1963;
herbie.model = "Beetle";
```
- Notice we included the **struct** `herbie` when defining its properties.

<br>

```c
struct car herbie;
year = 1963;
model = "Beetle";
```
- This would **not** be valid in **C**, properties **cannot exist** without the struct.

<br><br>

**Objects** not only have **properties**, but also **methods** or **functions** that are inherent to the object and have no meaning outside of it. These **methods** are defined within the object as well.

Instead of passing an object into a **function** `function(object)`, we call **methods** on objects:
```c
object.method()
```
<br><br>

Similar to **C structs**, we can define a new type of **object** using the `class` keyword in **Python**. **Classes** require an **initialization function**, also more-generally known as a **constructor**, which sets the **initial values** of the object's **properties**. 

In addition to defining properties, we also define **methods** that operate on the object. Every **method** must include at least **one parameter**, typically `self`, which refers to the instance of the object on which the method is called.

<br><br>

```py
class Student():

    def __init__(self, name, id):
        self.name = name
        self.id = id
    
    def changeID(self, id):
        self.id = id
    
    def print(self):
        print("{} - {}".format(self.name, self.id))
```
1. A new **class** names `Student` is defined (a class is a blueprint for creating **objects**).

2. The **constructor** method `__init__` is defined and **3** parameters are passed to it; `self` which refers to the instance being created, `name` and `id`.

3. **Values** of the **parameters** are assigned to the attributes of the object: `self.name = name` & `self.id = id`.

4. A **method** called `changeID` is defined. It allows the `id` **attribute** to be updated.

5. Another **method** called `print()` is defined. It prints out the `name` and `id ` attributes of the object in a **formatted** string.

<br><br>

```py
# Create a new Student object
jane = Student("Jane", 10)

# Print the details of jane
jane.print()

# Change the ID of jane
jane.changeID(11)

# Print the updated details of jane
jane.print()
```

<br><br>

> [!NOTE] 
> Good style is **crucial** in **Python**. Proper use of tabs and **indentation** is part of the syntax in this language, and neglecting style can lead to errors.

<br><br>

## Including Files

Just like in **C**, **Python** programs can consist of multiple files to form a single program.
```c
// Linking to a header file or library in C 

#include <cs50.h>
```
<br>

```py
# Linking to a module in Python

import CS50
```
<br>

To call a function from the `CS50` **module** the **dot syntax** syntax is used.
```py
cs50.get_int()

cs50.get_float()

cs50.get_string()
```
<br>

We can also import a specific **method** instead of the whole **module**.
```py
from cs50 import get_int
```
<br>

**Python** programs can be prewritten in `.py` files. If the program is not too complex, it can also be written directly in the **Python interpreter** at the **command lime**. To run a **Python** file through the interpreter, we enter in the command line `python <file>`.



