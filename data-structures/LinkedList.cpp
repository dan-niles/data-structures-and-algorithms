// A linked list is a linear collection of data elements whose order is not given by their physical placement in memory.
// Instead, each element points to the next.
// It is a data structure consisting of a collection of nodes which together represent a sequence.

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void printList(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
}

// Inserts new node into the list
// Time complexity : O(1)
void insertNode(Node **head_ref, int new_data)
{
    Node *newNode = new Node();
    newNode->data = new_data;
    newNode->next = *head_ref; // Set next node to previous head
    *head_ref = newNode;       // Set head pointer to new node
}

// Deletes node in list by searching with value
// Time complexity : O(n)
void deleteNode(Node **head_ref, int key)
{
    if (*head_ref == NULL) // If list is empty
    {
        cout << key << " is not found" << endl;
        return;
    }

    Node *head = *head_ref;
    if (head->data == key) // Key exists in head
    {
        *head_ref = head->next; // Set head node as next node
        return;
    }

    Node *currentNode = *head_ref;
    while (currentNode->next != NULL) // Loop till last element in list
    {
        if (currentNode->next->data == key)
        {
            currentNode->next = currentNode->next->next;
            return;
        }
        currentNode = currentNode->next;
    }

    cout << key << " is not found" << endl;
}

// Checks if key exists in list
// Time complexity : O(n)
void searchNode(Node **head_ref, int key)
{
    if (*head_ref == NULL) // If list is empty
    {
        cout << key << " is not found" << endl;
        return;
    }

    Node *currentNode = *head_ref;
    while (currentNode != NULL) // Key exists in head
    {
        if (currentNode->data == key)
        {
            cout << key << " is found" << endl;
            return;
        }
        currentNode = currentNode->next;
    }

    cout << key << " is not found" << endl;
}

int main()
{
    int a, b;
    Node *head = NULL; // Head pointer

    while (true)
    {
        cin >> a;

        if (a == -1)
        {
            printList(head);
            break;
        }

        cin >> b;

        switch (a)
        {
        case 1:
            insertNode(&head, b); // Passing the memory address of pointer
            break;
        case 2:
            deleteNode(&head, b);
            break;
        case 3:
            searchNode(&head, b);
            break;
        }
    }

    return 0;
}