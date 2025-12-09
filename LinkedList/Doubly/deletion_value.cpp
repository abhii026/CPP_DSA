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