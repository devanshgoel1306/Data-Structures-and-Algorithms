//program with quick sort on array
//average case complexity is O(nlogn)
//space complexity is O(1)
//worst case complexity is O(n*n)
//because it will traverse n-i times for n times
//ex- when array is already sorted

#include<stdio.h>
#include<stdlib.h> //to allocate the memory dynamically

//from NARASIMHA KARUMANCHI
//defining the heart of the quick_sort function
//that is the partition function
//in which pivot element is considered to be at index l
/*int partition(int array[], int l, int r){
    int left, right, pivot= array[l];

    left= l+1;
    right= r;
    while(left<right){

        while(array[left]<pivot) left++;

        while(array[right]>pivot) right--;

        if(left<right){
            int temp= array[left];
            array[left]= array[right];
            array[right]= temp;
        }
    }

    array[l]= array[right];
    array[right]= pivot;

    return right;
}*/

//pivot element is considered to be at index r
int partition(int array[], int l, int r){
    int left, right, pivot= array[r];

    left= l;
    right= r-1;
    while(left<right){

        while(array[left]<pivot) left++;

        while(array[right]>pivot) right--;

        if(left<right){
            int temp= array[left];
            array[left]= array[right];
            array[right]= temp;
        }
    }

    array[r]= array[left];
    array[left]= pivot;

    return left;
}

void quick_sort(int array[], int l, int r)
{
    //base condition
    if(l>=r) return;
    else{
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

    free(array);
    return 0;
}

/*Sample Output
Enter the size of the array: 9
Enter the elements: 10 1 2 3 18 12 2 4 5
Sorted array is: 1 2 2 3 4 5 10 12 18
*/
