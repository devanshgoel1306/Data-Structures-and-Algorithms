//Bellman=Ford Algorithm
//Dijkstra and Bellman-Ford can not find shortest path graph for graph having negative weight cycle.
//Bellman-Ford can detect -ve weight cycle whereas Dijkstra can not detect.
//It is not necessary if a cycle contains negative edge then it will be negative weight cycle.

#include <stdio.h>
#include <stdbool.h>
#include <time.h>

int v;
void bellman_ford(int graph[v][v])
{
    //array to store the cost via different paths
    int cost[v];
    //initially cost from source will be zero
    //because we are finding shortest path from source
    //to all other vertex
    //and all other cost will be infinity
    cost[0] = 0;
    int i = 0, j = 0, k = 0;
    for (i = 1; i < v; i++)
    {
        cost[i] = 127;
    }

    //array to store the shortest path graph
    int parent[v];
    //parent of source will be -1
    parent[0] = -1;

    for (i = 0; i < v - 1; i++)
    {
        //relaxing the edges from one vertex at a time
        for (j = 0; j < v; j++)
        {
            for (k = 0; k < v; k++)
            {
                //check if an edge exists from j to k
                if (graph[j][k] != 0)
                {
                    //relax the edge
                    if (cost[j] + graph[j][k] < cost[k])
                    {
                        //update the distance
                        cost[k] = cost[j] + graph[j][k];
                        //update the parent
                        parent[k] = j;
                    }
                }
            }
        }
    }

    //store the cost after relaxing v-1 times
    int temp[v];
    for(i=0;i<v;i++)
    {
        temp[i]=cost[i];
    }

    //relaxing once more to check for negative weight edge cycle
    //relaxing the edges from one vertex at a time
    for (j = 0; j < v; j++)
    {
        for (k = 0; k < v; k++)
        {
            //check if an edge exists from j to k
            if (graph[j][k] != 0)
            {
                //relax the edge
                if (cost[j] + graph[j][k] < cost[k])
                {
                    //update the distance
                    cost[k] = cost[j] + graph[j][k];
                    //update the parent
                    parent[k] = j;
                }
            }
        }
    }

    //check if the cost has reduced further
    for(i=0;i<v;i++)
    {
        if(temp[i]!=cost[i])
        {
            break;
        }
    }

    /*if(i==v)
    {
        //print the spg
        printf("Required spg is\n");
        for (i = 1; i < v; i++)
        {
            printf("%d-%d = %d\n", parent[i], i, cost[i]);
        }
    }
    else{
        printf("Negative weight edge cycle is present in the graph.\n");
    }*/
  
}

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

void dijkstra(int graph[v][v])
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
    bool processed[v];
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

    /*printf("Required spg is \n");
    //print the spg
    for(i=1;i<v;i++)
    {
        printf("%d-%d = %d\n",parent[i],i,value[i]);
    }*/
}

int main(void)
{
    //sparse graph
    int graph1[10][10] = {{0, 10, 0, 0, 5,0, 10, 0, 0, 5},
                       {0, 0, 0, 0, 5,0, 10, 0, 0, 5},
                       {0, 10, 0, 0, 5,0, 10, 0, 0, 5},
                       {0, 10, 0, 0, 5,0, 10, 0, 0, 5},
                       {0, 10, 0, 0, 0,0, 10, 0, 0, 5},
                       {0, 10, 0, 0, 5,0, 10, 0, 0, 5},
                       {0, 10, 0, 0, 5,0, 0, 0, 0, 5},
                       {0, 10, 0, 0, 5,0, 10, 0, 0, 5},
                       {0, 10, 0, 0, 5,0, 10, 0, 0, 5},
                       {0, 10, 0, 0, 5,0, 10, 0, 0, 0}};
    
    v = 10;

    //creating variable of type clock_t
    clock_t start, end;
    //calling the function clock with return type clock_t
    //no argument required for clock function
    //clock function returns the total processor clock
    start= clock();

    bellman_ford(graph1);

    end= clock();
    //to get the actual time in sec
    //we need to divide the no. of clocks  by macro CLOCKS_PER_SEC
    printf("When graph is sparse\n");
    printf("Total time taken by bellman_ford is %f s\n",(double)(end-start)/CLOCKS_PER_SEC);

    start= clock();

    dijkstra(graph1);

    end= clock();
    //to get the actual time in sec
    //we need to divide the no. of clocks  by macro CLOCKS_PER_SEC
    printf("Total time taken by dijkstra is %f s\n",(double)(end-start)/CLOCKS_PER_SEC);

    //dense graph
    int graph2[10][10] = {{0, 1, 2, 2, 5, 1 , 2, 3, 4, 5},
                       {0, 0, 2, 2, 5, 1 , 2, 3, 4, 5},
                       {0, 1, 0, 2, 5, 1 , 2, 3, 4, 5},
                       {0, 1, 2, 0, 5, 1 , 2, 3, 4, 5},
                       {0, 1, 2, 2, 0, 1 , 2, 3, 4, 5},
                       {0, 1, 2, 2, 5, 0 , 2, 3, 4, 5},
                       {0, 1, 2, 2, 5, 1 , 0, 3, 4, 5},
                       {0, 1, 2, 2, 5, 1 , 2, 0, 4, 5},
                       {0, 1, 2, 2, 5, 1 , 2, 3, 0, 5},
                       {0, 1, 2, 2, 5, 1 , 2, 3, 4, 0}};

    start= clock();

    bellman_ford(graph2);

    end= clock();
    printf("\nWhen graph is dense\n");
    printf("Total time taken by bellman_ford is %f s\n",(double)(end-start)/CLOCKS_PER_SEC);

    start= clock();

    dijkstra(graph2);

    end= clock();
    //to get the actual time in sec
    //we need to divide the no. of clocks  by macro CLOCKS_PER_SEC
    printf("Total time taken by dijkstra is %f s\n",(double)(end-start)/CLOCKS_PER_SEC);

    return 0;
}

/*Sample Output 
When graph is sparse
Total time taken by bellman_ford is 0.000000 s
Total time taken by dijkstra is 0.000000 s    

When graph is dense
Total time taken by bellman_ford is 0.000000 s
Total time taken by dijkstra is 0.000000 s  
*/
