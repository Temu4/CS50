# CS50

> Check tasks: `submit50 cs50/problems/2019/x/programName`

> Compile programs `clang -o test test.c -lcs50`

Content:

- [0. Lecture 0](#lecture-0)
- [1. Lecture 1](#lecture-1)
- [2. Lecture 2](#lecture-2)
- [3. Lecture 3](#lecture-3)
  - [3.1 CS50 IDE Offline](#cs50-ide-offline)

## Lecture 0

## Lecture 1

## Lecture 2

**Compiling process:**

- preprocessing
- compiling
- assembling
- linking

Items in array are stored one by one in the RAM after compiling.

## Lecture 3

For using debugging tool in CS50 IDE type

```
debug50 ./codeSrc
```

To get an address of the value use `&`.

```
int x = 1;
int xAddress = &x;
```

To work with an address (a **pointer**) you need to add `*` symbol between a type and a value. Ex: `int *a`. For allocating **pointee** to the pointer (for example, an integer)

```
int *a;
a = malloc(sizeof(int));
```

To get a value by an address - use dereference operator `*` before the address.

Ex: `int value = *a`.

```
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

![BMP structure](https://github.com/Temu4/cs50/raw/main/lecture_3/whodunit/bpm-structure.png)

### CS50 IDE Offline

https://cs50.readthedocs.io/ide/offline/

Start: `ide50 start`

Stop: `ide50 stop`
