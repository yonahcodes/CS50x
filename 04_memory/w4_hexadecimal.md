# Hexadecimal

Most Western cultures use the `decimal system`, **base-10**, to represent numeric data. Each position in a number represents a **power of 10**. 

```txt
0   1   2   3   4   5   6   7   8   9
```
```txt
Example number 365 --> 300 (10^2), 6 (10^1), 5 (10^0).
```
<br><br>

Computers use the `binary system`, **base-2**, to represent numeric (and all data). Each digit's position represents a **power of 2**.

```txt
0   1
```
```txt
Binary number 1011 --> (1 * 2^3) + (0 * 2^2) + (1 * 2^1) + (1 * 2^0) = 8 + 0 + 2 + 1 = 11 in decimal
``` 
<br><br>

The `hexadecimal system`, **base-16**, is a much more *concise* way to express the *binary data* in a computer system. Each position in a **hex number** corresponds to a **power of 16**, and each **hexadecimal digit** corresponds to **four binary digits (bits)**. This makes it convenient for expressing long and complex binary data efficiently.

```txt
0   1   2   3   4   5   6   7   8   9   A   B   C   D   E   F
```
<br>

|Decimal|Binary|Hexadecimal||Decimal|Binary|Hexadecimal|
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
|0|0000|0x**0**||8|1000|0x**8**|
|1|0001|0x**1**||9|1001|0x**9**|
|2|0010|0x**2**||10|1010|0x**A**|
|3|0011|0x**3**||11|1011|0x**B**|
|4|0100|0x**4**||12|1100|0x**C**|
|5|0101|0x**5**||13|1101|0x**D**|
|6|0110|0x**6**||14|1110|0x**E**|
|7|0111|0x**7**||15|1111|0x**F**|

<br>

> To distinguish numbers in **hexadecimal notation** from **decimal notation** we use prefix `0x`. 

<br>

Just like **binary** has **place values** (1, 2, 4, 8...) and **decimal** does too (1, 10, 100, 1000...), so does **hexadecimal** (1, 16, 265, 4096,...).

```txt
Hexadecimal number 0x397 --> (3 * 16^2) + (9 * 16^1) + (7 * 16^0) = 768 + 144 + 7 = 919 in decimal
```
```txt
Hexadecimal number 0xADC --> (10 * 16^2) + (13 * 16^1) + (12 * 16^0) = 2560 + 208 + 12 = 2780 in decimal
```
<br><br>

## Converting Binary to Hexadecimal

To convert a **binary** number to **hexadecimal**, we group `4 binary digits (bits)` together right to left. If the number of bits *isn't divisible by 4*, we can **"pad"** the binary number with **leading zeros** to make it a multiple of 4. 

<br>

**1.** Prepare the binary number, if it's not a multiple of 4 bits, add leading zeros: 

```txt
01000110101000101011100100111101
```
<br>

**2.** Group the the bits into **sets of 4 bits**, starting from the right:

```txt
0100 0110 1010 0010 1011 1001 0011 1101
```
<br>

**3.** Assign **weight** to each bit (`0000` = `*8 *4 *2 *1`) and **multiply** each bit by its corresponding weight:
```
0400 0420 8020 0020 8021 8001 0021 8401
```
<br>

**4.** Calculate **Decimal value** with the sum of the results for each group of 4 bits:

```txt
0+4+0+0  0+4+2+0  8+0+2+0  0+0+2+0  8+0+2+1  8+0+0+1  0+0+2+1  8+4+0+1

    4       6       10        2        11        9       3        13
```
<br>

**5.** Determine the corresponding **Hexadecimal digit**:

```txt
4   6   A   2   B   9   3   D  
```
```txt
0x46A2B93D
```
