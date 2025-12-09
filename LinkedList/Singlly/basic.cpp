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
Node *InsertAtRandom(Node *head, int value, int position)
{
    Node *newNode = new Node(value);
    if (position == 1)
    {
        newNode->next = head;
        return newNode;
    }
    Node *temp = head;
    for (int i = 1; i < position - 1; i++)
    {
        if (temp == NULL)
        {
            cout << "Position is greater than the length of the list." << endl;
            return head;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}
Node *InsertAtEnd(Node *head, int value)
{
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        return newNode;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}
Node *InsertAtbeggining(Node *head, int value)
{
    Node *newNode = new Node(value);
    newNode->next = head;
    return newNode;
}
void traverse(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data;
        if (head->next != nullptr)
        {
            cout << " -> ";
        }
        head = head->next;
    }
    cout << endl;
}
void search(Node *head, int value)
{
    Node *current = head;
    int pos = 1;
    while (current != nullptr)
    {
        if (current->data == value)
        {
            cout << value << " present at " << pos << " position.";
            return;
        }
        current = current->next;
        pos++;
    }
    cout << "Not found.";
}
int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    traverse(head);
    int x;
    cout << "Enter value to insert at beggining: ";
    cin >> x;
    head = InsertAtbeggining(head, x);
    traverse(head);
    int x1;
    cout << "Enter the value to insert at last: ";
    cin >> x1;
    head = InsertAtEnd(head, x1);
    traverse(head);

    int b, pos;
    cout << "Enter the position to insert at: ";
    cin >> pos;
    cout << "Enter the value to insert at random: ";
    cin >> b;
    head = InsertAtRandom(head, b, pos);
    traverse(head);

    return 0;
}