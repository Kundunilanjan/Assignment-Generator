2.	WAP to convert the number of years (user input) into months/days/hours/minutes/seconds using a switch-case statement.  

                                 Code

#include<stdio.h>

void main(){

int n;

printf("enter no of years");

scanf("%d",&n);

printf("1. to months\n");

printf("2. to days\n");

printf("3. to hours\n");

printf("4. to minutes\n");

printf("5. to seconds\n");

printf("enter your choice");

int c,m,d,h,mi,s;

scanf("%d",&c);

switch(c){

case 1:

m=n*12;

printf("%d",m);

break;

case 2:

d=(n*365);

printf("%d",d);

break;

case 3:

h=n*365*24;

printf("%d",h);

break;

case 4:

mi=(n*365*24*60);

printf("%d",mi);

break;

case 5:

s=(n*365*24*60*60);

printf("%d",s);

break;

default: printf("wrong\n");

}

}

