#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};
void travese(Node *head)
{
    Node *temp = head;
    if (head == nullptr)
        return;
    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
void Cyclebeg(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);
    slow = head;
    int count = 1;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
        count++;
    }
    // cout << "Cycle begins at node with value: " << slow->data << endl;
    cout << "Cycle begins at node: " << count << endl;
}
bool detectCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {

            return true;
        }
    }
    return false;
}
int main()
{
    Node *head = nullptr;
    Node *newNode1 = new Node(1);
    Node *newNode2 = new Node(2);
    Node *newNode3 = new Node(3);
    Node *newNode4 = new Node(4);
    Node *newNode5 = new Node(5);
    head = newNode1;
    newNode1->next = newNode2;
    newNode2->next = newNode3;
    newNode3->next = newNode4;
    newNode4->next = newNode5;
    newNode5->next = newNode1;
    // newNode5->next=nullptr;
    if (detectCycle(head))
    {
        cout << "Cycle detected in the linked list." << endl;
        Cyclebeg(head);
    }
    else
    {
        travese(head);
        cout << "No cycle detected in the linked list." << endl;
    }

    return 0;
}