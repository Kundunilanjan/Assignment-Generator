3. WAP to display any number of stars on the screen. Display a menu with the following options.



        1 - Fullscreen

        2 - Half screen

        3 - Top 3 lines

        4 - Bottom 3 lines

        5 - Right angled triangle (RT angle at right bottom)

        6 - Isosceles triangle (base at the bottom)

        7 - Circle (as shown in the lab)

        8 - Diamond blank (as shown in the lab)                           Code

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <ctype.h>

#include <math.h>

void full()

{

 for(int i=0;i<24;i++)

    {

        for(int j=0;j<80;j++){

             printf("*");

            }

             printf("\n");

     }

}

 void half()

{

  for(int i=0;i<24;i++){

        for(int j=0;j<40;j++){

             printf("*");

            }

             printf("\n");

      }

}

 void top()

{

  for(int i=0;i<3;i++){

          for(int j=0;j<80;j++){

               printf("*");

             }

               printf("\n");

       }

  for(int i=3;i<=24;i++){

          for(int j=0;j<80;j++){

               printf(" ");

             }

               printf("\n");

       }

}

void bottom()

{

  for(int i=0;i<21;i++){

           for(int j=0;j<80;j++){

                printf(" ");

              }

                printf("\n");

      }

 for(int i=21;i<=24;i++){

           for(int j=0;j<80;j++){

                printf("*");

              }

                printf("\n");

     }

}

void right()

{

  for(int i=0;i<24;i++){

            for(int j=0;j<80;j++){

                    if(j<80-i-1){

                                printf(" ");

                                 }

                    else{ printf("*");

                        }

               }

                   printf("\n");

      }

}

void iso()

{

  for(int i=1;i<=25;i++){

            for(int j=i;j<=25;j++){

                 printf(" ");

               }

            for(int k=1;k<=((2*i)-1);k++){

                 printf("*");

               }

                 printf("\n");

       }

}

void circle()

{

        int i,j;

        int cols = 80;

         for( i =24; i >=-24; i--) {

                for( j =-24; j <=24; j++){



                           if((i*i+j*j<=576)&&(i*i+j*j>=400)){

                                   printf("*");

                                }

                           else{  printf(" ");

                                }

                   }

                          printf("\n");

             }



}

void diamond()

{

int i,s,j,k;

for(i=1;i<=24;i++)

  {

    for(s=i;s<73;s++)

             printf("*");

    for(j=1;j<=(2*i)-1;j++)

             printf(" ");

    for(k=i;k<73;k++)

             printf("*");

             printf("\n");



  }



for(i=23;i>=1;i--)

  {

    for(s=i;s<73;s++)

             printf("*");

    for(j=1;j<=(2*i)-1;j++)

             printf(" ");

    for(k=i;k<73;k++)

             printf("*");

            printf("\n");



  }



}



void main()

{

printf("1.Full screen\n");

printf("2.Half screen\n");

printf("3.Top 3 lines\n");

printf("4.Bottom 3 lines\n");

printf("5.Right angled\n");

printf("6.Isosceles triangle\n");

printf("7.Circle\n");

printf("8.diamond blank\n");

printf("Enter you choice:\n");

int ch;

scanf("%d",&ch);

           if(ch==1)

                   {

                       full();

                   }

           if(ch==2){

                       half();

                     }

           if(ch==3){

                       top();

                    }

           if(ch==4){

                       bottom();

                     }

           if(ch==5)

                   {

                        right();

                    }

           if(ch==7)

                   {

                         circle();

                    }

           if(ch==6)

                   {

                          iso();

                    }

           if(ch==8)

                   {

                          diamond();

                    }

}

