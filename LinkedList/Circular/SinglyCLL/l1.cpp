#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void deleteAtbeginning(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (head->next == head)
    {
        delete head;
        head = NULL;
        return;
    }
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    Node *toDelete = head;
    head = head->next;
    temp->next = head;
    delete toDelete;
}void deleteAtend(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (head->next == head)
    {
        delete head;
        head = NULL;
        return;
    }
    Node *temp = head;
    while (temp->next->next != head)
    {
        temp = temp->next;
    }
    Node *toDelete = temp->next;
    temp->next = head;
    delete toDelete;
}
void deleteAtrandom(Node *&head, int position)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    // ✅ Position should start from 1
    if (position <= 0)
    {
        cout << "❌ Invalid position: " << position << endl;
        return;
    }

    // ✅ Case 1: Delete head (position = 1)
    if (position == 1)
    {
        // Only 1 node
        if (head->next == head)
        {
            delete head;
            head = NULL;
            return;
        }

        // Find last node
        Node *last = head;
        while (last->next != head)
            last = last->next;

        Node *toDelete = head;
        head = head->next;      // Move head
        last->next = head;      // Fix circular link
        delete toDelete;
        return;
    }

    // ✅ Case 2: Delete middle or end
    Node *temp = head;
    int count = 1;

    // Move to (position - 1)th node
    while (count < position - 1 && temp->next != head)
    {
        temp = temp->next;
        count++;
    }

    // If position out of range
    if (temp->next == head)
    {
        cout << "❌ Invalid position: " << position << endl;
        return;
    }

    // Node to delete
    Node *toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
}


void insertAtBeginning(Node *&head, int data)
{
    Node *new_node = new Node(data);
    if (head == NULL)
    {
        head = new_node;
        head->next = head;
        return;
    }
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = head;
    head = new_node;
}
void insertAtend(Node *&head, int data)
{
    Node *new_node = new Node(data);
    if (head == NULL)
    {
        head = new_node;
        head->next = head;
        return;
    }
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = head;
}
void traverse(Node *&head)
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    cout << "Circular Linked List: ";
    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
Node* findMiddle(Node* head)
{
    if (head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;         // move 1 step
        fast = fast->next->next;   // move 2 steps
    }

    return slow;   // slow is at middle
}

int main()
{
    Node *head = NULL;
    int n;
    cout << "Number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        insertAtend(head, value);
    }
    traverse(head);
    // insertAtBeginning(head, 10);
    // deleteAtbeginning(head);
    // deleteAtend(head);
    // int pos;
    // cout << "Position to delete: ";
    // cin >> pos;
    // deleteAtrandom(head, pos);
    Node* mid = findMiddle(head);
    cout << "Middle Node: " << mid->data << endl;
    

    // traverse(head);
    return 0;
}

git remote add origin https://github.com/abhii026/CPP_DSA