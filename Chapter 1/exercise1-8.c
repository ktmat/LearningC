#include <stdio.h>

main() {
    int c, nl, blanks, tabs;
    nl = 0;
    tabs = 0;
    blanks = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            nl++;
        } else if (c == '\t') {
            tabs++;
        } else if (c == ' ') {
            blanks++;
        }
    }
    printf("Blanks: %d\n", blanks);       // Print count of blanks
    printf("Tabs: %d\n", tabs);           // Print count of tabs
    printf("Newlines: %d\n", nl);   // Print count of newlines
}
