//Prim's Algo is used to find the minimum spanning tree.
//It is a greedy algo in which at every step we choose minimum weight edge.
//When all weight's are unique then there exist only one mst.
//Time complexity is O(v^2)
//All node weights are infinity except source.
//Since, we need to SELECT SOURCE 1st. (we can choose any node as source)

#include<stdio.h>
#include<stdbool.h>
int V=9; //no. of vertices

int select_min_vertex(short int value[], bool set_mst[])
{
    int minimum= __INT8_MAX__;
    int vertex;
    for(int i=0;i<V;i++)
    {
        if(set_mst[i]==false && value[i]<minimum)
        {
            vertex= i;
            minimum= value[i];
        }
    }
    return vertex;
}

void find_mst(short int graph[V][V])
{
    short int parent[V]; //stores mst
    short int value[V];  //used for edge relaxation
    int i=0;
    for(i=0;i<V;i++)
    {
        value[i]=__INT8_MAX__;
    }
    bool set_mst[V]; //true when vertex is included in mst
    for(i=0;i<V;i++)
    {
        set_mst[i]=false;
    }

    //assuming the start point as node 0
    parent[0]= -1; //start node has no parent
    value[0]= 0;   //start node has value=0 to get picked 1st

    //form mst with (no. of vertices-1) edges
    for(i=0;i<V-1;i++)
    {
        //select best vertex by greedy method
        int u= select_min_vertex(value, set_mst);
        set_mst[u]= true; //include new vertex in mst

        //relax adjacent vertices(not yet included in bst)
        for(int j=0;j<V;j++)
        {
            //3 constraints to relax:
            //1. Edge is present from u to j
            //2. Vertex j is not included in mst
            //3. Edge weight is smaller than current edge weight

            if(graph[u][j]!=0 && set_mst[j]==false && graph[u][j]<value[j])
            {
                value[j]= graph[u][j];
                parent[j]= u;
            }
        }
    }

    int min_cost=0;
    
    printf("Edges of mst\n");
    for(i=1;i<V;i++)
    {
        printf("%d-%d\n",i,parent[i]);
    }

    for(i=1;i<V;i++)
    {
        min_cost+= graph[i][parent[i]];
    }
    printf("Minimum cost of mst is %d.\n",min_cost);

}

int main(void)
{
    short int graph[9][9]= {{0,4,0,0,0,0,0,8,0},
                      {4,0,8,0,0,0,0,11,0},
                      {0,8,0,7,0,4,0,0,2},
                      {0,0,7,0,9,10,0,0,0},
                      {0,0,0,9,0,10,0,0,0},
                      {0,0,4,10,10,0,2,0,0},
                      {0,0,0,0,0,2,0,1,6},
                      {8,11,0,0,0,0,1,0,7},
                      {0,0,2,0,0,0,6,7,0}};

    find_mst(graph);

    return 0;
}

/*Sample Output
Edges of mst
1-0
2-1
3-2
4-3
5-2
6-5
7-6
8-2
Minimum cost of mst is 37.
*/