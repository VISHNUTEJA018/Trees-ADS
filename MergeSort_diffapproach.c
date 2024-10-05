#include <stdio.h>
#include <stdlib.h>

void merge(int A[], int l, int mid, int up)
{
    int i = l, j = mid + 1, k = l;
    int temp[up - l + 1]; // Dynamically allocate the size of temp

    while (i <= mid && j <= up) {
        if (A[i] <= A[j]) {
            temp[k - l] = A[i];
            i++;
        } else {
            temp[k - l] = A[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k - l] = A[i];
        i++;
        k++;
    }

    while (j <= up) {
        temp[k - l] = A[j];
        j++;
        k++;
    }

    // Copy the sorted elements back to the original array
    for (i = l; i <= up; i++) {
        A[i] = temp[i - l];
    }
}
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}
void printarray(int arr[],int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

}
int main()
{
    int n,i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter the array elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Sorted array is: ");
    mergeSort(arr, 0, n - 1);

    printarray(arr,n);
    return 0;
}
