3.	WAP to assist in the design of a hydroelectric dam. Prompt the user for the dam's height and the number of cubic meters of water projected to flow from the top to the bottom each second. Predict how many megawatts of power will be produced if 90% of the work done on the water by gravity is converted to electrical energy.

For the following runs, report the outputs.

A. Use height = 200 m and flow of 1.50 x 10^3 m^3/s.

B. Use height = 170 m and flow of 1.30 x 10^3 m^3/s.

                                               Code

#include<stdio.h>

void main(){

    int h,v;

    printf("enter the height:");

    scanf("%d",&h);

    printf("enter flow rate:");

    scanf("%d",&v);

    int m=1000*v;

    int p=(9.81*m*h)*(0.9/1000000);

    printf("the power generated in megawatts is %d",p);

}

