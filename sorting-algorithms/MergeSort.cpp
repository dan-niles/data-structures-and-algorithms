// Time complexity: O(n*log(n))
// Space complexity: O(n)

// The Merge Sort algorithm is a sorting algorithm that is considered an example of the divide and conquer strategy.
// So, in this algorithm, the array is initially divided into two equal halves and then they are combined in a sorted manner.

#include <iostream>
using namespace std;

void printArray(int A[], int length, string prefix = "")
{
    cout << prefix;
    cout << "[ ";
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
    cout << "]" << endl;
}

// Time Complexity: O(n)
void merge(int A[], int left, int mid, int right)
{
    int n1, n2;
    n1 = mid - left + 1; // No of elements in first half
    n2 = right - mid;    // No of elements in second half

    int L[n1], R[n2]; // Create two arrays to store both halves seperately
    int i, j, k;

    // Copy values from first half of array into L
    for (i = 0; i < n1; i++)
        L[i] = A[left + i];

    // Copy values from second half of array into R
    for (j = 0; j < n2; j++)
        R[j] = A[mid + j + 1];

    i = 0;
    j = 0;
    k = left;

    // Compare elements from L and R
    // and put them in correct location in main array
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    // Handling last element that hasn't been sorted yet
    while (i < n1)
    {
        A[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        A[k] = R[j];
        j++;
        k++;
    }
}

// Time Complexity: O(n)
void merge2(int A[], int left, int mid, int right)
{
    int n1, n2;
    n1 = mid - left + 1; // No of elements in first half
    n2 = right - mid;    // No of elements in second half

    int L[n1 + 1], R[n2 + 1]; // Create two arrays to store both halves seperately
    int i, j, k;

    // Copy values from first half of array into L
    for (i = 0; i < n1; i++)
        L[i] = A[left + i];

    // Copy values from second half of array into R
    for (j = 0; j < n2; j++)
        R[j] = A[mid + j + 1];

    // Set last values as infinity to avoid
    // handling remainders like in above Merge function
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    i = 0;
    j = 0;
    k = left;

    for (k = left; k <= right; k++)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int A[], int left, int right)
{
    if (left >= right)
        return;

    int mid;
    mid = (left + right) / 2; // Find index of element in middle

    mergeSort(A, left, mid);      // Perform merge sort on first half of array
    mergeSort(A, mid + 1, right); // Perform merge sort on second half of array
    merge2(A, left, mid, right);  // Merge the two halves
}

int main()
{
    int A[10] = {12, 23, 3, 67, 1, 78, 32, 7, 51, 47};
    printArray(A, 10, "Before sorting: ");
    mergeSort(A, 0, 9);
    printArray(A, 10, "After sorting: ");
    return 0;
}