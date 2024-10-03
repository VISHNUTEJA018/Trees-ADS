#include <stdio.h>
#include <stdlib.h>
//l=ldeft   up =right
void merge(int A[],int n, int l, int mid, int up)
{
    int i = l, j = mid + 1, k = l;
    int temp[50]; // Dynamically allocate the size of temp

    while (i <= mid && j <= up) {
        if (A[i] <= A[j]) {
            temp[k] = A[i];
            i++;
        } else {
            temp[k] = A[j];
            j++;
        }
        k++;
    }
    if(i>mid)
    {
        while(j<=up)
        {
            temp[k]=A[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<=mid)
        {
            temp[k]=A[i];
            i++;
            k++;
        }
    }

    // Copy the sorted elements back to the original array
    for (i = l; i <k; i++) {
        A[i] = temp[i];
    }
}
void mergeSort(int arr[],int n, int l, int up) {
    int mid;
    mid=(l+up)/2;


    if (l < up) {

        // Sort first and second halves
        mergeSort(arr,n, l, mid);
        mergeSort(arr,n, mid + 1, up);

        // Merge the sorted halves
        merge(arr,n, l, mid, up);
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
    mergeSort(arr,n, 0, n - 1);

    printarray(arr,n);
    return 0;
}
