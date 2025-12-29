#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int arr[] = {-4, -1, 0, 3, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> pos;
    vector<int> neg;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            neg.push_back(arr[i] * arr[i]);
        }
        else
        {
            pos.push_back(arr[i] * arr[i]);
        }
    }
    cout << "Negative part: ";
    for (int i = 0; i < neg.size(); i++)
    {
        cout << neg[i] << " ";
    }
    cout << endl;
    cout << "Positive part: ";
    for (int i = 0; i < pos.size(); i++)
    {
        cout << pos[i] << " ";
    }
    cout << endl;
    cout << "Reversed Negative part: ";
    std::reverse(neg.begin(), neg.end());
    for (int i = 0; i < neg.size(); i++)
    {
        cout << neg[i] << " ";
    }
    cout << endl;

    int p1 = 0, p2 = 0, i = 0;
    int n = pos.size();
    int m = neg.size();
    int arr1[n + m];
    while (p1 < neg.size() && p2 < pos.size())
    {
        if (neg[p1] < pos[p2])
        {
            arr1[i++] = neg[p1++];
        }
        else
        {
            arr1[i++] = pos[p2++];
        }
    }
    while (p1 < neg.size())
    {
        arr1[i++] = neg[p1++];
    }
    while (p2 < pos.size())
    {
        arr1[i++] = pos[p2++];
    }
    cout << "Square of Sorted Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr1[i] << " ";
    }
    return 0;
}