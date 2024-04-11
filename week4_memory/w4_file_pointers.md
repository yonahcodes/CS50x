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

<br>

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

<br><br>

### `fclose()`

**Closes** a file that was previously opened and **releases** any system resources associated with it. When the closing operation is successful, `fclose()` returns **zero**. Failing to properly close a file can result in *data loss* or *memory leaks*.

<br>

```c
fclose(<file pointer>);
```
<br>

```c
fclose(ptr1);
```
- `fclose()` simply takes the **pointer** to the file as an argument.

<br><br>

### `fgetc()`

**Reads** the next **single character** from the file it points to. In order for `fgetc()` ("file get char") to succeed, the **file pointer** passed in as a parameter *must* be opened in `"r"` mode or there will be an **error**.

<br>

```c
char ch = fgetc(<file pointer>);
```
<br>

```c
char ch = fgetc(ptr1);
```
- `fgetc()` simply takes the **pointer** to the file as an argument.

- The function takes **next character** (or the **first character** if called for the first time) and stores it in the variable `ch`.

<br><br>

Using `fgetc()` in a **loop** gives us the ability to read all the **single characters** in a file, *one-by-one*, and perform operations like printing each character to the screen.

Understanding how `fgetc()` works in **C** gives valuable insight into the workings of high level commands like the **Linux** command `cat` (concatenate) that works in a similar fashion, printing the contents of a file in our **Terminal** window.

<br><br>

```c
char ch;

while((ch = fgetc(ptr)) != EOF)
{
    printf("%c", ch);
}
```
- `ch = fgetc(ptr)` Obtains **one character** from the file.

- `!= EOF` Checks that the **character** is not **EOF** (End of File character).

- `printf("%c", ch);` prints the character.

- The `while` loop starts again and will *iterate through* every **character** of the file until it reaches the **last** character (**EOF**), successfully printing all the contents of the file.

<br><br>

### `fputc()`

**Writes** or **appends** a *single character* to the file it points to. For `fputc()` ("file put char") to function properly, the **file pointer** provided as an argument **must** be opened in a mode that allows writing, such as `"w"` or `"a"`.

<br>

```c
fputc(<character>, <file pointer>);
```
<br>

```c
fputc('A', ptr2);
```
- `fputc()` **writes** character `A` into file pointed to by `ptr2`.

<br><br>

```c
fputc('!', ptr3);
```
- `fputc()` here **writes** character `!` into file pointed to by `ptr3`.

<br><br>

Now that we can **read** characters from files and **write** characters to them. Let's extend our previous example to **copy** ont file to another, instead of printing to the screen. 

Combining `fgetc()`  and `fputc()` in **C** can give us insight into the workings of the **Linux** command `cp` (copy) that works in a similar fashion to **copy** files.

<br><br>

```c
char ch;

while ((ch = fgetc(ptr)) != EOF)
{
    fputc(ch, ptr2);
}
```
- `ch = fgetc(ptr)` Obtains one character from **file 1** that `ptr` points to.

- `!= EOF` Checks that the character is not EOF (End of File character).

- `fputc(ch,ptr2)` Will write that character to **file 2** that `ptr2` points to 

- The `while` loop starts again and will iterate through every character of **file 1** copying it to **file 2** until it reaches the last character (**EOF**), successfully **copying** all the contents of file 1 to a new file.

<br><br>

### `fread()`

**Reads** *multiple* blocks of data of a **specified size** from the file it points to and stores it in a `buffer` (usually an **array**). It is a version of **fgetc()** that allows us to **read** data of any size at once. For `fread()` to succeed, the **file pointer** passed in as a parameter *must* be opened in read mode `"r"` otherwise an **error** will occur.

<br>

```c
fread(<buffer>, <size>, <qty>, <file pointer>);
```
<br>

```c
int arr[10];

fread(arr, sizeof(int), 10, ptr);
```
- `int arr[10]` Statically declares on the **stack** an array of `10` **integers**.

