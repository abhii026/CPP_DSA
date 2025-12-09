#include <iostream>
using namespace std;
void merge(int arr1[], int arr2[], int n1, int n2, int arr3[])
{
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            arr3[k++] = arr1[i++];
        }
        else
        {
            arr3[k++] = arr2[j++];
        }
    }
    while (i < n1)
    {
        arr3[k++] = arr1[i++];
    }
    while (j < n2)
    {
        arr3[k++] = arr2[j++];
    }
}
int printArray(int arr[], int size)
{
    cout << "Merged array: " << endl;
    cout << "[ ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
    return 0;
}
int main()
{

    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int arr3[n1 + n2];
    merge(arr1, arr2, n1, n2, arr3);
    printArray(arr3, n1 + n2);
    return 0;
}