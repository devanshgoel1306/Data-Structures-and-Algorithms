//Adelson, Velsky, Landis(AVL) tree
//a type of weight balance tree
//Balance factor= h(left)-h(right)
//possible values can be -1,0,1
//AVL tree is a good balance tree because it reduces the height
//of the tree for n nodes which in case of bst can be equal to the
//no. of nodes

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    float data;
    struct node* left;
    struct node* right;
    int height;   
}node;

int max(int a,int b)
{
    if(a>=b) return a;
    else return b;
}

int height(node* root)
{
    
    if(!root)
    {
        //printf("Height= -1\n");
        return -1; //if the tree is empty
    }
        
    else 
        //printf("root->height: %d\n",root->height);
    return(root->height);
}

node* single_rotate_left(node* temp)
{
    node* aux= temp->left;
    temp->left= aux->right;
    aux->right=temp;
    temp->height= max(height(temp->right),height(temp->left))+1;
    aux->height= max(height(aux->left),temp->height)+1;
    return aux; //new root
}

node* single_rotate_right(node* temp)
{
    node* aux= temp->right;
    temp->right= aux->right;
    aux->right=temp;
    temp->height= max(height(temp->right),height(temp->left))+1;
    aux->height= max(height(aux->right),temp->height)+1;
    return aux; //new root
}

node* double_rotate_right(node* temp)
{
    temp->right= single_rotate_right(temp->right);
    return single_rotate_right(temp);
}

node* double_rotate_left(node* temp)
{
    temp->right= single_rotate_left(temp->left);
    return single_rotate_left(temp);
}

node* insertion(node* root,node* parent,float value)
{
    ////printf("Step 1\n");
    if(!root)
    {
        ////printf("Step 2\n");
        root=(node*)malloc(sizeof(node));

        if(!root) 
        {
            printf("Memory Error!");
            return NULL;
        }
        else{
            ////printf("Step 3\n");
            //assigning the values
            root->data= value;
            root->left= NULL;
            root->right= NULL;
            root->height=0;
        }
       
    }
    else if(root->data>value)
    {
        //printf("Step 4\n");
        root->left= insertion(root->left,root,value);
        //printf("Step 5\n");
        if(height(root->left) -height(root->right)==2)
        {
            //printf("Step 6\n");
            if(value<root->left->data)
            {
                root= single_rotate_left(root);
            }
            else{
                root= double_rotate_left(root);
            }
        }
    }
    else if(value>root->data){
        //printf("Step 7\n");
            root->right= insertion(root->right,root,value);
            //printf("Step 8\n");
            if(height(root->right) -height(root->left)==2)
            {
                //printf("Step 9\n");
                if(value<root->right->data)
                {
                    root= single_rotate_right(root);
                }
                else{
                    root= double_rotate_right(root);
                }
            }
    }
    
    root->height= max(height(root->right),height(root->left))+1;
    //printf("Step 10\n");
    return root;
}

void print_data(node* root)
{
    if(root!=NULL)
    {
        print_data(root->left);
        printf("%.2f ",root->data);
        print_data(root->right);
    }
    
}

void search(node* root,float value)
{
    if(root==NULL)
    {
        printf("Data not found!!!\n");
        return;
    }
    else if(value>root->data) search(root->right,value);
    else if(value<root->data) search(root->left,value);
    else if(value==root->data)
    {
        printf("Data found!!!\n");
    }
}

int main(void)
{
    node* root=NULL;
    printf("Available operations\n 1.Insertion\n 2.Searching\n 3.Deletion\n 4.Print the data\n 5.Height of the tree\n 6.Exit\n");
    int choice=0; float elem=0;

    while(1)
    {
        printf("Enter the choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("Enter the element to be inserted: ");
                    scanf("%f",&elem);
                    root= insertion(root,NULL,elem);
                    break;

            case 2: printf("Enter the element to be searched: ");
                    scanf("%f",&elem);
                    search(root,elem);
                    break;

            case 3: //deletion(root);
                    break;

            case 4: 
                    printf("Inorder Traversal is ");
                    print_data(root);
                    printf("\n");
                    break;

            case 5: printf("Height of the tree is %d.\n",height(root));
                    break;

            case 6: exit(-1);
                    break;
            default: printf("Wrong choice!!!\n");
        }
    }
    //free the root pointer
    free(root);
    return 0;
}

/*Sample Output
Available operations
 1.Insertion
 2.Searching
 3.Deletion
 4.Print the data
 5.Height of the tree
 6.Exit
Enter the choice: 1
Enter the element to be inserted: 111
Enter the choice: 2
Enter the element to be searched: 111
Data found!!!
Enter the choice: 4
Inorder Traversal is 111.00 
Enter the choice: 5
Height of the tree is 0.
Enter the choice: 1
Enter the element to be inserted: 13
Enter the choice: 5
Height of the tree is 1.
Enter the choice: 6
*/


