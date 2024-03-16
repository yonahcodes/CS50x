# CS50x Week 2 - Arrays
## Compiling

Compilers are programs that convert our *source* code into *machine* code so that they can be read and executed by a computer. **Clang** (short for C language) is compiler for C.

```c
#include <stdio.h>

int main(void)
{
    printf("hello, world\n");
}
```
We could use `clang hello` command to compile this **"hello.c"** file and it would work, but create a file with a default name of **a.out**. To run the program we will have to type `./a.out`

We can configure **clang** with command line arguments. 

`clang -o hello hello.c` Will compile the file and name it "**hello**" instead of default "**a.out**".

If we try to use `clang -o hello hello.c` on a file that uses a third party library, like the example below **<cs50.h>**, the compiler will not link it and fail to compile the file.

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What's your name? ");
    printf("hello, %s\n", name);
}
```
To fix this, we have to provide an additional command line argument `-l` to link the library. The full command will be `clang -o hello hello.c -lcs50`.

> In CS50 we use the pre-programmed `make hello.c` command to automate this process and achieve the same result.

### Compiling involves the following steps:
- **Preprocessing** is where the header files designated by a `#` like in the **preprocessor directive** `#include <cs50.h>`, are copied into your program. A library like **<cs50.h>** contains the *prototypes* of all built-in functions that we could use in our program. 

- **Compiling** is where your program is converted into **assembly code** (A low level language that acts as a bridge between **C** and machine code).

- **Assembling** involves the compiler converting your *assembly* code into *machine* code.

- **Linking** is where the code from your included **libraries** are converted also into *machine* code and combined with your code. The final executable file is then outputted.

## Debugging
```c
#include <stdio.h>

int main(void)
{
    for (int i = 0; i <= 3; i++)
    {
        printf("#\n");
    }
}
```
Running the code above, **four** bricks appear instead of the intended **three**. `printf` is a very useful way of debugging your code.
```c
#include <stdio.h>

int main(void)
{
    for (int i = 0; i <= 3; i++)
    {
        printf("i is %i\n", i);
        printf("#\n");
    }
}
```
Here we used `printf("i is %i\n", i);` to print every iteration and help us *debug* the code. 
```
$ make buggy
$ ./buggy
i is 0
#
i is 1
#
i is 2
#
i is 3
#
```
Seeing this, we realize that the code needs to be corrected replacing `i <= 3` by `i < 3`.

A better more powerful tool we can use to address bugs is a **debugger**, a software tool created by programmers to help track down bugs in code.

### Using a debugger in CS50
- First we have to set a *breakpoint* by clicking to the left of the line number (a **red dot** should appear).
- Second, run `debug50 ./buggy`. The code will *pause* and *highlight* the line of executable code at or below this line of code. Use `step over` to keep moving through your code.
- This tool will not show you where the bug is, but it will help you slow down and see how your code is running step by step. Use `step into` to look further into details of your buggy code.
- A final form of debugging is called **rubber duck debugging**. When you are having challenges with your code, consider speaking out loud to a rubber duck about the code problem. 

> Get into the habit NOW of using the **debugger** instead of `printf`. You can also use `cs50.ai`.

## Arrays

Each data type requires a certain amount of system resources:
- **bool** 1 byte
- **int** 4 bytes
- **long** 8 bytes
- **float** 4 bytes
- **double** 8 bytes
- **char** 1 byte
- **string** ? bytes

> A **string** has a variable number of bytes depending on how many characters it holds.

This data is stored in the **Random-Access-Memory** chips, which have finite amount of memory that is divided in bytes. 

We can create a program that explores these concepts.
```c
#include <stdio.h>

int main(void)
{
    // Scores
    int score1 = 72;
    int score2 = 73;
    int score3 = 33;

    // Print average
    printf("Average: %f\n", (score1 + score2 + score3) / 3.0);
}
```
> If we involve a **floating point value** in the calculation, here `3.0`, the result will be rendered as **float** in the end.

The **integer** values stored in the scores will each fill **4 bytes** of memory.

This way of storing data works fine in this code, but will get messy if it scales to thousands of different scores. We can use **Arrays** to optimize how we store data in the code.

**Arrays** are  way of storing data back-to-back in memory such that this data is easily accessible.

```c
#include <stdio.h>

int main(void)
{
    // Get scores
    int scores[3];
    scores[0] = 72;
    scores[1] = 73;
    scores[2] = 33;

    // Print average
    printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / 3.0);
}
```
- `int scores[3]` is a way or telling the compiler to provide us three back-to-back places in memory of size `int` to store three `scores`.
- `scores[0]` examines the value at this location of memory by **indexing into** the array called `scores` at location `0` to see what value is stored there.

