//program on binary search tree
//It is a binary tree in which left subtree contains all the smaller elements than the parent
//and right subtree contains all the larger elements than the parent.
//This is also the major difference between binary tree and bst.
#include <stdio.h>
//for allocating the memory dynamically
#include <stdlib.h>

//structure of a node
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
    struct node *parent;
} node;

void insertion(node **root, int value)
{
    //printf("I am inserting elements %d\n", value);
    //creating a node for data
    node *leaf = (node *)malloc(sizeof(node));

    //assigning the values
    leaf->data = value;
    leaf->left = NULL;
    leaf->right = NULL;
    leaf->parent = NULL;

    //if the tree is empty
    if (*root == NULL)
    {
        *root = leaf;
    }
    else
    {
        node *temp = *root;
        while (temp->right != NULL || temp->left != NULL)
        {
            if (value <= temp->data)
            {
                if (temp->left == NULL) //if left child does not exist
                {
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if (temp->right == NULL) //if right child does not exist
                {
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }

        //if value to be inserted is less than or equal to parent value, then insert as left child
        if (value <= temp->data)
        {

            temp->left = leaf;
        }
        else
        {
            temp->right = leaf;
        }
        leaf->parent = temp;
    }
}

//traversing the bst in in_order
//It will give us sorted linked list
//parent is printed in between
//It takes O(n) where n is the no. of nodes in the bst.
void traverse_inorder(node *root)
{    
    if(root!=NULL)
    {
        traverse_inorder(root->left);
        printf("%d ", root->data);
        traverse_inorder(root->right);
    }
}

//traversing the bst in pre_order
//parent is printed first
//It takes O(n) where n is the no. of nodes in the bst.
//It is used to create a duplicate bst.
//One of its use is that to make a prefix expression
void traverse_preorder(node *root)
{
    if(root!=NULL)
    {
        printf("%d ", root->data);
        traverse_preorder(root->left);
        traverse_preorder(root->right);
    }
}

//traversing the bst in post_order
//parent is printed in last
//It takes O(n) where n is the no. of nodes in the bst.
//This order is used while freeing all the nodes of bst.
void traverse_postorder(node *root)
{
    if(root!=NULL)
    {
        traverse_postorder(root->left);
        traverse_postorder(root->right);
        printf("%d ", root->data);
    }
}

//searching in bst
//worst case complexity is O(n) when bst is left or right skewed.
//average case complexity is O(log n)
node *search(node *root, int value)
{
    node *temp = root;

    if (temp == NULL || value == temp->data)
        return temp;
    if (value < temp->data)
        return search(temp->left, value);
    else
        return search(temp->right, value);

    return temp;
}

//finding the minimum element
//minimum value is the leftmost node value of bst
//In worst case it takes O(n) when the bst is left skewed.
//In best case it takes O(1) when the bst is right skewed.
node *minimum(node *root)
{
    node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

//finding the maximum element
//maximum value is the rightmost node value of bst
//In best case it takes O(1) when the bst is left skewed.
//In worst case it takes O(n) when the bst is right skewed.
node *maximum(node *root)
{
    node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

//finding the successor element
//element just greater than value
node *successor(node *root, int value)
{
    //get the address of the node with value and its parent
    node *temp = search(root, value);
    node *parent = temp->parent;
    //printf("Parent value is %d of %d.\n",parent->data,temp->data);

    //if right child exists
    if (temp->right != NULL)
        return minimum(temp->right);

    while (parent != NULL && temp == parent->right)
    {
        temp = parent;
        parent = parent->parent;
    }

    //if we are trying to find the successor node of root
    //but the bst is left skewed
    //then no successor exist
    if(parent==NULL)  
    {
        printf("It is root node.\n");
        return NULL;
    }
    else
        return parent;
}

//deleting element from bst
void deletion(node **root, int value)
{
    node *temp = search(*root, value);
    node *clear = temp;
    printf("Element to be deleted is %d\n",temp->data);

    //case-1
    //the node to be deleted is leaf
    if(temp->left==NULL && temp->right==NULL)
    {
        //break the link
        //if the leaf is right child
        if(temp->parent->right= temp)
        temp->parent->right=NULL;

        //if the leaf is left child
        if(temp->parent->left= temp)
        temp->parent->left=NULL;

        free(temp);//free the memory
    }
    //case-2
    //if left subtree does not exist
    //or the node to be deleted has one child only
    else if (temp->left == NULL)
    {
        //if the node to be deleted is root
        //and bst is right skewed
        if(temp=*root)
        {
            *root= temp->right;
        }
        else{
            //new link from parent of node to be deleted
            //to the right child of the node to be deleted
            temp->parent->right= temp->right;
            temp->right->parent= temp->parent;
        }
        
        free(clear);//free the memory
    }
    //case-2
    //if right subtree does not exist
    //or the node to be deleted has one child only
    else if (temp->right == NULL)
    {
        //if the node to be deleted is root
        //and bst is left skewed
        if(temp=*root)
        {
            *root= temp->left;
        }
        else{
            //new link from parent of node to be deleted
            //to the left child of the node to be deleted
            temp->parent->left= temp->left;
            temp->left->parent= temp->parent;
        }
        
        free(clear);//free the memory
    }
    //case-3
    else
    {
        //when the node to be deleted has 2 children
        //there are two solutions to this problem
        //1.copy the minimum value
        //or the predecessor of the node to be deleted
        //minimum value will from right subtree
        //2. copy the maximum value
        //or the successor of the node to be deleted
        //maximum value will from left subtree
        node *y = maximum(temp->left);
        //printf("The left value is %d\n",temp->right->data);
        //printf("The maximum value is %d\n", y->data);

        temp->data = y->data;

        //case-1 arises
        //if it is a leaf node
        if (y->left == NULL && y->right == NULL)
        {
            //break the link
            //if the leaf is right child
            if(temp->parent->right= temp)
            temp->parent->right=NULL;

            //if the leaf is left child
            if(temp->parent->left= temp)
            temp->parent->left=NULL;    
        }
        //case-2 arises
        //if it is a right child
        else if (y->left != NULL)
        {
            y = y->right;
            y->parent->left = NULL; //break the link
            //printf("Cleared data: %d\n",clear->data);
        }
        free(y); //free the memory
    }
}

//finding the predecessor element
//element just less than value
node *predecessor(node *root, int value)
{
    //get the address of the node with value and its parent
    node *temp = search(root, value);
    node *parent = temp->parent;
    //printf("Parent value is %d of %d.\n",parent->data,temp->data);

    //if right child exists
    if (temp->left != NULL)
        return maximum(temp->left);

    while (parent != NULL && temp == parent->left)
    {
        temp = parent;
        parent = temp->parent;
    }
    return parent;
}

//finding the height of the bst
int find_height(node *root)
{
    if (root == NULL)
    {
        return -1; //height of empty tree
    }
    int left_height = find_height(root->left);
    int right_height = find_height(root->right);

    if (left_height >= right_height)
        return left_height + 1;
    else
        return right_height + 1;
}

//wiping off the memory
void delete_tree(node* root)
{
    if(root!=NULL)
    {
        //printf("I am deleting.\n");
        delete_tree(root->left);
        delete_tree(root->right);
        //printf("%d\n",root->data);
        free(root);
    }
}

int main(void)
{
    //creating the root node of the bst
    node *root = NULL;

    int i = 0, count = 0, elem = 0;
    printf("Enter the no. of elements to be inserted: ");
    scanf("%d", &count);

    //input the elements
    int data[count];
    printf("Enter the elements: ");
    for (i = 0; i < count; i++)
    {
        scanf("%d", &data[i]);
    }
    for (i = 0; i < count; i++)
    {
        insertion(&root, data[i]);
    }

    //traversing in_order
    printf("In order traversal of bst\n");
    traverse_inorder(root);

    //traversing in preorder
    printf("\nPre order traversal of bst\n");
    traverse_preorder(root);

    //traversing in post order
    printf("\nPost order traversal of bst\n");
    traverse_postorder(root);

    printf("\nEnter the element to be searched: ");
    scanf("%d", &elem);
    node *s = search(root, elem);
    if (s != NULL)
        printf("Element found!\n");
    else
        printf("Element not found!\n");

    //get the maximum element
    node *max = maximum(root);
    printf("Maximum element in the bst is %d.\n", max->data);

    //get the minimum element
    node *min = minimum(root);
    printf("Minimum element in the bst is %d.\n", min->data);

    //finding the successor element
    node *success = successor(root, elem);
    if(success!=NULL)
    printf("Value of successor element is %d.\n", success->data);
    else
        printf("Element is maximum.\n");

    //finding the successor element
    node *predecess = predecessor(root, elem);
    if (predecess != NULL)
        printf("Value of predecessor element is %d.\n", predecess->data);
    else
        printf("Element is minimum.\n");

    //finding the height of the tree
    int height = find_height(root);
    printf("Height of the tree is %d.\n", height);

    //deleting a node
    deletion(&root, elem);

    traverse_preorder(root);

    //free the root pointer
    delete_tree(root);
    free(root);

    return 0;
}
