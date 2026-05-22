# Variable Warnings

## About these warnings

These warnings are derived from the JOINT STRIKE FIGHTER AIR VEHICLE C++ CODING STANDARDS FOR THE SYSTEM DEVELOPMENT AND DEMONSTRATION PROGRAM document Revision C dated December 2005. 

Lessons learned from this document are applied to my C language notes. 

## Declaring & Initializing Variables

### ⚠️ Warning - Hiding Declarations ⚠️
**Declarations in an inner scope should not use the same name as a declaration in an outer scope, and therefore hide that identifier. This is called shadowing.**

```c
int sum = 0;
{
    int sum = 0;  // Bad: inner sum hides outer sum
    sum = f(x);   // Which sum? The inner one — easy to get wrong
}
// Outer sum is still 0, which may surprise the reader
```

Function parameter shadowing a global:

```c
int count = 0;          // file-scope variable

void process(int count) // Bad: parameter hides global 'count'
{
    count++;            // modifies the parameter, not the global
}
```

Local variable shadowing a parameter:

```c
void calculate(int result)
{
    int result = 0;  // Bad: hides the parameter 'result'
    ...
}
```

Loop variable shadowing an outer variable:

```c
int i = 10;
for (int i = 0; i < N; i++)  // Bad: loop 'i' hides outer 'i'
{
    ...
}
// outer i is still 10, but did you mean to use it in the loop?
```
### ⚠️ Warning - Declaration Scope ⚠️
**Declarations should be at the smalled feasible scope. This practice attempts to minimize the number of live variables that muse be considered. Variable declarations should be postponed until enough information is available for full initialization. A variable should never be placed in a partly-intialized or initialize-but-not-valid state.**

```c
// C99 and later — legal, and the preferred JSF-compliant style
for (int j = 0; j < max; ++j)
{
    // j only exists here
}

// C89/C90 — declarations must be at the top of a block
{
    int j;              // Must be here in C89
    for (j = 0; j < max; ++j)
    {
        // ...
    }
}
// j is gone after the closing brace
```

```c
void fun_1(void)
{
    int i;  // Bad: prematurely declared, only needed in loop
    ...     // Bad: i has a meaningless value here
    for (i = 0; i < max; ++i)
    {
        ...
    }
    ...     // Bad: i is still accessible and usable here by mistake

    // C99+: Good — j declared and initialized exactly when needed
    for (int j = 0; j < max; ++j)
    {
        // Good: j is only known within this loop's scope
    }

    // C89 equivalent — still limits scope, just requires a block
    {
        int j = 0;      // Good: j is initialized immediately, not partly
        for (j = 0; j < max; ++j)
        {
            ...
        }
    }                   // Good: j goes out of scope here
}
```
```c
// Bad: declared but not yet validly initialized
int result;
if (condition)
{
    result = compute();  // Only initialized on one branch
}
// result may be garbage here — rule violation

// Good: declaration deferred until value is known
if (condition)
{
    int result = compute();  // Initialized at point of declaration
    use(result);
}
```

### ⚠️ Warning - Multiple Declarations ⚠️
**You should not declare multiple variables in the same line. It is bad practice.**

By following this warning, it increases readability and prevents confusion. 

```c
int p, q;   //Could lead to an error
int firstbutton_on_top_of_the_left_box, i; // Bad: Easy to overlook variable i 
```

### ⚠️ Warning - Use Floats Properly ⚠️
**It is important to adhere to the IEEE Standard for Floating-Point Arithmetic (IEEE 754) to maintain consistency. The IEEE 754 addressed many problems found in the diverse floating-point implementations that made them difficult to use reliably and portably.**

**Bad: Compiler Optimisation Breaks Predictability**

```c
// Compiled with -ffast-math

float x = 1000000.0f;
float y = -999999.0f;
float z = 1.0f;

float result = (x + y) + z;     // You expect 2.0
                                // Bad: compiler may reorder to x + (y + z)
                                // giving a different result due to rounding
                                // The answer is now unpredictable
```
**Good: Standard Compliant Arithmetic**
```c
// Compiled without -ffast-math, on an IEEE 754 compliant target

float x = 1000000.0f;
float y = -999999.0f;
float z = 1.0f;

float result = (x + y) + z;     // Good: operations happen left to right
                                // exactly as written, every time,
                                // on every run, on every compliant machine
```

**Bad: Assuming Exact Decimal Results**
```c
float x = 0.1f;
float y = 0.2f;

if (x + y == 0.3f)              // Bad: this will likely never be true
{                               // 0.1 and 0.2 cannot be represented exactly
    do_something();             // This code may never execute
}
```

**Good: Comparing with a Tolerance**
```c
float x = 0.1f;
float y = 0.2f;
float difference;

difference = (x + y) - 0.3f;

if (difference < 0.0f)          // Good: get absolute value manually
{
    difference = -difference;
}

if (difference < 0.0001f)       // Good: check within a small tolerance
{                               // rather than exact equality
    do_something();
}
```

**Bad: Using a Non-Compliant Soft Float Library**
```c
// On an embedded target with a cheap software float library
// that cuts corners on rounding

float a = 1.5f;
float b = 1.5f;
float result = a * b;       // Bad: library gives 2.24999 instead of 2.25
                            // Rounding is wrong, result is unpredictable
                            // and differs from what any other machine gives
```

**Good: Verified Compliant Library**
```c
// Same target, but using a verified IEEE 754 soft float library

float a = 1.5f;
float b = 1.5f;
float result = a * b;   // Good: result is exactly 2.25 every time
                        // because the library follows IEEE 754 rounding rules
```
