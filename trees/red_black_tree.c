//program on red-black tree
//root is always black
//child of red are black
//sentinel node has color black
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
    
    if(y->parent==NULL)//or y is the root node //doubt
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

int main()
{
    sentinel=(node*)malloc(sizeof(node));
    sentinel->color= 'b';//default color of sentinel node is black
    sentinel->right=sentinel->left=NULL;

    //root of the tree
    node* root=NULL;
    root=(node*)malloc(sizeof(node));
    root->parent=sentinel;

    //inserting the elements
    root->data=10;
    root->color='b'; //by property color of the root is always black
    //allocating the memory for nodes
    node* arr=(node*)calloc(6,sizeof(node));

    //inserting the left element
    //putting the values in the left node
    arr[0].color='r';
    arr[0].data=5;
    arr[0].left=(arr+2);
    arr[0].right=(arr+3);
    //arr[0].left=arr[0].right=sentinel;
    arr[0].parent=root;
    //inserting the right element
    //putting the values in the right node
    arr[1].color='b';
    arr[1].data=15;
    arr[1].left=arr[1].right=sentinel;
    arr[1].parent=root;
    //creating the link as the left child of the root node
    root->left=arr;
    //creating the link as the right child of the root node
    root->right=(arr+1);

    //inserting the left element
    //putting the values in the left node
    arr[2].color='b';
    arr[2].data=2;
    arr[2].left=arr[2].right=sentinel;
    arr[2].parent=arr;
    //inserting the right element
    //putting the values in the right node
    arr[3].color='r';
    arr[3].data=7;
    arr[3].left=(arr+4),arr[3].right=(arr+5);
    arr[3].parent=arr;

    //inserting the left element
    //putting the values in the left node
    arr[4].color='b'; 
    arr[4].data=6;
    arr[4].left=arr[4].right=sentinel;
    arr[4].parent=(arr+3);
    //inserting the right element
    //putting the values in the right node
    arr[5].color='b';
    arr[5].data=8;
    arr[5].left=arr[5].right=sentinel;
    arr[5].parent=(arr+3);

    printf("Tree traversal before left-rotation:\n");
    traversal(root);
    left_rotate(root,root->left);
    //print the data
    printf("\nTree traversal after left-rotation:\n");
    traversal(root);
    printf("\n");

    right_rotate(root,root->left->left);
    //print the data
    printf("Tree traversal after right-rotation:\n");
    traversal(root);
    printf("\n");

    //free th variables
    free(arr); free(root); free(sentinel);
    return 0;
}

/*Sample Output
Tree traversal before left-rotation:
10 5 2 7 6 8 15 
Tree traversal after left-rotation:
10 7 5 2 6 8 15
Tree traversal after right-rotation:
10 5 2 7 6 8 15
*/
