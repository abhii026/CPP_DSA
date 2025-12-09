#include <iostream>
using namespace std;

int qsize = 5;
int qrear = -1;
int qfront = -1;
int Q[5];

void enqueue(int data)
{
    if ((qrear + 1) % qsize == qfront)
    {
        cout << "full" << endl;
    }
    else if (qfront == -1)
    {
        qfront = qrear = 0;
        Q[qrear] = data;
    }
    else
    {
        qrear = (qrear + 1) % qsize;
        Q[qrear] = data;
    }
}

void dequeue()
{
    if (qfront == -1)
    {
        cout << "Empty." << endl;
    }
    else if (qfront == qrear)
    {
        qfront = qrear = -1;
    }
    else
    {
        qfront = (qfront + 1) % qsize;
    }
}

void display()
{
    if (qfront == -1)
    {
        cout << "Empty." << endl;
        return;
    }
    int i = qfront;
    while (true)
    {
        cout << Q[i] << " ";
        if (i == qrear)
            break;
        i = (i + 1) % qsize;
    }
}

int main()
{
    int n;
    cout << "No of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int val;
        cout << "Enter " << i + 1 << "th value: ";
        cin >> val;
        enqueue(val);
    }

    display();
    return 0;
}
