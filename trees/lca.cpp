//Lowest Common Ancestor in Binary Tree

#include<iostream>
#include<vector>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data= value;
        left= NULL;
        right= NULL;
    }
};

Node* lca(Node* root, int v1, int v2)
{
    //if either v1 or v2 does not exist in binary tree
    if(root == NULL)
    {
        return NULL;
    }

    //if we found the value in binary tree
    if(root->data == v1 || root->data == v2)
    {
        return root;
    }

    //check for the values in left and right sub tree
    Node* left_lca= lca(root->left, v1, v2);
    Node* right_lca= lca(root->right, v1, v2);

    //if one value exist in left and other value exist in right sub tree
    //then left_lca and right_lca will be not null
    if(left_lca && right_lca)
    {
        return root;
    }

    //if both the values found in either right or left subtree
    if(left_lca) //or when left_lca is not null while right_lca is null
    {
        return left_lca;
    }

    //otherwise return right_lca
    return right_lca;
}

int main(void)
{
    /*
             1
            / \
            2  3
            /  /\
            4  5 6
               /
               7
    */
   Node* root= new Node(1);
   root->left= new Node(2);
   root->right= new Node(3);
   root->left->left= new Node(4);
   root->right->left= new Node(5);
   root->right->right= new Node(6);
   root->right->left->left= new Node(7);

    Node* ancestor= lca(root, 6, 7);

    if(ancestor == NULL) cout<<"LCA does not exist.\n";
    else cout<<"LCA is "<<ancestor->data; 

    return 0;
}