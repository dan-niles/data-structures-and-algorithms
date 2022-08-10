// Time complexity: O(n^2)
// Space complexity: 0(1)

// Bubble sort is a simple sorting algorithm that repeatedly steps through the list,
// compares adjacent elements and swaps them if they are in the wrong order.
// The pass through the list is repeated until the list is sorted.

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int length)
{
    bool swapped = true;
    while (swapped)
    {
        swapped = false;
        for (int i = 1; i < length; i++)
        {
            if (arr[i - 1] > arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                swapped = true;
            }
        }
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
    bubbleSort(arr, 10);
    printArray(arr, 10, "After sorting: ");

    return 0;
}