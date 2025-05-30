# Tries

Several **data structures** manage the **mapping** of **key-value** pairs. In **arrays** the element *index* serves as a **key**, and the *data* stored in that location is the **value**. **Hash tables** use a derived **hash code** from the data as a **key** and the **value** is the *linked list* of data hashing to the code.

**Tries** or **prefix trees** are specialized tree-like data structures where the **key** is guaranteed to be **unique** and the **value** could be as simple as a **Boolean** that tells us whether the data exists in the structure. **Tries** combine **structures** and **pointers** together to store data.

<br>

**Searching** a **trie** involves traversing from the **root**, **following paths** determined by each **character** in the **key** (the target data becomes a **roadmap**). If a **continuous path** corresponding to the **key** leads to a node that marks the end of a word, the **data exists** in the trie; otherwise, it does not.

Unlike with a **hash table**, there are no **collisions**, and no two different pieces of data share the same path, unless they are identical.

<br>

## Tries in C

Let's visualize a example by mapping **key-value pairs** where the **keys** are four-digit years (**YYYY**) and the **values** are names of **universities** founded during those years.

In this **trie**, the paths from central **root** node to a **leaf** node (containing the school names), would be labeled with digits of the year. Each **node** on the path from root to leaf could have **10 pointers**, **one** for each **digit**. To **insert** an element into the trie, we simply build the **correct path** from the root to the leaf.

<br>

```c
typedef struct _trie
{
    char university[20];
    struct _trie* paths[10];
}
trie;
```
- We define a new **struct** called `trie` representing a single node in the trie.

- `char university[20]` An array of `20` **characters** containing the universities names.

- `struct _trie* paths[10];` An array of `10` **pointers** (from 0 to 9). These pointers are used to **link** each trie node to its **children**. 

- After defining the structure we establish an **alias** `trie` to refer to the structure instead of **struct _trie**.

<br><br>

## Inserting Data

**Inserting data** in a **trie** involves creating a new node for each character or digit of the **key** that doesn't already have a corresponding node, **linking** it sequentially from the **root** to form a path representing the complete key.

<br>

### Insert `"Harvard"`, founded `1636`

```txt
 -----------------------------
|            ""               |
|-----------------------------|   // Empty Root node
|  |  |  |  |  |  |  |  |  |  |   // With 10 possible child pointers
 -----------------------------
  0  1  2  3  4  5  6  7  8  9
```
```txt
                        -----------------------------
                       |             ""              |   // Root
                       |-----------------------------|   // Insert 1st digit `1`
                       |  |  |  |  |  |  |  |  |  |  |
                        -----------------------------
                            1

                            |
                            v
     -----------------------------
    |             ""              |   // Create new node
    |-----------------------------|   // Set as child to root at index[1]
    |  |  |  |  |  |  |  |  |  |  |   // Insert second digit `6`
     -----------------------------
                       6

                       |
                       v
 -----------------------------
|             ""              |   // Create new node
|-----------------------------|   // Set as child to node(1) at index[6]
|  |  |  |  |  |  |  |  |  |  |   // Insert third digit `3`
 -----------------------------
           3

           |
           v
         -----------------------------
        |             ""              |   // Create new node
        |-----------------------------|   // Set as child to node(2) at index[3]
        |  |  |  |  |  |  |  |  |  |  |   // Insert fourth digit `6`
         -----------------------------
                            6

                            |
                            v
     -----------------------------
    |         "Harvard"           |   // Create a new node
    |-----------------------------|   // Set it as child to node(3) at index[6]
    |  |  |  |  |  |  |  |  |  |  |   // Store university name "Harvard"
     -----------------------------    // This is the LEAF node
```

<br><br>

