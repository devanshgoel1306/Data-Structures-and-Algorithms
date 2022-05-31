//Dijkstra Algo is used to find shortest path from one vertex to other all other vertex.
//Time Complexity O(V^2) where V is the no. of vertices.
//It is a greedy algo and can be used for both directed as well as undirected graph.
//This algo can not be used for -ve weight edge cycle.

#include<stdio.h>
#include<stdbool.h>

int select_min_vertex(int value[],bool processed[],int v)
{
    int i=0,min=__INT_MAX__,min_i=0;
    for(i=0;i<v;i++)
    {
        //the vertex is not processed
        if(!processed[i] && value[i]<min)
        {
            min_i=i;
            min=value[i];
        }
    }

    return min_i;
}

void dijkstra(int graph[5][5],int v)
{
    //stores shortest path structure
    int parent[v]; 
    //keeps shortest path values to each vertex from source
    int value[v];
    int i=0,j=0;
    for(i=0;i<v;i++)
    {
        value[i]=__INT_MAX__;
    }

    //true if vertex is processed
    bool processed[5];
    for(i=0;i<v;i++)
    {
        processed[i]=false;
    }

    //assuming start point as node->0
    //start node has no parent
    parent[0]=-1;
    //start node has value=0 to get picked list
    value[0]=0;

    //include (V-1) edges to cover all V vertices
    for(i=0;i<v-1;i++)
    {
        //select best vertex using greedy method
        int u= select_min_vertex(value, processed,v);
        //include new vertex in shortest path graph
        processed[u]= true;

        //relax adjacent vertices (not yet included in shortest path graph)
        for(j=0;j<v;j++)
        {
            // 3 conditions to relax:
            // 1.Edge is present from u to j.
            // 2.Vertex j is not included in shortest path graph.
            // 3.Edge weight is smaller than current Edge weight
            if(graph[u][j]!=0 && processed[j]==false && (value[u]+graph[u][j]<value[j]))
            {
                //update the distance
                value[j]=value[u]+graph[u][j];
                //update the parent
                parent[j]=u;
            } 
        }
    }

    printf("Required spg is \n");
    //print the spg
    for(i=1;i<v;i++)
    {
        printf("%d-%d = %d\n",parent[i],i,value[i]);
    }
}

int main(void)
{
    int graph[5][5]={{0,10,0,0,5},
                     {0,0,1,0,2},
                     {0,0,0,4,0},
                     {7,0,6,0,0},
                     {0,3,9,2,0}};
    int v=5;
    dijkstra(graph,v);

    return 0;
}

/*Sample Output
Required spg is 
4-1 = 8
1-2 = 9
4-3 = 7
0-4 = 5
*/