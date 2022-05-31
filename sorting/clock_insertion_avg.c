//program to sort the list in ascending order using insertion sort
//and calculating average case complexity
//when the array is in random order
//which is O(n^2)
#include<stdio.h>
#include<time.h> //for using clock_t data type and clock function and CLOCKS_PER_SEC macro
#include<stdlib.h> //for allocating the memory dynamically

void insertion_sort(int arr[], int len)
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

    for(;i<size; i++){
        arr[i]=(size-i)%5;
    }

    //creating variables of data type clock_t
    clock_t start, end;
    //calling the function clock
    //to get the no. of processor clocks
    start= clock();

    //calling the function insertion_sort
    insertion_sort(arr, size);

    //calling the function clock
    //to get the no. of processor clocks
    end= clock();

    //print the total execution time take by the insertion_sort
    printf("Total time taken by the insertion_sort in average case is %f ms.\n",(double)((end-start)/CLOCKS_PER_SEC)*1000);

    //free the arr pointer
    free(arr);

return 0;
}
/*Sample Output 1
Enter the size of the array: 32000
Total time taken by the insertion_sort in average case is 0.000000 ms.
*/
/*Sample Output 2
Enter the size of the array: 320000
Total time taken by the insertion_sort in average case is 102000.000000 ms.
*/

