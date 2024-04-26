# Hash Tables

**Hash tables** are data structures that provide fast data retrieval by using a **hash function** to compute an **index** into an **array of buckets** where the desired value can be found. Hash tables combine the random access of an *array* with the dynamism of a *linked list*.

This method allows for almost **constant time complexity** `O(1)` for **lookup**, **insertion**, and **deletion** (assuming we define the hash tables well). We create a **hash function** that takes a **key** as *input* and produces an **index** as *output* that suggests where the key should be placed in the table. 

<br>

**Hash tables** are a combination of two things:
- A **Hash Function**, which returns a nonnegative integer value called **hash code**.
- An **Array** capable of storing data of the type we wish to place into the data structure.

<br>

The main idea is that we run the **data** through the **hash function** and **store** it in the **element of the array** represented by the returned **hash code**. The **data** itself helps determine where it will be stored and this direct mapping allows for **fast** data retrieval. The trade off is that **hash tables** are not good at **ordering** or **sorting** data. 

<br><br>

## Hash Tables in C

```c
// Define an array of 10 strings
char *hashtable[10];
```
```txt
| 0 |                   |
| 1 |                   |
| 2 |                   |
| 3 |                   |
| 4 |                   |
| 5 |                   |
| 6 |                   |
| 7 |                   |
| 8 |                   |
| 9 |                   |
```
<br><br>

Imagine we wanted to *hash* the string `John` in our table. 
```c
int x = hash("John");
```
```c
x = 4;
```
```txt
| 0 |                   |
| 1 |                   |
| 2 |                   |
| 3 |                   |
| 4 |      "John"       |
| 5 |                   |
| 6 |                   |
| 7 |                   |
| 8 |                   |
| 9 |                   |
```
```c
hashtable[x] = "John";
```
- The string `"John"` is input into the `hash()` function, which computes a numerical value. In this case it returns `4`.

- The computed hash value `4` is stored in the variable `x` which is used as an **index** to access a specific **slot** in the **hash table**.

- The string `"John"` is assigned to the slot at **index** `x` in the hash table, effectively placing it in the `4`th slot.

<br><br>

It's the same process if we want to **add** more data to the hash table.
```c
// int x = hash("John")

int y = hash("Paul");
```
```c
// x = 4;
x = 6;
```
```txt
| 0 |                   |
| 1 |                   |
| 2 |                   |
| 3 |                   |
| 4 |      "John"       |
| 5 |                   |
| 6 |      "Paul"       |
| 7 |                   |
| 8 |                   |
| 9 |                   |
```
```c
// hashtable[x] = "John";

hashtable[y] = "Paul";
```
- The string `"Paul"` is input into the `hash()` function, which computes a numerical value. In this case it returns `6`.

- The computed hash value `6` is stored in the variable `y` which is used as an **index** to access a specific **slot** in the **hash table**.

- The string `"Paul"` is assigned to the slot at **index** `y` in the hash table, effectively placing it in the `6`th slot.

<br><br>

## Defining a Hash Function

To define a **good hash function** there are key characteristics to consider. Each of the following points is crucial for ensuring that a hash function is **effective**:

- Use only data being hashed (Ensure integrity and consistency of the hash function) 

- Use all of the data being hashed (Ensure uniform distribution and reduce collisions)

- Be deterministic (Same input should always produce same output)

- Uniformly distribute data (Uneven distribution increases collision risk)

- Generate very different hash codes for very similar data (minimizes collisions and maintains good performance)

<br><br>

```c
unsigned int hash(char* str)
{
    int sum = 0;
    for (int j = 0; str[j] != '\0'; j++)
    {
        sum += str[j];
    }
    return sum % HASH_MAX;
}
```
- Define a function `hash` that takes a single argument `str`, which is a string and returns an `unsigned int` value, which is the **hash code** computed from the input string.

- `int sum = 0;` Initializes a counter variable `sum` that will be used to sum the **ASCII** values of the **characters** in the string.

