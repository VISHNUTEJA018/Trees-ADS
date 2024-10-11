#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bitonicmerge(int arr[], int low, int size, int dir) {
    if (size > 1) {
        int gap = size / 2;
        for (int i = low; i < low + gap; i++) {
            if ((dir == 1 && arr[i] > arr[i + gap]) || (dir == 0 && arr[i] < arr[i + gap])) {
                swap(&arr[i], &arr[i + gap]);
            }
        }
        bitonicmerge(arr, low, gap, dir);
        bitonicmerge(arr, low + gap, gap, dir);
    }
}

void bitonicsort(int arr[], int low, int size, int dir) {
    if (size > 1) {
        int gap = size / 2;
        bitonicsort(arr, low, gap, 1); // Sort in ascending order
        bitonicsort(arr, low + gap, gap, 0); // Sort in descending order
        bitonicmerge(arr, low, size, dir);
    }
}

void readArray(int arr[], int n) {
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void displayArray(int arr[], int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of the array (must be a power of 2): ");
    scanf("%d", &n);

    // Check if n is a power of 2
    if (n <= 0 || (n & (n - 1)) != 0) {
        printf("Size must be a positive power of 2.\n");
        return 1;
    }

    int* arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    readArray(arr, n);
    printf("Values before sorting:\n");
    displayArray(arr, n);

    bitonicsort(arr, 0, n, 1); // Sort in ascending order
    printf("Values after sorting:\n");
    displayArray(arr, n);

    free(arr);
    return 0;
}
