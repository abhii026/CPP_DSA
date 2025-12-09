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
void insertAtPosition(int arr[], int &current, int maxs, int element, int position)
{
    if (current >= maxs)
    {
        cout << "Array is full" << endl;
        return;
    }
    if (position < 0 || position > current)
    {
        cout << "Invalid position" << endl;
        return;
    }
    for (int i = current - 1; i >= position; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[position] = element;
    current++;
}
void insertAtBeginning(int arr[], int &current, int maxs, int element)
{
    insertAtPosition(arr, current, maxs, element, 0);
}
void insertAtEnd(int arr[], int &current, int maxs, int element)
{
    insertAtPosition(arr, current, maxs, element, current);
    int main()
    {

        int maxs = 20;
        int current = 6;
        int arr[current] = {1, 2, 3, 4, 5, 6};
        int element, position;
        cout << "Enter element to insert: ";
        cin >> element;
        cout << "Enter position to insert: ";
        cin >> position;
        if (position == 0)
            cout << "Inserting at the beginning" << endl;

        else if (position == current)
            cout << "Inserting at the end" << endl;
        else
            cout << "Inserting at position " << position << endl;
        insertAtPosition(arr, current, maxs, element, position);
        PrintArray(arr, current);
        return 0;
    }
