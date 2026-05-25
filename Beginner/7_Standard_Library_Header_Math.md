## Math Functions and `<math.h>` in C

## What is `<math.h>`?

`<math.h>` is a standard library header that gives your program access to a collection of mathematical functions beyond what the basic arithmetic operators can do. Things like square roots, powers, trigonometry, logarithms, and rounding all live here. Without including it, none of these functions are available to the compiler.

```c
#include <math.h>
```

### Linking the Math Library

On Linux and some Unix systems, including the header is not enough on its own. You also need to explicitly link the math library when compiling by passing the `-lm` flag to GCC. Forgetting this is one of the most common beginner compilation errors with `<math.h>`.

```
gcc program.c -o program -lm
```

On Windows with MinGW or MSVC this flag is typically not needed, but it does not hurt to include it as a habit.

## The `double` Convention

Every function in `<math.h>` takes and returns `double` by default. This is intentional -- mathematical operations generally benefit from the extra precision that `double` provides over `float`. If you pass a `float` it gets automatically promoted to `double` before the function runs.

```c
float x = 2.0;
double result = sqrt(x);   // x is promoted to double automatically
```

If you specifically need `float` versions of these functions, C99 added `float` variants with an `f` suffix and `long double` variants with an `l` suffix:

```c
sqrtf(x);    // float version
sqrtl(x);    // long double version
sqrt(x);     // double version (default)
```

## Power and Root Functions

### `pow()` -- Raise to a Power

Raises a base number to an exponent. Both arguments are `double`.

```c
#include <stdio.h>
#include <math.h>

int main() {
    printf("%f\n", pow(2.0, 10.0));   // Output: 1024.000000
    printf("%f\n", pow(3.0,  3.0));   // Output: 27.000000
    printf("%f\n", pow(9.0,  0.5));   // Output: 3.000000  (square root)
    printf("%f\n", pow(2.0, -1.0));   // Output: 0.500000  (negative exponent)

    return 0;
}
```

> `pow(x, 0.5)` is mathematically equivalent to `sqrt(x)` but `sqrt()` is faster and should be preferred when you just need a square root.

### `sqrt()` -- Square Root

Returns the square root of a non-negative number. Passing a negative value produces `NaN` (Not a Number).

```c
printf("%f\n", sqrt(25.0));    // Output: 5.000000
printf("%f\n", sqrt(2.0));     // Output: 1.414214
printf("%f\n", sqrt(-1.0));    // Output: -nan  (undefined for negatives)
```

### `cbrt()` -- Cube Root

Returns the cube root. Unlike `sqrt()`, `cbrt()` handles negative numbers correctly.

```c
printf("%f\n", cbrt(27.0));    // Output: 3.000000
printf("%f\n", cbrt(-8.0));    // Output: -2.000000
```

### `hypot()` -- Hypotenuse

Computes the length of the hypotenuse of a right triangle given the two other sides. Equivalent to `sqrt(x*x + y*y)` but more numerically stable for very large or very small values.

```c
printf("%f\n", hypot(3.0, 4.0));    // Output: 5.000000
printf("%f\n", hypot(5.0, 12.0));   // Output: 13.000000
```

## Rounding Functions

All four rounding functions take a `double` and return a `double`. They differ only in which direction they round.

### `floor()` -- Round Down

Rounds toward negative infinity -- always goes to the lower integer.

```c
printf("%f\n", floor(4.9));    // Output: 4.000000
printf("%f\n", floor(4.1));    // Output: 4.000000
printf("%f\n", floor(-4.1));   // Output: -5.000000  (toward negative infinity)
```

### `ceil()` -- Round Up

Rounds toward positive infinity -- always goes to the higher integer.

```c
printf("%f\n", ceil(4.1));    // Output: 5.000000
printf("%f\n", ceil(4.9));    // Output: 5.000000
printf("%f\n", ceil(-4.9));   // Output: -4.000000  (toward positive infinity)
```

### `round()` -- Round to Nearest

Rounds to the nearest integer. Halfway cases (exactly .5) round away from zero.

```c
printf("%f\n", round(4.5));    // Output: 5.000000
printf("%f\n", round(4.4));    // Output: 4.000000
printf("%f\n", round(-4.5));   // Output: -5.000000  (away from zero)
```

### `trunc()` -- Truncate Toward Zero

Drops the decimal portion entirely, always moving toward zero regardless of sign.

```c
printf("%f\n", trunc(4.9));    // Output: 4.000000
printf("%f\n", trunc(-4.9));   // Output: -4.000000  (toward zero, not -5)
```

