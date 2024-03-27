# Variables and Scope

**Scope** is a characteristic of a *variable* that defines from which functions that variable may be accessed.

- `Local variables` can only be accessed within the functions in which they are created.
- `Global variables` can be accessed by any function in the program. (They are declared outside of  )

So far in the course, we have been working mostly with **local variables**.

```c
int main(void)
{
    int result = triple(5);
}

int triple(int x)
{
    return x * 3;
}
```

- `x` is **local** to the function `triple()`. No other function can refer to that variable, not even `main()`.
- `result` variable is **local** to `main()` function.<br><br>

## Global Variables

If a variable is declared outside of all functions, any function may refer to it. In this example `global`:

```c
#include <stdio.h>

float global = 0.5050;

int main(void);
{
    triple();
    printf("%f\n", global);
}

void triple(void)
{
    // Equivalent to global = global * 3;
    global *= 3;
}
```

<br><br>

## Local Variables

Local variables in **C** are `passed by value` in function calls. When you pass *local variables* to a function, a copy of the variable's **value** is made and given to the function. This means that changes made to the variable inside the function **do not** affect the original variable outside the function. The function will operate on its own version of the variable and any modifications made to it are confined to the **scope** of the function.

```c
int main(void)
{
    int foo = 4;
    triple(foo);
}

int triple(int x)
{
    return x *= 3;
}
```

In the code above, `foo` is not changed and we will not achieve the desired effect of tripling the value of `foo`.

```c
int main(void)
{
    int foo = 4;
    foo = triple(foo);
}

int triple(int x)
{
    return x *= 3;
}
```

In the code above, we **overwrite** `foo`, giving `triple()` a copy of `foo` and assigning the return value back to `foo`.

> Things can get complicated if the same variable name appears in multiple functions, which is perfectly okay as long as the variables exist in different **scopes**.

```c
int increment(int x);

int main(void)
{
    int x = 1;
    int y;
    y = increment(x);

    printf("x is %i, y is %i\n", x, y);
}

int increment(int x)
{
    x++;
    return x;
}
```

The code above will return:

```
x is 1, y is 2
```

Notice that both functions use variables called `x`, but is important to understand that these two variables are **independent** of each other. Because of the **scope**, they will not interfere with one another.

We can visualize this as follows:

```c
int increment(int x);

int main(void)
{
    int Xm = 1;
    int y;
    y = increment(Xm);

    printf("x is %i, y is %i\n", Xm, y);
}

int increment(int Xi)
{
    Xi++;
    return Xi;
}
```
