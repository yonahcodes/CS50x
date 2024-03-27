# CS50x Section 3 - Algorithms

## Searching

`Linear Search`: Iterative search algorithm that sequentially checks each element in a list until the target value is found or the list is exhausted.

`Binary Search`: Divide-and-conquer algorithm that efficiently locates a target value in a **sorted** list by repeatedly dividing the search interval in half.
<br><br>

### What is the *greatest* number of steps this algorithm will *ever* take?

|Linear Search|Binary Search|
|:-:|:-:|
|N|log2(N)|

<br>

- `N` being the number of elements in the array.
- `log2(N)` logarithm base 2 of the value `N` represents the number of times you need to divide `N` by `2` to get to the target value.

<br><br>

#### What is (approximately!) the greatest number of steps this algorithm will *ever* take?

|Linear Search|Binary Search|
|:-:|:-:|
|O(N)|O(log2(N))|

<br><br>

#### What is the *fewest* number of steps this algorithm could *ever* take?

|Linear Search|Binary Search|
|:-:|:-:|
|1|1|

<br><br>

#### What is (approximately!) the *fewest* number of steps this algorithm could *ever* take?

|Linear Search|Binary Search|
|:-:|:-:|
|Ω(1)|Ω(1)|

<br><br>

|Common|Notations|
|:-:|:-:|
|O(1)|Ω(1)|
|O(log(N))|Ω(log(N))|
|O(N)|Ω(N)|
|O(N2)|Ω(N2)|

<br><br>

## Sorting

`Merge sort`: Divide-and-conquer sorting algorithm that divides the array into smaller parts, sorts them individually, and then merges them back together.

`Selection sort`: Iterative sorting algorithm that repeatedly selects the *smallest* element from the unsorted portion of the array and swaps it with the element at the beginning of the unsorted portion.

`Bubble sort`: Iterative sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.
<br><br>

|Algorithm|O|Ω|
|:-:|:-:|:-:|
|Merge sort|O(Nlog(N))|Ω(Nlog(N)|)
|Selection sort|O(N^2)|Ω(N^2)|
|Bubble sort|O(N^2)|Ω(N)|

<br>

We are given 3 compiled **C** programs named `sort1`, `sort2` and `sort3` each implementing a different sorting algorithm: `selection sort`, `bubble sort` or `merge sort`. Let's try to guess which algorithm is in use by each file:

|Algorithm|reversed50000.txt|sorted50000.txt|
|:-:|:-:|:-:|
|Sort 1|?|?|
|Sort 2|?|?|
|Sort 3|?|?|

<br>

- `sort1` Takes **4.916s** to sort *reversed* list; Takes **0.444s** to sort *sorted* list

- `sort2` Takes **0.578s** to sort *reversed* list; Takes **0.497s** to sort *sorted* list

- `sort3` Takes **2.525s** to sort *reversed* list; Takes **2.515s** to sort *sorted* list

<br>

|Algorithm|reversed50000.txt|sorted50000.txt|
|:-:|:-:|:-:|
|Sort 1|Slow|Fast|
|Sort 2|Fast|Fast|
|Sort 3|Slow|Slow|

<br>

- `sort1` uses: **Bubble Sort**

- `sort2` uses: **Merge Sort**

- `sort3` uses: **Selection Sort**

<br>

|Algorithm|reversed50000.txt|sorted50000.txt|
|:-:|:-:|:-:|
|Sort 1|O(N^2)|Ω(N)|
|Sort 2|O(Nlog(N))|Ω((Nlog(N))|
|Sort 3|O(N^2)|Ω(N^2)|

<br>

## Structs

A **struct** in **C** programming language is a composite data type declaration that defines a physically *grouped list of variables* under one name in a block of memory.

```c
typedef struct
{
    string name;
    int name;
}
nom;
```

- `nom` is the name of the **struct**.
- `string name` and `int name` variables are **members** of the structure.

### Example

```c
typedef struct
{
    string name;
    int votes;
}
candidate;

candidate president;
president.name = "Samia";
president.votes = 10;
```

We can also create an **array**:

```c
candidate candidates[4];
```

<br>

#### Now let's create a program that

1. Defines an array of candidates

2. Searches the array to find the most votes awarded to any single candidate

3. Prints out that candidate's name

<br>

```c
#include <cs50.h>
#include <stdio.h>

// Define the struct
typedef struct
{
    string name;
    int votes;
}
candidate;

int main(void)
{

    // Define name and length of the array
    const int num_candidates = 3;
    candidate candidates[num_candidates];

    // Define values of struct in each array index
    candidates[0].name = "Carter";
    candidates[0].votes = 10;

    candidates[1].name = "Yuliia";
    candidates[1].votes = 12;

    candidates[2].name = "Inno";
    candidates[2].votes = 7;

    // Find highest number of votes
    int highest_votes = 0;
    for (int i = 0; i < num_candidates; i++)
    {
        if (candidates[i].votes > highest_votes)
        {
            highest_votes = candidates[i].votes;
        }
    }

    // Print name of candidate with highest number of votes
    for (int i = 0; i < num_candidates; i++)
    {
        if (candidates[i].votes == highest_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return 0;
}
```

<br><br>

## Recursion

Recursion is a technique of making a function call itself. This technique provides a way to break complicated problems down into simple problems which are easier to solve.

### Factorial

The product of all positive integers from 1 up to a given number. Factorials are good candidates for using recursion.

```txt
1! = 1  // 1! is read as "1 Factorial"

2! = 2 * 1 = 2

3! = 3 * 2 * 1 = 6

4! = 4 * 3 * 2 * 1 = 24
```

If we rearrange the operations, we notice a pattern:

```txt
            1! = 1 

        2! = 2 * 1

    3! = 3 * 2 * 1

4! = 4 * 3 * 2 * 1
```

> [!Note]
> `2! is 2 * 1!`, `3! is 3 * 2!` and `4! is 4 * 3!`

- `1! = 1` is the **Base case**

- `1!` in `2! = 2 * 1!` is the **Recursive call**

- `2! is 2 * 1!`, `3! is 3 * 2!` and `4! is 4 * 3!` is the **Call stack**

#### Now let's create a program that calculates the factorial of a number using *recursion*

```c
#include <cs50.h>
#include <stdio.h>

int factorial(int n);

int main(void)
{
    // Get positive value for n
    int n;
    do
    {
        n = get_int("n: ");
    }
    while (n < 0);

    // Print factorial
    printf("%i\n", factorial(n));
}

// Implement factorial function
int factorial(int n)
{
    // Base case
    if (n == 1)
    {
        return 1;
    }

    return n * factorial(n - 1);
}
```

- `factorial(int n)` function takes user input as argument.

- It checks it `n` is equal to 1, which is the **Base case** for the factorial function.

- If `n` is not equal to 1, the function calls itself **recursively** with the argument `n - 1`.

- This process **decreases** the value of `n` until it reaches the **base case** where `n` is 1.

- Now that `n` has a set value of 1, it can solve the other **recursive calls**.

- It then returns the results back up the **call stack** multiplying the values to compute the final factorial.
