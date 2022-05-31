#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//defining the function for bubble sort
//worst and avg. time comlexity is O(n^2)
//best case when array is already sorted O(n)
void bubble_sort(int arr[], int len)
{
    //flag variable to check if swap occurs inside inner for loop or not
    int flag=1;
    for(int i=0; i<len; i++)
    {
        for(int j=i; j<len-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                //swap the elements
                arr[j]=arr[j]+arr[j+1];
                arr[j+1]=arr[j]-arr[j+1];
                arr[j]=arr[j]-arr[j+1];
                flag=0;
            }
        }
        if(flag)
        {
            break;
        }
    }
}

//defining the function for insertion sort
//worst and avg. time comlexity is O(n^2)
//best case when array is already sorted O(n)
void insertion_sort(int arr[], int len)
{
    int key=0, j=0;

    for(int i=1; i<len-1; i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            //swap the elements
            arr[j+1]=arr[j];
            j-=1;
        }
        arr[j+1]=key;
    }
}

//defining the function for selection sort
//worst, best and avg. time comlexity is O(n^2)
void selection_sort(int arr[], int len){
    int min=0, index=0;
    for(int i=0; i<len-1; i++)
    {
        min=arr[i];
        index=i;
        for(int j=i+1; j<len; j++)
        {
            //if the element is larger
            if(min>arr[j]){
                index=j;
                min=arr[j];
            }
        }
        //swap the elements
        arr[index]=arr[i];
        arr[i]=min;
    }
}

int main()
{
    time_t start, end;
    start= time(NULL);

    //declaring an array of size 20
    int* array= (int*)calloc(20, sizeof(int));
    printf("Options available\n1.Insertion in begin\n2.Insertion in middle\n3.Insertion at the end\n");
    printf("4.Delete first \n5.Delete from the end\n6.Delete from middle\n7.Display\n8.Search an element\n9.Sorting using bubble sort\n");
    printf("10.Sorting using insertion sort\n11.Sorting using selection sort\n12.Length of the array\n13.Merging in end\n14.Execution time\n15.Exit\n");

    //variable to store the current length of the array
    int length=0;
    //variable to store the choice
    int choice;
    //variable to store the element
    int elem=0;
    //variable to store the positions
    int pos=0;
    //flag variable for searching
    int flag=1;
    //variable to store the length of second array
    int length2=0;

    do{
        int flag2=0;
        
        printf("Operation: ");
        scanf("%d",&choice);

        //if the choice is insertion
        if(choice==1 || choice==2|| choice==3)
        {
            printf("Enter the element: ");

            scanf("%d",&elem);
            length+=1;
        }
        else if(choice==4 || choice==5 ||choice==6){
            length-=1;
        }
        else if(choice==8){
            printf("Enter the element: ");

            scanf("%d",&elem);
        }
        else if (choice==13)
        {
            flag2=1;
            printf("Enter the size of 2nd array: ");

            scanf("%d",&length2);
        }

        //allocating the memory dynamically for second array
        int* b;
        b= (int*)calloc(length2, sizeof(int));

        //input the elements of the second array
        if(length2!=0 && flag2)
        {
            printf("Enter the elements of the 2nd array: ");
            for(int i=0; i<length2; i++)
            {
                scanf("%d",&b[i]);
            }
            flag2=0;
        }
        
        switch(choice)
        {
            case 1:
            //insertion in the beginning
            //shifting the elements to the right
            for(int i=length; i>0; i--)
            {
                array[i]=array[i-1];
            }
            array[0]=elem;
            break;
            
            case 2:
            //insertion at position pos
            printf("Enter the position: ");
            scanf("%d",&pos);
            //if the position is positive and less than the length of the array
            if(pos>0 && pos<=length)
            {
                for(int i=length; i>pos-1; i--)
                {
                    array[i]=array[i-1];
                }
                array[pos-1]=elem;
            }
            else {
                printf("You have entered invalid position.\n");
            }
            break;

            case 3:
            //insertion at the end
            array[length-1]=elem;
            break;

            case 4:
            //deleting the first element
            printf("Deleted element: %d\n",array[0]);
            //shifting the elements to the right of the array
            for(int i=0; i<length; i++)
            {
                array[i]=array[i+1];
            }
            break;

            case 5:
            length+=1;
            //deleting the last element
            printf("Deleted element: %d\n",array[length-1]);
            length-=1;
            break;

            case 6:
            //deleting the element at position pos
            printf("Enter the position: ");
            scanf("%d",&pos);
            
                for(int i=pos-1; i<length; i++)
                {
                    array[i]=array[i+1];
                }
            break;
            
            case 7:
            for(int i=0; i<length; i++)
            {
                printf("%d  ",array[i]);
            }
            printf("\n");
            break;

            case 8:
            for(int i=0; i<length; i++)
            {
                if(elem==array[i])
                {
                    printf("Element found at position: %d\n", i+1);
                    flag=0;
                    break;
                }
            }
            if(flag)
            {
                printf("Element not found!\n");
            }
            flag=1;
            break;

            case 9:
            bubble_sort(array, length);
            break;

            case 10:
            insertion_sort(array, length);
            break;

            case 11:
            selection_sort(array, length);
            break;

            case 12:
            printf("Length of the array: %d\n",length);
            break;

            case 13:
            //adding the elements in the end
            for(int i=length; i<length+length2; i++)
            {
                array[i]=b[i-length];
            }
            //update the length value
            length+=length2;
            free(b);
            break;

            case 14:
            end=time(NULL);
            printf("%.5fs\n",difftime(end, start));
            break;

            case 15:
            free(array);
            exit(0);
            break;
            
            default:
            printf("You have entered wrong choice!");
        }
        

    }while(1);
    
    return 0;
}
