//sorting technique based on cards game
#include<stdio.h>
#include<stdlib.h>

void insertion_sort(int arr[], int length)
{
    for(int i=1; i<length; i++)
    {
        //key element from the sub-unsorted array
        int key= arr[i];

        //counter variable to traverse through sub-sorted array
        int j=i-1;
        //getting the correct position for the key element
        while(j>=0 && arr[j]>key)
        {
            //shifting the greater elements towards right
            arr[j+1]= arr[j];
            //update the value of the variable j
            j-=1;
        }
        //put the key element at it's correct position in sub-sorted array
        arr[j+1]= key;
    }
}
int main(void)
{
    int n;
    //input the no. of elements in the array
    printf("Enter the no. of elements in the array: ");
    scanf("%d", &n);

    //allocating the memory dynamically for the array
    int* arr= (int*)calloc(n, sizeof(int));

    printf("Enter the elements: ");
    //input the elements of the array
    for(int i=0; i<n; i++)
    {
        scanf("%d", arr+i);
    } 

    //calling the insertion_sort function for sorting
    insertion_sort(arr, n);

    //print the sorted array
    printf("Sorted array: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    } 
}
/*Sample Output
Enter the no. of elements in the array: 5
Enter the elements: 9 8 7 6 5
Sorted array: 5 6 7 8 9
*/