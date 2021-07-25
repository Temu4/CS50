# CS50

> Check tasks: `submit50 cs50/problems/2019/x/programName`

> Compile programs `clang -o test test.c -lcs50`

Content:

- [0. Lecture 0](#lecture-0)
- [1. Lecture 1](#lecture-1)
- [2. Lecture 2](#lecture-2)
- [3. Lecture 3](#lecture-3)
  - [3.1 CS50 IDE Offline](#cs50-ide-offline)
- [4. Lecture 4](#lecture-4)
- [5. Lecture 5 - HTTP, HTML, CSS](#lecture-5)
- [6. Lecture 6 - Python](#lecture-6)

## Lecture 0

## Lecture 1

Compile C code - `clang -o hello hello.c`

## Lecture 2

**Compiling process:**

- preprocessing
- compiling
- assembling
- linking

Items in array are stored one by one in the RAM after compiling.

## Lecture 3

For using debugging tool in CS50 IDE type

```c
debug50 ./codeSrc
```

To get an address of the value use `&`.

```c
int x = 1;
int xAddress = &x;
```

To work with an address (a **pointer**) you need to add `*` symbol between a type and a value. Ex: `int *a`. For allocating **pointee** to the pointer (for example, an integer)

```c
int *a;
a = malloc(sizeof(int));
```

To get a value by an address - use dereference operator `*` before the address.

Ex: `int value = *a`.

```c
*a = 42;
```

---

Numbers naming convention:

- **binary numbers** end with `...b`
- **octal numbers** start with `0...`
- **hexadecimal numbers** start with `0x...`.

> Hexadecimal number consists of `0-9,a-f`

---

BMP image file structure

![BMP structure](https://github.com/Temu4/cs50/raw/main/lecture_3/whodunit/bmp-structure.png)

### CS50 IDE Offline

https://cs50.readthedocs.io/ide/offline/

Start: `ide50 start`

Stop: `ide50 stop`

## Lecture 4

A **hash-table** is an array of linked list (each element of each is a pointer).

## Lecture 5

**TCP/IP** - data transport protocol

**URL** - Uniform Resource Locator

**HTTP Statuses:**

- 200 _OK_
- 301 _Moved Permanently_
- 302 _Found_
- 304 _Not Modified_
- 401 _Unauthorized_
- 403 _Forbidden_
- 404 _Not found_
- 418 _I'm a Teapot_
- 500 _Internal Server Error_

## Lecture 6 - Python

Data types in Python:

- bool
- float
- int
- str
- dict (hash tables)
- list (arrays)
- range
- set
- tuple

Compilation of Python code `python hello.py`

Compiling process:

_source code => compiler => byte code => interpreter_

In Python variables have function scope:

```python
def test_function():
  while True:
    n = 123
    break
  return n #n=123
```
