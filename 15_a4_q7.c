#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Convert a string to uppercase
void string_toupper(char *str) {
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}

// Compare two strings ignoring case
int string_greater(const char *str1, const char *str2) {
    char upper_str1[strlen(str1) + 1];
    char upper_str2[strlen(str2) + 1];

    strcpy(upper_str1, str1);
    strcpy(upper_str2, str2);

    string_toupper(upper_str1);
    string_toupper(upper_str2);

    return strcmp(upper_str1, upper_str2) > 0;
}

int main() {
    const char *str1 = "apple";
    const char *str2 = "Banana";

    if (string_greater(str1, str2)) {
        printf("%s comes after %s when ignoring case.\n", str1, str2);
    } else {
        printf("%s comes before %s when ignoring case.\n", str1, str2);
    }

    return 0;
}
