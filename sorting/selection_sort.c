//finding the smallest element in the sub-unsorted array
//place the smallest element in it's correct position
//sorting technique based on cards game
#include<stdio.h>
#include<stdlib.h>

void selection_sort(int arr[], int length)
{
    for(int i=0; i<length-1; i++)
    {
        //assuming the first element of the sub-unsorted array to be smallest
        int min= arr[i];

        //counter variable to traverse through sub-unsorted array
        int j=i+1;
        //temporary variable to store the position of the smallest element in sub-unsorted array
        int temp= i;
        //getting the position of smallest element in sub-unsorted array
        while(j<length)
        {
            if(arr[j]<min) 
            {
                min= arr[j]; temp= j;
            }
            
            //update the value of the variable j
            j+=1;
        }
        //swapping the ith element and the (i+1)th smallest element
        if(temp!=i)
            {
                arr[i]= arr[i]+arr[temp];
                arr[temp]= arr[i]-arr[temp];
                arr[i]= arr[i]-arr[temp];
            }
    }
}
int main(void)
{
    int n=0;
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
    selection_sort(arr, n);

    //print the sorted array
    printf("Sorted array: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    } 
}