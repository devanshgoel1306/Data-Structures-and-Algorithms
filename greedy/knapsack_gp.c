//In Fractional Knapsack, we can take a part of item also.

#include<stdio.h>

typedef struct item
{
    float value;
    float weight;
    float per_unit;
}item;


int knapsack_gp(int capacity,item items[],int i,int n_items)
{
    //base condition
    //knapsack is full
    //no item is left
    if(n_items==i || capacity==0)
    {
        return 0;
    }
    //if item does not exist
    else if(items[i].weight==0)
    {
        return knapsack_gp(capacity,items,i+1,n_items);
    }
    else{
        //if weight of item is less than or equal to capacity
        if(items[i].weight<=capacity)
        {
            //update the remaining capacity
            return items[i].value+knapsack_gp(capacity-items[i].weight,items,i+1,n_items);
        }
        //if weight of item is more than capacity
        else
        {
            //capacity will become zero
            return capacity*items[i].per_unit+knapsack_gp(0,items,i+1,n_items);
        }
    }

}

void swap(item* a,item* b)
{
    //swapping the value
    a->value= a->value + b->value;
    b->value= a->value - b->value;
    a->value= a->value - b->value;

    //swapping the weight
    a->weight= a->weight + b->weight;
    b->weight= a->weight - b->weight;
    a->weight= a->weight - b->weight;

    //swapping the per_unit
    a->per_unit= a->per_unit + b->per_unit;
    b->per_unit= a->per_unit - b->per_unit;
    a->per_unit= a->per_unit - b->per_unit;

}

//defining the min_heapify function
//here i is the index of the parent 
//size is the length  of the array
void min_heapify(item items[], int i, int size)
{
    //variable to store the index of the smallest
    //element by comparing parent and its children
    int smallest=i;
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
        //check if the left child is smaller than the parent
        if(items[l].per_unit<items[i].per_unit) 
        {
            //left child is smaller than the parent
            smallest=l;
        }
        //if parent is smaller than the left child
        else{
            smallest=i;
        }
    }
    else{
        return ;
    }

    //check if the right child exists
    if(r<size)
    {
        //check if the right child is smaller than the element largest
        if(items[r].per_unit<items[smallest].per_unit) 
        {
            //right child is smaller than the parent
            smallest=r;
        }
    }

    //if the parent is not smallest
    if(smallest!=i)
    {
        //exchange the position of the smallest element
        //with parent to obtain sub min-heap
        swap(items+i,items+smallest);

        //calling the min-heapify function again
        min_heapify(items,smallest,size);
    }


}

//defining the build_min_heap function
//this function is used to make sub min heaps
//in the heap using min_heapify function. It targets all the internal 
//nodes for doing this.
void build_min_heap(item items[], int n_items)
{
    //maximum index of the internal node
    //possible
    //we take floor value of size/2-1
    int i=(n_items/2)-1;
    //printf("maximum index of internal node: %d\n",i);

    //traversing all the internal nodes
    while(i>=0)
    {
        /*for(int j=0;j<size;j++)
    {
        printf("%d ",array[j]);
    }
        printf("\n");*/
        min_heapify(items,i,n_items);
        i--;
    }
}

//defining the heap_sort function
void heap_sort(item items[], int size)
{
    //calling build_min_heap
    build_min_heap(items,size);
    
    int i=0;
    /*for(i=0;i<size;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");*/
    for(i=0;i<size-1;i++)
    {
        //interchange the value of first and last element
        swap(items,items+size-i-1);
        //printf("\nroot: %d last:%d\n",array[0],array[size-i-1]);

        //calling the max_heapify function
        min_heapify(items,0,size-i-1);

        /*for(int j=0;j<size;j++)
        {
            printf("%d ",array[j]);
        }
        printf("\n");*/
    }
}

int main(void)
{
    //input the no. of items
    int n_items=0;
    printf("Enter the no. of items: ");
    scanf("%d",&n_items);

    //creating array of structures
    item items[n_items];
    int i=0;

    //input the array of weight of each item
    printf("Enter the weight of each item: ");
    for(i=0;i<n_items;i++)
        scanf("%f",&items[i].weight);

    //input the array of value of each item
    printf("Enter the value of each item: ");
    for(i=0;i<n_items;i++)
        scanf("%f",&items[i].value);

    
    //input the capacity of knapsack
    int capacity=0;
    printf("Enter the capacity of knapsack: ");
    scanf("%d",&capacity);

    //calculating the cost per_unit for each item
    for(i=0;i<n_items;i++)
    {
        items[i].per_unit= items[i].value/items[i].weight;
        //printf("%f\n",items[i].value);
    }

    //sort the array of structures in descending order of their value per_unit
    heap_sort(items,n_items);

    /*for(i=0;i<n_items;i++)
    {
        printf("%f\n",items[i].value);
    }*/

    //calling the knapack function
    int max_profit=knapsack_gp(capacity,items,0,n_items);
    printf("Maximum profit is %d.\n",max_profit);

    return 0;
}

/*Sample Output 1
Enter the no. of items: 3
Enter the weight of each item: 8 4 6
Enter the value of each item: 864 392 240
Enter the capacity of knapsack: 15
Maximum profit is 1376.
*/

/*Sample Output 2
Enter the no. of items: 3
Enter the weight of each item: 8 4 6
Enter the value of each item: 864 392 240
Enter the capacity of knapsack: 50
Maximum profit is 1496.
*/

/*Sample Output 3
Enter the no. of items: 5
Enter the weight of each item: 8 6 4 0 21
Enter the value of each item: 864 240 392 0 21
Enter the capacity of knapsack: 30
Maximum profit is 1508.
*/
