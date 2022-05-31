//problem link- https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

#include <stdio.h>

void sort012(int a[], int n)
{
    long int i=0, count_0=0, count_1=0, count_2=0;
    
    for(i=0;i<n;i++){
        if(a[i] == 0) count_0+=1;
        else if(a[i] == 1) count_1+=1;
        else count_2+=1;
    }
    
    i=0;
    while(count_0--){
        a[i]= 0;
        i++;
    }
    while(count_1--){
        a[i]= 1;
        i++;
    }
    while(count_2--){
        a[i]= 2;
        i++;
    }

}
int main() {

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d", &arr[i]);
        }
        sort012(arr, n);

        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    return 0;
}