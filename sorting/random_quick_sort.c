//program with randomize quick sort on array
//average case complexity is O(nlogn)
//space complexity is O(1)
//worst case complexity is O(nlogn)

#include<stdio.h>
#include<stdlib.h> //to allocate the memory dynamically

//defining the heart of the quick_sort function
//that is the partition function
int partition(int array[], int l, int r)
{
    //creating the pivot element
    //as the last element of the array
    int pivot= array[r];

    //pointer to get the last smallest element than pivot element
    int i=l-1;
    int j=l;
    //comparing the elements with the pivot element
    for(;j<r;j++)
    {
        if(pivot>=array[j])
        {
            i++;
            //swapping the element at the ith position with jth element
            //if we will swap without using third variable 
            //then problem will arise because we will be updating
            //the value at same index twice when i==j
            int temp= array[i];
            array[i]= array[j];
            array[j]=temp;
        }
    }
    i++;
    //swap the element at the ith and rth position
    int temp= array[i];
    array[i]= array[r];
    array[r]=temp;

    return i;
}

void quick_sort(int array[], int l, int r)
{
    //base condition
    if(l>=r) return;
    else{
        //swapping the random element in the unsorted array
        int r_index=(l+r)/2;
        int temp= array[r_index];
        array[r_index]= array[r];
        array[r]= temp;
        int p_index= partition(array,l,r);//divide
        
        //calling the quick_sort function for two partitions
        quick_sort(array,l,p_index-1);  //first half
        quick_sort(array,p_index+1,r);  //second half
    }
}

int main(void)
{
    //input the size of the array
    int size=0;
    printf("Enter the size of the array: ");
    scanf("%d",&size);

    //allocating the memory dynamically for the array
    int* array= (int*)calloc(size,sizeof(int));

    //input the elements
    printf("Enter the elements: ");
    for(int i=0; i<size;i++)
    {
        scanf("%d",&array[i]);
    }

    //calling the quick sort function
    quick_sort(array,0,size-1);

    //print the sorted array
    printf("Sorted array is: ");
    for(int i=0; i<size;i++)
    {
        printf("%d ",array[i]);
    }
}