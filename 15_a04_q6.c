#include <stdio.h>
#include <string.h>

void trim_blanks(const char *to_trim, char *trimmed) {
    // Find the first non-blank character
    while (*to_trim && (*to_trim == ' ' || *to_trim == '\t')) {
        to_trim++;
    }

    // Find the last non-blank character
    const char *end = to_trim + strlen(to_trim) - 1;
    while (end >= to_trim && (*end == ' ' || *end == '\t')) {
        end--;
    }

    // Copy the trimmed portion using strncpy
    strncpy(trimmed, to_trim, end - to_trim + 1);
    trimmed[end - to_trim + 1] = '\0'; // Null-terminate the result
}

int main() {
    const char to_trim[] = "   Hello, world!    ";
    char trimmed[100]; // Adjust the size as needed

    trim_blanks(to_trim, trimmed);
    printf("Trimmed: '%s'\n", trimmed);

    return 0;
}
