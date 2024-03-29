# Selection Sort

In **Selection Sort**, the idea of the algorithm is to find the smallest unsorted element and add it to the end of the sorted list.

**Pseudocode**:

```txt
Repeat until no unsorted elements remain:
    Search the unsorted part of the data to find the smallest value
    Swap the smallest found value with the first element of the unsorted part
```

## How does Selection Sort Work?

Let's sort the following array to illustrate the process:

```txt
| 5 | 2 | 1 | 3 | 6 | 4 |
```
<br>

**1.** Search the **unsorted part** of the data (currently the entire array) to find the **smallest** value.

```txt
| 5 | 2 | *1 | 3 | 6 | 4 |

| 1 |
```

**2.** Swap the **smallest** value with the **first** element of the unsorted part

```txt
| *5 | 2 | *1 | 3 | 6 | 4 |

    1 <-> 5

| *1 | 2 | *5 | 3 | 6 | 4 |
```
<br>

> [!NOTE]
> Smallest element `1` is now at the beginning of the array and `sorted`. It will not be considered in the following passes.

```txt
| *1 | ---------- | 2 | 5 | 3 | 6 | 4 |
```
<br>

**3.** *Repeat*, search the unsorted part of the data to find the **smallest** value.

```txt
| 1 | ---------- | 2 | 5 | 3 | 6 | 4 |

| *2 | 5 | 3 | 6 | 4 |

| 2 |
```
**4.** Swap the **smallest** value with the **first** element of the unsorted part

```txt
| *2 | 5 | 3 | 6 | 4 |
```
> `2` is also the first element of the unsorted part, it is swapped with itself, leaving it where it originally was.

<br>

> [!NOTE]
> Smallest element `2` is now `sorted`. It will not be considered in the following passes.

```txt
| 1 | *2 | ---------- | 5 | 3 | 6 | 4 |
```

<br>

**5.** *Repeat*, search the unsorted part of the data to find the **smallest** value.

```txt
| 1 | 2 | ---------- | 5 | 3 | 6 | 4 |

| 5 | 3* | 6 | 4 |

| 3 |
```
**6.** Swap the **smallest** value with the **first** element of the unsorted part

```txt
| *5 | *3 | 6 | 4 |

    3 <-> 5

| *3 | *5 | 6 | 4 |
```
```txt
| 1 | 2 | ---------- | *3 | *5 | 6 | 4 |
```
<br>

> [!NOTE]
> Smallest element `3` is now `sorted`. It will not be considered in the following passes.

```txt
| 1 | 2 | *3 | ---------- | 5 | 6 | 4 |
```

<br>

**7.** *Repeat*, search the unsorted part of the data to find the **smallest** value.

```txt
| 1 | 2 | 3 | ---------- | 5 | 6 | 4 |

| 5 | 6 | *4 |

| 4 |
```
**8.** Swap the **smallest** value with the **first** element of the unsorted part

```txt
| *5 | 6 | *4 |

    4 <-> 5

| *4 | 6 | *5 |
```
```txt
| 1 | 2 | 3 | ---------- | *4 | 6 | *5 |
```
<br>

> [!NOTE]
> Smallest element `4` is now `sorted`. It will not be considered in the following passes.

```txt
| 1 | 2 | 3 | *4 | ---------- | 6 | 5 |
```

<br>

**9.** *Repeat*, search the unsorted part of the data to find the **smallest** value.

```txt
| 1 | 2 | 3 | 4 | ---------- | 6 | 5 |

| 6 | *5 |

| 5 |
```

**10.** Swap the **smallest** value with the **first** element of the unsorted part

```txt
| *6 | *5 |

  5 <-> 6

| *5 | *6 |
```
```txt
| 1 | 2 | 3 | 4 | ---------- | *5 | 6 |
```
<br>

> [!NOTE]
> Smallest element `5` is now `sorted`. It will not be considered in the following passes.

```txt
| 1 | 2 | 3 | 4 | 5 | ---------- | 6 |
```

<br>

**11.** *Repeat*, search the unsorted part of the data to find the **smallest** value.

```txt
| 1 | 2 | 3 | 4 | 5 | ---------- | 6 |

| 6 |
```
**12.** Swap the **smallest** value with the **first** element of the unsorted part

```txt
| *6 |
```
> `6` is also the first element of the unsorted part, it is swapped with itself, leaving it where it originally was.

<br>

> [!NOTE]
> Smallest element `6` is now considered `sorted`.

```txt
| 1 | 2 | 3 | 4 | 5 | *6 |
```

<br>

Now that we went through the **entire data set**, we can declare the array `SORTED`.

```txt
| 1 | 2 | 3 | 4 | 5 | 6 |
```
<br><br>

`Worst-case-scenario`: We have to iterate over each of the `n` elements of the array (to find the smallest unsorted element) and we must repeat this process `n` times, since only one element gets sorted on each pass, resulting in a running time of `O(n^2)`.
<br><br>

`Best-case-scenario`: Exactly the same! There's no way to guarantee the array is sorted until we go through this process for all elements, resulting in a running time of `Ω(n^2)`. 
