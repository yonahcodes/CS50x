# Structures

**Structures** or (**structs**) are **user-defined** data types that allow us to *group* variables of different types under a single type **name**. This makes it easier to manage complex data, as we can access all the components with a single variable. We use **structs** to group together elements of a variety of data types that have a **logical connection**.

```c
struct car
{
    int year;
    char model[10];
    char plate[7];
    int odometer;
    double engine_size;
};
```
- `struct` it the structure **type**, `car` is the structure **name**.

- Inside of the struct `{}` we define all the variables we want to include.

- `;` Completes the definition (commonly syntax error).

<br><br>

## Declaring a struct in the Stack

Once we have defined a **structure**, which is typically done in **separate `.h` files** or atop our programs **outside of any functions**, we can create variables of that type using the familiar syntax. We can also access the various **fields** or **members** of the structure using the `.` **dot operator**.

```c
// Variable declaration
struct car mycar;

// Field accessing
mycar.year = 2011;
strcmp(mycar.plate, "CS50");
mycar.odometer = 50505;
```
- We declare a variable of type `struct car` (we just created), called `mycar`.

- We use the `.` operator to access the fields of the struct: `struct_name.member` (`mycar.year`, `mycar.plate`, `mycar.odometer`).

<br><br>

## Declaring a struct in the Heap

<br>

**Structures**, like variables of all other data types, do not need to be created on the **stack**. We can **dynamically allocate structures** at *run time* if our program requires it. In order to access the fields of our structures in that situation, we need to **dereference** the **pointer** to the structure.

```c
// Variable declaration
struct car *mycar = malloc(sizeof(struct car));

// Field accessing
(*mycar).year = 2011;
strcmp((*mycar).plate, "CS50");
(*mycar).odometer = 50505;
```
- We declare a variable of type `struct car` called `mycar` and we dynamically allocate using `malloc()` enough memory to hold a struct.

- `sizeof()` figures out exactly how much **space** to allocate for this specific struct.

- To access the fields, we use the `*` **dereference operator** to dereference `mycar` followed by the `.` **dot operator** and the **member**: `(*mycar)`.`year`

<br><br>

## The `->` Arrow Operator

There is a shorter syntax that we can use to simplify this process, that combines the function of `*` and `.` operators. The `->` **arrow operator**:
- First it **dereferences** the pointer on the left side of the operator.
- Second, it **accesses** the field on the right side of the operator.

<br>

```c
// Variable declaration
struct car *mycar = malloc(sizeof(struct car));

// Field accessing
mycar->year = 2011;
strcmp(mycar->plate, "CS50");
mycar->odometer = 50505;
```
