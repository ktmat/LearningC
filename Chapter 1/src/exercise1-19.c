#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void reverse(char s[]) {
    int length = strlen(s);
    printf("strlen: %d\n", strlen(s));
    int i, temp;

    printf("length: %d\n", length);
    for (i = 0; i < length / 2; i++) {
	printf("i = %d\n", i);
        temp = s[i];
	printf("temp: %c\n", temp);
        s[i] = s[length - i - 1];
	printf("s[i] = %c\n", s[i]);
        s[length - i - 1] = temp;
    }
}

int main() {
    char line[MAXLINE];

    while (fgets(line, MAXLINE, stdin) != NULL) {
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] == '\0';
        }
        reverse(line);
        printf("%s\n", line);
    }
    return 0;
}
