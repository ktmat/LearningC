#include <stdio.h>

#define MAX_WORD_LENGTH 20  // Maximum word length tracked
#define IN  1               // Inside a word
#define OUT 0               // Outside a word

int main() {
    int c, state, word_length;
    int lengths[MAX_WORD_LENGTH + 1] = {0};  // Array to store word length counts
    int max_count = 0;  // Track the maximum count for scaling

    state = OUT;
    word_length = 0;

    // Count word lengths
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {  // End of a word
                state = OUT;
                if (word_length > 0) {
                    if (word_length <= MAX_WORD_LENGTH) {
                        lengths[word_length]++;
                    } else {
                        lengths[MAX_WORD_LENGTH]++;  // Group overflow lengths
                    }
                }
                word_length = 0;
            }
        } else {
            state = IN;
            word_length++;
        }
    }

    // Find the maximum count for scaling
    for (int i = 1; i <= MAX_WORD_LENGTH; i++) {
        if (lengths[i] > max_count) {
            max_count = lengths[i];
        }
    }

    // Print the vertical histogram
    for (int row = max_count; row > 0; row--) {
        for (int i = 1; i <= MAX_WORD_LENGTH; i++) {
            if (lengths[i] >= row) {
                printf("  # ");
            } else {
                printf("    ");
            }
        }
        printf("\n");
    }

    // Print the x-axis labels
    for (int i = 1; i <= MAX_WORD_LENGTH; i++) {
        printf("%3d ", i);
    }
    printf("\n");

    return 0;
}
