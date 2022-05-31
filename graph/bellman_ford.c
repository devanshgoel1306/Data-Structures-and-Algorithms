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

    if(i==v)
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
    }
  
}

int main(void)
{
    /*int graph[5][5] = {{0, 10, 0, 0, 5},
                       {0, 0, 1, 0, 2},
                       {0, 0, 0, 4, 0},
                       {7, 0, 6, 0, 0},
                       {0, 3, 9, 2, 0}};*/
    
    int graph[3][3]= {{0,1,0},
                      {0,0,2},
                      {-4,0,0}};
    v = 3;
    bellman_ford(graph);
    return 0;
}

/*Sample Output
Required spg is
4-1 = 8
1-2 = 9
4-3 = 7
0-4 = 5
*/
