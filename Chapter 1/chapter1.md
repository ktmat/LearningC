# 1.1 Getting Started
The only way to learn a new programming language is by writing programs in it. The first program to write is the same for all languages:

```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}
```
The main function is declared with the return type of an **int**. The return value is 0 after running the printf statement. Printf is included in the stdio header file.


# 1.2 Variables and Arithmetic Expressions
The next program uses the formula C = (5/9)(F-32) to print the following table of Fahrenheit temperatures and their centigrade or Celsius equivalents.

```
 1 -17
 20 -6
 40 4
 60 15
 80 26
 100 37
 120 48
 140 60
 160 71
 180 82
 200 93
 220 104
 240 115
 260 126
 280 137
 300 148
 ```
 
The program itself still consists of the definition of a single function named main.. It is longer than the one that printed ``hello, world``, but not complicated. It introduces several new ideas, including comments, declarations, variables, arithmetic expressions, loops, and formatted output.
```c
#include <stdio.h>

main() {
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper) {
        celsius = 5 * (fahr-32) / 9;
        printf("%d\t$d\n", fahr, celsius);
        fahr = fahr + step;
    }
}
```
The C Programming Language provides several other data types besides int and float, including:
| Type | Explanation |
| ---- | ----------- |
| char | character - a single byte |
| short | short integer |
| long | long integer |
| double | double-precisions floating point |

The size of these objects is also machine-dependent. There are also arrays, structures and u8nions of these basic types, pointers to them, and functions that return them, all of which we will meet in due course.

# 1.3 The for Statement
There are plenty of different ways to write a program for a particular task. Let's try a variation on the temperature converter.
```c
#include <stdio.h>

main() {
    int fahr; 
    for (fahr = 0; fahr <= 300; fahr = fahr + 20) {
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }
}
```
The choice between while and for is arbitrary, based on which seems cleaer. The for is usually appropriate for loops in which the initialisation and increment are single statements and logically related, since it is more compacy than while and it keeps the loop control statements together in one place.

**Exercise 1-5.** Modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0.
```c
#include <stdio.h>

main() {
    int fahr;
    for (fahr = 300; fahr >= 0; fahr = fahr - 20) {
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }
}
```

# 1.5 Character Input and Output
We are going to consider a family of related programs for processing character data. You will find that many programs are just expanded versions of the prototypes that we discuss here.

The model of input and output supported by the standard library is very simple. Text input or output, regardless of where it originates or where it goes to, is dealt with as streams of characters. A text stream is a sequence of characters divided into lines; each line consists of zero or more characters followed by a newline character. It is the responsibility of the lbirary to make each input or output stream confirm this model; the C programmer using hte library need not worry about how lines are represented outside the program.

The standard library provides several functions for reading or writing one character at a time, of which ```getchar``` and ```putchar``` are the simplest.. Each time it is called, ```getchar``` reads the next input characters from a text stream and returns that as its value That is, after
```c
c = getchar();
```
the variable ```c``` contains the next character of input. The characters normally come from the keyboard.

The function ```putchar``` prints a character each time it is calle:
```c
putchar(c);
```
prints the content of the integer variable c as a character, usually o nthe screen. Calls to ```putchar``` and ```printf``` may be interleaved; the output will appear in the order in which the calls are made.

# 1.5.1 File Copying
Given ```getchar``` and ```putchar```, you can write a surprising amount of useful code without knowing anything more about input and output. The simplest example is a program that copies its input to its output one character at a time:
```
read a character
   while (character is not end-of-file indicator)
    output the character just read
    read a character
```
Converting into C gives:
```c
#include <stdio.h>

main() {
    int c;
    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
}
```
The program for copying would be written more soncisely by experienced C programmers. In C, any assignment, such as
```c
c = getchar();
```
is an expression and has a value, which is the value of the left hand side after the assignment. This means that an assignment can appear as part of a larger expression, If the assignment of a character to ```c``` is put inside the test part of a ```while``` loop, the copy program can be written this way:
```c
#include <stdio.h>

main() {
    int c;
    
    while ((c = getchar()) != EOF) {
        putchar(c);
    }
}
```
The ```while``` gets a character, assigns it to ```c```, and then tests whether the character was the end-of-file signal. If it was not, the body of the ```while``` is executed, printing the character. The ```while``` then repeats. .When the end of the input is finally reached, the ```while``` terminates and so does ```main```.