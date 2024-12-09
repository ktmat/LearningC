# Chapter 4 - Functions and Program Structure
Functions break large computing tasks into smaller ones, and enable people to build on what others have done instead of starting over from scratch.

## 4.1 Basics of Functions
Design and write a program to print each line of its input that contains a particular pattern, or string of characters. For example, searching for the pattern of letters "ould" in the set of lines.
```
Ah Love! could you and I with Fate conspire 
To grasp this sorry Scheme of Things entire, 
Would not we shatter it to bits -- and then 
Re-mould it nearer to the Heart's Desire! 
```
will produce the output...
```
Ah Love! could you and I with Fate conspire
Would not we shatter it to bits -- and then
Re-mould it nearer to the Heart's Desire!
```
The job falls neatly into three pieces:
```
while (there is another line)
    if (the line contains the pattern)
        print it
```
Here goes the code.
```c
#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int max)
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

main() {
    char line[MAXLINE];
    int found = 0;

    while (getline(line, MAXLINE) > 0) {
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    }
    return found;
}

int getline(char s[], int lim) {
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = c;
        s[i] = '\0';
        return i;
    }
}

int strindex(char s[], char t[]) {
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
            ;
        }
        if (k > 0 && t[k] == '\0') {
            return i;
        }
    }
    return -1;
}
```
## 4.6 Static Variables
The ```static``` declaration limits the scope of that object to the rest of the source file being compiled. They preserve their value regardless of scope.
```c
static char buf[BUFSIZE];
static int bufp = 0;
int getch(void) {...}
void ungetch(int c) {...}
```
The ```static``` declaration can be used for both variables and functions. Normally, functions are global, visible to any part of the program. If a function is declared ```static```, its name is invisible outside of the file in which it is declared.
## 4.7 Register Variables
A ```register``` declaration advises the compiler that the variable in question will be heavily used. THe idea is that the ```register``` variables are to be placed in machine registers, which may result in smaller and faster programs But compilers are free to ignore the advice.
```c
register int x;
register char c;
```
## 4.10 Recursion
C functions may be used recursively. Here is an example of recursion.
```c
#include <stdio.h>

void printd(int n) {
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n / 10) {
        printd(n / 10);
    }
    putchar(n % 10 + '0');
}
```
The ```qsort``` function in C makes use of this recursion.
```c
void qsort(int v[], int left, int right) {
    int i, last;
    void swap(int v[], int i, int j);
    if (left >= right) {
        return;
    }
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if (v[i] < v[left]) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}
```
This is where swap is defined as follows:
```c
void swap(int v[], int i, int j) {
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}