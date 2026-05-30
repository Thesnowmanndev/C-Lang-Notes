# If Statements in C

## What is an If Statement?

An if statement is the most fundamental decision-making tool in C. It lets your program **evaluate a condition and choose whether or not to execute a block of code** based on whether that condition is true or false. Without if statements, every program would run the same way every time regardless of the data it receives.

## Basic Syntax

```c
if (condition) {
    // code that runs if condition is true
}
```

The condition is any expression that evaluates to a number. In C there is no dedicated boolean type in the traditional sense -- **zero means false and any non-zero value means true**. This is an important distinction from some other languages.

```c
int x = 5;

if (x) {
    printf("x is non-zero, so this runs\n");
}

if (0) {
    printf("This never runs\n");
}
```

## If / Else

The `else` block runs when the `if` condition is false. Exactly one of the two blocks will always execute.

```c
int age = 16;

if (age >= 18) {
    printf("You are an adult.\n");
} else {
    printf("You are a minor.\n");
}
```

**Output:**
```
You are a minor.
```

## If / Else If / Else

When you have more than two possible outcomes, chain `else if` blocks together. C evaluates them top to bottom and executes the first one whose condition is true. The final `else` is a catch-all that runs if none of the conditions above it were true.

```c
int score = 82;

if (score >= 90) {
    printf("Grade: A\n");
} else if (score >= 80) {
    printf("Grade: B\n");
} else if (score >= 70) {
    printf("Grade: C\n");
} else if (score >= 60) {
    printf("Grade: D\n");
} else {
    printf("Grade: F\n");
}
```

**Output:**
```
Grade: B
```

Once a condition matches, the rest of the chain is skipped entirely. Even if multiple conditions could be true, only the first matching one executes.

## Comparison Operators

These are the operators used to build conditions inside if statements:

| Operator | Meaning | Example |
|----------|---------|---------|
| `==` | Equal to | `x == 5` |
| `!=` | Not equal to | `x != 5` |
| `>` | Greater than | `x > 5` |
| `<` | Less than | `x < 5` |
| `>=` | Greater than or equal | `x >= 5` |
| `<=` | Less than or equal | `x <= 5` |

```c
int x = 10;

printf("%d\n", x == 10);   // Output: 1 (true)
printf("%d\n", x != 10);   // Output: 0 (false)
printf("%d\n", x > 5);     // Output: 1 (true)
printf("%d\n", x < 5);     // Output: 0 (false)
```

## Logical Operators

Logical operators let you combine multiple conditions into a single expression:

| Operator | Meaning | Example |
|----------|---------|---------|
| `&&` | AND -- both conditions must be true | `x > 0 && x < 10` |
| `\|\|` | OR -- at least one condition must be true | `x < 0 \|\| x > 100` |
| `!` | NOT -- inverts the condition | `!(x == 5)` |

```c
int age = 25;
int has_id = 1;

if (age >= 21 && has_id) {
    printf("Entry allowed.\n");
}

int x = 150;

if (x < 0 || x > 100) {
    printf("Value is out of range.\n");
}

int is_raining = 0;

if (!is_raining) {
    printf("No umbrella needed.\n");
}
```

**Output:**
```
Entry allowed.
Value is out of range.
No umbrella needed.
```

### Short-Circuit Evaluation

C evaluates `&&` and `||` using short-circuit logic. For `&&`, if the left side is false C skips the right side entirely because the result is already determined to be false. For `||`, if the left side is true C skips the right side because the result is already true. This matters when the right side has a side effect or could cause an error.

```c
int x = 0;

// Without short-circuit, dividing by x would crash
// With short-circuit, the right side never evaluates when x == 0
if (x != 0 && (10 / x) > 2) {
    printf("This is safe.\n");
}
```

## Nested If Statements

If statements can be placed inside other if statements. Each level creates a more specific condition that must be satisfied.

```c
int age = 20;
int citizen = 1;
int registered = 0;

if (age >= 18) {
    if (citizen) {
        if (registered) {
            printf("You can vote.\n");
        } else {
            printf("You need to register first.\n");
        }
    } else {
        printf("Only citizens can vote.\n");
    }
} else {
    printf("You must be 18 or older to vote.\n");
}
```

**Output:**
```
You need to register first.
```

Deeply nested if statements can become hard to read. When nesting goes beyond two or three levels it is usually worth refactoring with logical operators or functions to flatten the logic.

