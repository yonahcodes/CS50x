# CS50x Week 3 - Algorithms
In week zero, we introduced the idea of an **algorithm** as a "black box" that may take an *input* and produce an *output*.

This week, we are going to expand our understanding of algorithms and focus upon the design of algorithms and how to measure their efficiency.


## Linear Search
Last week we introduced the idea of an **array**, data stored in a contiguous manner in the computer's memory.

Let's imagine we have an array of **7** indexes, each index contains an unknown integer.
```
[0] [1] [2] [3] [4] [5] [6]
```
We want to know if the number `50` is inside the array. A computer must look at *each index* to be able to see if the number is inside. We call this process of finding such a number, character, string, or other item **searching**.

We can hand our *array* to an **algorithm** that will search through our indexes to see if the number `50` is inside one of them: Returning a *boolean* value of `true` or `false`.

```
array[] -> | algorithm | -> bool
```
We can imagine instructions we might provide our algorithm to undertake this task in *pseudocode*:
```
For each index from left to right
    If 50 is inside index
        Return true
Return false
```
> Notice that `Return false` is not indented
```
For each index from left to right
    If 50 is inside index
        Return true
    Else
        Return false
``` 
In this second **wrong** version, the program will `Return false` after checking the first index **only** and assume the `50` is not there without checking other indexes.

A computer scientist could translate the *pseudocode* as follows:
```
For i from 0 to n-1
    If 50 is in index[i]
        Return true
Return false
```       
`Linear Search` is defined as a sequential search algorithm that starts at one end and goes through each element of an array until the target element is found, otherwise the search continues until the end of the data set.
<br><br>

## Binary Search

Binary search is another **search algorithm** that could be employed in our task of finding the `50`.

Assuming that the values within the *indexes* have been arranged from `smallest to largest`, the pseudocode for *binary search* would appear as follows:
```
If no indexes left
    Return false
If 50 is inside the middle index
    Return true
Else if 50 < middle index
    Search left half
Else if 50 > middle index
    Search right half
```
Using the nomenclature of code, we can further modify our **algorithm** as follows:
```
If no index[] left
    Return false
If 50 is inside index[middle]
    Return true
Else if 50 < index[middle]
    Search index[0] through index[middle - 1]
Else if 50 > index[middle]
    Search index[middle + 1] through index[n - 1]
```
`Binary Search` is an efficient algorithm that operates on **sorted arrays**. It works by repeatedly dividing the search interval in **half** beginning with the **middle element** of the array. If the target value matches the middle element, the search concludes successfully. Otherwise, it narrows down the search range by half based on whether the target is **smaller** or **larger** than the middle element. This process is repeated until the target is **found** or the search range is **empty**.
<br><br>

## Running Time
![complexity](../img/cs50Week3Slide010.png)
In an example of finding the page containing a phone number in a phone book:
- `n` would be checking one page at a time
- `n/2` would be checking two pages at a time (half the time of `n`)
- `log2n` would be taking the value of `n` and divide it by `2` again and again until finding the phone number.
<br><br>

Rather than being ultra-specific about the mathematical efficiency of an algorithm, computer scientists discuss **efficiency** in terms of the order of various **running times** using `big O notation`.

![big o graphed](../img/cs50Week3Slide042.png)

In the above graph, the *first* algorithm is `O(n)` or `in the order of n`. The *second* is in `O(n)` as well. The *third* is in `O(log n)`. 

It's the shape of the **curve** that shows the efficiency of an algorithm. 
<br><br>

#### Common running times include:

- `O(n^2)` **Quadratic** time complexity. Considered the **worst** running time. An example may be `n` people doing `n` things, like shaking everyone's hand `n * n`. 

- `O(n log n)` **Log-linear** time complexity. The time taken by the algorithm grows in proportion to `n` multiplied by the `logarithm of n`.

- `O(n)` **Linear** time complexity. Linear search was of order **O(n)** because it would take `n` number of steps to run even in the worst case.

- `O(log n)` **Logarithmic** time complexity. The time taken by the algorithm decreases logarithmically as the size of `n` decreases. Binary search was of order `O(log n)`.

- `O(1)` **Constant** time complexity. Considered the **fastest** running time. The time taken by the algorithm remains constant regardless of `n`. Example would be accessing a specific element in an array.

#### Programmers are interested in both the worst case, or **upper bound**, and the best case, or **lower bound**:

- The *Big O* `O` symbol, represents the worst case of an algorithm.

- The *Omega* `Ω` symbol is used to denote the best case of an algorithm, such as `Ω(log n)`. An example would be finding the *element* in the first index checked in *linear search* `Ω(1)`, or finding the *element* in the middle index we checked first in *Binary search* `Ω(1)`.

- The *Theta* `Θ` symbol is used to denote where the **upper bound**`O`  and **lower bound**`Ω` are the same, where the best case and the worst case running times are the same. An example would be taking names in attendance one by one, it will take the same number of steps `Θ(n)`
<br><br>

