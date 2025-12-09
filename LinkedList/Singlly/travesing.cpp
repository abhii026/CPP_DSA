#include <iostream>
#include <vector>
using namespace std;

// Step 1: Define a Node structure
struct Node
{
    int data;   // data part
    Node *next; // pointer to the next node
};

// Step 2: Declare head pointer (start of linked list)
Node *head = NULL; // initially list is empty

// Step 3: Function to insert new node at the end
void insert(int value)
{
    // Create a new node
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    // If list is empty, new node becomes head
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        // Otherwise, find last node and link new node
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    cout << "Inserted " << value << " into the list.\n";
}

// Step 4: Function to traverse the list
void traverse()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    Node *temp = head;
    cout << "Linked List elements: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void arr(Node *head)
{
    Node *temp = head;
    vector<int> v;
    // int i = 0;
    while (temp != NULL)
    {
        v.push_back(temp->data);
        temp = temp->next;
    }
    for (int x : v)
    {
        cout << x << " ";
    }
}
void swap(vector v,int )

// Step 5: Function to search for an element
void search(int key)
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    Node *temp = head;
    int position = 1;
    bool found = false;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            cout << "Element " << key << " found at position " << position << ".\n";
            found = true;
            break;
        }
        temp = temp->next;
        position++;
    }

    if (!found)
    {
        cout << "Element " << key << " not found in the list.\n";
    }
}

// Step 6: Main function (Menu-driven)
int main()
{
    int choice, value;
    while (true)
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert element\n";
        cout << "2. Traverse Array\n";
        cout << "3. Search element\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            insert(value);
            break;
        case 2:
            arr(head);
            break;
        case 3:
            cout << "Enter value to search: ";
            cin >> value;
            search(value);
            break;
        case 4:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
