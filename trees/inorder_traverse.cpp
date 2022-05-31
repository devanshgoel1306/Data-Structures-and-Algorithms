//Inorder Traversal in Binary Tree using iteration and recursion

#include<iostream>
#include<stack>


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


void inorder_traverse(Node* node)
{
    //take an empty stack with data type as Node*
    stack<Node*> s;

    while(node != NULL || !s.empty())
    {
        if(node != NULL)
        {
            //push the node pointer in the stack s
            s.push(node);

            //change the position of the node pointer
            //to the left sub tree
            node= node->left;
        }
        else{
            node= s.top();
            s.pop();

            //print the data
            cout<< node->data << " ";

            //change the position of the node pointer
            //to the right sub tree
            node= node->right;

        }
    }
}

void inorder_recur(Node* node)
{
    if(node == NULL) return;

    inorder_recur(node->left);
    cout<< node->data << " ";
    inorder_recur(node->right);
    
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

    cout<<"Inorder Traversal using iteration is :";
   inorder_traverse(root);

   cout<<"\nInorder Traversal using recursion is :";
   inorder_recur(root);

    return 0;
}