> With **Arrays** we must start counting at "**0**", if we don't, we will waste one space.

We can further improve this code by introducing a **loop**. We *index into* `scores` by using `scores[i]` where `i` is supplied by the **for loop**:
```c
int main(void)
{
    // Get scores
    int scores[3];
    for (int i = 0; i < 3; i++)
    {
        scores[i] = get_int("Score: ");
    }

    // Print average
    printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / 3.0);
}
```
> We can declare a **constant** variable `N` to indicate that its value should not be changed during the program's execution and prevent its modification. It is common practice to *capitalize* a constant name.

```c
int main(void)
{
    // Get scores
    const int N = 3
    int scores[N];
    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score: ");
    }

    // Print average
    printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / (float) N);
}
```

We can also *simplify* or *abstract away* the calculation of the average:
```c
#include <cs50.h>
#include <stdio.h>

// Constant
const int N = 3;

// Prototype
float average(int length, int array[]);

int main(void)
{
    // Get scores
    int scores[N];
    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score: ");
    }

    // Print average
    printf("Average: %f\n", average(N, scores));
}

float average(int length, int array[])
{
    // Calculate average
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum / (float) length;
}
```
A new function called `average` is declared. Notice how the `average` function takes `int array[]`, which means that the compiler passes an *array* to this function.

> Not only can **arrays** be containers: They can be passed between functions.

## Strings

A `string` is simply an array of variables of 
type `char`: an array of characters.

```c
#include <stdio.h>

int main(void)
{
    char c1 = 'H';
    char c2 = 'I';
    char c3 = '!';

    printf("%c %c %c\n", c1, c2, c3);
}
```
This code will output a string of characters:
```
HI!
```

Now lets modify `%c` *char* placeholders to `%i` to print out integers:
```c
#include <stdio.h>

int main(void)
{
    char c1 = 'H';
    char c2 = 'I';
    char c3 = '!';

    printf("%i %i %i\n", c1, c2, c3);
}
```
The code will now return the **ASCII** integer equivalents of the characters:
```
72 73 33
```
To further understand how a **string** works:
```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = "HI!";
    printf("%c%c%c\n", s[0], s[1], s[2]);
}
```
```
HI!
```
>Notice how the `printf`statement presents three values from our *array* called `s`.

We can replace `%c` by `%i` as follows and add one value of `s` to see what happens:
```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = "HI!";
    printf("%i %i %i %i\n", s[0], s[1], s[2], s[3]);
}
```
This code prints the string's **ASCII** codes, including a special character printed after *every string* called `NUL character` `\0` (00000000), that tells the computer that the **string** ends here.
```
72 73 33 0
```
Let's imagine we want to say both `HI!` and `BYE!`:
```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = "HI!";
    string t = "BYE!";

    printf("%s\n", s);
    printf("%s\n", t);
}
```
You can visualize this stored as follows:
```
H I ! \0 B Y E ! \0
```
We can also modify this code to include **arrays**:
```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string words[2];

    words[0] = "HI!";
    words[1] = "BYE!";

    printf("%s\n", words[0]);
    printf("%s\n", words[1]);
}
```
```
HI!
BYE!
```
We can visualize the **strings** stored as two *arrays of characters*:

`H I ! \0` and `B Y E ! \0`

If we break down how each **char** is stored:

- `H` words [0] [0] 
- `I` words [0] [1]  
- `!` words [0] [2] 
- `\0` words [0] [3] 
- `B` words [1] [0]  
- `Y` words [1] [1] 
- `E` words [1] [2] 
- `!` words [1] [3]  
- `\0` words [1] [4] 

## String Length
A common programming, and perhaps **C** more specifically, is to discover the length of an array. 

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("Name: ");


    int n = 0;
    while (name[n] != '\0')
    {
        n++;
    }
    printf("%i\n", n);
}
```
Notice that this code loops until the `NUL` character is found and returns number of *chars* in user's input.

We can also improve the code by *abstracting away the counting as follows:

```c
#include <cs50.h>
#include <stdio.h>

// Prototype for string counting function
int string_length(string s);

int main(void)
{
    // Prompt for user's name
    string name = get_string("Name: ");
    int length = string_length(name);
    printf("%i\n", length);
}

