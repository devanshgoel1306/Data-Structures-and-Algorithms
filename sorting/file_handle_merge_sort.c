//gettting the input data from input_data.txt file
//we are using merge_sort technique to sort 
//the data. Time complexity is O(nlogn)
//and space complexity is O(n)

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//defining the heart of the merge sort
//that is merge function
void merge(int array[], int l, int mid, int r)
{
    //creating the temporary arrays to store the
    //two halfs of the array
    int a[mid-l+1], b[r-mid];

    //assigning the data to the arrays
    for(int i=0; i<mid-l+1; i++){
        a[i]= array[l+i];
    }
    for(int i=0; i<r-mid; i++){
        b[i]= array[mid+1+i];
    }

    //temporary pointers to get the array sorted
    int p=0,q=0;
    //pointing to the current element of the array
    int i=l;

    while(p<mid-l+1 && q<r-mid){
        if(a[p]>b[q])
        {
            array[i]= b[q];
            //increment the pointer by 1
            
            q++;
        }
        else{
            array[i]= a[p];
            //increment the pointer by 1
            p++;
        }
        i++;
    }

    //adding the remaining elements to the array
    while(p<mid-l+1)
    {
        array[i]= a[p];
        p++;
        i++;
    }
    while(q<r-mid)
    {
        array[i]= b[q];
        q++;
        i++;
    }
}

//defining the function for the merge_sort
void merge_sort(int array[], int l, int r)
{
    if(l>=r) return;
    else{
        //dividing the array into two parts
        int mid= (l+r)/2;
        merge_sort(array,l,mid); //first half
        merge_sort(array,mid+1,r); //second half

        //conquering or sorting the sub arrays
        merge(array,l,mid,r);
    }
}

int main(void){

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

//calling the merge_sort function
//to sort the array
merge_sort(array, 0, size-1);

//calling the function time
end= time(NULL);

printf("Time taken by the merge sort is %lf micro seconds.", difftime(end,start)*1000*1000);

//writing the sorted array in a new file
//with name merge_sort_output.txt
fptr= fopen("C:\\Users\\adarsh\\Desktop\\DAA LAB\\merge_sort_output.txt","w");

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
Time taken by the merge sort is 0.000000 micro seconds.
*/
