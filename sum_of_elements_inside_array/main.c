#include<stdio.h>
#include"array_utils.h"
#include"parallel_sum.h"

int main() {
    int nproc = 4;  // Number of threads
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size > MAX) {
        printf("Array size exceeds the maximum limit of %d.\n", MAX);
        return -1;
    }

    generate_array(size);  // Generate random numbers for the array
    printf("Array contents:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    printf("Calculating sum using %d threads...\n", nproc);
    compute_parallel_sum(nproc, size);

    printf("The sum of the array elements is: %d\n", global_sum);

    return 0;
}