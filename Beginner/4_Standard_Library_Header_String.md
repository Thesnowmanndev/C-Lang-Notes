# Standard Library Header `<string.h>` in C

- [Standard Library Header `<string.h>` in C](#standard-library-header-stringh-in-c)
  - [What is `<string.h>`?](#what-is-stringh)
  - [The Most Important Functions](#the-most-important-functions)
    - [`strlen()` -- String Length](#strlen----string-length)
    - [`strcpy()` -- String Copy](#strcpy----string-copy)
    - [`strcat()` -- String Concatenation](#strcat----string-concatenation)
    - [`strcmp()` -- String Comparison](#strcmp----string-comparison)
    - [`strchr()` -- Find a Character in a String](#strchr----find-a-character-in-a-string)
    - [`strstr()` -- Find a Substring](#strstr----find-a-substring)
    - [`strlwr()` and `strupr()` -- Change Case](#strlwr-and-strupr----change-case)
    - [`strrev()` -- Reverse a String](#strrev----reverse-a-string)
  - [Safer Versions of Common Functions](#safer-versions-of-common-functions)
  - [Putting It All Together -- Full Example](#putting-it-all-together----full-example)
  - [Quick Reference Summary](#quick-reference-summary)

## What is `<string.h>`?

In C, strings are not a built-in type with built-in operations. You cannot add two strings together with `+`, compare them with `==`, or measure their length with a simple property. The `<string.h>` header file is a standard library that gives you a collection of **pre-built functions to work with strings and memory**. You include it at the top of your program just like `<stdio.h>`.

```c
#include <string.h>
```

All strings in C are arrays of `char` ending with a **null terminator** `\0`. Every function in `<string.h>` depends on this null terminator to know where the string ends, so understanding that concept is important before using these functions.

## The Most Important Functions

### `strlen()` -- String Length

Returns the **number of characters** in a string, not counting the null terminator `\0`.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char name[] = "Marcus";

    printf("%zu\n", strlen(name));  // Output: 6

    return 0;
}
```

Use `%zu` as the format specifier since `strlen()` returns a `size_t` type, which is an unsigned integer.

### `strcpy()` -- String Copy

**Copies** one string into another. You cannot assign strings with `=` after declaration in C, so `strcpy()` is how you do it.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char source[] = "Hello";
    char destination[10];

    strcpy(destination, source);
    printf("%s\n", destination);  // Output: Hello

    return 0;
}
```

The destination must be **large enough** to hold the source string including the null terminator. Copying into a buffer that is too small causes undefined behavior.

### `strcat()` -- String Concatenation

**Appends** one string onto the end of another. The destination string is modified in place.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char greeting[20] = "Hello, ";
    char name[] = "Marcus";

    strcat(greeting, name);
    printf("%s\n", greeting);  // Output: Hello, Marcus

    return 0;
}
```

Again, make sure the destination array is large enough to hold both strings combined plus the null terminator.

### `strcmp()` -- String Comparison

**Compares** two strings character by character. This is how you check if two strings are equal in C since using `==` on strings only compares memory addresses, not the actual content.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char a[] = "apple";
    char b[] = "apple";
    char c[] = "banana";

    printf("%d\n", strcmp(a, b));  // Output: 0  (equal)
    printf("%d\n", strcmp(a, c));  // Output: negative number (a comes before c)
    printf("%d\n", strcmp(c, a));  // Output: positive number (c comes after a)

    return 0;
}
```

The return values work like this:

| Return Value | Meaning |
|-------------|---------|
| `0` | Both strings are equal |
| Negative number | First string comes before second alphabetically |
| Positive number | First string comes after second alphabetically |

In practice you will most often use it to check equality like this:

```c
if (strcmp(a, b) == 0) {
    printf("Strings are equal\n");
}
```

### `strchr()` -- Find a Character in a String

Searches a string for the **first occurrence** of a character and returns a pointer to that position. Returns `NULL` if the character is not found.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[] = "Hello, World!";
    char *result = strchr(sentence, 'W');

    if (result != NULL) {
        printf("Found: %s\n", result);  // Output: World!
    }

    return 0;
}
```

### `strstr()` -- Find a Substring

Searches a string for the **first occurrence of a substring** and returns a pointer to where it starts. Returns `NULL` if not found.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[] = "I love programming in C";
    char *result = strstr(sentence, "programming");

    if (result != NULL) {
        printf("Found: %s\n", result);  // Output: programming in C
    }

    return 0;
}
```

### `strlwr()` and `strupr()` -- Change Case

Converts a string to all **lowercase** or all **uppercase**.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char text[] = "Hello World";

    printf("%s\n", strlwr(text));  // Output: hello world
    printf("%s\n", strupr(text));  // Output: HELLO WORLD

    return 0;
}
```

> Note: `strlwr()` and `strupr()` are not part of the official C standard and may not work on all compilers. They work fine on Windows with MinGW/MSVC but may be unavailable on Linux or Mac with GCC. A common workaround is to loop through characters using `tolower()` and `toupper()` from `<ctype.h>`.

### `strrev()` -- Reverse a String

Reverses a string in place.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char text[] = "Hello";

    printf("%s\n", strrev(text));  // Output: olleH

    return 0;
}
```

> Same caveat as above. `strrev()` is not part of the C standard and is compiler-specific. It works on Windows but not always on GCC/Linux.

## Safer Versions of Common Functions

C provides safer alternatives to `strcpy()` and `strcat()` that let you specify a maximum number of characters to read, reducing the risk of overflowing the destination buffer.

| Unsafe Version | Safer Version | What it limits |
|---------------|--------------|----------------|
| `strcpy(dest, src)` | `strncpy(dest, src, n)` | Copies at most `n` characters |
| `strcat(dest, src)` | `strncat(dest, src, n)` | Appends at most `n` characters |
| `strcmp(a, b)` | `strncmp(a, b, n)` | Compares at most `n` characters |

```c
char destination[10];
char source[] = "Hello, World!";

strncpy(destination, source, 9);
destination[9] = '\0';  // Always manually null-terminate after strncpy

printf("%s\n", destination);  // Output: Hello, Wo
```

> `strncpy()` does NOT automatically add a null terminator if the source is longer than `n`, so it is good practice to always manually set the last character to `\0` as shown above.

## Putting It All Together -- Full Example

```c
#include <stdio.h>
#include <string.h>

int main() {
    char firstName[20] = "John";
    char lastName[] = "Smith";
    char fullName[50];

    // Copy firstName into fullName
    strcpy(fullName, firstName);

    // Append a space
    strcat(fullName, " ");

    // Append lastName
    strcat(fullName, lastName);

    printf("Full name:  %s\n", fullName);
    printf("Length:     %zu\n", strlen(fullName));

    // Compare two strings
    if (strcmp(firstName, "John") == 0) {
        printf("First name is John\n");
    }

    // Search for a character
    char *ptr = strchr(fullName, 'S');
    if (ptr != NULL) {
        printf("Found 'S' at: %s\n", ptr);
    }

    return 0;
}
```

**Output:**
```
Full name:  John Smith
Length:     10
First name is John
Found 'S' at: Smith
```

## Quick Reference Summary

- Include `<string.h>` to access all string functions
- `strlen()` returns the length of a string, not counting `\0`
- `strcpy()` copies one string into another (destination must be large enough)
- `strcat()` appends one string onto the end of another
- `strcmp()` compares two strings and returns `0` if they are equal
- `strchr()` finds the first occurrence of a character in a string
- `strstr()` finds the first occurrence of a substring in a string
- `strlwr()` and `strupr()` change case but are not standard on all compilers
- Prefer `strncpy()`, `strncat()`, and `strncmp()` for safer size-limited operations
