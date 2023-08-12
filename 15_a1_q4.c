4. Write a C program to find the frequency of a character present in the
text given in a file.
                             code
#include<stdio.h>
#include<stdlib.h>
void main(){
  char target_char, ch;
  int count=0;
  FILE *ptr;
  printf ("enter the character to find its frequency:\n") ; 
  scanf("%c", &target_char); 
  ptr=fopen ("Testing.txt","r") ; 
  if (ptr==NULL) {
  printf("file has no such comment.");
  exit(0);
 }
 while((ch=fgetc(ptr))!=EOF)
 { 
    if (ch==target_char) { 
        count++;
    }
 }
       fclose(ptr) ;
       printf ("the frequency of %c character is %d", target_char, count); 
}
