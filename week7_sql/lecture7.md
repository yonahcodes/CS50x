# CS50x Week 7 - SQL

**SQL** (Structured Query Language) is the standard language used to interact with **relational databases**. It enables programmers to execute various operations such as creating, retrieving, updating, and deleting **data**. 

**SQL** is design to handle data in a **tabular form**, where data is organized into **rows** and **columns**, and it provides powerful **query** capabilities that allow users to manage millions of records with ease.

<br>

## Flat-File Database

**Spreadsheets** like those created in **Microsoft Excel** and **Google Sheets** can be outputted to a `csv` or **comma-separated values** file. `csv` files are **flat file databases**, **single tables** storing data  in a plain **text** where each line represents a single **record** and **fields** are separated by **delimiters** (commas).

<br>

Importing a `.csv` file to **VSCode**:
```txt
Timestamp,language,problem
10/30/2023 13:38:01,Python,"Hello, World"
10/30/2023 13:38:01,Python,DNA
10/30/2023 13:38:01,Python,"Hello, World"
10/30/2023 13:38:01,Python,Scratch
...
```
- The first row is the **Header row** containing the title of each column. 

- Notice in the `"Hello, world"` problem, double quotes `""` where added automatically in order not to confuse the coma separated words with two different **fields**.

<br>

**Python** comes with **built-in** support for **csv** files
```py
import csv

# Open CSV file in "read mode"
with open("favorites.csv", "r") as file:
    
    # Create reader
    reader = csv.reader(file)
    
    # Skip header row
    next(reader)
    
    # Iterate over CSV file, printing each favorite
    for row in reader:
        print(row[1])
```
```txt
Python
Python
Python
Scratch
Python
Python
...
```
- `with` is a **control flow structure** that allows us to start an indented block of code containing instructions and **automatically close** the file when the block ends.

- `open()` is a built-in function used to open a file and return a **file object**.

- `as file` binds the file to the `file` variable that will be used inside the block to perform operations on the file.

- `reader = csv.reader(file)` A `csv.reader` **object** is created which allows us to **iterate over lines** in the `csv` file, convert them into a **list of strings** and store the in `reader`.

- The **for loop** iterates through each row in the `csv` file and prints the **second element** `row[1]` of each row (the second column).

<br>

```py
import csv

# Open CSV file in "read mode"
with open("favorites.csv", "r") as file:
    
    # Create reader
    reader = csv.reader(file)
    
    # Skip header row
    next(reader)
    
    # Iterate over CSV file, printing each favorite
    for row in reader:
        favorite = row[1]
        print(favorite)
```
- In this version we store the variable `favorite` to store the data in `row[1]`.

<br>

> [!NOTE]
> One of the **disadvantages** of this approach is that we are trusting that `row[1]` is always the favorite and no changes have been made to the file like swapping columns.

<br>

We can resolve this issue by modifying our code as follows
```py
import csv

# Open CSV file in "read mode"
with open("favorites.csv", "r") as file:
    
    # Create Dict.Reader
    reader = csv.DictReader(file)
    
    # Iterate over CSV file, printing each favorite
    for row in reader:
        print(row["language"])   
```
- In this version we are using `csv.DictReader` which will create a **dictionary** for each column in the file, identify the **headers** in the first row as **keys**.

- `row["language"]` is now using the **key** to index into the **dictionary**.

<br>

### Analyzing the data

```py
import csv

# Open CSV file
with open("favorites.csv", "r") as file:

    # Create DictReader
    reader = csv.DictReader(file)

    # Counts
    scratch, c, python = 0, 0, 0

    # Iterate over the CSV file, counting the favorites
    for row in reader:
        favorite = row["language"]
        if favorite == "Scratch":
            scratch += 1
        elif favorite == "C":
            c += 1
        elif favorite == "Python":
            python += 1

# Print counts
print(f"Scratch: {scratch}")
print(f"C: {c}")
print(f"Python: {python}")
```
```txt
Scratch: 40
C: 78
Python: 280
```
- Notice the we initialized **counters** for each language and used `if` statements and `==` signs to **increment** the counts when a match is found.

- In the `print` statements, we used `f` **formatted** and `{}` to include the variables values.

<br>

We can further improve our code using **Python**'s ability to **sort counts**
```py
import csv

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    counts = {}

    for row in reader:
        favorite = row["language"]
        if favorite in counts:
            counts[favorite] += 1
        else:
            counts[favorite] = 1

for favorite in sorted(counts):
    print(f"{favorite}: {counts[favorite]}")
```
- In this version, instead of initializing a counter for each language, we create a empty **dictionary** `counts = {}`.

- The **for loop** will iterate through each row, extract the value under **language** and store it in `favorite`

