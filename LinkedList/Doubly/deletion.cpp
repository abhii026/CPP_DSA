#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *previous;
    Node(int new_data)
    {
        this->data = new_data;
        this->next = NULL;
        this->previous = NULL;
    }
};
void deleteAtbeg(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    if (head != NULL)
    {
        head->previous = NULL;
    }
    delete temp;
}
void deleteAtend(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp->previous != NULL)
    {
        temp->previous->next = NULL;
    }
    else
    {
        head = NULL;
    }
    delete temp;
}
void deleteAtrandom(Node *&head, int position)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (position <= 0)
    {
        cout << "❌ Invalid position: " << position << endl;
        return;
    }
    if (position == 1)
    {
        deleteAtbeg(head);
        return;
    }
    Node *temp = head;
    int count = 1;
    while (temp != NULL && count < position)
    {
        temp = temp->next;
        count++;
    }
    if (temp == NULL)
    {
        cout << "❌ Invalid position: " << position << endl;
        return;
    }
    if (temp->previous != NULL)
    {
        temp->previous->next = temp->next;
    }
    if (temp->next != NULL)
    {
        temp->next->previous = temp->previous;
    }
    delete temp;
}

void insertAtBeginning(Node *&head, int data)
{
    Node *new_node = new Node(data);
    if (head == NULL)
    {
        head = new_node;
        return;
    }
    new_node->next = head;
    head->previous = new_node;
    head = new_node;
}
void insertAtend(Node *&head, int data)
{
    Node *new_node = new Node(data);
    if (head == NULL)
    {
        head = new_node;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->previous = temp;
}
void insertAtrandom(Node *&head, int data, int position)
{
    if (position <= 0)
    {
        cout << "❌ Invalid position: " << position << endl;
        return;
    }

    // insert at beginning if position == 1
    if (position == 1)
    {
        insertAtBeginning(head, data);
        return;
    }

    Node *temp = head;
    int count = 1;

    // move to position - 1
    while (temp != NULL && count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    // if position > length + 1
    if (temp == NULL)
    {
        cout << "❌ Invalid position: " << position << endl;
        return;
    }

    Node *new_node = new Node(data);
    new_node->next = temp->next;
    new_node->previous = temp;

    if (temp->next != NULL)
        temp->next->previous = new_node;

    temp->next = new_node;
}
void search(Node *&head)
{
    int key;
    cout << "Key to search: ";
    cin >> key;
    Node *temp = head;
    int position = 1;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            cout << "✅ Element " << key << " found at position " << position << endl;
            return;
        }
        temp = temp->next;
        position++;
    }
    cout << "❌ Element " << key << " not found in the list" << endl;
}
void traverse(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data;
        if (temp->next != nullptr)
        {
            cout << " <=> ";
        }

        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node *head = NULL;
    int n;
    cout << "No. of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        insertAtend(head, value);
    }
    traverse(head);
    int value;
    cout << "Value: ";
    cin >> value;
    int position;
    cout << "Position: ";
    cin >> position;
    if (position == 0)
    {
        insertAtBeginning(head, value);
    }
    else if (position == n)
    {
        insertAtend(head, value);
    }
    else
    {
        insertAtrandom(head, value, position);
    }
    traverse(head);
    deleteAtbeg(head);
    traverse(head);
    deleteAtend(head);
    traverse(head);
    cout << "Position to delete: ";
    cin >> position;
    deleteAtrandom(head, position);
    traverse(head);

    return 0;
}
