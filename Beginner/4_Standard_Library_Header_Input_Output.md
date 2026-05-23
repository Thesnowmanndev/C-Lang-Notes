# Standard Library Header `<stdio.h>` in C

## What is `<stdio.h>`?

`<stdio.h>` stands for **Standard Input/Output Header**. It is the most commonly included header file in C and the one you will put at the top of nearly every program you write. It gives your program access to functions that handle input and output operations, meaning reading data in and printing data out, whether that is to the screen, the keyboard, or a file.

```c
#include <stdio.h>
```

Without it, functions like `printf()` and `scanf()` are completely unknown to the compiler.

## Output Functions

### `printf()` -- Print Formatted Output

Prints formatted text to the screen. You have already been using this heavily. It accepts a format string with format specifiers as placeholders for variable values.

```c
#include <stdio.h>

int main() {
    int age = 21;
    float height = 5.11;
    char grade = 'A';

    printf("Age: %d\n", age);
    printf("Height: %.2f\n", height);
    printf("Grade: %c\n", grade);

    return 0;
}
```

**Output:**
```
Age: 21
Height: 5.11
Grade: A
```

### `puts()` -- Print a String

Prints a string to the screen and **automatically adds a newline** at the end. It is simpler than `printf()` when you just need to print a plain string with no formatting.

```c
#include <stdio.h>

int main() {
    puts("Hello, World!");
    puts("Learning C is fun.");

    return 0;
}
```

**Output:**
```
Hello, World!
Learning C is fun.
```

### `putchar()` -- Print a Single Character

Prints a single `char` to the screen.

```c
#include <stdio.h>

int main() {
    char letter = 'C';
    putchar(letter);   // Output: C
    putchar('\n');     // Print a newline

    return 0;
}
```

## Input Functions

### `scanf()` -- Read Formatted Input

Reads input from the keyboard using format specifiers and stores the values in variables. The `&` address-of operator is required for all non-array variables.

```c
#include <stdio.h>

int main() {
    int age;
    float height;

    printf("Enter your age and height: ");
    scanf("%d %f", &age, &height);
    printf("Age: %d, Height: %.2f\n", age, height);

    return 0;
}
```

### `gets()` -- Read a Full Line (Deprecated)

Reads a full line of input including spaces. You may see this in older C code, but it is considered **unsafe and deprecated** because it has no way to limit how many characters it reads, making it vulnerable to buffer overflow. Do not use it in new code.

```c
// Unsafe -- do not use
char name[50];
gets(name);
```

### `fgets()` -- Read a Full Line Safely

The safe replacement for `gets()`. It reads a full line of input and lets you specify the maximum number of characters to read, protecting against buffer overflow.

```c
#include <stdio.h>

int main() {
    char name[50];

    printf("Enter your full name: ");
    fgets(name, 50, stdin);
    printf("Hello, %s", name);

    return 0;
}
```

**Output:**
```
Enter your full name: John Smith
Hello, John Smith
```

### `getchar()` -- Read a Single Character

Reads a single character from the keyboard. It waits for the user to press Enter and then captures the first character typed.

```c
#include <stdio.h>

int main() {
    char letter;

    printf("Enter a character: ");
    letter = getchar();
    printf("You entered: %c\n", letter);

    return 0;
}
```

> `getchar()` is also commonly used as a trick to **pause a program** and wait for the user to press Enter before the window closes, like this: `getchar();`

## File Functions

`<stdio.h>` also provides functions to read from and write to files on disk. Files are handled through a `FILE` pointer.

### Opening and Closing Files

`fopen()` opens a file and returns a `FILE` pointer. `fclose()` closes it when you are done. Always close a file after you are finished with it.

```c
FILE *fptr;
fptr = fopen("notes.txt", "w");   // Open for writing
fclose(fptr);                      // Close the file
```

File open modes:

| Mode | Meaning |
|------|---------|
| `"r"` | Read only (file must exist) |
| `"w"` | Write only (creates file, overwrites if exists) |
| `"a"` | Append (adds to end of file) |
| `"r+"` | Read and write |
| `"w+"` | Read and write (overwrites) |
| `"a+"` | Read and append |

