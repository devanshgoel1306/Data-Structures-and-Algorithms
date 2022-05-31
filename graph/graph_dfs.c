#include <stdio.h>
#include <stdlib.h>
#define SIZE 40

/*
//implementing queue using array
typedef struct queue{
    int items[SIZE];
    int front;
    int rear;
}queue;

//creating the empty queue
queue* create_queue();
//elements are always inserted in the last of the queue
void enqueue(queue* q,int);
//function to return the dequeued element from the front end
int dequeue(queue* q);

void display(queue* q)
//check if the queue is empty
int is_empty(queue* q)
//display the elements in the queue
void print_queue(queue* q);
*/
typedef struct node
{
  int vertex;
  struct node *next;
} node;

//creating the node
node *create_node(int);

typedef struct Graph
{
  int num_vertices;
  node **adj_lists;
  int *visited;
  int *d_time; //discovering time
  int *f_time; //finish time
} Graph;

int time;
//dfs algorithm
void dfs(Graph *graph)
{
  time = 0;
  
  int i = 0;
  for (i = 0; i < graph->num_vertices; i++)
  {
    /*if(graph->visited[i]==0) //for white we are using 0
        {
            dfs_visit(graph,i);
        }*/
    printf("%d ", i);
  }
}

/*void dfs_visit(Graph* graph, int i)
{
    time+=1;
    graph->d_time[i]= time; //assigning the discovering time
    graph->visited[i]= 1; //for gray we are using 1

    node* temp= graph->adj_lists[i];
    while(temp!=NULL)
    {
        if()

        temp=temp->next;
    }
}*/
//creating a node
node *create_node(int v)
{
  node *new_node = malloc(sizeof(node));
  new_node->vertex = v;
  new_node->next = NULL;
  return new_node;
}

//creating a graph
Graph *create_graph(int vertices)
{
  Graph *graph = malloc(sizeof(Graph));
  graph->num_vertices = vertices;

  graph->adj_lists = malloc(vertices * sizeof(node *));
  graph->visited = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++)
  {
    graph->adj_lists[i] = NULL;
    graph->visited[i] = 0;
  }
  return graph;
}

//add edge
void add_edge(Graph *graph, int src, int dest)
{
  //add edge from src to dest
  node *new_node = create_node(dest);
  new_node->next = graph->adj_lists[src];
  graph->adj_lists[src] = new_node;

  //add edge from dest to src
  new_node = create_node(src);
  new_node->next = graph->adj_lists[dest];
  graph->adj_lists[dest] = new_node;
}
/*
//create a queue
queue* create_queue()
{
    queue* q= malloc(sizeof(queue));
    //sentinel values
    q->front=-1;
    q->rear= -1;
    return q;
}

//check if the queue is empty
int is_empty(queue* q)
{
    if(q->rear==-1) return 1;
    else return 0;
}

//adding elements into queue
void enqueue(queue* q,int value)*/
int main(void)
{
  Graph *graph = create_graph(6);

  add_edge(graph, 0, 1);
  add_edge(graph, 0, 2);
  add_edge(graph, 1, 2);
  add_edge(graph, 1, 4);
  add_edge(graph, 1, 3);
  add_edge(graph, 2, 4);
  add_edge(graph, 3, 4);

  dfs(graph);
  return 0;
}