int string_length(string s)
{
    // Count number of characters up until '\0' (aka NUL)
    int n = 0;
    while (s[n] != '\0')
    {
        n++;
    }
    return n;
}
```
 > Pay attention to **scope** when naming variables. Variables could be the same but have to have different names when used in the *main* function and *locally* in a function.

 Since this is a common problem within programming, other programmers have created code in the `string.h` library to find the **length of a string**. You can find the length of a string by using the pre-made function `strlen`:

 ```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Prompt for user's name
    string name = get_string("Name: ");
    int length = strlen(name);
    printf("%i\n", length);
}
```

Imagine we wanted to create a program that converted all lowercase characters to uppercase ones:
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // If lowercase
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            printf("%c", s[i] - 32);
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}
```
This code *iterates* through each value in the string. The program looks at each character. If the character is **lowercase**, if subtracts the value **32** from it to convert it to its **UPPERCASE** equivalent from the **ASCII** chart.

```c
// Making the for loop more efficient:

1.  for (i = 0; i < strlen(s); i ++)

2.  int length = strlen(s)
    for (i = 0; i < length; i ++)

3.  for (i = 0, length = strlen(s); i < length; i++)

4.  for (i = 0, n = strlen(s); i < n; i++)
```

`ctype.h` is another library we can use to make this process easier. The program below *iterates* through each character of the string. the `toupper` function is passed to `s[i]` and each character is **lowercase** is converted to **UPPERCASE**. 
```c
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After:  ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            printf("%c", toupper(s[i]));
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}
```
> The `toupper` function automatically knows to uppercase only lowercase characters. Hence, we can simplify the code as follows:

```c
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", toupper(s[i]));
    }
    printf("\n");
}
```

## Command-Line Arguments

`Command-line arguments` are those arguments that are passed to your program at the command line. For example, all those statements we typed after `clang` are considered command line arguments.

Consider this program:
```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string answer = get_string("What's your name? ");
    printf("hello, %s\n", answer);
}
```
If we wanted to be able to take arguments at the command line before the program runs:

```c
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    printf("hello, %s\n", argv[1]);
}
```
- `string argv[]` means an array of strings
- `int argc` means integer of number of words typed
- The name of your program is accessible in `argv[0]`

We can now run the program and enter the **name** we want to greet in the command line:<br>
$`./greet Name`<br>

The program will return:<br>
```
hello, Name
```
If we wanted to add some *error checking* and prevent user from entering more than **2** command arguments `./greet` & `name`:
```c
#include <cs50.h>
#include <stdio.h>
int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf("hello, %s\n", argv[1]);
    }
    else
    {
        printf("hello, world\n");
    }
}
```
> Notice that this program knows both **`argc`**, the number of command line arguments, and **`argv`** which is an array of the characters passed as arguments at the command line.

## Exit Status

When a program ends, a special exit code is provided to the computer.<br>

When a program exits without an error, a status code of `0` is provided by the computer. Often, when a **error** occurs that results in the program ending, a status of `1` is provided by the computer.

```c
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Missing command-line argument\n");
        return 1;
    }
    printf("hello, %s\n", argv[1]);
    return 0;
}
```
If you fail to provide `./status Name`, you will get an **exit status** of **`1`**. However, if you provide `./status Name`, you will get an exit status of **`0`**.

> If we want to see what the most recently run program exit with, we can type in the **terminal** `echo $?` command.

## Cryptography

Cryptography is the art of **encrypting** and **decrypting** or *ciphering* and *deciphering* a message.

### Encryption:<br>
Scrambling a message so that only you and the recipient can receive it.
```
 plaintext + key -> | cipher | -> ciphertext 
```
`plaintext` and a `key` are provided to a `cipher`. The `cipher` uses the `key` to make decisions about how to implement its cipher algorithm.

- `plaintext` is self explanatory.
- `key` is a special argument (number) passed to the **cipher** along with **plaintext**. 
- `cipher` is an **algorithm** for encrypting and decrypting data.

#### **Example**:<br>
Plaintext is `HI!` and Key is `13`. The `cipher` will change every letter of the plaintext by another one 13 letters down. `H` becomes `U` and `I` becomes `V`, `!` is unchanged, resulting in the encrypted `UV!`

### Decryption: <br>
Unscrambling a message to its original form. Using the same **key** that was used to encrypt it we can reverse the process.

#### **Example**:<br> 
Encrypted message is `UV!` and Key is `-13`. The `cipher` will change back every letter of the encrypted message by another one 13 letters **UP**. `U` becomes `H` and `V` becomes `I`, `!` is unchanged, resulting in the decrypted message `HI!`