- `fread()` Reads `10` `int` size elements (40 bytes) from the file that `ptr` points to, and store them in `arr`.

<br>

> Note that `arr` is also a **pointer** to the beginning of the block of memory on the **stack** that stores the data.

<br><br>

```c
double* arr2 = malloc(sizeof(double) * 80);

fread(arr2, sizeof(double), 80, ptr);
```
- `double* arr2 = malloc(sizeof(double) * 80);` Declares a **pointer variable** called `arr2` that points to a **dynamically allocated** block of memory on the **heap** of `80` elements of **size** `double`.

- `fread()` **Reads** `80` elements of size `double` (640 bytes) from the file that `ptr` points to, and stores them in `arr2`.

<br>

> Note that `arr2` is also a **pointer** to the beginning of the block of memory on the **heap** that stores the data.

<br><br>

```c
char c;
fread(&c, sizeof(char), 1, ptr);
```
- Instead of storing the data in an **array**, we could store it in a **variable**.

- `char c;` Declares a variable of size char (1 byte) on the **stack**. 

- `fread()` here **Reads** `1` element of size `char` (1 byte) from a file that `ptr` points to, and stores it in the **address** of `&c`.

<br>

> Notice that we did not pass the variable `c` directly but the **address** of `&c` because the first argument of `fread()` is a **pointer**.

<br><br>

### `fwrite()`

**Writes** *multiple* blocks of data of a **specified size** to the file it points to from a `buffer` (usually an **array**). It is a version of **fputc()** that allows us to **write** data of any size at once. For `fwrite()` to succeed, the **file pointer** passed in as a parameter *must* be opened in **write** `"w"` or **append** `"a"` mode  or otherwise an **error** will occur.

<br>

```c
fwrite(<buffer>, <size>, <qty>, <file pointer>);
```
<br>

```c
int arr[10];

fwrite(arr, sizeof(int), 10, ptr);
```
- `int arr[10]` Statically declares on the **stack** an array of `10` **integers**.

- `fwrite()` Writes `10` `int` size elements (40 bytes) to the file that `ptr` points to from `arr`.

<br>

> Note that `arr` is also a **pointer** to the beginning of the block of memory on the **stack** that stores the data.

<br><br>

```c
double* arr2 = malloc(sizeof(double) * 80);

fwrite(arr2, sizeof(double), 80, ptr);
```
- `double* arr2 = malloc(sizeof(double) * 80);` Declares a **pointer variable** called `arr2` that points to a **dynamically allocated** block of memory on the **heap** of `80` elements of **size** `double`.

- `fwrite()` **Writes** `80` elements of size `double` (640 bytes) to the file that `ptr` points to, from `arr2`.

<br>

> Note that `arr2` is also a **pointer** to the beginning of the block of memory on the **heap** that stores the data.

<br><br>

```c
char c;
fread(&c, sizeof(char), 1, ptr);
```
- Instead of reading the data from an **array**, we could write it from a **variable**.

- `char c = 'x';` Declares and initializes a variable of size char (1 byte) on the **stack**. 

- `fread()` here **Writes** `1` element of size `char` (1 byte) to a file that `ptr` points to, from the address of `&c` (which contains `x`).

<br>

> Notice that we did not pass the variable `c` directly but the **address** of `&c` because the first argument of `fwrite()` is a **pointer**.

<br><br>

There are a lot of other useful **File I/O** functions in `<stdio.h>` we can work with. Here are some of the ones that could be useful:
<br>

|**Function**|**Description**|
|:-:|:-|
|fgets( )|Reads a full string from a file.|
|fputs( )|Writes a full string to a file.|
|fprintf( )|Writes a formatted string to a file.|
|fseek( )|Allows you to rewind or fast-forward within a line.|
|ftell( )|Tells you at what (byte) position you are within a file.|
|feof( )|Tells you whether you've read to the end of a file.|
|ferror( )|Indicates whether an error has occurred in working with a file.|
