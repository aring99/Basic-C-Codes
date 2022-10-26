#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

void readInput(int arr[], int *nPtr)
{
    int array_sizer = 0;
    printf("Enter the number of elements:\n");
    scanf("%d", &array_sizer);
    *nPtr = array_sizer;
    //*nPtr = 9;
    //int i = *nPtr;
    //printf("%d", i);

    printf("Enter %d elements:\n", array_sizer);
    int input_getter = 0;
    for(int input_checker = 0; input_checker < array_sizer; input_checker++)
    {
        scanf("%d", &input_getter);
        arr[input_checker] = input_getter;
    }
}

void printNumbers(const int arr[], int n)
{
    printf("Array elements:");

    for(int input_checker = 0; input_checker < n; input_checker++)
    {
        printf("%d ", arr[input_checker]);
    }
    printf("\n");
}

void swap(int *xPtr, int *yPtr)
{
    int temp = 0;
    temp = *xPtr;
    *xPtr = *yPtr;
    *yPtr = temp;
}
int main()
{
    int arr[SIZE];
    int array_size;
    readInput(arr, &array_size);
    int first_index = 0;
    int second_index = 0;
    printNumbers(arr, array_size);
    printf("Enter the first index to be swapped: \n");
    scanf("%d", &first_index);
    printf("Enter the second index to be swapped: \n");
    scanf("%d", &second_index);
    swap(&arr[first_index], &arr[second_index]);
    printNumbers(arr, array_size);

    return 0;
}
