//program using time() and time_t data type
//merge sort
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void merge(int arr[], int l, int mid, int r){
    //creating sub-unsorted array
    int a[mid-l+1], b[r-mid];
    //pointers for sorting
    int p=0; int q=0;
    
    //storing the unsorted values
    for(int i=0; i<mid-l+1; i++){
        a[i]=arr[l+i];
    }
    for(int i=0; i<r-mid; i++){
        b[i]=arr[mid+1+i];
    }
    
    int i=l;
    while(p<mid-l+1 && q<r-mid){
        if(a[p]<b[q]){
            arr[i]= a[p];
            p++;
        }
        else{
            arr[i]= b[q];
            q++;
        }
        i++;
    }
    while(p<mid-l+1){
        arr[i]= a[p];
        p++; i++;
    }

    while(q<r-mid){
        arr[i]= b[q];
        q++; i++;
    }
}

void merge_sort(int arr[], int l, int r){
    if(l<r){
        int mid=(l+r)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,r);
        
        //calling the merge function to get sub sorted array
        merge(arr, l, mid, r);
    }
}

int main(void){
    int size=0;
    printf("Input the size of the array: ");
    scanf("%d",&size);

    //allocating the memory dynamically for the array
    int* arr=(int*)calloc(size,sizeof(int));

    if(arr==NULL){
        printf("Sorry!\n");
    }

    //input the elements in the array
    for(int i=0; i<size; i++){
        arr[i]= size-i;
    }

    //creating variable of type time_t to store the execution time taken
    //by the merge sort algorithm
    time_t start, end;

    //calling the function time to get the calendar time
    start=time(NULL);

    //calling the merge sort function
    merge_sort(arr,0,size-1);

    //calling the function time to get the calendar time
    end=time(NULL);

    printf("Time taken by the merge sort is %lf ns.\n", (double)difftime(end,start)*1000000000);

    //free the pointer arr
    free(arr);
}

/*Sample Output
Input the size of the array: 32000
Time taken by the merge sort is 0.000000 ns.
*/

