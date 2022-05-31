//in-place merge sort
//with Time Complexity O(n^2)
//space Complexity O(1)
#include<stdio.h>
#include<stdlib.h>

void merge(int array[], int l, int mid, int r)
{
    //pointers to point the two halves of the array
    int p=l,q=mid+1;

    while(p<=mid && q<r+1)
    {
        if(array[q]<=array[p])
        {
            int hole_value= array[q];
            //shift the elements towards right
            int i=q;
            for(;i>p;i--)
            {
                array[i]=array[i-1];
            }
            array[p]=hole_value;
        }
        q++;
        p++;
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

/*Sample Output 1
Enter the size of the array: 5
enter the elements: 1 2 3 4 5
The sorted array is : 1 2 3 4 5 

Sample Output 2
Enter the size of the array: 5
enter the elements: 5 4 3 2 1
The sorted array is : 1 2 3 4 5

Sample Output 3
Enter the size of the array: 5
enter the elements: 9 88 88 7 9
The sorted array is : 7 9 9 88 88 
*/
