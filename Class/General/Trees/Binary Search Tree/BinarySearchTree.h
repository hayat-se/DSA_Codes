#include<iostream>
using namespace std;

// struct Node
// {
//     int info;
//     Node* left;
//     Node* right;
// };

// class BST
// {
//     Node* tree;
// public:
//     BST()
//     {
//         tree = NULL;
//     }

//     bool isEmpty()
//     {
//         return (tree == NULL);
//     }

//     Node* getRoot()
//     {
//         return tree;
//     }

//     void insertHelper(Node*& node, int val)
//     {
//         if(node == NULL)
//         {
//             node = new Node();
//             node->info = val;
//             node->left = NULL;
//             node->right = NULL;
//         }
//         else if(val < node->info)
//         {
//             insertHelper(node->left, val);
//         }
//         else if(val > node->info)
//         {
//             insertHelper(node->right, val);
//         }
//     }

//     void insertItem(int val)
//     {
//         insertHelper(tree, val);
//     }

//     int retriveHelper(Node* root, int target)
//     {
//         if(root == NULL)
//         {
//             cout<<"Item Not FOUND...\n";
//             return -999;
//         }
//         else if(target == root->info)
//         {
//             return root->info;
//         }
//         else if(target < root->info)
//         {
//             return retriveHelper(root->left, target);
//         }
//         else if(target > root->info)
//         {
//             return retriveHelper(root->right, target);
//         }
//     }

//     int retriveItem(int target)
//     {
//         retriveHelper(tree, target);
//     }

//     void printTree(Node* root)
//     {
//         if(tree == NULL)
//         {
//             cout<<"No Nodes in Tree...\n";
//         }
//         else
//         {
//             printTree(root->left);
//             cout<<root->info <<", ";
//             printTree(root->right);
//         }
//     }

//     void preTraversal(Node* root)
//     {
//         if(root != NULL)
//         {
//             cout<<root->info<<", ";
//             preTraversal(root->left);
//             preTraversal(root->right);
//         }
//     }

//     void inTraversal(Node* root)
//     {
//         if(root != NULL)
//         {
//             inTraversal(root->left);
//             cout<<root->info<<", ";
//             inTraversal(root->right);
//         }
//     }

//     void postTraversal(Node* root)
//     {
//         if(root != NULL)
//         {
//             postTraversal(root->left);
//             postTraversal(root->right);
//             cout<<root->info<<", ";
//         }
//     }
// };


struct Node
{
    int data;
    Node* left;
    Node* right;
};


class BST
{
    Node* root;

    int insertHelper(Node*& root, int val)
    {
        if(root == NULL)
        {
            root = new Node();
            root->data = val;
            root->left = NULL;
            root->right = NULL;
        }
        else if(val < root->data)
        {
            insertHelper(root->left, val);
        }
        else if(val > root->data)
        {
            insertHelper(root->right, val);
        }
    }

    int retriveHelper(Node* node, int target)
    {
        if(node == NULL)
        {
            cout<<"No node in ";
        }
    }

public:
    BST()
    {
        root = NULL;
    }

    BST(int val)
    {
        root->data = val;
        root->left = NULL;
        root->right = NULL;
    }

    bool isEmpty()
    {
        return (root == NULL);
    }

    Node* getRoot()
    {
        return root;
    }

    void  insertItem(int val)
    {
        insertHelper(root, val);
    }

    int retriveItem(int target)
    {
        retriveHelper(root, target);
    }

    void preTraversal(Node* node)
    {
        if(node != NULL)
        {
            cout<<node->data <<", ";
            preTraversal(node->left);
            preTraversal(node->right);
        }
    }

    void inTraversal(Node* node)
    {
        if(node != NULL)
        {
            inTraversal(node->left);
            cout<<node->data <<", ";
            inTraversal(node->right);
        }
    }

    void postTraversal(Node* node)
    {
        if(node != NULL)
        {
            postTraversal(node->left);
            postTraversal(node->right);
            cout<<node->data<<", ";
        }
    }
};