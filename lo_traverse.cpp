//Level Order Traversal in Binary Tree

#include<iostream>
#include<queue>

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

void level_order(Node* root)
{
    queue<Node*> q;

    //push the root element
    q.push(root);

    //run the loop till the queue is non-empty
    while(!q.empty())
    {
        //print the data
        cout<< q.front()->data << " ";

        //push the right and left child of the front element in queue
        if(q.front()->left != NULL) q.push(q.front()->left);
        if(q.front()->right != NULL) q.push(q.front()->right);

        //pop the front element
        q.pop();

    }
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

    level_order(root);

    return 0;
}