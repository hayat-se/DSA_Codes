#include<iostream>
using namespace std;

struct BT
{
    int info;
    BT* left;
    BT* right;
};

class BinaryTree
{
    BT* tree;

public:
    static int totalNodes;
    BinaryTree()
    {
        tree = NULL;
        totalNodes++;
    }

    BinaryTree(int val)
    {
        tree = new BT();
        tree->info = val;
        tree->left = NULL;
        tree->right = NULL;
        totalNodes++;
    }

    BinaryTree(BT* leftTree, BT* rightTree, int val)
    {
        tree = new BT();
        tree->info = val;
        tree->left = leftTree;
        tree->right = rightTree;
        totalNodes++;
    }

    static int getTotalNodes()
    {
        return totalNodes;
    }

    BT* getRoot()
    {
        return tree;
    }

    bool isEmpty()
    {
        return (tree == NULL);
    }

    BT* makeTree(int val)
    {
        BT* node = new BT();
        node->info = val;
        node->left = NULL;
        node->right = NULL;
    }

    void setLeftNode(BT* tree, int val)
    {
        if(tree == NULL)
        {
            cout<<"No Node in the tree...\n";
        }
        else if(tree->left != NULL)
        {
            cout<<"Already Value on left Node...\n";
        }
        else
        {
            tree->left = makeTree(val);
        }
    }

    void setRightNode(BT* tree, int val)
    {
        if(tree == NULL)
        {
            cout<<"No Node in the tree...\n";
        }
        else if(tree->right != NULL)
        {
            cout<<"Already Value on Right Node...\n";
        }
        else
        {
            tree->right = makeTree(val);
        }
    }

    void preTraversal(BT* root)
    {
        if(root != NULL)
        {
            cout<<root->info <<", ";
            preTraversal(root->left);
            preTraversal(root->right);
        }
    }

    void inTraversal(BT* root)
    {
        if(root != NULL)
        {
            inTraversal(root->left);
            cout<<root->info<<", ";
            inTraversal(root->right);
        }
    }

    void postTraversal(BT* root)
    {
        if(root != NULL)
        {
            postTraversal(root->left);
            postTraversal(root->right);
            cout<<root->info <<", ";
        }
    }
};

int BinaryTree::totalNodes = 0;