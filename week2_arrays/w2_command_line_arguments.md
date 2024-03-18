# Command Line Arguments
So far, all our programs have begun the same way:
```c
int main(void)
{

}
```
Since we have been collecting user input through **in-program** prompts, we haven't needed to add arguments to `main()`. If we wanted the user to provide data to our program **before** the program starts running, we need a new form.

To collect so called `command-line arguments` from the user, we need to declare `main()` as:
```c
int main(int argc, string argv[])
{

}
```
These two special **arguments** enable us to know what data the user provided at the command line and how much data they provided.
<br><br>

## `argc` - argument count
This **integer**-type variable will store the **number** of command-line arguments the user typed, including the program's name.<br><br>

|command|argc|
|:-|:-:|
|./greedy|1|
|./greedy 1024 cs50|3|

<br><br>
## `argv` - argument vector
This **array** of strings stores, one string per element, the actual text the user typed at the command-line.

- The **first** element of *argv* is always found at `argv[0]`.
- The **last** element of *argv* is always found at `argv[argc-1]`.
<br><br>
```
./greedy 1024 cs50
```
|argv indices|argv contents|
|:-:|:-:|
|argv[0]|"./greedy"|
|argv[1]|1024|
|argv[2]|cs50|
|argv[3]|???|

<br>

- Note that `1024` is stored as a **string** in `argv[1]` not as an integer.

- `argv[3]` is out of the range of our array. We are likely going to get a `Segmentation fault` for attempting to access memory outside the bounds of our array.