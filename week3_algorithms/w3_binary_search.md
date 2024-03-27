# Binary Search

In **Binary search**, the idea of the algorithm is to **divide and conquer**, reducing the search area by half each time, trying to find a *target* element.

In order to leverage this power however, our array must first be **sorted**, else we cannot make assumptions about the array's contents.

**Pseudocode**:

```txt
Repeat until the sub(array) is of size 0;
    Calculate the middle point of the current (sub)array.   
    If the target is at the middle, stop.
    Otherwise, if the target is less than the middle value, repeat, changing the end point to be just to the left of the middle.
    Otherwise, if the target is greater than the middle value, repeat, changing the start point to be just to the right of the middle.
```

## Let's visualize this process

```txt
| 6 | 7 | 8 | 9 | 10 | 11 | 14 | 15 | 17 | 19 | 22 | 23 | 25 | 28 | 30 | --> Elements

| 0 | 1 | 2 | 3 |  4 |  5 |  6 |  7 |  8 |  9 | 10 | 11 | 12 | 13 | 14 | --> Indexes
```

|Target|Start|End|Middle|
|:-:|:-:|:-:|:-:|
|**19**|Index[0]| Index[14]|Index[7]|

<br>

1. Is the value in **index[7]** `15` == `19` ? `No`

2. Target `19` is `>` than **index[7]** value `15`

3. Change start point to next index to the right of middle point `index[8]`

4. Find the new middle point `index[11]`

<br>

|Target|Start|End|Middle|
|:-:|:-:|:-:|:-:|
|**19**|**Index[8]**|Index[14]|Index[11]|

<br>

1. Is the value in **index[11]** `23` == `19` ? `No`

2. Target `19` is `<` than **index[11]** value `23`

3. Change end point to next index to the left of middle point `index[10]`

4. Find the new middle point `index[9]`

<br>

|Target|Start|End|Middle|
|:-:|:-:|:-:|:-:|
|**19**|Index[8]|**Index[10]**|Index[9]|

<br>

1. Is the value in **index[9]** `19` == `19` ? `Yes`

2. Stop the program

<br><br>

### Let's try to look for an element that does not exist in the array

```txt
| 6 | 7 | 8 | 9 | 10 | 11 | 14 | 15 | 17 | 19 | 22 | 23 | 25 | 28 | 30 | --> Elements

| 0 | 1 | 2 | 3 |  4 |  5 |  6 |  7 |  8 |  9 | 10 | 11 | 12 | 13 | 14 | --> Indexes
```

|Target|Start|End|Middle|
|:-:|:-:|:-:|:-:|
|**16**|Index[0]| Index[14]|Index[7]|

<br>

1. Is the value in **index[7]** `15` == `16` ? `No`

2. Target `16` is `>` than **index[7]** value `15`

3. Change start point to next index to the right of middle point `index[8]`

4. Find the new middle point `index[11]`

<br>

|Target|Start|End|Middle|
|:-:|:-:|:-:|:-:|
|**16**|**Index[8]**|Index[14]|Index[11]|

<br>

1. Is the value in **index[11]** `23` == `16` ? `No`

2. Target `16` is `<` than **index[11]** value `23`

3. Change end point to next index to the left of middle point `index[10]`

4. Find the new middle point `index[9]`

<br>

|Target|Start|End|Middle|
|:-:|:-:|:-:|:-:|
|**16**|Index[8]|**Index[10]**|Index[9]|

<br>

1. Is the value in **index[9]** `19` == `16` ? `No`

2. Target `16` is `<` than **index[9]** value `19`

3. Change end point to the next index to the left of middle point `index[9]`

4. Find the new middle point `index[8]`

<br>

|Target|Start|End|Middle|
|:-:|:-:|:-:|:-:|
|**16**|Index[8]|**Index[8]**|Index[8]|

<br>

1. Is the value in the **index[8]** `17` == `16` ? `No`

2. Target `16` is `<` than **index[8]** value `17`

3. Change end point to the next index to the left of middle point `index[7]`

<br>

|Target|Start|End|Middle|
|:-:|:-:|:-:|:-:|
|**16**|Index[8]|**Index[7]**|Index[8]|

<br>

> [!CAUTION]
> Notice that start index[8] is greater than end index[7]. The two ends of our array have CROSSED

This confirms that we have a **(sub)array** of size `0` and we can now **guarantee** that an element of value `16` does not exist in the array.
<br><br>

`Worst-case scenario`: We have to divide a list of elements in half repeatedly to find the target element, either because the target element will be found at the end of the last division or doesn't exist in the array at all, resulting in `O(log n)`.

`Best-case-scenario`: The target element is at the midpoint of the full array, and so we can stop immediately after we start, resulting in `Ω(1)`.
