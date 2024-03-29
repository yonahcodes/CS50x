# Merge Sort

In **merge sort**, the idea of the algorithm is to sort smaller arrays and then combine those arrays together (merge them) in sorted order.

Merge sort leverages **recursion**, a process in which we solve a problem by invoking the process itself to solve smaller sub-problems.

**Pseudocode:**

```txt
Sort the left half of the array (assuming n > 1)
Sort the right half of the array (assuming n > 1)
Merge the two halves together
```
<br>

## How does Merge Sort Work?

Let's sort the following array to illustrate the process:

```txt
| 5 | 2 | 1 | 3 | 6 | 4 |
```
<br>

**1.** Sort the **left** half of the array

```txt
| *5 | *2 | *1 | 3 | 6 | 4 |

|  5 |  2 |  1 |
```
<br>

**2.** Sort the **left** part of the sub-array

```txt
| *5 | 2 | 1 |

| 5 |
```

> Note that we arbitrarily chose to use `5` as the left half, it could have been `5 | 2`.

<br>

A **single element** must necessarily be sorted. We can consider that the element `5` is `sorted`.

```txt
    | 2 | 1 |
| 5 |
```
<br>

**3.** Sort the **right** part of the sub-array

```txt
    | *2 | *1 |
| 5 |
```
<br>

**4.** **How?** *Repeat* -> sort **left** part of the sub-array.

```txt
| *2 | 1 |

| 2 |
```
Single element `2` is now considered `sorted`.

```txt
         | 1 |
    | *2 |    
| 5 |
```
<br>

**5.** Sort the **right** part of the sub-array

```txt
        | *1 |
    | 2 |    
| 5 |
```
Single element `1` is now considered `sorted`.

```txt
    | 2 | *1 |    
| 5 |
```
<br>

**6.** **Merge** the two halves together

- Now, we need to **merge** the elements of each sub-part.

- To merge **two elements**, we compare the **first** element of the *left* part and the **first** element of the *right* part.

- Then place them in a **sorted** way.
```txt
               | *2 | *1 |  

| 5 |----------|  1 |  2 |
```
`5` as a *single element* is considered **merged** and **sorted**.

<br><br>

>[!NOTE]
> At this point, from the **original array**, we separated the **left half**, we sorted the *left* part (of the left sub-array) and we sorted the *right* part (of the left sub-array).
```txt
| 5 | 2 | 1 | 3 | 6 | 4 |

| 5 | 2 | 1 |

| 5 | = Sorted      | 1 | 2 | = Sorted  
```
<br><br>

Now the next step is to **merge** the *left* and *right* parts of the **sub-array**.

<br>

**7.** *Repeat*, **merge** the two halves together

- To merge, we compare the **first** element of the *left* part and the **first** element of the *right* part

- Then place them in a **sorted** way.

```txt
| *5 |----------| *1 | 2 |

| 1 |
```
<br>

**8.** *Repeat*, **merge** the two halves together

```txt
| *5 |----------| *2 |

| 1 | 2 |
```
<br>

**9.** *Repeat*, **merge** the two halves together
```txt
| *5 |

| 1 | 2 | 5 |
```
<br><br>

>[!NOTE]
> At this point, from the **original array**, we separated the **left half** and **sorted** it.
```txt
| 5 | 2 | 1 | 3 | 6 | 4 |

| 5 | 2 | 1 |

| 1 | 2 | 5 | = Sorted
```
<br><br>

Now the next step is to sort the **right half** of the **original array**.

<br>

**10.** Sort the **right** half of the array
```txt
| 5 | 2 | 1 | *3 | *6 | *4 |

            |  3 |  6 |  4 |
```
<br>

**11.** Sort the **left** part of the sub-array
```txt
| *3 |  6 |  4 |

| 3 |
```
Single element `3` is now considered `sorted`.
```txt
    | 6 | 4 |
| 3 |
```
<br>

**12.** Sort the **right** part of the sub-array
```txt
    | *6 | *4 |
| 3 |
```
<br>

