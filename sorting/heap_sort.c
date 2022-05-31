//use the file input_data.txt as input data
//time complexity for heap sort is
//O(nlogn)
//time complexity of max-heapify is O(logn or h)
//for build-max heap is O(n)

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//defining the max_heapify function
//here i is the index of the parent 
//size is the length  of the array
void max_heapify(int array[], int i, int size)
{
    //variable to store the index of the largest
    //element by comparing parent and its children
    int largest=i;
    //index of the left child
    int l=2*i+1;
    //index of the right child
    int r=2*i+2;

    //check if the left child exists
    //we are first checking the existence of the left child
    //because it is the property of the heap data structure
    //that if left child does not exist then right child
    //will also not exist 
    if(l<size)
    {
        //check if the left child is greater than the parent
        if(array[l]>array[i]) 
        {
            //left child is greater than the parent
            largest=l;
        }
        //if parent is greater than the left child
        else{
            largest=i;
        }
    }
    else{
        return ;
    }

    //check if the right child exists
    if(r<size)
    {
        //check if the right child is greater than the element largest
        if(array[r]>array[largest]) 
        {
            //right child is greater than the parent
            largest=r;
        }
    }

    //if the parent is not largest
    if(largest!=i)
    {
        //exchange the position of the largest element
        //with parent to obtain sub max-heap
        int temp=array[i];
        array[i]=array[largest];
        array[largest]=temp;

        //calling the max-heapify function again
        max_heapify(array,largest,size);
    }


}

//defining the build_max_heap function
//this function is used to make sub max heaps
//in the heap using max_heapify function. It targets all the internal 
//nodes for doing this.
void build_max_heap(int array[], int size)
{
    //maximum index of the internal node
    //possible
    //we take floor value of size/2-1
    int i=(size/2)-1;
    //printf("maximum index of internal node: %d\n",i);

    //traversing all the internal nodes
    while(i>=0)
    {
        /*for(int j=0;j<size;j++)
    {
        printf("%d ",array[j]);
    }
        printf("\n");*/
        max_heapify(array,i,size);
        i--;
    }
}

//defining the heap_sort function
void heap_sort(int array[], int size)
{
    //calling build_max_heap
    build_max_heap(array,size);
    
    int i=0;
    /*for(i=0;i<size;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");*/
    for(i=0;i<size-1;i++)
    {
        //interchange the value of first and last element
        int temp= array[0];
        array[0]= array[size-i-1];
        array[size-i-1]= temp;
        //printf("\nroot: %d last:%d\n",array[0],array[size-i-1]);

        //calling the max_heapify function
        max_heapify(array,0,size-i-1);

        /*for(int j=0;j<size;j++)
        {
            printf("%d ",array[j]);
        }
        printf("\n");*/
    }
}


int main(void)
{
    //creating a file pointer
    FILE* fptr;

    //opening a file to read the input data
    //and store its data in the dynamic array
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

    //calling the heap_sort function
    //to sort the array
    heap_sort(array, size);

    //calling the function time
    end= time(NULL);

    printf("Time taken by the heap sort is %lf micro seconds.", difftime(end,start)*1000*1000);

    //writing the sorted array in a new file
    //with name heap_sort_output.txt
    fptr= fopen("C:\\Users\\adarsh\\Desktop\\DAA LAB\\heap_sort_output.txt","w");

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
Time taken by the heap sort is 0.000000 micro seconds.
*/
