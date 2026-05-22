# Arithmetic Operators in C

- [Arithmetic Operators in C](#arithmetic-operators-in-c)
  - [What are Arithmetic Operators?](#what-are-arithmetic-operators)
  - [The 5 Core Arithmetic Operators](#the-5-core-arithmetic-operators)
  - [Each Operator in Detail](#each-operator-in-detail)
    - [Addition `+` and Subtraction `-`](#addition--and-subtraction--)
    - [Multiplication `*`](#multiplication-)
    - [Division `/` — ⚠️ Read Carefully](#division---️-read-carefully)
    - [Modulus `%` — The Remainder Operator](#modulus---the-remainder-operator)
  - [Order of Operations (Operator Precedence)](#order-of-operations-operator-precedence)
  - [Augmented Assignment Operators (Shorthand)](#augmented-assignment-operators-shorthand)
  - [Increment `++` and Decrement `--`](#increment--and-decrement---)
    - [Prefix vs Postfix — An Important Distinction](#prefix-vs-postfix--an-important-distinction)
  - [Putting It All Together — Full Example](#putting-it-all-together--full-example)
  - [Quick Reference Summary](#quick-reference-summary)

## What are Arithmetic Operators?

Arithmetic operators are **symbols that perform mathematical operations** on variables and values. 

## The 5 Core Arithmetic Operators

| Operator | Name | Example | Result |
|----------|------|---------|--------|
| `+` | Addition | `10 + 3` | `13` |
| `-` | Subtraction | `10 - 3` | `7` |
| `*` | Multiplication | `10 * 3` | `30` |
| `/` | Division | `10 / 3` | `3` |
| `%` | Modulus (remainder) | `10 % 3` | `1` |

## Each Operator in Detail

### Addition `+` and Subtraction `-`
These work exactly as you'd expect mathematically.

```c
int a = 10, b = 3;

printf("%d\n", a + b);  // Output: 13
printf("%d\n", a - b);  // Output: 7
```

### Multiplication `*`
Also straightforward. Note that C uses `*` not `x` for multiplication.

```c
int a = 10, b = 3;

printf("%d\n", a * b);  // Output: 30
```

### Division `/` — ⚠️ Read Carefully

Division in C behaves **differently depending on the types involved.**

**Integer Division (both operands are `int`):**
When you divide two integers, C **throws away the decimal**, it does **NOT** round, it simply truncates (cuts off).

```c
int a = 10, b = 3;

printf("%d\n", a / b);  // Output: 3  (NOT 3.333...)
```

**Float Division (at least one operand is `float` or `double`):**
If either number is a decimal type, you get a decimal result.

```c
float a = 10.0, b = 3.0;

printf("%f\n", a / b);  // Output: 3.333333
```

**Forcing decimal division with integers using casting:**
If you have two integers but want a decimal result, you can **cast** one to a float:

```c
int a = 10, b = 3;

printf("%f\n", (float)a / b);  // Output: 3.333333
```

> Casting is covered more in depth in its own topic.

### Modulus `%` — The Remainder Operator

Modulus gives you the **leftover remainder** after division. **It only works on integers.**

```c
int a = 10, b = 3;

printf("%d\n", a % b);  // Output: 1
```

Think of it as: `10 / 3 = 3` with `1` left over → so `10 % 3 = 1`

**Common real-world uses of `%`:**
- Checking if a number is even or odd → `x % 2 == 0` means even
- Wrapping numbers around a range (e.g., clock hours, array indexes)
- Checking divisibility → `x % 5 == 0` means x is divisible by 5

```c
int number = 7;

if (number % 2 == 0) {
    printf("Even\n");
} else {
    printf("Odd\n");   // Output: Odd
}
```

## Order of Operations (Operator Precedence)

C follows the same order of operations as standard math, often remembered as **PEMDAS/BODMAS:**

1. `( )` — Parentheses first
2. `*`, `/`, `%` — Multiplication, Division, Modulus (left to right)
3. `+`, `-` — Addition, Subtraction (left to right)

```c
int result;

result = 2 + 3 * 4;       // = 2 + 12 = 14  (NOT 20)
result = (2 + 3) * 4;     // = 5 * 4  = 20
result = 10 - 4 / 2;      // = 10 - 2 = 8
result = 10 % 3 + 1;      // = 1 + 1  = 2
```

> **Rule of thumb:** When in doubt, use parentheses `( )` to make your intent explicit and avoid bugs.

---

## Augmented Assignment Operators (Shorthand)

These are shorthand operators that **perform an arithmetic operation and assign the result** back to the same variable in one step. You will see these everywhere in C code.

| Shorthand | Equivalent To |
|-----------|--------------|
| `x += 5` | `x = x + 5` |
| `x -= 5` | `x = x - 5` |
| `x *= 5` | `x = x * 5` |
| `x /= 5` | `x = x / 5` |
| `x %= 5` | `x = x % 5` |

```c
int x = 10;

x += 5;   // x is now 15
x -= 3;   // x is now 12
x *= 2;   // x is now 24
x /= 4;   // x is now 6
x %= 4;   // x is now 2
```

## Increment `++` and Decrement `--`

These are special operators that **add 1 or subtract 1** from a variable. They are extremely common in loops and counters.

| Operator | Name | Effect |
|----------|------|--------|
| `++` | Increment | Adds 1 to the variable |
| `--` | Decrement | Subtracts 1 from the variable |

```c
int x = 5;

x++;  // x is now 6
x--;  // x is now 5 again
```

### Prefix vs Postfix — An Important Distinction

The `++` and `--` can go **before** (prefix) or **after** (postfix) the variable, and this matters when the expression is used inside another operation.

| Style | Syntax | Behavior |
|-------|--------|----------|
| Postfix | `x++` | Uses the current value **first**, then increments |
| Prefix | `++x` | Increments **first**, then uses the new value |

```c
int x = 5;
int a, b;

a = x++;   // a = 5, then x becomes 6  (postfix — use then increment)
b = ++x;   // x becomes 7 first, then b = 7  (prefix — increment then use)

printf("a = %d\n", a);  // Output: 5
printf("b = %d\n", b);  // Output: 7
printf("x = %d\n", x);  // Output: 7
```

> When `++` or `--` is used **alone on its own line**, prefix and postfix behave identically. The difference only matters when used inside a larger expression.

## Putting It All Together — Full Example

```c
#include <stdio.h>

int main() {
    int a = 10, b = 3;
    float result;

    printf("Addition:       %d\n", a + b);       // 13
    printf("Subtraction:    %d\n", a - b);       // 7
    printf("Multiplication: %d\n", a * b);       // 30
    printf("Division (int): %d\n", a / b);       // 3
    printf("Division (flt): %f\n", (float)a / b); // 3.333333
    printf("Modulus:        %d\n", a % b);       // 1

    int x = 10;
    x += 5;
    printf("After += 5:     %d\n", x);           // 15
    x++;
    printf("After x++:      %d\n", x);           // 16

    return 0;
}
```

---

## Quick Reference Summary

- `+`, `-`, `*`, `/`, `%` are the 5 core arithmetic operators
- **Integer division truncates** — it does not round
- **Modulus `%`** gives the remainder and only works on integers
- **Respect operator precedence** — use `( )` to control order
- **Augmented operators** (`+=`, `-=`, etc.) are shorthand for common operations
- **`++` and `--`** add/subtract 1, and prefix vs postfix matters in expressions
