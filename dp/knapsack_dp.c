/*The Knapsack problem is a problem in combinatorial optimization.
Given a set of items, each with a weight and a value, determine the 
number of each item to include in a collection so that the total
weight is less than or equal to a given limit and the total value
is as large as possible.*/

//0-1 Knapsack using dynamic programming approach
#include<stdio.h>

int max(int a,int b)
{
    return (a>b)?a:b;
}

int knapsack_dp(int capacity, int weight[],int value[], int n_items)
{
    //base condition
    //items has finished
    //knapsack is full
    if(n_items==-1 || capacity==0)
    {
        return 0;
    }
    //weight of item is more than the capacity of knapsack
    //weight of item is not 0
    else if(weight[n_items]>capacity || weight[n_items]==0)
    {
        return knapsack_dp(capacity,weight,value,n_items-1);
    }
    else{
        return max(value[n_items]+knapsack_dp(capacity-weight[n_items],weight,value,n_items-1),knapsack_dp(capacity,weight,value,n_items-1));
    }
}

int main(void)
{
    //input the no. of items
    int n_items=0;
    printf("Enter the no. of items: ");
    scanf("%d",&n_items);

    //input the array of weight of each item
    int weight[n_items],i=0;
    printf("Enter the weight of each item: ");
    for(i=0;i<n_items;i++)
        scanf("%d",&weight[i]);

    //input the array of value of each item
    int value[n_items];
    printf("Enter the value of each item: ");
    for(i=0;i<n_items;i++)
        scanf("%d",&value[i]);

    
    //input the capacity of knapsack
    int capacity=0;
    printf("Enter the capacity of knapsack: ");
    scanf("%d",&capacity);

    //calling the knapack function
    int max_profit=knapsack_dp(capacity,weight,value,n_items-1);
    printf("Maximum profit is %d.\n",max_profit);

    return 0;
}

/*Sample Output
Enter the no. of items: 5
Enter the weight of each item: 8 6 4 0 21
Enter the value of each item: 894 260 392 298 27
Enter the capacity of knapsack: 30
Maximum profit is 1546.
*/