- `for (int j = 0; str[j] != '\0'; j++)` **Loop** through each character of the input string `str` until it reached the null character `\0`, which marks the **end of the string**. Index `j` is used to access each character.

- `sum += str[j];` Each character or the string is converted to its **ASCII** integer value and added to `sum`.

- `return sum % HASH_MAX;` The final line returns the computed **hash code**. Calculates the **remainder** of `sum` divided by `HASH_MAX` (a constant that represents the maximum number of buckets in the hash table).

<br>

> [!NOTE]
> It is good practice to use a **well-tested**, **established** **hash function** rather than attempting to write your own. This approach leverages the collective expertise of the developer community and ensures the **efficiency** and **reliability** of the function while **reducing complexity**. (Remember to **give credit** the authors).

<br><br>

## Resolving Collisions

Let's imagine a scenario where we **hash** a new **string** `"Ringo"` and it returns the **same hash code** as a previous string `6`.
```c
// int x = hash("John")
// int y = hash("Paul");

int z = hash("Ringo");
```
```c
// x = 4;
// y = 6;

z = 6;
```
```txt
| 0 |                   |
| 1 |                   |
| 2 |                   |
| 3 |                   |
| 4 |      "John"       |
| 5 |                   |
| 6 |      "Paul"       |
| 7 |                   |
| 8 |                   |
| 9 |                   |
```
```c
// hashtable[x] = "John";
// hashtable[y] = "Paul";

hashtable[z] = "Ringo";
```
> [!IMPORTANT]
> A **collision** occurs when two pieces of **data**, when run through the **hash function**, yield the **same hash code**.

<br>

Presumably we want to store **both** pieces of data `"Paul"` and `"Ringo"` in the hash table, so we should not replace `"Paul"` by `"Ringo"`. Instead, we need to find a way to get **both elements** into the hash table while trying to preserve **quick** insertion and lookup.

<br><br>

### Linear Probing

**Linear probing** is a method used in hash tables to **resolve collisions** (two elements are assigned to the same bucket). If we have a collision, it tries to place the data in the **next consecutive slot** in the array. If the next slot is also occupied, linear probing continues to **check subsequent slots** until a empty slot is found (**wrapping around** to the beginning if necessary).

<br>

**Example**:
```c
hash("Ringo"); returns 6
```
```txt
| 0 |                   |
| 1 |                   |
| 2 |                   |
| 3 |                   |
| 4 |      "John"       |
| 5 |                   |
| 6 |      "Paul"       | <--- Slot 6 Occupied
| 7 |      "Ringo"      | <--- Place in the next consecutive free slot
| 8 |                   |
| 9 |                   |
```
<br><br>

```c
hash("Bart"); returns 7
```
```txt
| 0 |                   |
| 1 |                   |
| 2 |                   |
| 3 |                   |
| 4 |      "John"       |
| 5 |                   |
| 6 |      "Paul"       | 
| 7 |      "Ringo"      | <--- Slot 7 Occupied
| 8 |      "Bart"       | <--- Place in the next consecutive free slot
| 9 |                   |
```
<br><br>

```c
hash("Lisa"); returns 3
```
```txt
| 0 |                   |
| 1 |                   |
| 2 |                   |
| 3 |      "Lisa"       | <--- Place in empty slot 3
| 4 |      "John"       |
| 5 |                   |
| 6 |      "Paul"       | 
| 7 |      "Ringo"      | 
| 8 |      "Bart"       | 
| 9 |                   |
```
<br><br>

```c
hash("Homer"); returns 6
```
```txt
| 0 |                   |
| 1 |                   |
| 2 |                   |
| 3 |      "Lisa"       | 
| 4 |      "John"       |
| 5 |                   |
| 6 |      "Paul"       | <--- Slot 6 Occupied
| 7 |      "Ringo"      | <--- Slot 7 Occupied
| 8 |      "Bart"       | <--- Slot 8 Occupied
| 9 |      "Homer"      | <--- Place in empty slot 9
```
<br><br>

