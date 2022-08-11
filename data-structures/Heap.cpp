// A Heap is a special Tree-based data structure in which the tree is a complete binary tree.
// Generally, Heaps can be of two types: Max-Heap:
//    - In a Max-Heap the key present at the root node must be greatest among the keys present at all of it's children.
//    - In a Min-Heap the key present at the root node must be smallest among the keys present at all of it's children.

#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// Swaps the values of given variables
void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

// Maintains the max-heap property
void maxHeapify(vector<int> &heap, int i)
{
    int size = heap.size();
    int largest = i;

    int left = 2 * i + 1;  // Left child of ith node
    int right = 2 * i + 2; // Right child of ith node

    // Find the largest among parent, left child & right child
    if (left < size && heap[left] > heap[largest])
        largest = left;
    if (right < size && heap[right] > heap[largest])
        largest = right;

    // If largest value has been changed
    if (largest != i)
    {
        swap(&heap[i], &heap[largest]);
        maxHeapify(heap, largest);
    }
}

// Maintains the min-heap property
void minHeapify(vector<int> &heap, int i)
{
    int size = heap.size();
    int smallest = i;

    int left = 2 * i + 1;  // Left child of ith node
    int right = 2 * i + 2; // Right child of ith node

    // Find the smallest among parent, left child & right child
    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    // If smallest value has been changed
    if (smallest != i)
    {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, smallest);
    }
}

// Choose between max-heapify and min-heapify
void heapify(vector<int> &heap, int i)
{
    maxHeapify(heap, i);
    // minHeapify(heap, i);
}

// Build heap in a bottom up manner
void buildHeap(vector<int> &heap)
{
    int size = heap.size();
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(heap, i);
}

// Insert node into heap
void insert(vector<int> &heap, int newNum)
{
    int size = heap.size();

    if (size == 0)
        heap.push_back(newNum);
    else
    {
        heap.push_back(newNum);
        for (int i = size / 2 - 1; i >= 0; i--) // Heapify after addition
            heapify(heap, i);
    }
}

// Delete node from heap
void deleteNode(vector<int> &heap, int num)
{
    int size = heap.size();
    int i;
    for (i = 0; i < size; i++)
    {
        if (num == heap[i])
            break;
    }

    // Swap ith node with last node in heap
    swap(&heap[i], &heap[size - 1]);

    heap.pop_back();                        // Remove node
    for (int i = size / 2 - 1; i >= 0; i--) // Heapify after removal
    {
        heapify(heap, i);
    }
}

int main()
{
    vector<int> heapTree;

    insert(heapTree, 3);
    insert(heapTree, 4);
    insert(heapTree, 9);
    insert(heapTree, 5);
    insert(heapTree, 2);

    cout << "Max-Heap array: ";
    printArray(heapTree);

    deleteNode(heapTree, 4);

    cout << "After deleting an element: ";

    printArray(heapTree);
}