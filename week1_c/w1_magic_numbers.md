# C - Magic Numbers

In C programming, "**magic numbers**" refer to numeric constants that are used in the code without explanation. These numbers are often hard-coded and lack clear context or meaning.

```c
card deal_cards(deck name)
{
    for (int i = 0; i < 52; i++)
    {
        // deal the card
    }
}
```

In the example above `52` is a **magic number**. It is used without explanation and could lead to problems if this function is one of many in a suite of programs that manipulate decks fo cards.

```c
card deal_cards(deck name)
{
    int deck_size = 52;
    for (int i = 0; i < 52; i++)
    {
        // deal the card
    }
}
```

The program above fixes one problem, but introduces another.

- Even if **globally** declared, if some other function in our suite inadvertently manipulates `deck_size`, it could lead to problems.
<br><br>

## Preprocessor Directive or Macro

> **C** provides a **preprocessor directive** (also called a **macro**) for creating symbolic constants.

```c
#define NAME REPLACEMENT
```

At the time the program is compiled, `#define` goes through the code and replaces `NAME` with `REPLACEMENT`.

```c
#define PI 3.14159265
```

At the time the program is compiled, `#define` goes through the code and replaces `PI` with `3.14159265`.

```c
#define COURSE "CS50"
```

At the time the program is compiled, `#define` goes through the code and replaces `COURSE` with `"CS50"`.

> If `#include` is similar to copy/paste, then `#define` is analogous to find/replace.

In the previous deck_size example, it would look like this:

```c
#define DECKSIZE 52

card deal_cards(deck name)
{
    for (int i = 0; i < DECKSIZE; i++)
    {
        // deal the card
    }
}
```
