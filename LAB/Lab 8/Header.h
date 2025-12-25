#include<iostream>
using namespace std;

// struct BT
// {
//     int info;
//     BT* left;
//     BT* right;
// };

// class BinaryTree
// {
//     BT* tree;

// public:
//     static int totalCount;
//     BinaryTree()
//     {
//         totalCount ++;
//         tree = nullptr;
//     }

//     BT* getRoot()
//     {
//         return tree;
//     }
    
//     BinaryTree(int value)
//     {
//         totalCount ++;
//         tree = new BT();
//         tree->info = value;
//         tree->left = NULL;
//         tree->right = NULL;
//     }

//     BinaryTree(BT* leftBT, BT* rightBT, int value)
//     {
//         totalCount ++;
//         tree->info = value;
//         tree->left = leftBT ;
//         tree->right = rightBT;
//     }

//     bool isEmpty()
//     {
//         return (tree == NULL);
//     }

//     BT* makeTree(int value)
//     {
//         BT* node = new BT();
//         node->info = value;
//         node->left = NULL;
//         node->right = NULL;

//         return node;
//     }

//     void setLeft(BT* root, int val)
//     {
//         if(root == NULL)
//         {
//             cout<<"Error ! Adding value to NULL Tree...\n";
//         }
//         if(root->left != NULL)
//         {
//             cout<<"Error ! Left value if already setted...\n";
//         }

//         root->left = makeTree(val);
//     }

//     void setRight(BT* root, int val)
//     {
//         if(root == NULL)
//         {
//             cout<<"Error ! Adding value to NULL Tree...\n";
//         }
//         if(root->right != NULL)
//         {
//             cout<<"Error ! Right value is already setted...\n";
//         }

//         root->right = makeTree(val);
//     }

//     void inTraverse(BT* tree)
//     {
//         if(tree != NULL) 
//         {
//             inTraverse(tree->left);
//             cout<<tree->info <<", ";
//             inTraverse(tree->right);
//         }
//     }

//     void preTraverse(BT* tree)
//     {
//         if(tree != NULL) 
//         {
//             cout<<tree->info <<", ";
//             preTraverse(tree->left);
//             preTraverse(tree->right);
//         }
//     }

//     void postTraverse(BT* tree)
//     {
//         if(tree != NULL) 
//         {
//             postTraverse(tree->left);
//             postTraverse(tree->right);
//             cout<<tree->info <<", ";
//         }
//     }
// };

// int BinaryTree::totalCount = 0;


struct BT
{
    int info;
    BT* left;
    BT* right;
};


class BinaryTree
{
    BT* tree;
    static int totalNodes;
public:
    BinaryTree();
    BinaryTree(int value);
    BinaryTree(BT*, BT*, int value);
    static int getTotalNodes();
    bool isEmpty();
    BT* getRoot();
    BT* makeTree(int);
    void setLeftNode(BT*, int);
    void setRightNode(BT*, int);
    void preTraversal(BT*);
    void inTraversal(BT*);
    void postTraversal(BT*);
};

BinaryTree::BinaryTree()
{
    tree = NULL;
    totalNodes++;
}

BinaryTree::BinaryTree(int value)
{
    tree = new BT();
    tree->info = value;
    tree->left = NULL;
    tree->right = NULL;
    totalNodes++;
}

BinaryTree::BinaryTree(BT* leftNode, BT* rightNode, int value)
{
    tree = new BT();
    tree->info = value;
    tree->left = leftNode;
    tree->right = rightNode;
    totalNodes++;
}


int BinaryTree::getTotalNodes()
{
    return totalNodes;
}

bool BinaryTree::isEmpty()
{
    return (tree == NULL);
}

BT* BinaryTree::getRoot()
{
    return tree;
}

BT* BinaryTree::makeTree(int value)
{
    BT* node = new BT();
    node->info = value;
    node->left = NULL;
    node->right = NULL;
}

void BinaryTree::setLeftNode(BT* root, int value)
{
    if(root == NULL)
    {
        cout<<"Error! Tree has no Node";
    }
    else if(root->left != NULL)
    {
        cout<<"Value already Exist on left node...";
    }
    else 
    {
        root->left = makeTree(value);
    }
}

void BinaryTree::setRightNode(BT* root, int value)
{
    if(root == NULL)
    {
        cout<<"Error! Tree has no Node";
    }
    else if(root->right != NULL)
    {
        cout<<"Value already exist on Right node...";
    } 
    else
    {
        root->right = makeTree(value);
    }
}

void BinaryTree :: preTraversal(BT* root)
{
    if(root != NULL)
    {
        cout<<root->info <<", ";
        preTraversal(root->left);
        preTraversal(root->right);
    } 
}

void BinaryTree::inTraversal(BT* root)
{
    if(root != NULL)
    {
        inTraversal(root->left);
        cout<<root->info <<", ";
        inTraversal(root->right);
    }
}

void BinaryTree::postTraversal(BT* root)
{
    if(root != NULL)
    {
        postTraversal(root->left);
        postTraversal(root->right);
        cout<<root->info <<", ";
    }
}

int BinaryTree::totalNodes = 0;