#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int new_data)
    {
        this->data = new_data;
        this->next = NULL;
    }
};

// Insert at beginning
Node *InsertAtBeginning(Node *head, int value)
{
    Node *newNode = new Node(value);
    newNode->next = head;
    return newNode;
}

// Insert at end
Node *InsertAtEnd(Node *head, int value)
{
    Node *newNode = new Node(value);
    if (head == NULL)
        return newNode;

    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Insert at random (middle)
Node *InsertAtRandom(Node *head, int value, int position)
{
    Node *newNode = new Node(value);
    Node *temp = head;
    for (int i = 1; i < position; i++)
    {
        if (temp == NULL)
        {
            cout << "Invalid position." << endl;
            return head;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Traverse list
void traverse(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data;
        if (head->next != nullptr)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        head = InsertAtEnd(head, val);
    }

    cout << "Linked List: ";
    traverse(head);

    int pos, val;
    cout << "Enter position to insert (0 for beginning, " << n + 1 << " for end): ";
    cin >> pos;
    cout << "Enter value to insert: ";
    cin >> val;

    if (pos == 0)
    {
        head = InsertAtBeginning(head, val);
        cout << "Modified Linked List: ";
        traverse(head);
    }
    else if (pos == n + 1)
    {
        head = InsertAtEnd(head, val);
        cout << "Modified Linked List: ";
        traverse(head);
    }
    else if (pos > 0 && pos <= n)
    {
        head = InsertAtRandom(head, val, pos);
        cout << "Modified Linked List: ";
        traverse(head);
    }
    else
    {
        cout << "Invalid position." << endl;
    }

    return 0;
}
