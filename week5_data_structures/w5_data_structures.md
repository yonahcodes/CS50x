# Data Structures

**Data structures** are essential components that help **organize** and **store** data efficiently in computer memory. They provide a way to manage and manipulate data effectively, enabling faster **access**, **insertion** and **deletion** operations.

The four main types of data structures that we covered are **arrays**, **linked lists**, **hash tables** and **tries**. Variations include trees and heaps (related to tries), stacks and queues (similar to arrays or linked lists). These structures generally cover most of what we will work with in **C**.

<br>

## Choosing the appropriate data structure

When selecting a **data structure** for a particular application, we have to weight the **pros** against the **cons**. Let's consider some of the important metrics for each.

<br>

|ARRAYS|
|:-:|
|**Insertion** is **bad** - lots of shifting to fit an element in the *middle*|
|**Deletion** is **bad** - lots of shifting after removing an element|
|**Lookup** is **great** - random access, *constant time*|
|**Sorting** is relatively **easy**|
|**Size** is relatively **small**|
|**Flexibility** **bad** - stuck with a fixed size|

<br><br>

|LINKED LISTS|
|:-:|
|**Insertion** is **easy** - just tack onto the front|
|**Deletion** is **easy** - once you find the element|
|**Lookup** is **bad** - have to rely on *liner search*|
|**Sorting** relatively **difficult** - unless sorting while constructing, losing speed|
|**Size** is relatively **small** (nto as small as arrays)|

<br><br>

|HASH TABLES|
|:-:|
|**Insertion** is **good** - two-step process (hash, then add)|
|**Deletion** is **easy** - once you find the element|
|**Lookup** is on average **better** than linked lists (smaller lists) - real world *constant factor*|
|**Sorting** is **bad** - using an array is better|
|**Size** depends on the data we are storing|

<br><br>

|TRIES|
|:-:|
|**Insertion** is **complex** - lots of dynamic memory allocation|
|**Deletion** is **easy** - just free a node|
|**Lookup** is **fast** - not quite as fast as an *array*|
|**Sorting** is already **done** as we build|
|**Size** can be **huge** even with little data - not great if space is a premium|
