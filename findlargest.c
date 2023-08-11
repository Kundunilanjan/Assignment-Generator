1.WAP to input FIVE numbers and find the largest one using the if-else ladder only.
                                     Code
#include<stdio.h>
void main(){
int a,b,c,d,e;
scanf("%d",&a);
scanf("%d",&b);
scanf("%d",&c);
scanf("%d",&d);
scanf("%d",&e);
if(a>b && a>c && a>d && a>e){
printf("max: %d",a);
}
else if(b>a && b>c && b>d && b>e)
printf("max: %d",b);
else if(c>a && c>b && c>d && c>e)
printf("max: %d",c);
else if(d>a && d>b && d>c && d>e)
printf("max: %d",d);
else
printf("max; %d",e);
}
