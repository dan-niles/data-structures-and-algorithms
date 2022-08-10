// Binary search tree is a data structure that quickly allows us to maintain a sorted list of numbers.
// The properties that separate a binary search tree from a regular binary tree is...
//     - All nodes of left subtree are less than the root node
//     - All nodes of right subtree are more than the root node
//     - Both subtrees of each node are also BSTs i.e. they have the above two properties

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int key;
    struct node *left, *right;
};

// Create new node
struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;

    return temp;
}

// Inorder traversal - Print node when visited for second time
// In a BST, inorder traversal prints the nodes in sorted order
void inOrderTraversal(struct node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        cout << " " << root->key;
        inOrderTraversal(root->right);
    }
}

// Find the inorder successor - Minimum/Leftmost leaf node of given node
struct node *findInOrderSuccessor(struct node *node)
{
    struct node *current = node;

    // Traverse and find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Insert node into BST
struct node *insert(struct node *node, int key)
{
    // If tree is empty, return a new node
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key); // If key is less than node value, find a place to insert in left BST
    else
        node->right = insert(node->right, key); // If key is greater than node value, find a place to insert in right BST

    return node;
}

// Deleting a node - Need to consider 3 cases...
//   - Case 1 : If node to be deleted has no children
//   - Case 2 : If node to be deleted has 1 child
//   - Case 3 : If node to be deleted has 2 children
struct node *deleteNode(struct node *root, int key)
{
    // Return if the tree is empty
    if (root == NULL)
        return root;

    // Find the node to be deleted
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        // Case 1 & 2 : If the node is with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // Case 3 : If the node has two children
        struct node *temp = findInOrderSuccessor(root->right);

        // Place the inorder successor in position of the node to be deleted
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int main()
{
    struct node *root = NULL;

    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);

    cout << "Inorder traversal: ";
    inOrderTraversal(root);

    cout << "\nAfter deleting 10\n";
    root = deleteNode(root, 10);

    cout << "Inorder traversal: ";
    inOrderTraversal(root);
}