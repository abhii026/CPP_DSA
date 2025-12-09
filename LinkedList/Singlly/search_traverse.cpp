#include <iostream>
using namespace std;

// Step 1: Node structure
struct Node
{
    int data;
    Node *next;
};

// Step 2: Function to create linked list using user input
Node *createLinkedList()
{
    Node *head = NULL;
    Node *temp = NULL;
    Node *tail = NULL;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;

        // Create new node
        temp = new Node();
        // Assign data and next pointer
        temp->data = value;
        temp->next = NULL;

        // Insert node into linked list
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    return head;
}

// Step 3: Traversal function
void traverse(Node *head)
{
    Node *current = head;
    cout << "\nLinked List: ";
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Step 4: Search function
void search(Node *head, int key)
{
    Node *current = head;
    int pos = 1;
    while (current != NULL)
    {
        if (current->data == key)
        {
            cout << key << " found at position " << pos << endl;
            return;
        }
        current = current->next;
        pos++;
    }
    cout << key << " not found in the list." << endl;
}

// Step 5: Main function
int main()
{
    Node *head = createLinkedList();
    traverse(head);

    int key;
    cout << "\nEnter value to search: ";
    cin >> key;
    search(head, key);

    return 0;
}
