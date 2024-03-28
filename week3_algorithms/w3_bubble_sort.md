# Bubble Sort

In **Bubble Sort**, the idea of the algorithm is to move higher valued element generally toward the right and lower value elements generally towards the left.

**Pseudocode**:

```txt
Set swap counter to a non-zero value
Repeat until swap counter is 0;
    Reset swap counter to 0
    Look at each adjacent pair
        if two adjacent element are not in order, swap them and add one to the swap counter
```        
<br>

## How does Bubble Sort Work?

Let's sort the following array to illustrate the process:

```txt
| 5 | 2 | 1 | 3 | 6 | 4 |
```

**1.** Set swap counter to a **non-zero** value

|Swap Counter|
|:-:|
|**-1**|

<br>

**2.** Reset swap counter to 0

|Swap Counter|
|:-:|
|**0**|

<br>

**3.** Look at each adjacent pair starting from the left

```txt
| *5 | *2 | 1 | 3 | 6 | 4 |
```

**4.** If two adjacent elements are not in order *swap them* and add `1` to the swap counter

```txt
| 2 | 5 |

| *2 | *5 | 1 | 3 | 6 | 4 |
```

|Swap Counter|
|:-:|
|**1**|

<br>

**5.** *Repeat*, Look at next adjacent pair to the right

```txt
| 2 | *5 | *1 | 3 | 6 | 4 |
```

**6.** If two adjacent elements are not in order *swap them* and add `1` to the swap counter

```txt
| 1 | 5 |

| 2 | *1 | *5 | 3 | 6 | 4 |
```

|Swap Counter|
|:-:|
|**2**|

<br>

**7.** *Repeat*, Look at next adjacent pair to the right

```txt
| 2 | 1 | *5 | 3* | 6 | 4 |
```

**8.** If two adjacent elements are not in order *swap them* and add `1` to the swap counter

```txt
| 3 | 5 |

| 2 | 1 | *3 | *5 | 6 | 4 |
```

|Swap Counter|
|:-:|
|**3**|

<br>

**9.** *Repeat*, Look at next adjacent pair to the right

```txt
| 2 | 1 | 3 | *5 | *6 | 4 |
```

**10.** If two adjacent elements are not in order *swap them* and add `1` to the swap counter

```txt
| 2 | 1 | 3 | *5 | *6 | 4 |
```
> `5` and `6` are in order, swap counter unchanged, we move on to the next pair

|Swap Counter|
|:-:|
|**3**|

<br>

**11.** *Repeat*, Look at next adjacent pair to the right

```txt
| 2 | 1 | 3 | 5 | *6 | *4 |
```

**12.** If two adjacent element are not in order *swap them* and add `1` to the swap counter

```txt
| 4 | 6 |

| 2 | 1 | 3 | 5 | *4 | *6 |
```
|Swap Counter|
|:-:|
|**4**|

<br>

> [!NOTE]
> Largest element `6` is now bubbled all the way to the end of the array and considered `sorted`. It will not be considered in the following passes.

```txt
| 2 | 1 | 3 | 5 | 4 |----------| 6 |
```

<br>

### We now finished *one pass* through bubble sort, we go back to the condition `Repeat until the swap counter is 0`.

<br>

**13.** Reset swap counter to 0

|Swap Counter|
|:-:|
|**0**|

<br>

**14.** Look at each adjacent pair starting from the left

```txt
| *2 | *1 | 3 | 5 | 4 |----------| 6 |
```

**15.** If two adjacent elements are not in order *swap them* and add `1` to the swap counter

```txt
| 1 | 2 |

| *1 | *2 | 3 | 5 | 4 |----------| 6 |
```

|Swap Counter|
|:-:|
|**1**|

<br>

**16.** *Repeat*, Look at next adjacent pair to the right

```txt
| 1 | *2 | *3 | 5 | 4 |----------| 6 |
```

**17.** If two adjacent elements are not in order *swap them* and add `1` to the swap counter

```txt
| 1 | *2 | *3 | 5 | 4 |----------| 6 |
```
> `2` and `3` are in order, swap counter unchanged, we move on to the next pair

|Swap Counter|
|:-:|
|**1**|

<br>

**18.** *Repeat*, Look at next adjacent pair to the right

```txt
| 1 | 2 | *3 | *5 | 4 |----------| 6 |
```

**19.** If two adjacent elements are not in order *swap them* and add `1` to the swap counter

```txt
| 1 | 2 | *3 | *5 | 4 |----------| 6 |
```
> `3` and `5` are in order, swap counter unchanged, we move on to the next pair

|Swap Counter|
|:-:|
|**1**|

<br>

**20.** *Repeat*, Look at next adjacent pair to the right

```txt
| 1 | 2 | 3 | *5 | *4 |----------| 6 |
```

**21.** If two adjacent elements are not in order *swap them* and add `1` to the swap counter

```txt
| 4 | 5 |

| 1 | 2 | 3 | *4 | *5 |----------| 6 |
```

|Swap Counter|
|:-:|
|**2**|

<br>

> [!NOTE]
> Second largest element `5` is now bubbled all the way to the end of the array and considered **sorted**. It will not be considered in the next passes.

```txt
| 1 | 2 | 3 | 4 |----------| 5 | 6 |
```
<br>

### We now finished *two passes* through bubble sort, we go back to the condition `Repeat until the swap counter is 0`.

<br>

**22.** Reset swap counter to 0

|Swap Counter|
|:-:|
|**0**|

<br>

**23.** Look at each adjacent pair starting from the left

```txt
| *1 | *2 | 3 | 4 |----------| 5 | 6 |
```

**24.** If two adjacent elements are not in order *swap them* and add `1` to the swap counter

```txt
| *1 | *2 | 3 | 4 |----------| 5 | 6 |
```
> `1` and `2` are in order, swap counter unchanged, we move on to the next pair

|Swap Counter|
|:-:|
|**0**|

<br>

**25.** *Repeat*, Look at next adjacent pair to the right

```txt
| 1 | *2 | *3 | 4 |----------| 5 | 6 |
```

**26.** If two adjacent elements are not in order *swap them* and add `1` to the swap counter

```txt
| 1 | *2 | *3 | 4 |----------| 5 | 6 |
```
> `2` and `3` are in order, swap counter unchanged, we move on to the next pair

|Swap Counter|
|:-:|
|**0**|

<br>

**27.** *Repeat*, Look at next adjacent pair to the right

```txt
| 1 | 2 | *3 | *4 |----------| 5 | 6 |
```

**26.** If two adjacent elements are not in order *swap them* and add `1` to the swap counter

```txt
| 1 | 2 | *3 | *4 |----------| 5 | 6 |
```
> `3` and `4` are in order, swap counter unchanged

|Swap Counter|
|:-:|
|**0**|

<br>

Now that we went through the whole array and we didn't have to make any swaps (the **swap counter** is still at `0`), we can declare the array `SORTED`.

```txt
| 1 | 2 | 3 | 4 | 5 | 6 |
```
<br><br>

`Worst-case-scenario`: The array is in reverse order; we have to "bubble" each of the `n` elements all the way across the array, and since we can only fully bubble **one** element into position per pass, we must to this `n` times, resulting in a running time of `O(n^2)`.
<br><br>

`Best-case-scenario`: The array is already perfectly sorted, and we make no swaps on the first pass, resulting in a running time of `Ω(n)`.
