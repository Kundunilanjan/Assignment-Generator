4.Write a C program to find the frequency of a character present in the text given in a file.
                              code
#include<stdio . h>
 int main(){
 char target char, ch; int count=0; FILE *ptr;
 printf ("'enter the character to find its frequency:\n") ; Scanf("%c", &target_char); ptr=fopen (" Testing. txt", "r") ; if (pt r==NULL) {
 printf("file has no such comment. "); return 1;
 }
 while( ( ch=fgetc (ptr) ) !=EOF){ if (ch==target_char) { count++;
 fclose (ptr) ;
 printf ("the frequency of %c character is sd", target char, count); return 0;
}
