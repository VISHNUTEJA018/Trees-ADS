#include<stdio.h>
int min(int a,int b)
{
    return (a<b)?a:b;
}
int fibonacciSearch(int a[], int n, int key)
{

    int fib2 = 0;  
    int fib1 = 1; 
    int fibM = fib1 + fib2;  
    
    while (fibM < n) 
    {
        fib2 = fib1;
        fib1 = fibM;
        fibM = fib1 + fib2;
    }
    int offset = -1;
    while (fibM > 1)
    {
        int i = min(offset + fib2, n - 1);
        if (a[i] < key)
        {
            fibM = fib1;
            fib1 = fib2;
            fib2 = fibM - fib1;
            offset = i;
        }
        else if (a[i] > key)
        {
            fibM = fib2;
            fib1 = fib1 - fib2;
            fib2 = fibM - fib1;
        }
        else
        {
            return i;
        }
    }
    if (fib1 && a[offset + 1] == key)
    {
        return offset + 1;
    }
    return -1;
}
int main()
{
    int n,key;
    
    printf("Enter the size of the array: ");
    scanf("%d",&n);

    int a[100];
    printf("Enter the elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);    
    }
    printf("\n");
    
    printf("Enter the key value: ");
    scanf("%d",&key);

    int result = fibonacciSearch(a,n,key);

    if(result!=-1)
    {
        printf("............Element found..........\n");
    }
    else
    {
        printf("...........Element Not found...........\n");
    }
    return 0;
}