## search.c
We can implement **linear search** in **C** as follows:
```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Define array & values of elements (int)
    int number[] = {20, 500, 10, 5, 100, 1, 50};

    // Prompt user for number to find
    int n = get_int("Number: ");

    // Linear search
    for (int i = 0; i < n; i++)
    {
        if (number[i] == n)
        {
            printf("Found\n");
            // Indicate success and exit
            return 0;
        }
    }
    printf ("Not found\n");
    // Exit program with an error
    return 1;
}
```
Let's now search for a **string** within an array:
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

    string s = get_string("String: ");
    for (int i = 0; i < 6; i++)
    {
        if (strcmp(strings[i], s) == 0)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
```
> [!CAUTION]
> Note that we cannot use same format to compare strings as we did with integers.

Instead we used `if (strcmp(string[], s) == 0)`:
 
- `strcmp` is a function available through the `<string.h>` library. 

- `strcmp` takes strings as arguments and will return `0` if the strings are the same.

- The strings are compared based on the **ASCII** values of their characters.
<br><br>

We can combine these ideas of both numbers and strings into a **Phone Book** program: 
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Arrays of strings
    string names[] = {"Carter", "David", "John"};
    string numbers[] = {"+1-617-495-1000", "+1-617-495-1000", "+1-949-468-2750"};

    // Prompt user for name
    string name = get_string("Name: ");
    for (int i = 0; i < 3; i++)
    {
        // Compare name with names in array
        if (strcmp(names[i], name) == 0)
        {
            // print Found followed by corresponding phone number
            printf("Found: %s\n", numbers[i]);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
```
> [!TIP]
> Rule of thumb: If you are not going to do math with a number, store it as a string not an integer. Ex : Phone numbers.

This program works on the basis that `names[0]` corresponds to `numbers[0]`, and `names[1]` to `numbers[1]`. While this works, there are numerous inefficiencies; and as this program scales, there is a chance that names and numbers may not correspond.
<br><br>

## Data Structures

In **C**, there is a way by which we can create our own data types via a `struct`. It would be useful to create our own data type called `person`, that stores a `name` and `number`:

```c
// Define new data type
typedef struct
{
    // Assign variables ot it
    string name;
    string number;
}
// Name it
person;
```

Now let's see it in action:
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    person people[3];

    people[0].name = "Carter";
    people[0].number = "+1-617-495-1000";

    people[1].name = "David";
    people[1].number = "+1-617-495-1000";

    people[2].name = "John";
    people[2].number = "+1-949-465-2750";

    string name = get_string("Name: ");
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
```
- We create an array called `people` of type `person` that is a size of `3`. 

-  To update the names of the people in our array, we use `people[0].name` to assign a name to `person[0]`.

- To update the numbers to the people in our array, we use `people[1].number` to assign a number to `person[1]`.
<br><br>

## Sorting
Sorting refers to the process of arranging a list of values in a specific **order**. The goal of sorting is to make it easier to search, access, and manipulate data efficiently. There are many different **sorting algorithms**.
<br><br>
```
unsorted -> | Algorithm | -> sorted
```
```
7 2 5 4 1 6 0 3 -> | Algorithm | -> 0 1 2 3 4 5 6 7
```

### Selection Sort

**Selection sort** is a simple algorithm that repeatedly selects the **smallest element** from the **unsorted** sublist and *swaps* it with the **leftmost** unsorted element. This process effectively grows the sorted sublist by one element with each iteration. 

The algorithm for selection sort in *pseudocode* is:
```
For i from 0 to n-1
    Find smallest number between numbers[i] and numbers[n-1]
    Swap smallest number with numbers[i]
```
Every time we sort one element, the number of steps reduce by one.
- The first time iterating through the list took `n-1` steps.
- The second time, it took `n-2` steps.
```
(n - 1) + (n - 2) + (n - 3) + ... + 1
```
This could be simplified to:
```
n(n - 1)/2

(n^2 - n)/2

n^2/2 - n/2
```
And ultimately *big O* notation `O(n^2)`: 

- The worst-case scenario for **selection sort** occurs when the input list is in reverse order. In each iteration the algorithm needs to find the minimum element from the remaining unsorted sublist, resulting in `nested loops` and `quadratic time complexity`.

- *Omega* notation `Ω(n^2)`: Best case scenario occurs when the list is already sorted. Even then, selection sort still need to iterate through `n` elements, `n` number of times to ensure that it's properly sorted, resulting in `quadratic time complexity`.

- *Theta* notation `Θ(n^2)`: In **selection sort**, the time complexity of both upper and lower bounds is proportional to `n^2`.
<br><br>

## Bubble Sort

**Bubble sort** is a simple sorting algorithm that repeatedly steps through the input list element by element, comparing the current element with the other after it, swapping their values to "**bubble**" larger elements to the end.  

```
Repeat n-1 times
    For i from 0 to n-2
        If numbers[i] and numbers[i+1] out of order
            Swap them
    In no swaps
        Quit        
```            
> [!Note]
> `n-2` is used as the limit of the range, it ensures that the loop iterates up to the second-to-last element of the array and the comparisons are made within the the bounds of the array. If `n-1` were used, the loop would attempt to compare the last element with an index beyond the array's bounds.

<br><br>
As we further sort the array, we know more and more of it becomes sorted, so we only need to look at the pairs of numbers that haven't been sorted yet. Representing this mathematically, where **n** represents the number of cases, it could be said that the **bubble sort** can be analyzed as:

```
(n-1) x (n-1)

n^2 - 1n - 1n + 1

n^2 - 2n + 1

O(n^2)
```
- `n^2` being the most influential factor in determining the efficiency of this algorithm. `Bubble sort`, like **selection sort**, is considered to be of the order `O(n^2)` in the worst case where all values are unsorted, resulting in **quadratic time complexity**.

- In the best case scenario, where all values are sorted, it will only take **one** pass through the list to confirm that it's sorted, resulting in **linear time complexity** and an **Omega notation** of `Ω(n)`.

- **Theta notation** is not directly applicable to **bubble sort**, since the *upper* and *lower* bounds are different. 
<br><br>

## Recursion
**Recursion** is a concept in programming where a function calls itself. We saw this earlier:
```
If no indexes left
    return false
If number inside middle index
    Return true
Else if number < middle index
    Search left half
Else if number > middle index
    Search right half
```
- Notice that we are calling `search` in smaller and smaller iterations of this problem. 

- Each **recursive call** reduces the problem size until it reaches a **base case**, which is a condition that allows the function to stop calling itself and return a result. In our example if would be the line: `If no indexes found -> return false`.
<br><br>

In week 1 we wanted to create a pyramid structure as follows:
```
#
##
###
####
```
```c
#include <cs50.h>
#include <stdio.h>

void draw(int n);

int main(void)
{
    int height = get_int("Height: ");
    draw(height);
}

void draw(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
```
To implement this using **recursion**, we can change our code as follows:
```c
#include <cs50.h>
#include <stdio.h>

void draw(int n);

int main(void)
{
    int height = get_int("Height: ");
    draw(height);
}

void draw(int n)
{
    // If nothing to draw
    if (n <= 0)
    {
        return;
    }
    // Draw pyramid of height n - 1
    draw(n - 1);

    // Draw one more row of width n
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}
```
> [!NOTE]
> Notice the **base case** will ensure the code does not run forever. 

- The line `if(n <= 0)` terminated the recursion because the problem has been solved. Every time `draw` calls itself, it calls itself by `n-1`. At some point, `n-1` will equal `0`, resulting in the `draw` function returning and the program will end.
<br><br>

## Merge Sort

**Merge sort** is a very efficient algorithm that follows the divide-and-conquer approach to sort a list of elements. It works by **recursively** dividing the input list into smaller *sublists*, sorting them and **merging** the sublists in a sorted manner. Merge sort is efficient for sorting large datasets, however, it does require additional memory space.

```
If only one number
    Quit
Else    
    Sort left half of numbers
    Sort right half of numbers
    Merge sorted halves
```
<br><br>
Consider the following list of numbers:
```
6341
```

1. Merge sort asks, "Is this one number?" The answer is `no`, the algorithm continues.
```
6341
```
2. Merge sort will now **split** the numbers down the middle (or as close as it can get) and sort the **left** half of the numbers.
```
63|41
```
3. Merge sort would look at the sublist on the left and ask "is this one number?" The answer is `no`, it would then split the numbers on the **left** down the middle.
```
6|3
```
4. Merge sort will ask again "is this one number?" The answer is `yes`, it will look at the number on the left and the number on the right. It will put the smaller number first, then the second smallest
```
36
```
5. Now, we return where we left off in the pseudocode now that the left side has been sorted.
```
36|41
```
6. Merge sort would look at the sublist on the **right** and ask "is this one number?" The answer is `no`, it would then split the numbers on the right down the middle.
```
4|1
```
7. Merge sort will ask again "is this one number?" The answer is `yes`, it will look at the number on the left and the number on the right. It will put the smaller number first, then the second smallest
```
14
```
8. Both sublists are now sorted. 
```
36|14
```
9. Finally, the algorithm will `merge` both sides. It will look at the **first** number on the left and the **first** number on the right. It will put the smaller number first, then the second smallest. The algorithm will repeat this for all numbers.
```
36 | 14

136 | 4 

1346
```
10. Merge sort is complete, and the program quits.
<br><br>

We can think of this process represented as follows:

- The algorithm for the division phase can be represented as taking `O(log n)` time, where `n` is the number of elements in the array.

- In the merging process, each merging step takes `O(n)` time per level, where `n` is the total number of elements in the list.

- The total time complexity os merge sort is the product of these two phases, which is `O(n log n)`.

- The best case is still `Ω(n log n)` because the algorithm still must visit each place in the list.

- Therefore, merge sort is on the order of `Θ(n log n)`.
