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

void merge(int A[], int p, int q, int r)
{
    int n1, n2;
    n1 = q - p + 1;
    n2 = r - q;

    int L[n1], R[n2];
    int i, j, k;
    for (i = 0; i < n1; i++)
    {
        L[i] = A[p + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = A[q + j + 1];
    }

    i = 0;
    j = 0;
    k = p;

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

void mergeSort(int A[], int p, int r)
{
    if (p >= r)
        return;

    int q;
    q = (p + r) / 2;

    mergeSort(A, p, q);
    mergeSort(A, q + 1, r);
    merge(A, p, q, r);
}

int main()
{
    int A[10] = {12, 23, 3, 67, 1, 78, 32, 7, 51, 47};
    printArray(A, 10, "Before sorting: ");
    mergeSort(A, 0, 9);
    printArray(A, 10, "After sorting: ");
    return 0;
}