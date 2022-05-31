//program to insert n elements in the linked list in sorted order
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

void insertion(node** head, int index, int value){
    node* new_node= (node*)malloc(sizeof(node));
    //assigning the value
    new_node->data= value; new_node->next= NULL;

    //if insertion at head
    if(index==0){
        new_node->next= *head; *head= new_node;
    }
    else{
        node* temp=*head;
        for(int i=0; i<index-1; i++){
            temp=temp->next;
        }
        new_node->next= temp->next;
        temp->next= new_node;
    }
}

void print_list(node** head){
    node* temp=*head;
    printf("Values in the list are: ");
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    
}
void sort_insertion(node** head){
    int value=0;
    for(int i=0; i<4;i++){
        printf("Enter the value: ");
        scanf("%d",&value);
        int i=0;
        node* temp= *head;
        //getting the correct position for the value
        while(temp!=NULL && value>temp->data){
            temp=temp->next;
            i++;
        }
        insertion(head,i,value);
    }
    //print the sorted linked list after the insertion
    print_list(head);
}

int main(void){
    //creating the head pointer
    node* head= NULL;

    sort_insertion(&head);
}