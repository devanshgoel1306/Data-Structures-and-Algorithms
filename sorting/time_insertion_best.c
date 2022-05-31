//program to sort the list in ascending order using insertion sort
//and calculating best case complexity
//when the array is already sorted
//which is O(n)
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void insertion_sort(int arr[], int len)
{
    //since first element is already sorted
    int i=1;
    //picking each element one by one
    for(;i<len; i++){
        //key value
        int key= arr[i];
        //checking with the previous elements
        int j=i-1;
        //comparing the key element with previous elements
        while(arr[j]>arr[j+1]&&j>=0)
        {
            //shift the element towards right
            arr[j+1]=arr[j];
            //decrementing value of variable j
            j-=1;
        }
        //put the key value at it's correct position
        arr[j+1]=key;
    }
}
int main(void)
{
    //input the size of array
    int size=0;
    printf("Enter the size of the array: ");
    scanf("%d",&size);

    //allocating the memory dynamically for the array
    int * arr=(int*)calloc(size,sizeof(int));

    //best case occurs when the array is already in sorted order
    int i=0;
    for(;i<size; i++){
        arr[i]=i;
    }

    //creating variables of data type time_t
    time_t start, end;
    //calling the function time
    //to get the calendar time
    start= time(NULL);

    //calling the function insertion_sort
    insertion_sort(arr, size);

    //calling the function time
    //to get the calendar time
    end= time(NULL);

    //print the total execution time take by the insertion_sort
    printf("Total time taken by the insertion_sort in best case is %lf ms.\n",difftime(end,start)*1000);

return 0;
}
/*Sample Output
Enter the size of the array: 32000
Total time taken by the insertion_sort in best case is 0.000000 ms.
*/
