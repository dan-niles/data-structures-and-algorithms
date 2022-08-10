// Time complexity: O(n^2)
// Space Complexity: O(1)

// Insertion sort is a simple sorting algorithm that builds the final sorted array one item at a time.
// It  places an unsorted element at its suitable place in each iteration.

#include <iostream>
using namespace std;

void insertionSort(int arr[], int length)
{
    int key, i;
    for (int j = 1; j < length; j++)
    {
        key = arr[j];
        i = j - 1;
        while (i >= 0 && arr[i] > key)
        {
            arr[i + 1] = arr[i]; // Swap operation
            i -= 1;
        }
        arr[i + 1] = key;
    }
}

void printArray(int arr[], int length, string prefix = "")
{
    cout << prefix;
    cout << "[ ";
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

int main()
{
    int arr[10] = {12, 23, 3, 67, 1, 78, 32, 7, 51, 47};
    printArray(arr, 10, "Before sorting: ");
    insertionSort(arr, 10);
    printArray(arr, 10, "After sorting: ");

    return 0;
}