### Inserting `"Yale"`, founded `1701`
```txt
                                 -----------------------------
                                |             ""              |   // Start at the Root
                                |-----------------------------|   // Path 1 is cleared already
                                |  |  |  |  |  |  |  |  |  |  |   // Follow path `1`
                                 -----------------------------
                                    1

                                    |
                                    v
              -----------------------------
             |             ""              |   // Path 7 is NULL
             |-----------------------------|   // Insert second digit `7`
             |  |  |  |  |  |  |  |  |  |  |
              -----------------------------
                                6   7

                               /     \
                              v       v
 -----------------------------      -----------------------------
|             ""              |    |             ""              |   // Create new node
|-----------------------------|    |-----------------------------|   // Set as child to node(1) at index[7]
|  |  |  |  |  |  |  |  |  |  |    |  |  |  |  |  |  |  |  |  |  |   // Insert third digit `0`
 -----------------------------      -----------------------------
          3                          0

          |                            \
          v                             v
  ----------------------------        ------------------------------
|             ""              |      |              ""              |   // Create new node
|-----------------------------|      |------------------------------|   // Set it as child to node(2b) at index[0]
|  |  |  |  |  |  |  |  |  |  |      |  |  |  |  |  |  |  |  |  |   |   // Insert fourth digit `1`
 -----------------------------        ------------------------------
                   6                      1

                   |                      |
                   v                      v
 -----------------------------          -----------------------------
|         "Harvard"           |        |           "Yale"            |   // Create new node
|-----------------------------|        |-----------------------------|   // Set it as child to node (3b) at index[1]
|  |  |  |  |  |  |  |  |  |  |        |  |  |  |  |  |  |  |  |  |  |   // Store University name "Yale"
 -----------------------------          -----------------------------    // This is another LEAF node
```
- Storing `"Yale"` involves **inserting** the digits of the year `1701` **one by one** into the trie, **following** pointers already established, **creating nodes** as necessary and **linking** them to the **root node**.

<br><br>

## Searching for Data

To **search** for an element in a **trie**, we use successive digits to navigate from the root. If we can make it to the **end** without hitting a dead end (**NULL** pointer), the element is **found**.

<br>

Imagine we wanted to search the **trie** for `"Harvard"` founded in `1636`:

```txt
                                 -----------------------------
                                |             ""              |
                                |-----------------------------|
                                |  |  |  |  |  |  |  |  |  |  |
                                 -----------------------------
                                    1

                                    |
                                    v
              -----------------------------
             |             ""              |
             |-----------------------------|
             |  |  |  |  |  |  |  |  |  |  |
              -----------------------------
                                6   7

                               /     \
                              v       v
 -----------------------------      -----------------------------
|             ""              |    |             ""              |
|-----------------------------|    |-----------------------------|
|  |  |  |  |  |  |  |  |  |  |    |  |  |  |  |  |  |  |  |  |  |
 -----------------------------      -----------------------------
          3                          0

          |                            \
          v                             v
  ----------------------------        ------------------------------
|             ""              |      |              ""              |
|-----------------------------|      |------------------------------|
|  |  |  |  |  |  |  |  |  |  |      |  |  |  |  |  |  |  |  |  |   |
 -----------------------------        ------------------------------
                   6                      1

                   |                      |
                   v                      v
 -----------------------------          -----------------------------
|         "Harvard"           |        |           "Yale"            |
|-----------------------------|        |-----------------------------|
|  |  |  |  |  |  |  |  |  |  |        |  |  |  |  |  |  |  |  |  |  |
 -----------------------------          ----------------------------- 
```
0. Create a **traversal pointer** that starts at the **root**.
1. Can we follow path `1` ? **Yes**, we continue.
2. Can we follow path `6` ? **Yes**, we continue.
3. Can we follow path `3` ? **Yes**, we continue.
4. Can we follow path `6` ? **Yes**, we continue.
5. Is the value stored `"Harvard"`? **Yes**, data is **found**.

<br>

#### Now imagine we wanted to search the **trie** for `"Princeton"` founded in `1746`:

1. Can we follow path `1` ? **Yes**, we continue.
2. Can we follow path `7` ? **Yes**, we continue.
3. Can we follow path `4` ? **No**, we reached a dead end, data is **not found**.

<br><br>

The process of **searching** for an element in a **trie**, as illustrated above, underscores the trie's **efficiency** in navigating through sequences of characters or digits. The **time complexity** of this search is often linear to the length of the key being searched. This makes **tries** useful in **large** datasets where **fast** and frequent retrievals are required.
