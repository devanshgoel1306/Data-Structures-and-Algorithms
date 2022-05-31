//merge sort
//with Time Complexity O(nlog n)
//space Complexity O(n)
#include<stdio.h>
#include<stdlib.h>

void merge(int array[], int l, int mid, int r)
{
    //creating the temporary arrays
    int a[mid-l+1],b[r-mid];

    //copy the elements in the array a and b
    int i=0;
    for(;i<mid-l+1;i++){
        a[i]=array[l+i];
    }
    i=0;
    for(;i<r-mid;i++){
        b[i]=array[mid+i+1];
    }

    //pointing variables for array a and b
    int p=0,q=0;
    i=l;
    while(p<mid-l+1 && q<r-mid)
    {
        if(a[p]<b[q])
        {
            array[i]= a[p];
            //increasing the pointer
            p++;
            i++;
        }
        else{
            array[i]= b[q];
            //increasing the pointer
            q++;
            i++;
        }
    }

    //if some elements left in array a or b
    while(p<mid-l+1)
    {
        array[i]= a[p];
        i++; p++;
    }
    while(q<r-mid){
        array[i]= b[q];
        i++; q++;
    }
}

void merge_sort(int array[], int l, int r){
if(l<r)
{
    int mid=(l+r)/2;
    merge_sort(array,l,mid); //divide
    merge_sort(array,mid+1,r); //divide

    merge(array,l,mid,r); //conquer
}
}

int main(void)
{
    int size=0;
    printf("Enter the size of the array: ");
    scanf("%d",&size);

    //allocating the the memory dynamically for the array
    int* array=(int*)calloc(size,sizeof(int));

    int i=0;
    printf("enter the elements: ");
    //input the elements
    for(;i<size;i++){
        scanf("%d",&array[i]);
    }

    //calling the merge_sort function
    merge_sort(array,0,size-1);

    printf("The sorted array is : ");
    //print the sorted array
    i=0;
    for(;i<size;i++){
        printf("%d ",array[i]);
    }
}
