# Linear Search

In **Linear search**, the idea of the algorithm is to iterate across the array from left to right, searching for a specified element.

**Pseudocode**:

```txt
Repeat, starting at the first element:
    If the first element is the target element, stop.
    Otherwise, move to the next element.
```

|Target|
|:-:|
|9|

```txt
| 11 | 23 | 8 | 14 | 30 | 9 | 6 | 17 | 22 | 28 | 25 | 15 | 7 | 10 | 19 |
```

1. Is `11` == 9 ? No
2. Is `23` == 9 ? No
3. Is `8` == 9 ? No
4. Is `14` == 9 ? No
5. Is `30` == 9 ? No
6. Is `9` == 9 ? `Yes`
7. Stop the program
<br><br>

If the `target element` is **NOT** in the array, the **linear search** algorithm will still go through the list one element at a time, until the end of the data set.
<br><br>

`Worst-case scenario`: We have to look through the entire array of `n` elements, either because the *target element* is the last element of the array or doesn't exist in the array, resulting in a running time of `O(n)`.
<br><br>

`Best-case scenario`: The target element is the **first element** of the array, and so we can stop looking immediately after we start, resulting in a running time of `Ω(1)`.
