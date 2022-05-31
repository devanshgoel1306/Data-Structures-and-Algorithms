//program to sort the list in ascending order using insertion sort
//and calculating worst case complexity
//when the array is in descending order
//which is O(n^2)
#include<stdio.h>
#include<time.h> //for using time_t data type and time function
#include<stdlib.h> //for allocating the memory dynamically

void insertion_sort(int arr[], long int len)
{
    //since first element is already sorted
    int i=1;
    //picking each element one by one
    for(;i<len; i++){
        //key value
        int key= arr[i];
        //checking from the previous elements
        int j=i-1;
        //comparing the key element with previous elements
        while(arr[j]>key&&j>=0)
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

    //worst case occurs when the array is in descending order
    //and we want it in ascending order
    int i=0;
    //assigning the value as size,size-1,size-2,...
    for(;i<size; i++){
        arr[i]=32000-i;
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
    printf("Total time taken by the insertion_sort in worst case is %lf ms.\n",(double)(difftime(end,start))*1000);


    //free the arr pointer
    free(arr);

return 0;
}
/*Sample Output
Enter the size of the array: 32000
Total time taken by the insertion_sort in worst case is 1000.000000 ms.
*/
