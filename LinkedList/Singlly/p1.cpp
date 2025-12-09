#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *insert(Node *head, int val)
{
    Node *newNode = new Node{val, nullptr};
    if (!head)
        return newNode;
    Node *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

void display(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void doubleValues(Node *head)
{
    while (head)
    {
        head->data *= 2;
        head = head->next;
    }
}

void sumWithPrevious(Node *head)
{
    if (!head)
        return;
    int prev = head->data;
    head = head->next;
    while (head)
    {
        head->data = head->data + prev;
        prev = head->data - prev;
        head = head->next;
    }
}

int main()
{
    Node *head = nullptr;
    int n, val;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter value: ";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        head = insert(head, val);
    }

    doubleValues(head);
    display(head);

    sumWithPrevious(head);
    display(head);
}