### `fprintf()` -- Write to a File

Works exactly like `printf()` but writes to a file instead of the screen.

```c
#include <stdio.h>

int main() {
    FILE *fptr = fopen("output.txt", "w");

    if (fptr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fprintf(fptr, "Hello from C!\n");
    fprintf(fptr, "Writing to a file.\n");

    fclose(fptr);
    printf("File written successfully.\n");

    return 0;
}
```

> Always check if `fopen()` returned `NULL` before using the file pointer. `NULL` means the file could not be opened, and trying to write to a `NULL` pointer will crash your program.

### `fscanf()` -- Read from a File

Works exactly like `scanf()` but reads from a file instead of the keyboard.

```c
#include <stdio.h>

int main() {
    FILE *fptr = fopen("output.txt", "r");
    char line[100];

    if (fptr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(fptr, "%s", line) != EOF) {
        printf("%s\n", line);
    }

    fclose(fptr);

    return 0;
}
```

`EOF` stands for **End of File**. It is a constant defined in `<stdio.h>` that signals there is nothing left to read.

### `fgets()` with Files -- Read a Line from a File

`fgets()` is not just for keyboard input. You can also use it to read a full line from a file by passing the file pointer instead of `stdin`.

```c
#include <stdio.h>

int main() {
    FILE *fptr = fopen("output.txt", "r");
    char line[100];

    if (fptr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, 100, fptr) != NULL) {
        printf("%s", line);
    }

    fclose(fptr);

    return 0;
}
```

## Format Specifier Quick Reference

Since `printf()` and `scanf()` are the most used functions from `<stdio.h>`, here is a full reference of their format specifiers:

| Specifier | Type | Example |
|-----------|------|---------|
| `%d` | `int` | `42` |
| `%f` | `float` | `3.140000` |
| `%lf` | `double` | `3.141593` |
| `%c` | `char` | `A` |
| `%s` | string (`char` array) | `Hello` |
| `%p` | pointer address | `0x7ffee` |
| `%x` | hexadecimal integer | `2a` |
| `%o` | octal integer | `52` |
| `%e` | scientific notation | `3.14e+00` |
| `%zu` | `size_t` (from sizeof/strlen) | `8` |

### Formatting Numbers in `printf()`

You can control how numbers are displayed by adding modifiers to the specifier:

```c
printf("%.2f\n", 3.14159);    // 2 decimal places    -> 3.14
printf("%10d\n", 42);         // Right-align in 10 spaces ->         42
printf("%-10d|\n", 42);       // Left-align in 10 spaces  -> 42        |
printf("%05d\n", 42);         // Pad with zeros           -> 00042
```

## Putting It All Together -- Full Example

```c
#include <stdio.h>

int main() {
    char name[50];
    int age;
    FILE *fptr;

    // Get input from user
    printf("Enter your name: ");
    fgets(name, 50, stdin);

    printf("Enter your age: ");
    scanf("%d", &age);

    // Print to screen
    printf("\nHello, %s", name);
    printf("You are %d years old.\n", age);

    // Write to a file
    fptr = fopen("record.txt", "w");
    if (fptr != NULL) {
        fprintf(fptr, "Name: %s", name);
        fprintf(fptr, "Age: %d\n", age);
        fclose(fptr);
        puts("Record saved to file.");
    }

    return 0;
}
```

## Quick Reference Summary

- `printf()` prints formatted output to the screen using format specifiers
- `puts()` prints a string and automatically adds a newline
- `putchar()` prints a single character
- `scanf()` reads formatted input from the keyboard (remember `&`)
- `fgets()` reads a full line safely with a size limit (preferred over `gets()`)
- `getchar()` reads a single character from the keyboard
- `fopen()` opens a file and returns a `FILE` pointer, always check for `NULL`
- `fprintf()` writes formatted output to a file
- `fscanf()` reads formatted input from a file
- `fclose()` closes a file after you are done with it
- `EOF` is a constant that signals the end of a file