### Rounding Comparison Summary

```c
double x = 4.6,  y = -4.6;

printf("%-10s %6.1f %6.1f\n", "floor()",  floor(x),  floor(y));
printf("%-10s %6.1f %6.1f\n", "ceil()",   ceil(x),   ceil(y));
printf("%-10s %6.1f %6.1f\n", "round()",  round(x),  round(y));
printf("%-10s %6.1f %6.1f\n", "trunc()",  trunc(x),  trunc(y));
```

**Output:**
```
floor()        4.0   -5.0
ceil()         5.0   -4.0
round()        5.0   -5.0
trunc()        4.0   -4.0
```

## Absolute Value Functions

### `fabs()` -- Absolute Value for Doubles

Returns the absolute (non-negative) value of a `double`. For integers use `abs()` from `<stdlib.h>` instead.

```c
#include <math.h>

printf("%f\n", fabs(-7.5));    // Output: 7.500000
printf("%f\n", fabs( 7.5));    // Output: 7.500000
```

### `fmod()` -- Floating Point Remainder

The floating point equivalent of the `%` modulus operator. Returns the remainder after dividing two `double` values.

```c
printf("%f\n", fmod(10.5, 3.0));   // Output: 1.500000
printf("%f\n", fmod( 7.0, 2.5));   // Output: 2.000000
```

## Logarithm and Exponential Functions

### `exp()` -- Euler's Number Raised to a Power

Returns `e` (approximately 2.71828) raised to the power of the argument.

```c
printf("%f\n", exp(1.0));    // Output: 2.718282  (e^1)
printf("%f\n", exp(2.0));    // Output: 7.389056  (e^2)
printf("%f\n", exp(0.0));    // Output: 1.000000  (e^0 = 1)
```

### `log()` -- Natural Logarithm (Base e)

Returns the natural logarithm of a positive number. Passing zero or a negative number produces `-inf` or `NaN`.

```c
printf("%f\n", log(1.0));          // Output: 0.000000
printf("%f\n", log(M_E));          // Output: 1.000000  (log of e = 1)
printf("%f\n", log(100.0));        // Output: 4.605170
printf("%f\n", log(0.0));          // Output: -inf
```

### `log2()` -- Logarithm Base 2

Returns the base-2 logarithm. Useful in computer science for calculating bit widths and algorithmic complexity.

```c
printf("%f\n", log2(1.0));     // Output: 0.000000
printf("%f\n", log2(8.0));     // Output: 3.000000
printf("%f\n", log2(1024.0));  // Output: 10.000000
```

### `log10()` -- Logarithm Base 10

Returns the base-10 logarithm.

```c
printf("%f\n", log10(1.0));      // Output: 0.000000
printf("%f\n", log10(100.0));    // Output: 2.000000
printf("%f\n", log10(1000.0));   // Output: 3.000000
```

## Trigonometric Functions

All trig functions in `<math.h>` work in **radians**, not degrees. If you have degrees you need to convert first.

```c
// Degrees to radians conversion
double degrees_to_radians(double degrees) {
    return degrees * (M_PI / 180.0);
}
```

### `sin()`, `cos()`, `tan()`

```c
#include <stdio.h>
#include <math.h>

int main() {
    double angle = M_PI / 6.0;   // 30 degrees in radians

    printf("sin(30) = %.4f\n", sin(angle));   // Output: 0.5000
    printf("cos(30) = %.4f\n", cos(angle));   // Output: 0.8660
    printf("tan(30) = %.4f\n", tan(angle));   // Output: 0.5774

    return 0;
}
```

### `asin()`, `acos()`, `atan()` -- Inverse Trig

Return the angle in radians whose sine, cosine, or tangent equals the argument.

```c
printf("%.4f\n", asin(0.5));    // Output: 0.5236 radians (30 degrees)
printf("%.4f\n", acos(0.5));    // Output: 1.0472 radians (60 degrees)
printf("%.4f\n", atan(1.0));    // Output: 0.7854 radians (45 degrees)
```

### `atan2()` -- Two-Argument Arctangent

`atan2(y, x)` computes the angle of the point `(x, y)` from the positive x-axis, correctly handling all four quadrants. This is almost always preferred over `atan()` in practice because `atan()` cannot distinguish between opposite quadrants.

```c
printf("%.4f\n", atan2(1.0,  1.0));   // Output:  0.7854  ( 45 degrees)
printf("%.4f\n", atan2(1.0, -1.0));   // Output:  2.3562  (135 degrees)
printf("%.4f\n", atan2(-1.0, -1.0));  // Output: -2.3562  (225 degrees)
```

