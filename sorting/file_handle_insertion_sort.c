//use the file input_data.txt as input data
//time complexity for insertion sort is
//0(n) in best and 0(n^2) in average and worst case 

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//defining the insertion_sort function
void insertion_sort(int array[], int size)
{
    //first element is already sorted
    for(int i=1; i<size; i++)
    {
        int j=i-1;
        //hole element
        int hole= array[i];

        //comparing the ith element
        //with the previous elements
        while(j>=0 && array[j]>hole)
        {
            //shifting the larger elements towards right
            array[j+1]= array[j];
            j--;
        }

        //placing the hole element at its correct position
        array[j+1]= hole;
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

    //calling the insertion_sort function
    //to sort the array
    insertion_sort(array, size);

    //calling the function time
    end= time(NULL);

    printf("Time taken by the insertion sort is %lf micro seconds.", difftime(end,start)*1000*1000);

    //writing the sorted array in a new file
    //with name insertion_sort_output.txt
    fptr= fopen("C:\\Users\\adarsh\\Desktop\\DAA LAB\\insertion_sort_output.txt","w");

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
Time taken by the insertion sort is 2000000.000000 micro seconds.
*/