## Single Line If Statements

When the body of an if statement is a single statement, the curly braces are technically optional:

```c
if (x > 0)
    printf("Positive\n");
```

This is valid C but is considered risky practice. It is easy to add a second line thinking it is still inside the if block when it is not:

```c
if (x > 0)
    printf("Positive\n");
    printf("This always runs!\n");   // NOT inside the if -- indentation is misleading
```

The general advice is to **always use curly braces** even for single-line bodies. It removes ambiguity and prevents this class of bug entirely.

## The Ternary Operator -- Shorthand If/Else

The ternary operator is a compact way to write a simple if/else that produces a value. It is not a replacement for full if statements but is useful for short conditional assignments and inline expressions.

**Syntax:**
```c
condition ? value_if_true : value_if_false
```

```c
int age = 20;
char *status = (age >= 18) ? "adult" : "minor";
printf("%s\n", status);   // Output: adult

int x = -5;
int abs_x = (x >= 0) ? x : -x;
printf("%d\n", abs_x);    // Output: 5
```

The ternary operator can also be used directly inside `printf()`:

```c
int score = 74;
printf("Result: %s\n", score >= 60 ? "Pass" : "Fail");   // Output: Result: Pass
```

## Common Beginner Mistakes

**1. Using `=` instead of `==` for comparison**

This is one of the most common bugs in C. A single `=` is assignment, not comparison. The if statement will evaluate to the assigned value, which is almost always non-zero and therefore always true.

```c
int x = 5;

if (x = 10) {   // Assigns 10 to x, then evaluates 10 as true -- ALWAYS runs
    printf("This always runs.\n");
}

if (x == 10) {  // Correct -- compares x to 10
    printf("x is 10\n");
}
```

A technique called a **Yoda condition** guards against this by putting the constant on the left. If you accidentally write `=` instead of `==` the compiler will throw an error because you cannot assign to a constant:

```c
if (10 == x) {   // If you accidentally write 10 = x, compiler error saves you
    printf("x is 10\n");
}
```

**2. Comparing floating point values with `==`**

Floating point arithmetic is imprecise. Two floats that should be mathematically equal may not be exactly equal in memory due to rounding.

```c
float result = 0.1 + 0.2;

if (result == 0.3) {           // Likely false due to floating point imprecision
    printf("Equal\n");
}

// Correct approach -- check if the difference is small enough
if (fabs(result - 0.3) < 0.0001) {
    printf("Close enough to equal\n");
}
```

**3. Forgetting that `else` attaches to the nearest `if`**

In nested if statements without braces, `else` binds to the closest preceding `if`, which may not be the one you intended:

```c
int x = 10, y = 5;

if (x > 0)
    if (y > 0)
        printf("Both positive\n");
else
    printf("This belongs to the inner if, not the outer!\n");
```

Always use braces to make the structure explicit and avoid this ambiguity.

## Putting It All Together -- Full Example

```c
#include <stdio.h>

int main() {
    int temperature;

    printf("Enter the temperature (F): ");
    scanf("%d", &temperature);

    if (temperature >= 90) {
        printf("It is very hot outside.\n");
    } else if (temperature >= 70) {
        printf("It is warm outside.\n");
    } else if (temperature >= 50) {
        printf("It is cool outside.\n");
    } else if (temperature >= 32) {
        printf("It is cold outside.\n");
    } else {
        printf("It is below freezing.\n");
    }

    char *advice = (temperature >= 60) ? "No jacket needed." : "Bring a jacket.";
    printf("%s\n", advice);

    return 0;
}
```

**Example Output (input: 45):**
```
It is cool outside.
Bring a jacket.
```

## Quick Reference Summary

- An if statement executes a block only when its condition is true
- In C, zero is false and any non-zero value is true
- `else` provides an alternative block when the condition is false
- Chain `else if` blocks to handle multiple distinct conditions
- `&&` requires both conditions to be true, `||` requires at least one, `!` inverts
- Short-circuit evaluation means the right side of `&&` and `||` may not execute
- Always use curly braces even for single-line if bodies to prevent subtle bugs
- Never use `=` when you mean `==` -- assignment inside a condition is a common bug
- Never compare floats with `==` -- check if the difference is within a small tolerance instead
- The ternary operator `? :` is a concise shorthand for simple if/else value selection
