// #include<iostream>
// using namespace std;

// struct TreeNode
// {
//     TreeNode* left;
//     TreeNode* right;
//     int info;
// };


// class BinarySearchTree
// {
//     TreeNode* root;
// public:
//     static int numberOfNodes; // for counting

//     BinarySearchTree();
//     bool isEmpty();
//     int NumberOfNodes(); 
//     void InsertItem(int item); 
//     // void RetrieveItem ( int& item, bool& found ); 
//     void PrintTree () ;
//     void PrintHelper ( TreeNode* ptr); 
//     void InsertHelper ( TreeNode* ptr, int item );
//     // void RetrieveHelper ( TreeNode* ptr, int& item, bool& found ); 
//     // void DestroyHelper ( TreeNode* ptr ) ;
// };

// int BinarySearchTree::numberOfNodes = 0;


// BinarySearchTree::BinarySearchTree()
// {
//     root = NULL;
//     numberOfNodes++;
// }

// bool BinarySearchTree::isEmpty()
// {
//     return (root == NULL);
// }

// int BinarySearchTree::NumberOfNodes()
// {
//     return numberOfNodes;
// }

// void BinarySearchTree::InsertHelper(TreeNode* node, int item)
// {
//     if(node == NULL)
//     {
//         node = new TreeNode();
//         node->info = item;
//         node->left = NULL;
//         node->right = NULL;
//     }
//     else if(item < node->info)
//     {
//         cout<<item<<"is less than"<<node->info<<"\n";
//         InsertHelper(node->left, item);
//     }
//     else if(item > node->info)
//     {
//         cout<<item<<"is greater than"<<node->info<<"\n";
//         InsertHelper(node->right , item);
//     }
// }


// void BinarySearchTree::InsertItem(int item)
// {
//     cout<<"insert Tree called\n";
//     InsertHelper(root,item);
// }

// void BinarySearchTree::PrintHelper(TreeNode* node)
// {
//     if(node != NULL) 
//     {
//         PrintHelper(node->left);
//         cout<<node->info <<", ";
//         PrintHelper(node->right);
//     }
// }

// void BinarySearchTree::PrintTree()
// {
//     PrintHelper(root);
// }


#include<iostream>
using namespace std;

struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int info;
};

class BinarySearchTree {
    TreeNode* root;

public:
    static int numberOfNodes;

    BinarySearchTree();
    bool isEmpty();
    int NumberOfNodes();
    void InsertItem(int item);
    void PrintTree();

private:
    void PrintHelper(TreeNode* node);
    void InsertHelper(TreeNode*& node, int item);
};

int BinarySearchTree::numberOfNodes = 0;

BinarySearchTree::BinarySearchTree()
{
    root = NULL;
}

bool BinarySearchTree::isEmpty()
{
    return (root == NULL);
}

int BinarySearchTree::NumberOfNodes()
{
    return numberOfNodes;
}

void BinarySearchTree::InsertHelper(TreeNode*& node, int item)
{
    if(node == NULL)
    {
        node = new TreeNode();
        node->info = item;
        node->left = NULL;
        node->right = NULL;
        numberOfNodes++;
    }
    else if(item < node->info)
    {
        InsertHelper(node->left, item);
    }
    else if(item > node->info)
    {
        InsertHelper(node->right , item);
    }
}

void BinarySearchTree::InsertItem(int item)
{
    InsertHelper(root, item);
}

void BinarySearchTree::PrintHelper(TreeNode* node)
{
    if(node != NULL)
    {
        PrintHelper(node->left);
        cout << node->info << ", ";
        PrintHelper(node->right);
    }
}

void BinarySearchTree::PrintTree()
{
    PrintHelper(root);
}