```c
hash("Marge"); returns 6
```
```txt
| 0 |      "Marge"      | <--- Wrap around to beginning and place in empty slot 0
| 1 |                   |
| 2 |                   |
| 3 |      "Lisa"       | 
| 4 |      "John"       |
| 5 |                   |
| 6 |      "Paul"       | <--- Slot 6 Occupied
| 7 |      "Ringo"      | <--- Slot 7 Occupied
| 8 |      "Bart"       | <--- Slot 8 Occupied
| 9 |      "Homer"      | <--- Slot 9 Occupied
```
<br>

> [!NOTE]
> Note that we are starting to stretch **data** far away from corresponding **hash codes** and in the process starting to loose **constant time complexity**.

<br>

**Linear probing** is subject to a problem called **clustering**, where consecutive slots get filled up, making it more likely in the future that the cluster will grow, which **slows** down the **search process** in densely filled tables. 

<br><br>

### Chaining 

**Chaining** is a method used to handle **collisions** and eliminate **clustering** by allowing each **slot** to hold **multiple elements**. Each element of the array is a **pointer** to the **head** of a **linked list**. This allows to store a *chain* of data with the same **hash code**. 

Because we are using **linked lists**, **insertion** can be considered a **constant time** `O(1)` operation, assuming the hash function is efficient and the hash table well structured. **Lookup** however, is close to **linear time** `O(n)`, although the more **lists** or **buckets**, the better performance we are going to have (the `n`  number of elements is divided by the number of lists).

<br>

**Example:**

```c
node* hashtable[10];
```
```txt
| 0 |                   
| 1 |                   
| 2 |                   
| 3 |                   
| 4 |                   
| 5 |                   
| 6 |                   
| 7 |                   
| 8 |                   
| 9 |                   
```
- We define an **array** of `10` **nodes** (heads of linked lists).

<br><br>

```c
hash ("Joey"); returns 6
```
```txt
| 0 |                   
| 1 |                   
| 2 |                   
| 3 |                   
| 4 |                   
| 5 |                   
| 6 |--------------------> | "Joey" |              
| 7 |                      |        |       
| 8 |                   
| 9 |                   
```
- The **pointer** at array location `6` points to the head of the **linked list** composed, for now, by the single node `"Joey"`.

<br><br>

```c
hash ("Ross"); returns 2
```
```txt
| 0 |                   
| 1 |                   
| 2 |--------------------> | "Ross" |               
| 3 |                      |        |
| 4 |                   
| 5 |                   
| 6 |--------------------> | "Joey" |              
| 7 |                      |        |       
| 8 |                   
| 9 |                   
```
- The **pointer** at array location `2` points to the head of the **linked list** composed, for now, by the single node `"Ross"`.

<br><br>

```c
hash ("Rachel"); returns 4
```
```txt
| 0 |                   
| 1 |                   
| 2 |--------------------> |  "Ross"  |               
| 3 |                      |          |
| 4 |----------------------------------------> | "Rachel" |                   
| 5 |                                          |          |
| 6 |--------------------> |  "Joey"  |              
| 7 |                      |          |       
| 8 |                   
| 9 |                   
```
- The **pointer** at array location `4` points to the head of the **linked list** composed, for now, by the single node `"Rachel"`.

<br><br>

#### Now let's imagine a scenario where we hash a new string `"Phoebe"` and it returns the same hash code as previous data:

```c
hash ("Phoebe"); returns 6
```
```txt
| 0 |                   
| 1 |                   
| 2 |--------------------> |  "Ross"  |               
| 3 |                      |          |
| 4 |----------------------------------------> | "Rachel" |                   
| 5 |                                          |          |
| 6 |---------> | "Phoebe" |              
| 7 |           |          |---------> |  "Joey"  |    
| 8 |                                  |          |         
| 9 |       
```
- Just like **adding a node** to the **head** of a linked list, we **malloc** space for `"Phoebe"`, point it's **next** field to the **old head** of the list `"Joey"` and then set `"Phoebe"` as the new **head** of the linked list. We now stored two elements in the array location `6`.
