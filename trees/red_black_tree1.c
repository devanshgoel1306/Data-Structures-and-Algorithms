#include<stdio.h>
#include<stdlib.h>

//defining the structure
typedef struct node
{
    int data;
    struct node* parent;
    struct node* left;
    struct node* right;
    char color;
}node;

node* sentinel;
void traversal(node* root)
{
    if(root!=sentinel)
      {
        printf("%d ",root->data);
        traversal(root->left);
        traversal(root->right);
      }

}

void left_rotate(node* root,node* x)
{
  node*y=x->right;
  x->right=y->left;

  if(y->left!=NULL)
  {
    y->left->parent=x;
  }
  y->parent=x->parent;

  if(x->parent==sentinel)
  {
    root=y;
  }
  else if(x==x->parent->left)
  {
    x->parent->left=y;
  }
  else{
    x->parent->right=y;
  }

  y->left=x;
  x->parent=y;
}

void right_rotate(node* root,node* x)
{
    //node y is the right child of node x
    node* y=x->parent;
    //right child of node x is left child of node y
    y->left= x->right;
    
    if(x->right!=NULL)
    {
        //update the parent of right child of node x
        x->right->parent=y;
    }
    //update the parent of x as parent of y
    x->parent=y->parent;
    
    if(y->parent==sentinel)//or y is the root node //doubt
    {
        //new root of tree is node x
        root=x;
    }
    else if(y->parent->right==y)//if y is left child
    {
        //update right child of y's parent is x
        y->parent->right=x;
    }
    else{//if y is left child
        //update left child of y's parent is x
        y->parent->left=x;
    }
    //right child of x is y
    x->right=y;
    //parent of y is x
    y->parent=x;
    
}

node* insert_fixup(node* root,node* z)
{
    node* y;
    while((z)->parent->color=='r')
    {
        if((z)->parent==(z)->parent->parent->left)
        {
            y=(z)->parent->parent->right;
            if(y->color=='r')
            {
                (z)->parent->color='b';
                y->color='b';
                (z)->parent->parent->color='r';
            }
            else if((z)==(z)->parent->right)
            {
                (z)=(z)->parent;
                left_rotate(root,(z));
            }
            z->parent->color='b';
            z->parent->parent->color='r';
            root= right_rotate(root,z->parent->parent);
        }
        else{
            y=z->parent->parent->left;
            if(y->color=='r')
            {
                z->parent->color='b';
                y->color='b';
                z->parent->parent->color='r';
            }
            else if(z==z->parent->left)
            {
                z=z->parent;
                right_rotate(root,z);
            }
            z->parent->color='b';
            z->parent->parent->color='r';
            left_rotate(root,z->parent->parent);
        }
    }
    (root)->color='b';
    return root;
}

node* insertion(node* root,int value)
{
    node* z=(node*)malloc(sizeof(node));
   
    z->data=value;
    
    node* y=sentinel;
  
    node* x=root;
      
    while(x!=sentinel)
    {
        y=x;
        if((z)->data<x->data) x=x->left;
        else x=x->right;
        //printf("1\n");
    }
    z->parent=y;

    if(y==sentinel)
    {
        root=z;
        //printf("I am root.\n");
    }
    else if(z->data<y->data)
    {
        y->left=z;
    }
    else{
        y->right=z;
    }
    z->left=sentinel;
    z->right=sentinel;
    z->color='r';
    //printf("I am insertion.\n");
    //root=insert_fixup(root,z);

    return root;
}

void pre_order_traversal(node* root)
{
    if(root!=sentinel)
    {
        printf("%d ",root->data);
        pre_order_traversal(root->left);
        pre_order_traversal(root->right);
    }
}

void search(node* root,int value)
{
    node* temp=root;

    while(temp->data!=value && temp!=sentinel)
    {
        if(temp->data<value) temp=temp->right;
        else temp=temp->left;
    }
    if(temp!=sentinel) printf("\nElement found!\n");
    else printf("\nElement not found.\n");
}

int main()
{
    sentinel=(node*)malloc(sizeof(node));
    sentinel->color= 'b';//default color of sentinel node is black
    sentinel->right=sentinel->left=NULL;

    //root of the tree
    node* root=NULL;
    root=(node*)malloc(sizeof(node));
    root=sentinel;
    root->parent=sentinel;

    int i=0,value=0;
    for(;i<7;i++)
    {
        printf("Enter the number: ");
        scanf("%d",&value);
        root=insertion(root,value);
    }

    pre_order_traversal(root);

    search(root,value);
    return 0;
}

/*Sample Output
Enter the number: 10
Enter the number: 5
Enter the number: 15
Enter the number: 2
Enter the number: 7
Enter the number: 6
Enter the number: 8
10 5 2 7 6 8 15 
Element found!  
*/