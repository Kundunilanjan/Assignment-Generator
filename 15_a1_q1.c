1. Write a program in C to find the third largest from the given array of
integers without sorting.
                              code
#include <stdio.h>

int findThirdLargest(int arr[], int size) {
    if (size < 3) {
        printf("Array has less than three elements.\n");
        return -1;
    }
    
    int firstLargest = arr[0];
    int secondLargest = arr[1];
    int thirdLargest = arr[2];
    
    for (int i = 3; i < size; i++) {
        if (arr[i] > firstLargest) {
            thirdLargest = secondLargest;
            secondLargest = firstLargest;
            firstLargest = arr[i];
        } else if (arr[i] > secondLargest) {
            thirdLargest = secondLargest;
            secondLargest = arr[i];
        } else if (arr[i] > thirdLargest) {
            thirdLargest = arr[i];
        }
    }
    
    return thirdLargest;
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    int thirdLargest = findThirdLargest(arr, size);
    if (thirdLargest != -1) {
        printf("The third largest element is: %d\n", thirdLargest);
    }
    
    return 0;
}
