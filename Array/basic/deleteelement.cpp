#include <iostream>
using namespace std;
void PrintArray(int arr[], int current)
{
    for (int i = 0; i < current; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void deleteAtPosition(int arr[], int &current, int position)
{
    if (current <= 0)
    {
        cout << "Array is empty" << endl;
        return;
    }
    if (position < 0 || position >= current)
    {
        cout << "Invalid position" << endl;
        return;
    }
    for (int i = position; i < current - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    current--;
}
int main()
{

    int maxs = 20;
    int current = 6;
    int arr[current] = {1, 2, 3, 4, 5, 6};
    int position;
    cout << "Enter position to delete: ";
    cin >> position;
    deleteAtPosition(arr, current, position);
    PrintArray(arr, current);
    return 0;
}