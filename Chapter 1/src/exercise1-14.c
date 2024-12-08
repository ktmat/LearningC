#include <stdio.h>

#define MAX_CHARS 128  // Maximum number of ASCII characters

int main() {
    int c, i, max_freq = 0;
    int frequencies[MAX_CHARS] = {0};  // Array to store character frequencies
    int used_chars[MAX_CHARS] = {0};  // Tracks which characters are used
    int unique_count = 0;  // Count of unique characters

    // Read input and count frequencies
    while ((c = getchar()) != EOF) {
        if (c >= 0 && c < MAX_CHARS) {
            if (frequencies[c] == 0) {
                used_chars[unique_count++] = c;  // Add to the list of used characters
            }
            frequencies[c]++;
        }
    }

    // Find the maximum frequency for scaling
    for (i = 0; i < unique_count; i++) {
        if (frequencies[used_chars[i]] > max_freq) {
            max_freq = frequencies[used_chars[i]];
        }
    }

    // Print the histogram
    for (int row = max_freq; row > 0; row--) {
        for (i = 0; i < unique_count; i++) {
            if (frequencies[used_chars[i]] >= row) {
                printf("  # ");
            } else {
                printf("    ");
            }
        }
        printf("\n");
    }

    // Print x-axis labels
    for (i = 0; i < unique_count; i++) {
        printf("  %c ", used_chars[i]);
    }
    printf("\n");

    return 0;
}

