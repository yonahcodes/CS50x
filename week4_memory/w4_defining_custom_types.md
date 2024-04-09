# Defining Custom Types

The **C** keyword `typedef` provides a way to create an **alias** or *rewritten name* for **data types**. The basic idea is to first **define a type** is a normal way, then **alias it** to something else.
```c
typedef <old name> <new name>;
```
```c
typedef unsigned char byte;
```
- `typedef` Creates alias to existing data type.
- `unsigned char` Represents an unsigned (non-negative) character data type.
- `byte` New name assigned to the type `unsigned char`.

After this declaration, **byte** can now be used as a synonym for `unsigned char`.

<br>

```c
typedef char * string;
```
- `typedef` Creates alias to existing data type.
- `char *` Represents a string data type.
- `string` New name assigned to the type `char *`.

Following this declaration, **string** can now be used as a synonym for `char *`.

<br><br>

## `typedef` and `struct`

When combined with a `struct`, `typedef` enables the creation of **custom data types** with *user-defined* names.

<br>

```c
struct car
{
    int year;
    char model[10];
    char plate[7];
    int odometer;
    double engine_size;
};

typedef struct car car_t;
```
- `typedef` Creates alias to the `struct` data type created.
- `struct car` Represents a the `struct` we created.
- `car_t` New name assigned to the type `struct car`.

Following this declaration, **car_t** can now be used as a synonym for `struct car`.

<br>

### Alternative Syntax
An *alternative syntax* exists, allowing us to define and name the **structure** at the same time:

```c
typedef struct car
{
    int year;
    char model[10];
    char plate[7];
    int odometer;
    double engine_size;
};
car_t;
```

<br>

### Variable Declaration

```c
// Variable declaration BEFORE `typedef`
struct car mycar;

// Field accessing 
mycar.year = 2011;
strcpy(mycar.place, "cs50");
mycar.odometer = 50505;
```
```c
// Variable declaration AFTER `typedef`
car_t mycar;

// Field accessing 
mycar.year = 2011;
strcpy(mycar.place, "cs50");
mycar.odometer = 50505;
```
