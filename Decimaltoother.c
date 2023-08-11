2.	WAP to convert decimal to A. Binary, B. Octal, and C. Hexadecimal numbers using CASE statement. 

                                            Code

#include <stdio.h>



void decimalToBinary(int num) {

    int binary[32];

    int i = 0;

    

    while (num > 0) {

        binary[i] = num % 2;

        num /= 2;

        i++;

    }

    

    printf("Binary: ");

    for (int j = i - 1; j >= 0; j--) {

        printf("%d", binary[j]);

    }

    printf("\n");

}



void decimalToOctal(int num) {

    printf("Octal: %o\n", num);

}



void decimalToHexadecimal(int num) {

    printf("Hexadecimal: %X\n", num);

}



int main() {

    int decimalNum;

    char choice;



    printf("Enter a decimal number: ");

    scanf("%d", &decimalNum);



    printf("Choose conversion: \n");

    printf("A. Binary\nB. Octal\nC. Hexadecimal\n");

    scanf(" %c", &choice);



    switch (choice) {

        case 'A':

        case 'a':

            decimalToBinary(decimalNum);

            break;

        case 'B':

        case 'b':

            decimalToOctal(decimalNum);

            break;

        case 'C':

        case 'c':

            decimalToHexadecimal(decimalNum);

            break;

        default:

            printf("Invalid choice.\n");

            break;

    }



    return 0;

}

              

