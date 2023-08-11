1.	WAP to calculate the sum of the squares of those numbers only whose LSD is five, falling between two numbers taken as user input. Print the numbers satisfying the constraints, their squares, and the sum on the terminal.

                                               Code

#include<stdio.h>

void main(){

    int x,y,sum=0;

    printf("enter the lower bound:\n");

    scanf("%d",&x);

    printf("enter the upper  bound:\n");

    scanf("%d",&y);

    for(int i=x;i<=y;i++){

        if(i%10==5){

            printf("\n the number is %d",i);

            printf("\n the square of the number is %d",i*i);

            sum+=(i*i);

        }

    }

    printf("the sum of the square of the all the number is %d",sum);

}

