// Worst complexity: O(log n)
// Space complexity: O(1)

// Binary search is an efficient algorithm for finding an item from a sorted list of items.
// It works by repeatedly dividing in half the portion of the list that could contain the item,
// until you've narrowed down the possible locations to just one.

// IMPORTANT : ARRAY MUST BE SORTED BEFORE DOING A BINARY SEARCH!

#include <iostream>
using namespace std;

// Iterative binary search
int binarySearch(int arr[], int left, int right, int key)
{
    while (left <= right)
    {
        int mid = left + ((right - left) / 2); // Find index of middle element

        if (arr[mid] == key) // Check if search value is in the middle
            return mid;

        if (key > arr[mid])
            left = mid + 1; // Check in right sub-array if search value is greater than mid value
        else
            right = mid - 1; // Check in left sub-array if search value is less than mid value
    }

    return -1; // Value not found
}

// Recursive binary search
int binarySearchRec(int arr[], int left, int right, int key)
{
    if (left <= right)
    {
        int mid = left + (right - left) / 2; // Find index of middle element

        if (arr[mid] == key) // Check if search value is in the middle
            return mid;

        if (arr[mid] > key)
            return binarySearchRec(arr, left, mid - 1, key); // Check in right sub-array if search value is greater than mid value

        return binarySearchRec(arr, mid + 1, right, key); // Check in left sub-array if search value is less than mid value
    }

    return -1; // Value not found
}

int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int key = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearchRec(arr, 0, n - 1, key);

    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;

    return 0;
}