2. Given an array of n integers, write C program for reversing the
contents of the array without using another array.
                            code
#include<stdio.h>
 void main () {
 int n,temp;
 printf ("enter number of elements:\n"); 
 scanf("%d",&n); 
 int a[n];
 printf("enter elements:"); 
 for(int i=0;i<n;i++){
 scanf("%d",&a[i]);
 }
 int i=0;
 int j=n-1; 
 while (i<=j&&j>=0){ 
 temp = a[i]; 
 a[i]=a[j]; 
 a[j]=temp; 
 i++;
 j--;
 }
 printf("after reversing: \n"); 
 for (int i=0;i<n;i++) {
 printf("%d", a[i]);
 }
 }
