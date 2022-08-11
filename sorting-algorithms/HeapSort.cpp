// Time complexity: n*log(n)
// Space complexity: 1

// Heap sort is a comparison-based sorting technique based on Binary Heap data structure.
// It is similar to the selection sort where we first find the minimum element
// and place the minimum element at the beginning. Repeat the same process for the remaining elements.

#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> &arr, string prefix)
{
    cout << prefix << endl;
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
void maxHeapify(vector<int> &heap, int size, int i)
{
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
        maxHeapify(heap, size, largest);
    }
}

// Build max-heap in a bottom up manner
void buildMaxHeap(vector<int> &heap, int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        maxHeapify(heap, size, i);
}

void heapSort(vector<int> &arr)
{
    int size = arr.size();
    buildMaxHeap(arr, size);

    for (int i = size - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        maxHeapify(arr, i, 0);
    }
}

int main()
{
    vector<int> arr = {12, 23, 3, 67, 1, 78, 32, 7, 51, 47};
    printArray(arr, "Before sorting: ");
    heapSort(arr);
    printArray(arr, "After sorting: ");

    return 0;
}