**13.** **How?** *Repeat* -> sort **left** part of the sub-array.

```txt
| *6 | 4 |

| 6 |
```
Single element `6` is now considered `sorted`.
```txt
        | 4 |
    | *6 |
| 3 |
```
<br>

**14.** Sort **right** part of the sub-array.

```txt
        | *4 |
    | 6 |
| 3 |
```
Single element `4` is now considered `sorted`.
```txt
    | 6 | *4 |
| 3 |
```
<br>

**15.** **Merge** the two halves together

- Now, we need to **merge** the elements of each sub-part.

- To merge **two elements**, we compare the **first** element of the *left* part and the **first** element of the *right* part.

- Then place them in a **sorted** way.
```txt
               | *6 | *4 |  

| 3 |----------|  4 |  6 |
```
`3` as a *single element* is considered **merged** and **sorted**.

<br><br>

>[!NOTE]
> At this point we separated the **right half** and sorted the *left* part (of the right sub-array) and sorted the *right* part (of the right sub-array).
```txt
| 5 | 2 | 1 | 3 | 6 | 4 |

            | 3 | 6 | 4 |

| 3 | = Sorted      | 4 | 6 | = Sorted  
```
<br><br>

Now the next step is to **merge** the *left* and *right* parts of the **sub-array**.

<br>

**16.** *Repeat*, **merge** the two halves together

- To merge, we compare the **first** element of the *left* part and the **first** element of the *right* part

- Then place them in a **sorted** way.

```txt
| *3 |----------| *4 | 6 |

| 3 |
```
<br>

**17.** *Repeat*, **merge** the two halves together

```txt
| *4 | *6 |

| 3 | 4 | 6 |
```
> Since the `4` and `6` are on the same side and ordered, the bloc gets placed in order.

<br><br>

>[!NOTE]
> At this point, from the **original array**, we separated the **left half** and **sorted** it.
> Then we separated the **right half** and **sorted** it.
```txt
| 5 | 2 | 1 | 3 | 6 | 4 |

| 5 | 2 | 1 |

| 1 | 2 | 5 | = Sorted

            | 3 | 6 | 4 |

            | 3 | 4 | 6 | = Sorted  
```

<br><br>

Now the next step is to **merge** the `sorted` halves of the **original array**.

<br>


**18.** **Merge** the two halves together

- We compare the **first** element of the *left* half and the **first** element of the *right* half.

- Then place them in a **sorted** way.
```txt
| *1 | 2 | 5 |----------| *3 | 4 | 6 |

| 1 |
```
<br>

**19.** *Repeat*, **merge** the two halves together
```txt
| *2 | 5 |----------| *3 | 4 | 6 |

| 1 | 2 |
```
<br>

**20.** *Repeat*, **merge** the two halves together
```txt
| *5 |----------| *3 | 4 | 6 |

| 1 | 2 | 3 |
```
<br>

**21.** *Repeat*, **merge** the two halves together
```txt
| *5 |----------| *4 | 6 |

| 1 | 2 | 3 | 4 |
```
<br>

**22.** *Repeat*, **merge** the two halves together
```txt
| *5 |----------| *6 |

| 1 | 2 | 3 | 4 | 5 |
```
<br>

**23.** *Repeat*, **merge** the two halves together
```txt
| *6 |

| 1 | 2 | 3 | 4 | 5 | 6 |
```
<br>

Now that we went through the **entire data set**, we can declare the array `SORTED`.

```txt
| 1 | 2 | 3 | 4 | 5 | 6 |
```
<br><br>

`Worst-case-scenario`: We have to split `n` elements up and then recombine them, effectively doubling the sorted sub-arrays as we build them up. (combining sorted 1-element arrays into 2-element arrays, combining sorted 2-element arrays into 4-element arrays...). This scenario would result in a running time of `O(n log n)`.
<br><br>

`Best-case-scenario`: The array is already perfectly sorted. But we still have to split and recombine it back together with this algorithm, resulting in a running time of `Ω(n log n)`. 
