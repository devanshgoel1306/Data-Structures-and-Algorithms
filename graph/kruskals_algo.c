//Kruskal's Algorithm is used to find the minimum spanning tree.
//It is a greedy algorithm.
//Minimum spanning tree consists of edges one less than the no. of vertex in the original graph.
//MST exists only for a connected graph.
//We delete the parallel edges and self loop from the graph.
//We arrange the edges in increasing order of their weights.
//Then choose an edge one by one.
//Add it to the MST, if it does not create a loop.

#include<stdio.h>
#include<stdbool.h>

typedef struct edge
{
    short int source;
    short int destiny;
    short int weight;
}edge;

typedef struct dsuf //disjoint set for find and union operation
{
    int parent;
    int rank;
}dsuf;

//global variable
dsuf d[10]; 

void swap(edge* e1,edge* e2); //prototype declaration

//defining the max_heapify function
//here i is the index of the parent
//size is the no. of edges in the graph
void max_heapify(edge e[], int i, int size)
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
    //does not exist
    if(l<size)
    {
        //check if the left child is greater than the parent
        if(e[l].weight>e[i].weight)
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
        if(e[r].weight>e[largest].weight)
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
        swap(e+i,e+largest);

        //calling the max-heapify function again
        max_heapify(e,largest,size);
    }


}

//defining the build_max_heap function
//this function is used to make sub max heaps
//in the heap using max_heapify function. It targets all the internal
//nodes for doing this.
void build_max_heap(edge e[], int size)
{
    //maximum index of the internal node
    //possible
    //we take floor value of size/2-1
    int i=(size/2)-1;
    //printf("I am in build_max_heap.\n");
    //printf("maximum index of internal node: %d\n",i);

    //traversing all the internal nodes
    while(i>=0)
    {
        /*for(int j=0;j<size;j++)
    {
        printf("%hi %hi %hi\n",e[j].source,e[j].destiny,e[j].weight);
    }
        printf("\n");*/
        max_heapify(e,i,size);
        i--;
    }
    /*for(int j=0;j<size;j++)
    {
        printf("%hi %hi %hi\n",e[j].source,e[j].destiny,e[j].weight);
    }*/
}

//defining the heap_sort function
void heap_sort(edge e[], int size)
{
    //calling build_max_heap
    build_max_heap(e,size);

    int i=0;
    /*for(i=0;i<size;i++)
    {
        printf("%d ",e[i].weight);
    }
    printf("\n");*/
    for(i=0;i<size-1;i++)
    {
        //interchange the value of first and last element
        swap(e,e+size-i-1);
        
        //calling the max_heapify function
        max_heapify(e,0,size-i-1);    
    }
}

//swapping the details of the edges
void swap(edge* e1,edge* e2)
{
    //swapping the sources
    (*e1).source= (*e1).source+(*e2).source;
    (*e2).source= (*e1).source-(*e2).source;
    (*e1).source= (*e1).source-(*e2).source;

    //swapping the destiny
    (*e1).destiny= (*e1).destiny+(*e2).destiny;
    (*e2).destiny= (*e1).destiny-(*e2).destiny;
    (*e1).destiny= (*e1).destiny-(*e2).destiny;

    //swapping the weight
    (*e1).weight= (*e1).weight+(*e2).weight;
    (*e2).weight= (*e1).weight-(*e2).weight;
    (*e1).weight= (*e1).weight-(*e2).weight;
    
}

int find(int v)
{
    if(d[v].parent==-1)
        return v;
    else
        return find(d[v].parent);
}

void union_op(int from,int to)
{
    if(d[to].rank>=d[from].rank)
    {
        //parent of from is to now
        d[from].parent= to;
        d[to].rank++; //increase the rank of one vertex
    }
    else{
        d[to].parent= from;
        d[from].rank++; //increase the rank of one vertex
    }
}

void kruskals(edge e[],int n_vertex,int n_edges)
{
    //edge list to store the edges of mst
    edge mst[n_vertex-1];

    //sorting the edges in increasing order of their weight
    heap_sort(e,n_edges);

    int i=0,j=0;

    //traversing the edges
    //till the mst has v-1 edges
    while(i<n_vertex && j<n_edges)
    {
        //find absolute parent
        int from_p= find(e[j].source); 
        int to_p= find(e[j].destiny);

        if(from_p==to_p) //if both have same absolute parent or root
        {
            j++; //not include the edge in mst
            continue;
        }

        //union operation
        union_op(from_p,to_p); //union of 2 sets
        mst[i].source=e[j].source;
        mst[i].destiny=e[j].destiny;
        mst[i].weight=e[j].weight;
        i++; j++;
    }
    
    printf("mst is\n");
    for(i=0;i<n_vertex-1;i++)
    {
        printf("%d %d %d\n",mst[i].source,mst[i].destiny,mst[i].weight);
    }
}

int main(void)
{
    //input the no. of vertex
    short int n_vertex=0;
    printf("enter the no. of vertex\n");
    scanf("%hi",&n_vertex);
    //printf("%hi",n_vertex);

    //input the no. of edges
    short int n_edges=0;
    printf("enter the no. of edges\n");
    scanf("%hi",&n_edges);
    //printf("%hi",n_edges);

    //input the edges
    printf("Enter the source, destiny and weight of edge\n");
    int i=0;
    edge e[n_edges];
    for(i=0;i<n_edges;i++)
    {
        scanf("%hi %hi %hi",&e[i].source,&e[i].destiny,&e[i].weight);
    }
    /*for(i=0;i<n_edges;i++)
    {
        printf("%hi %hi %hi\n",e[i].source,e[i].destiny,e[i].weight);
    }*/

    //mark all the nodes as independent sets
    for(i=0;i<n_vertex;i++)
    {
        d[i].parent=-1;
        d[i].rank=0;
    }

    kruskals(e,n_vertex,n_edges);

    return 0;
}

/*Sample Output
enter the no. of vertex
6
enter the no. of edges
10
Enter the source, destiny and weight of edge   
0 1 1
2 4 1
1 3 1
0 2 2
2 3 2
3 4 2
1 2 3
1 4 3
4 5 3
3 5 4
mst is
2 4 1
1 3 1
0 1 1
3 4 2
4 5 3
*/