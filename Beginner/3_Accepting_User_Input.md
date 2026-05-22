# Accepting User Input in C

- [Accepting User Input in C](#accepting-user-input-in-c)
  - [What is User Input?](#what-is-user-input)
  - [`scanf()` — The Core Input Function](#scanf--the-core-input-function)
  - [Format Specifiers for `scanf()`](#format-specifiers-for-scanf)
  - [Reading Different Data Types](#reading-different-data-types)
    - [Reading an Integer](#reading-an-integer)
    - [Reading a Float](#reading-a-float)
    - [Reading a Double](#reading-a-double)
    - [Reading a Single Character](#reading-a-single-character)
  - [Reading Multiple Inputs at Once](#reading-multiple-inputs-at-once)
  - [Reading a String (Array of Characters)](#reading-a-string-array-of-characters)
  - [`fgets()` — Reading a Full Line of Text](#fgets--reading-a-full-line-of-text)
  - [Common Beginner Mistakes](#common-beginner-mistakes)
  - [Putting It All Together — Full Example](#putting-it-all-together--full-example)
  - [Quick Reference Summary](#quick-reference-summary)

## What is User Input?

User input is how your program **receives data from the person running it** during execution. Instead of values being hardcoded into your program, the user can supply them at runtime. In C, the primary function used to accept user input is `scanf()`, which works hand-in-hand with `printf()`, one prints to the screen, the other reads from it.

## `scanf()` — The Core Input Function

Just like `printf()` uses format specifiers to print variables, `scanf()` uses format specifiers to **read and store** input into a variable.

**Syntax:**
```c
scanf("format specifier", &variableName);
```

The `&` symbol is the **address-of operator**. It tells `scanf()` exactly where in memory to store the value the user types. Without it, your program will not store the input correctly, this is one of the most common beginner mistakes in C.

## Format Specifiers for `scanf()`

The same format specifiers from `printf()` apply to `scanf()`:

| Type | Specifier |
|------|-----------|
| `int` | `%d` |
| `float` | `%f` |
| `double` | `%lf` |
| `char` | `%c` |

## Reading Different Data Types

### Reading an Integer
```c
#include <stdio.h>

int main() {
    int age;

    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Your age is %d\n", age);

    return 0;
}
```
**Output:**
```
Enter your age: 21
Your age is 21
```

### Reading a Float
```c
#include <stdio.h>

int main() {
    float price;

    printf("Enter the price: ");
    scanf("%f", &price);
    printf("The price is %.2f\n", price);

    return 0;
}
```
> `%.2f` limits the printed decimal to 2 places — neat for currency.

### Reading a Double
```c
#include <stdio.h>

int main() {
    double pi;

    printf("Enter a precise decimal: ");
    scanf("%lf", &pi);
    printf("You entered: %lf\n", pi);

    return 0;
}
```

### Reading a Single Character
```c
#include <stdio.h>

int main() {
    char grade;

    printf("Enter your grade: ");
    scanf(" %c", &grade);   // Note the space before %c
    printf("Your grade is %c\n", grade);

    return 0;
}
```

> The **space before `%c`** is intentional and important. It tells `scanf()` to skip any whitespace (including leftover newline characters `\n` from a previous input) before reading the character. Without it, `scanf()` may accidentally capture an invisible leftover character instead of what the user types.

## Reading Multiple Inputs at Once

You can read multiple values in a single `scanf()` call by chaining format specifiers:

```c
#include <stdio.h>

int main() {
    int age;
    float height;

    printf("Enter your age and height: ");
    scanf("%d %f", &age, &height);
    printf("Age: %d | Height: %.2f\n", age, height);

    return 0;
}
```
**Output:**
```
Enter your age and height: 21 5.11
Age: 21 | Height: 5.11
```

The user can separate values with a **space or pressing Enter** — `scanf()` handles both.

## Reading a String (Array of Characters)

Strings in C are arrays of `char`. You can read a single word using `%s`:

```c
#include <stdio.h>

int main() {
    char name[20];   // Enough space for up to 19 characters + null terminator

    printf("Enter your name: ");
    scanf("%s", name);   // No & needed for arrays — explained below
    printf("Hello, %s!\n", name);

    return 0;
}
```
**Output:**
```
Enter your name: Marcus
Hello, Marcus!
```

> **Why no `&` for arrays?** An array's name in C already acts as the memory address of its first element, so `&` is not needed. This will make more sense when you study arrays and pointers.

⚠️ **Important limitation:** `%s` with `scanf()` **stops reading at a space**. So if the user types `John Smith`, only `John` gets stored. Reading full sentences with spaces requires `fgets()`, covered below.

## `fgets()` — Reading a Full Line of Text

When you need to capture input that contains spaces (like a full name or sentence), use `fgets()`:

**Syntax:**
```c
fgets(variableName, size, stdin);
```
- `variableName` — where to store the input
- `size` — maximum number of characters to read
- `stdin` — means "read from the keyboard"

```c
#include <stdio.h>

int main() {
    char fullName[50];

    printf("Enter your full name: ");
    fgets(fullName, 50, stdin);
    printf("Hello, %s!\n", fullName);

    return 0;
}
```
**Output:**
```
Enter your full name: John Smith
Hello, John Smith!
```

> `fgets()` **includes the newline character** `\n` when the user presses Enter, which may appear as an extra blank line in output. Removing it is a more advanced topic but worth knowing about.

## Common Beginner Mistakes

**1. Forgetting the `&` operator**
```c
int age;
scanf("%d", age);   // Missing & — undefined behavior
scanf("%d", &age);  // Correct
```

**2. Mismatching format specifiers**
```c
float price;
scanf("%d", &price);  // %d is for int, not float
scanf("%f", &price);  // Correct
```

**3. Forgetting the space before `%c`**
```c
char grade;
scanf("%c", &grade);   // May capture leftover newline
scanf(" %c", &grade);  // Space clears leftover whitespace
```

**4. Using `scanf()` for inputs with spaces**
```c
char name[50];
scanf("%s", name);      // Stops at first space
fgets(name, 50, stdin); // Reads the full line
```

## Putting It All Together — Full Example

```c
#include <stdio.h>

int main() {
    char name[50];
    int age;
    float height;
    char grade;

    printf("Enter your full name: ");
    fgets(name, 50, stdin);

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your height: ");
    scanf("%f", &height);

    printf("Enter your grade: ");
    scanf(" %c", &grade);

    printf("\n--- Your Info ---\n");
    printf("Name:   %s", name);
    printf("Age:    %d\n", age);
    printf("Height: %.2f\n", height);
    printf("Grade:  %c\n", grade);

    return 0;
}
```

## Quick Reference Summary

- `scanf()` reads user input using format specifiers matching the variable type
- Always use `&` before the variable name in `scanf()` — except for arrays/strings
- Use a **space before `%c`** to avoid capturing leftover newline characters
- `%s` in `scanf()` reads only a single word — it stops at spaces
- Use `fgets()` when you need to read a full line including spaces
- Multiple values can be read in one `scanf()` call by chaining specifiers
