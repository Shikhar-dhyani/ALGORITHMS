
#include <iostream>
using namespace std;

void merge(int arr[], int s, int mid, int e)
{
    int n1 = mid - s + 1, n2 = e - mid;
    int a1[n1];
    int a2[n2];
    for (int i = 0; i < n1; i++)
        a1[i] = arr[s+i];
    for (int i = 0; i < n2; i++)
        a2[i] = arr[mid+1+i];
    int  k = s;
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (a1[i] <= a2[j])
        {
            arr[k] = a1[i];
            i++;
        }
        else
        {
            arr[k] = a2[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = a1[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = a2[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int s, int e)
{
    if (s < e)
    {
        int m= s + (e - s) / 2;
        mergeSort(arr, s,m);
        mergeSort(arr, m + 1, e);
        merge(arr, s,m, e);
    }
}

// Print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver program
int main()
{
    int arr[] = {6, 5, 12, 10, 9, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, size - 1);

    cout << "Sorted array: \n";
    printArray(arr, size);
    return 0;
}