- `if` the **language** exists in the dictionary as a **key** it **increments** the count by `1`. If it doesn't, it it increments by `1` indicating the first appearance.

- The `print` statement uses a `f-string` to **embed** the variables directly in the string.  

<br>

> Notice we used the `sorted()` function to sort the languages alphabetically (**by key**). If the function was not used the order would be in which language **appeared first**.

<br><br>

We could also tell **Python** how to **sort** the items by passing arguments to `sorted()`
```py
for favorite in sorted(counts, key=counts.get):
    print(f"{favorite}: {counts[favorite]}")
```
```txt
Scratch: 40
C: 78
Python: 280
```
- `key = counts.get` The `key` argument is used to modify the **sorting method**. In this case `counts.get` is used to sort **by the values**, smallest to largest value (40, 78, 280).

<br>

We can also **reverse the order** to **largest to smallest** by adding `reverse=True`

```py
for favorite in sorted(counts, key=counts.get, reverse=True):
    print(f"{favorite}: {counts[favorite]}")
```
```txt
Python: 280
C: 78
Scratch: 40
```
<br>

We can also use the library `collections` and its `Counter` class, which will allow us to access the **counts** of each language without all the **if statements**
```py
import csv

from collections import Counter

# Open CSV file
with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    counts = Counter()

    # Iterate over CSV file, counting favorites
    for row in reader:
        favorite = row["language"]
        counts[favorite] += 1

# Print counts
for favorite, count in counts.most_common():
    print(f"{favorite}: {count}")
```
```txt
Python: 280
C: 78
Scratch: 40
```
- Notice how `counts = Counter()` enables the use of this imported `Counter` class from `collections`.

- The first **loop** increments the `counts` object.

- The second **loop** uses the built-in method `counts.most_common()` to return a **pair** of **key-value**.

<br>

To change the **column** we are examining, focusing on favorite **problem** instead of language, we simply replace `row["language"]` by `row["problem"]`
```py
import csv

from collections import Counter

# Open CSV file
with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    counts = Counter()

    # Iterate over CSV file, counting favorites
    for row in reader:
        favorite = row["problem"]
        counts[favorite] += 1

# Print counts
for favorite, count in counts.most_common():
    print(f"{favorite}: {count}")
```
<br>

We could also make the program more interactive and get the count of the popularity of a **specific problem** by **prompting the user** for favorite problem and printing the **count**.
```py
import csv

from collections import Counter

# Open CSV file
with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    counts = Counter()

    # Iterate over CSV file, counting favorites
    for row in reader:
        favorite = row["problem"]
        counts[favorite] += 1

# Print count
favorite = input("Favorite: ")
print(f"{favorite}: {counts[favorite]}")
```
```txt
Favorite: Hello, World 
```
```txt
Hello, World: 65
```
<br>

## Relational Databases

A Relational Database Management System is a type of database management system that stores data in a structured format using **tables** with rows and columns. Many relational database systems are equipped with the option of using `SQL` (Structured Query Language) for querying and updating the database.

SQL allows for four types of commands (**CRUD**):
````
CREATE, INSERT
READ
UPDATE
DELETE, DROP
````

To create a database with the SQL syntax :
````sql
CREATE TABLE table (column type, ...);
````
<br>

### sqlite3

`sqlite3` is a type of **SQL database** that has the core features required for an introduction to **SQL**.

To create a SQL database at the terminal: `sqlite3 filename`
```zsh
sqlite3 favorites.db
```
We are now using `sqlite3` program. It looks like this:
````zsh
sqlite>
````
To exit sqlite:
```zsh
.quit
```
To come back to the database:
```zsh
sqlite3 favorites.db
```
<br>

To put sqlite into csv mode by typing:
```zsh
.mode csv.
```
Then, we can import our data from our `csv` file into the database:
```zsh
.import favorites.csv favorites
```
<br>

We can type `.schema` to see the structure of the database:
```zsh
CREATE TABLE IF NOT EXISTS "favorites"(
"Timestamp" TEXT, "language" TEXT, "problem" TEXT);
```
<br>

To read items from a table:
```sql
SELECT columns FROM table
```
To read all data from our database use `*`
```sql
SELECT * FROM favorites;
```
Output
```zsh
"10/15/2024 3:40:19",Python,Scratch
"10/15/2024 4:41:52",Python,"Hello, World"
"10/15/2024 8:16:53",C,Tideman
"10/15/2024 10:28:48",Python,Tideman
"10/15/2024 10:28:51",Python,Mario
"10/15/2024 10:28:51",Python,Credit
"10/15/2024 10:28:52",Python,Filter
"10/15/2024 10:28:54",Python,Filter
"10/15/2024 10:28:55",Python,Tideman
"10/15/2024 10:28:55",Python,"Hello, World"
...
```
