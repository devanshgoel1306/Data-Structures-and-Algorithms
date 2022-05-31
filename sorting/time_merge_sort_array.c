//program on merge sort
//using array
#include<stdio.h>
#include<stdlib.h> //for allocating the memory dynamically
#include<time.h>

//function to merge the sub array in ascending order
void merge(int array[], int lower, int mid, int upper){
//array to store sub sorted array
int a[mid-lower+1], b[upper-mid];

//copy the data in the temporary array
int i=0;
for(; i<mid-lower+1; i++){
    a[i]=array[lower+i];
}
i=0;
for(;i<upper-mid;i++){
    b[i]=array[mid+1+i];
}

//pointers to point the array a and b's current element
int p=0,q=0;
//pointer to point the current element of the actual array
i=lower;

while(p<mid-lower+1 && q<upper-mid){
    if(a[p]<b[q]){
        array[i]=a[p];
        //increment the value of p and i
        p++; i++;
    }
    else{
        array[i]=b[q];
        //increment the value of q and i
        q++; i++;
    }
}
//add the remaining element
while(p<mid-lower+1){
    array[i]=a[p];
    p++; i++;
}
while(q<upper-mid){
    array[i]=b[q];
    q++; i++;
}
}
//function to sort the array
void merge_sort(int array[], int lower, int upper)
{
    if(lower<upper)
    {
        int mid=(lower+upper)/2;  //divide
        merge_sort(array,lower,mid ); //conquer
        merge_sort(array,mid+1,upper); //conquer

        merge(array,lower,mid,upper); //combine

    }
}
//function to get the best case input
//i.e., array is already sorted
void best_input(int array[], int size){
int i=0;
for(;i<size;i++){
    array[i]=i;
}
//input is like 0,1,2,3,..,size-1
}

//function to get the average case input
//i.e., array is in random fashion
void avg_input(int array[], int size){
int i=0;
for(;i<size;i++){
    array[i]=i%5;
}
//input is like 0,1,2,3,4,0,1,2,3,4..
}

//function to get the worst case input
//i.e., array is in descending order
void worst_input(int array[], int size){
int i=0;
for(;i<size;i++){
    array[i]=size-i;
}
//input is like size,size-1, size-2,..1
}

int main(void)
{
    printf("Enter the size of the array: ");
    int size=0;
    scanf("%d",&size);

    //allocating the memory for the array
    int* array=(int*)calloc(size,sizeof(int)); //calloc initializes all the element with 0

    //assigning the array for best case
    best_input(array,size);

    //creating time_t variables
    time_t start, end;

    //calling the function time
    start= time(NULL);

    //calling the function merge_sort
    merge_sort(array,0,size-1);

    //calling the function time
    end= time(NULL);

    printf("Time taken in best case is %lf ns.\n\n",(double)difftime(end,start)*1000*1000*1000);

    //assigning the array for average case
    avg_input(array,size);

    //calling the function time
    start= time(NULL);

    //calling the function merge_sort
    merge_sort(array,0,size-1);

    //calling the function time
    end= time(NULL);

    printf("Time taken in average case is %lf ns.\n\n",(double)difftime(end,start)*1000*1000*1000);

    //assigning the array for worst case
    worst_input(array,size);

    //calling the function time
    start= time(NULL);

    //calling the function merge_sort
    merge_sort(array,0,size-1);

    //calling the function time
    end= time(NULL);

    printf("Time taken in worst case is %lf ns.\n",(double)difftime(end,start)*1000*1000*1000);


    //free the array pointer
    free(array);
    return 0;

}

/*Sample Output
Enter the size of the array: 500000
Time taken in best case is 0.000000 ns.

Time taken in average case is 0.000000 ns.

Time taken in worst case is 0.000000 ns.
*/
