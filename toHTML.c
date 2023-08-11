#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replaceSubstring(char *str, const char *oldSubstr, const char *newSubstr) {
    char *ptr = strstr(str, oldSubstr);
    while (ptr != NULL) {
        memmove(ptr + strlen(newSubstr), ptr + strlen(oldSubstr), strlen(ptr + strlen(oldSubstr)) + 1);
        memcpy(ptr, newSubstr, strlen(newSubstr));
        ptr = strstr(ptr + strlen(newSubstr), oldSubstr);
    }
}

void clearInputBuffer() {
    int c;
    do {
        c = getchar();
    } while (c != '\n');
}

int main () {
    char name[100], group[100], roll[100], assignmentNo[100];
    int qno;

    //User input
    printf("Name: "); gets(name);
    printf("Group: "); gets(group);
    printf("roll: "); gets(roll);
    printf("Assignment No: "); gets(assignmentNo);
    printf("No of Questions: "); scanf("%d", &qno);

    char* htmlcode = (char *) malloc(1000000);

    snprintf(htmlcode, 10000000,
             "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"><title>Report</title><link rel=\"stylesheet\" href=\"prism.css\"/><script src=\"prism.js\" defer></script></head><body class='stackedit'><div class='stackedit__html'><hr>Name: %s<br>Group: %s<br>RollNo: %s<br><h1>&#128203;Assignment %s</h1>",
             name, group, roll, assignmentNo);

    // Menu driven input
    clearInputBuffer();
    for (int i = 1; i <= qno; i++) {
        char qLine[1000];
        char cfile[100];
        char output[1000];
        
        printf("\tQline: "); gets(qLine);
        printf("\tC file: ");gets(cfile);
        printf("\tPng files sep by space: "); gets(output);

        FILE *f = fopen(cfile, "r");
        if (f == NULL) {
            printf("The given C file does not exist. Try giving again\n\n");
            i -= 1; continue;
        }

        // Determine the file size
        fseek(f, 0, SEEK_END);
        long file_size = ftell(f);
        fseek(f, 0, SEEK_SET);

        char text[10000]; // Adjust buffer size as needed
        fread(text, 1, file_size, f);
        text[file_size] = '\0';
        fclose(f);

        // replace the < and >
        replaceSubstring(text, "<", "&lt;");
        replaceSubstring(text, ">", "&gt;");

        char temp[10000]; // Adjust buffer size as needed
        snprintf(temp, sizeof(temp), "<h3>%s</h3><p><strong>Code</strong></p><pre class='line-numbers'><code class='language-c'>%s</code></pre><p><strong>Output</strong></p>", qLine, text);
        strcat(htmlcode, temp);

        char *token = strtok(output, " ");
        while (token != NULL) {
            snprintf(temp, sizeof(temp), "<img src=\"%s\">", token);
            strcat(htmlcode, temp);

            token = strtok(NULL, " ");
        }
        strcat(htmlcode, "<hr>");
        printf("\n");
    }

    strcat(htmlcode, "</div></body></html>");

    // Writing to file
    FILE *outputFile = fopen("report.html", "w");
    if (outputFile == NULL) {
        printf("Error opening HTML file\n");
        return 1;
    }
    //write htmlCode
    fputs(htmlcode, outputFile);
    fclose(outputFile);

    free(htmlcode);
    printf("Process completed, please find a file named report.html on this directory\n");

    return 0;
}
