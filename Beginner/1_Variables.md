# Variables in C

- [Variables in C](#variables-in-c)
  - [What is a Variable?](#what-is-a-variable)
  - [Declaring \& Initializing Variables](#declaring--initializing-variables)
  - [The Basic Data Types](#the-basic-data-types)
  - [Format Specifiers (Printing Variables)](#format-specifiers-printing-variables)
  - [Naming Rules \& Conventions](#naming-rules--conventions)
  - [`const` — Making a Variable Unchangeable](#const--making-a-variable-unchangeable)
  - [How Variables Live in Memory](#how-variables-live-in-memory)
  - [Common Beginner Mistakes](#common-beginner-mistakes)
  - [Quick Reference Summary](#quick-reference-summary)

## What is a Variable?

A variable is a **named storage location in memory** that holds a value. In C, you must tell the compiler **what type of data** the box will hold before you can use it.

## Declaring & Initializing Variables

**Declaration** = telling the compiler the variable exists and what type it is.

**Initialization** = giving it a value for the first time.

```c
int age;           // Declaration only
int age = 21;      // Declaration + Initialization
age = 25;          // Assignment (changing the value later)
```

You can also declare multiple variables of the same type on one line:

```c
int x = 1, y = 2, z = 3;
```

## The Basic Data Types

These are the core types you will use constantly in C:

| Type | What it stores | Typical Size | Example |
|------|---------------|--------------|---------|
| `int` | Whole numbers | 4 bytes | `int age = 21;` |
| `float` | Decimal numbers (less precise) | 4 bytes | `float price = 9.99;` |
| `double` | Decimal numbers (more precise) | 8 bytes | `double pi = 3.14159265;` |
| `char` | A single character | 1 byte | `char grade = 'A';` |

> **Important:** `char` values use **single quotes** `' '`, never double quotes. Double quotes are for strings.

## Format Specifiers (Printing Variables)

To print a variable using `printf()`, you need a **format specifier** as a placeholder that matches the variable's type:

| Type | Specifier |
|------|-----------|
| `int` | `%d` |
| `float` | `%f` |
| `double` | `%lf` |
| `char` | `%c` |

```c
#include <stdio.h>

int main() {
    int age = 21;
    float price = 9.99;
    double pi = 3.14159265;
    char grade = 'A';

    printf("Age: %d\n", age);
    printf("Price: %f\n", price);
    printf("Pi: %lf\n", pi);
    printf("Grade: %c\n", grade);

    return 0;
}
```

**Output:**
```
Age: 21
Price: 9.990000
Pi: 3.141593
Grade: A
```

## Naming Rules & Conventions

**Rules (enforced by the compiler — breaking these causes errors):**
- Can only contain letters, digits, and underscores `_`
- Cannot start with a digit (`2fast` ❌, `fast2` ✅)
- Cannot be a reserved keyword (`int`, `return`, `for`, etc.)
- Case-sensitive — `age`, `Age`, and `AGE` are three different variables

**Conventions (not enforced, but widely followed):**
- Use descriptive names — `age` is better than `a`
- Use **snake_case** for multi-word names → `user_age`, `total_price`
- Constants are written in ALL_CAPS → `MAX_SIZE`

---

## `const` — Making a Variable Unchangeable

If you want a variable's value to never change after it's set, use the `const` keyword. Trying to change it later will cause a compiler error.

```c
const float PI = 3.14159;
PI = 3;   // ERROR — cannot modify a const variable
```

Use `const` whenever a value should stay fixed (e.g., tax rates, mathematical constants).

---

## How Variables Live in Memory

Every variable you declare takes up space in your computer's RAM. The amount of space depends on the type. You can check the exact size on your machine using the `sizeof()` operator:

```c
printf("Size of int:    %zu bytes\n", sizeof(int));
printf("Size of float:  %zu bytes\n", sizeof(float));
printf("Size of double: %zu bytes\n", sizeof(double));
printf("Size of char:   %zu bytes\n", sizeof(char));
```

> `%zu` is the format specifier for the result of `sizeof()`.

## Common Beginner Mistakes

**1. Using a variable before initializing it**
```c
int x;
printf("%d", x);  // Undefined behavior — x has a garbage value
```

**2. Type mismatch with format specifiers**
```c
float price = 9.99;
printf("%d", price);  // Wrong specifier — use %f for float
```

**3. Wrong quotes for char**
```c
char grade = "A";  // ❌ Double quotes make it a string, not a char
char grade = 'A';  // ✅ Correct
```

## Quick Reference Summary

```
[data type] [variable name] = [value];
```

- **Declare** the type before you use a variable
- **Match** format specifiers to types when printing
- **Use `const`** when the value should never change
- **Name clearly** — your future self will thank you

---
