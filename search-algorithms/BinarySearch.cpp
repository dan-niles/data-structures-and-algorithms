#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int h, int x)
{
    while (l <= h)
    {
        int mid = l + ((h - l) / 2);
        if (arr[mid] == x)
            return mid;
        if (x > arr[mid])
            l = mid + 1;
        else
            h = mid - 1;
    }
    return -1;
}

int binarySearchRec(int arr[], int l, int h, int x)
{
    if (l <= h)
    {
        int mid = l + (h - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearchRec(arr, l, mid - 1, x);

        return binarySearchRec(arr, mid + 1, h, x);
    }

    return -1;
}

int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearchRec(arr, 0, n - 1, x);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
    return 0;
}