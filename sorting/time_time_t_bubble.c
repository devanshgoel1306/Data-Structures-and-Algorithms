//program using time_t data type and time(), difftime() function 
//sorting used is bubble sort
//time complexity in worst, best and avg. is O(n^2)
//sample output in last
#include<stdio.h>
#include<stdlib.h> //for dynamic memory allocation
#include<time.h>

void bubble_sort(int arr[], int len){
    for(int i=0; i<len; i++){
        for(int j=0; j<len-i-1; j++){
            if(arr[j]>arr[j+1]){
                //swap the values
                arr[j]=arr[j]+arr[j+1];
                arr[j+1]=arr[j]-arr[j+1];
                arr[j]=arr[j]-arr[j+1];
            }
        }
    }
}

int main(void){
    //input the size of the array
    int size=0;
    printf("Enter the size of the array: ");
    scanf("%d",&size);

    //allocating the memory dynamically
    int* arr= (int*)calloc(size, sizeof(int));

    //input the data in the array
    for(int i=0; i<size; i++){
        arr[i]=size-1;
    }

    //creating the variables of type time_t
    time_t start, end;
    //calling the function time
    start= time(NULL);
    //calling the bubble sort function
    bubble_sort(arr, size);

    //calling the function time
    end= time(NULL);

    //time taken by the bubble sort
    printf("Time taken by the bubble sort is %lf s",difftime(end,start));


}

/*Sample Output
Enter the size of the array: 100000
Time taken by the bubble sort is 22.000000 s
*/