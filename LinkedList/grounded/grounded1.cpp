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
Node *insertAtbeg(Node *header, int key)
{

    Node *newNode = new Node(key);
    if (header == nullptr)
    {
        header->next = newNode;
        return;
    }
    else
    {
        newNode->next = header->next;
        header->next = newNode;
        return header;
        
    }
}
// Node* createGroundedList(int n){
//     Node* head=new Node(1);
//     Node* temp=head;
//     for(int i=2;i<=n;i++){
//         temp->next=new Node(i);
//         temp=temp->next;
//     }
//     return head;
// }
void traverse(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}
int main()
{

    Node *header = new Node(0);
    // Node* ground=createGroundedList(5);
    insertAtbeg(header, 5);
    insertAtbeg(header, 4);
    insertAtbeg(header, 3);
    insertAtbeg(header, 2);
    Node *ground = insertAtbeg(header, 1);
    header->next = ground;
    traverse(header);
    return 0;
}