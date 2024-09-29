#include<stdio.h>
#include<stdlib.h>
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
    int n,ch,key;
    int a[100];

    while(1)
    {
        printf("1.Search.\n");
        printf("2.exit\n");
        printf("3.create array:\n");        
        printf(" Enter your choise:");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("Enter the key element to search: ");
                    scanf("%d",&key);
                    int result=fibonacciSearch(a,n,key);
                    if(result!=-1)
                    {
                        printf("key found at index %d\n",result);
                    }
                    else
                    {
                        printf("Element not found.\n");
                    }
                    break;
            case 2: exit(0);

            case 3: printf("Enter the size of the array: ");
                    scanf("%d",&n);

                    printf("Enter array elements:");
                    for(int i=0;i<n;i++)
                    {
                        scanf("%d",&a[i]);
                    }
                    break;

            default: printf("Invalid choise\n");
        }

    }
    return 0;
}
