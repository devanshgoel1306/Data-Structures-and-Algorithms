#include <stdio.h>
#include<stdlib.h>

void merge(int arr[], int l, int mid, int r){
    //creating sub-unsorted array
    int a[mid-l+1], b[r-mid];
    //pointers for sorting
    int p=0; int q=0;
    
    //storing the unsorted values
    for(int i=0; i<mid-l+1; i++){
        a[i]=arr[l+i];
    }
    for(int i=0; i<r-mid; i++){
        b[i]=arr[mid+1+i];
    }
    
    int i=l;
    while(p<mid-l+1 && q<r-mid){
        if(a[p]<b[q]){
            arr[i]= a[p];
            p++;
        }
        else{
            arr[i]= b[q];
            q++;
        }
        i++;
    }
    while(p<mid-l+1){
        arr[i]= a[p];
        p++; i++;
    }

    while(q<r-mid){
        arr[i]= b[q];
        q++; i++;
    }
}

void merge_sort(int arr[], int l, int r){
    if(l<r){
        int mid=(l+r)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,r);
        
        //calling the merge function to get sub sorted array
        merge(arr, l, mid, r);
    }
}
int main()
{
    int no_of_elem=0;
    printf("Enter the no. of elements: ");
    scanf("%d",&no_of_elem);
    
    int *array=(int*)calloc(no_of_elem,sizeof(int));
    
    //input the elements
    printf("Enter the elements: ");
    for(int i=0; i<no_of_elem; i++){
        scanf("%d",&array[i]);
    }
    
    //calling the function merge_sort
    merge_sort(array,0,no_of_elem-1);
    
    //print the elements
    printf("Sorted array is ");
    for(int i=0; i<no_of_elem; i++){
        printf("%d ",array[i]);
    }
    
    //free the pointer
    free(array);
    
    return 0;
}