//problem link- https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1
#include <stdio.h>

void rotate(int arr[], int n);

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n] , i;
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        rotate(a, n);
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
        return 0;
}


void rotate(int arr[], int n)
{
    //store the value of the last element
    //of the array in a variable
    int last= arr[n-1];
    
    for(int i=n-1; i>0; i--){
        arr[i]= arr[i-1];
    }
    arr[0]= last;
    
    return arr;
}