//use the file input_data.txt as input data
//time complexity for randomized quick sort is
//0(nlogn) in best, average and worst case 
//and space complexity is O(1)

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//defining the heart of the random_quick_sort
//that is partition function
int partition(int array[], int l, int r)
{
    //choosing the last element of the array
    //as pivot element
    int pivot= array[r];

    //take the two pointers as i and j
    //i is used to point the current element 
    //which is less than the pivot element
    int i=l-1;
    int j=l;

    //traversing the array
    for(;j<r; j++){
        if(array[j]<=pivot)
        {
            i++;
            //swapping the values
            int temp= array[j];
            array[j]= array[i];
            array[i]= temp;
        }
    }
    //place the pivot element at its correct position
    i++;
    int temp= array[i];
    array[i]= array[r];
    array[r]= temp;

    //return the correct index of the pivot element
    return i;
}

//defining the random_quick_sort function
void random_quick_sort(int array[], int l,int r)
{
    if(l>=r) return;
    else{
        //swapping the random values
        int temp= array[l];
        array[l]= array[(l+r)/2];
        array[(l+r)/2]= temp;

        //calling the function partition
        //it will return the correct position 
        //of the last element that is array[r] 
        int p_index= partition(array, l,r);

        //calling the function random quick sort
        random_quick_sort(array,l,p_index-1);
        random_quick_sort(array, p_index+1, r);
    }
}

int main(void)
{
    //creating a file pointer
    FILE* fptr;

    //opening a file to read the input data
    //and store its in the dynamic array
    fptr= fopen("C:\\Users\\adarsh\\Desktop\\DAA LAB\\input_data.txt","r");

    //input the size of the data
    int size=0;
    printf("Enter the size of the data: ");
    scanf("%d",&size);

    //allocating the memory for the array
    int* array=(int*)calloc(size,sizeof(int));

    for(int i=0; i<size; i++){
        //getting the data in the array
        //using fscanf function
        fscanf(fptr,"%d ",&array[i]);
    }

    //closing the file 
    fclose(fptr);

    //creating variable of type time_t
    time_t start, end;

    //calling the function time
    start= time(NULL);

    //calling the random_quick_sort function
    //to sort the array
    random_quick_sort(array, 0, size-1);

    //calling the function time
    end= time(NULL);

    printf("Time taken by the random_quick sort is %lf micro seconds.", difftime(end,start)*1000*1000);

    //writing the sorted array in a new file
    //with name random_quick_sort_output.txt
    fptr= fopen("C:\\Users\\adarsh\\Desktop\\DAA LAB\\random_quick_sort_output.txt","w");

    for(int i=0; i<size; i++){
        fprintf(fptr,"%d ",array[i]);
    }

    //free the array pointer
    free(array);

    //closing the file 
    fclose(fptr);

return 0;
}

/*Sample Output
Enter the size of the data: 32000
Time taken by the random_quick sort is 0.000000 micro seconds.
*/
