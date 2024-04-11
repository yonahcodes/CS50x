# File Pointers

Unlike data stored in temporary variables, **persistent data** does not disappear when your program ends and **remains** intact across sessions, allowing information to be stored and accessed. The ability to read data from and write data to files is the primary means of storing **persistent data**.

To facilitate this essential functionality, **C** uses a specific type of data structure called `FILE`. This is not just any ordinary data structure but a sophisticated **abstraction** (hides the *underlying complexity*) that represents files within a program.

These **file objects** are manipulated using **file pointers** `FILE*` and together form the backbone of `File I/O` (Input/Output) in **C**.

<br>

## File Manipulation Functions 

The file manipulation functions all live in the `<stdio.h>` library. All of the **file I/O function** accepts `FILE*` as one of their parameters, except for the `fopen()` function, which is used to get a **file pointer** in the first place.

<br>

```txt
fopen()  -  fclose()  -  fgetc()  -  fputc()  -  fread()  -  fwrite() 
```
<br>

### `fopen()`

**Opens** a file for future reading/writing and **returns a file pointer** to it. It's important to check the return value for `NULL`. Attempting to **dereference** a pointer whose value is **NULL** can lead to a **Segmentation fault**.

```c
FILE* ptr = fopen(<filename>, <operation>);
```
<br>

```c
FILE* ptr1 = fopen("file1.txt", "r");
```
- `fopen()` takes *two arguments*, the **file name** `file1.txt` and the **mode string** `"r"` that specifies to open it in **read mode**.

<br><br>

```c
FILE* ptr2 = fopen("file2.txt", "w");
```
- `fopen()` takes *two arguments*, the **file name** `"file2.txt"` and the **mode string** `"w"` that specifies to open it in **write mode**.

<br><br>

```c
FILE* ptr3 = fopen("file3.txt", "a");
```
- `fopen()` takes *two arguments*, the **file name** and the **mode string** `"a"`that specifies to open it for **append mode**.

<br><br>

>[!CAUTION]
> **Writing** to a file involves starting from scratch. `"r"` mode will **remove all existing content** in the file before adding the new data. If the file does not exist, a *new one* is created.<br><br>
**Appending** to a file means **adding new data** to the **end of the file**. `"a"` mode will place the **file pointer** at the end of the file, ensuring that any new data does not overwrite the existing content but adds to it.