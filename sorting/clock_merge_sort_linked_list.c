//program on merge_sort()
//using linked list
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//creating the structure for node
typedef struct node{
int data;
struct node* next;
}node;

//function to insert elements in the beginning
void insert_element(node** head, int value){

//allocating the memory for node
node* new_node=(node*)malloc(sizeof(node));

//assigning value to it's data members
new_node->next=NULL;
new_node->data=value;

if(head==NULL){
    *head= new_node;
}
else{
    new_node->next= *head;
    *head= new_node;
}

}


//function to print the linked list
void print_list(node** head){
node* temp= *head;

printf("Elements in the linked list are ");
while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
}
printf("\n");
}

//function to free the space acquired by nodes of the linked list
void empty(node** head){

    while((*head)->next!=NULL){
        node* temp=*head;
        (*head)=(*head)->next;
        free(temp);
    }
    //we can not free last node
    //because then *head will also get deleted
    //so assign it the value NULL
    *head=NULL;
}

//function for best case input
void best_input(node** head, int size){
int i=0;
for(;i<size;i++){
    insert_element(head,size-i);
}
//linked list will be
//1,2,3,4,.. because insertion is taking place in the beginning
}

//function for average case input
void avg_input(node** head, int size){
int i=0;
for(;i<size;i++){
    insert_element(head,i%5);
}
//linked list will be
//4,3,2,1,0,4,3,2,1,0.. because insertion is taking place in the beginning
}

//function for worst case input
void worst_input(node** head, int size){
int i=0;
for(;i<size;i++){
    insert_element(head,i);
}
//linked list will be
//size,size-1,size-2.. because insertion is taking place in the beginning
}

//function to merge
void merge(node* head, int lower, int mid, int upper){
//temporary array
int a[mid-lower+1], b[upper-mid];

//creating temporary pointer
node* temp=NULL;
temp= head;
//point the temp to lower node
int x=0;
while(x<lower){
    temp=temp->next;
    //increment the value of x
    x++;
}

//copying the data
int i=0;
for(;i<mid-lower+1;i++){
    a[i]= temp->data;
    temp=temp->next;
}
i=0;
for(;i<upper-mid;i++){
    b[i]= temp->data;
    temp=temp->next;
}

temp=head;
x=0;
while(x<lower){
    temp=temp->next;
    //increment the value of x
    x++;
}
//creating pointers to point the current elements of the array a and b
int p=0, q=0;
//inserting the elements in their correct position
while(p<mid-lower+1 && q<upper-mid){
    if(a[p]<b[q]){
        temp->data= a[p];
        p++; temp=temp->next;
    }
    else{
        temp->data= b[q];
        q++; temp=temp->next;
    }
}
//inserting the remaining elements
while(p<mid-lower+1){
    temp->data= a[p];
    temp=temp->next;
    p++;
}


while(q<upper-mid){
    temp->data= b[q];
    temp=temp->next;
    q++;
}
}

//function for sorting the linked list
void merge_sort(node* head,int lower, int upper){

if(lower<upper)
{
    int mid=(lower+upper)/2;  //divide
    merge_sort(head,lower,mid);    //conquer
    merge_sort(head,mid+1,upper);  //conquer
    merge(head,lower,mid,upper);  //combine
}
}

int main(void){
    printf("Enter the size of the array: ");
    int size=0;
    scanf("%d",&size);
    
    node* head=NULL;
    
    //creating variable of type clock_t
    clock_t start,end;

    //best case input
    best_input(&head, size);
    //calling the clock function
    start= clock();
    merge_sort(head,0,size-1);
    //calling the clock function
    end= clock();
    printf("Time taken in best case is %lf s.\n",(double)((end-start)/CLOCKS_PER_SEC));
    //free the linked list
    empty(&head);
    
    //avg case input
    avg_input(&head, size);
    //calling the clock function
    start= clock();
    merge_sort(head,0,size-1);
    //calling the clock function
    end= clock();
    printf("Time taken in average case is %lf s.\n",(double)((end-start)/CLOCKS_PER_SEC));
    //free the linked list
    empty(&head);
    
    //worst case input
    worst_input(&head, size);
    //calling the clock function
    start= clock();
    merge_sort(head,0,size-1);
    //calling the clock function
    end= clock();
    printf("Time taken in worst case is %lf s.\n",(double)((end-start)/CLOCKS_PER_SEC));
    //free the linked list
    empty(&head);

    //free the head pointer
    free(head);
    return 0;
}

/*Sample Output
Enter the size of the array: 100000
Time taken in best case is 64.000000 s.
Time taken in average case is 65.000000 s.
Time taken in worst case is 64.000000 s.
*/
