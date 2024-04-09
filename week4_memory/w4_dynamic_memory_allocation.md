# Dynamic Memory Allocation

We've previously seen one way to work with pointers, pointing a **pointer variable** at another **variable** that already exists in our system. This requires us to know exactly **how much memory** our system will need at the moment our program is **compiled**.

Sometimes we cannot know how much memory we'll need at **compile-time**, particularly in scenarios where the size of the data may **vary** based on **user input**, and need to **access to new memory** while our program is running. 

`Dynamic memory allocation` provides a mechanism for accessing memory at **runtime**. To achieve this, we can use **pointers** to get access to a block of **dynamically-allocated memory** at runtime.

**Dynamically allocated memory** comes from a pool of memory known as the `heap`.