## Mathematical Constants

`<math.h>` defines several useful constants. They are available when you define `_USE_MATH_DEFINES` before including the header on some compilers, though on GCC they are available by default.

```c
#define _USE_MATH_DEFINES   // Required on MSVC
#include <math.h>
```

| Constant | Value | Meaning |
|----------|-------|---------|
| `M_PI` | 3.14159265358979... | Pi |
| `M_E` | 2.71828182845904... | Euler's number |
| `M_SQRT2` | 1.41421356237309... | Square root of 2 |
| `M_LN2` | 0.69314718055994... | Natural log of 2 |
| `M_LOG2E` | 1.44269504088896... | Log base 2 of e |

```c
printf("Pi      = %.10f\n", M_PI);     // Output: 3.1415926536
printf("e       = %.10f\n", M_E);      // Output: 2.7182818285
printf("sqrt(2) = %.10f\n", M_SQRT2);  // Output: 1.4142135624
```

## Special Values -- `NaN` and `Infinity`

Some math operations produce results that are not ordinary numbers. `<math.h>` provides functions to check for these.

```c
#include <math.h>

double a = sqrt(-1.0);     // NaN
double b = log(0.0);       // -Infinity
double c = 1.0 / 0.0;     // Infinity (undefined behavior technically, but common)

printf("%d\n", isnan(a));       // Output: 1 (true)
printf("%d\n", isinf(b));       // Output: 1 (true)
printf("%d\n", isfinite(c));    // Output: 0 (false -- it is infinite)
```

| Function | Returns true when |
|----------|------------------|
| `isnan(x)` | x is Not a Number |
| `isinf(x)` | x is positive or negative infinity |
| `isfinite(x)` | x is a normal finite number |
| `isnormal(x)` | x is a normal number (not zero, NaN, or inf) |

Always check for these conditions when performing operations that could produce them, especially division, logarithms, and square roots of potentially negative numbers.

## Putting It All Together -- Full Example

```c
#include <stdio.h>
#include <math.h>

int main() {
    double a = 9.0, b = 3.0;

    printf("pow(%.0f, %.0f)   = %.2f\n", a, b, pow(a, b));
    printf("sqrt(%.0f)        = %.2f\n", a, sqrt(a));
    printf("cbrt(27.0)        = %.2f\n", cbrt(27.0));
    printf("hypot(3, 4)       = %.2f\n", hypot(3.0, 4.0));
    printf("floor(4.7)        = %.2f\n", floor(4.7));
    printf("ceil(4.2)         = %.2f\n", ceil(4.2));
    printf("round(4.5)        = %.2f\n", round(4.5));
    printf("fabs(-7.5)        = %.2f\n", fabs(-7.5));
    printf("fmod(10.5, 3.0)   = %.2f\n", fmod(10.5, 3.0));
    printf("log10(1000)       = %.2f\n", log10(1000.0));
    printf("log2(1024)        = %.2f\n", log2(1024.0));
    printf("sin(PI/2)         = %.2f\n", sin(M_PI / 2.0));
    printf("cos(0)            = %.2f\n", cos(0.0));

    return 0;
}
```

**Output:**
```
pow(9, 3)       = 729.00
sqrt(9)         = 3.00
cbrt(27.0)      = 3.00
hypot(3, 4)     = 5.00
floor(4.7)      = 4.00
ceil(4.2)       = 5.00
round(4.5)      = 5.00
fabs(-7.5)      = 7.50
fmod(10.5, 3.0) = 1.50
log10(1000)     = 3.00
log2(1024)      = 10.00
sin(PI/2)       = 1.00
cos(0)          = 1.00
```

## Quick Reference Summary

- Include `<math.h>` and compile with `-lm` on Linux to access math functions
- All functions use `double` by default -- use `f` suffix variants for `float`
- `pow(x, y)` raises x to y, but use `sqrt()` directly for square roots since it is faster
- `floor()` always goes down, `ceil()` always goes up, `round()` goes to nearest, `trunc()` drops the decimal
- `fabs()` is for `double` absolute value -- use `abs()` from `<stdlib.h>` for integers
- All trig functions use radians -- convert degrees with `degrees * (M_PI / 180.0)`
- Prefer `atan2(y, x)` over `atan()` when working with angles in two dimensions
- `log()` is natural log base e, `log2()` is base 2, `log10()` is base 10
- Always check for `NaN` and infinity with `isnan()`, `isinf()`, and `isfinite()` when operations could produce them
- Mathematical constants like `M_PI` and `M_E` are defined in `<math.h>`