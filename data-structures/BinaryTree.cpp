// A binary tree is a tree data structure in which each parent node can have at most two children.
// Each node of a binary tree consists of three items : data item, address of left child and address of right child.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;           // Data item
    struct Node *left;  // Pointer to left child
    struct Node *right; // Pointer to right child
};

// Add new node to tree
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));

    node->data = data;

    node->left = NULL;
    node->right = NULL;
    return (node);
}

// Preorder traversal - Print node when visited for first time
void preOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        cout << " " << root->data;
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Inorder traversal - Print node when visited for second time
void inOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        cout << " " << root->data;
        inOrderTraversal(root->right);
    }
}

// Postorder traversal - Print node when visited for third time
void postOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << " " << root->data;
    }
}

int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);

    cout << "preorder traversal: " << endl;
    preOrderTraversal(root);

    cout << "\nInorder traversal: " << endl;
    inOrderTraversal(root);

    cout << "\nPostorder traversal: " << endl;
    postOrderTraversal(root);
}