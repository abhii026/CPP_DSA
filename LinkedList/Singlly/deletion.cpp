#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int new_data) {
        data = new_data;
        next = NULL;
    }
};

Node* insertAtend(Node *head, int value) {
    Node *newNode = new Node(value);
    if (head == NULL) return newNode;
    Node *temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    return head;
}

void traverse(Node *head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next != NULL) cout << " -> ";
        head = head->next;
    }
}

Node* deleteAtBeginning(Node *head) {
    if (head == NULL) {
        cout << "List is empty";
        return NULL;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* deleteAtend(Node *head) {
    if (head == NULL) {
        cout << "!!Empty List!!";
        return NULL;
    }
    if (head->next == NULL) {
        delete head;
        return NULL;
    }
    Node *temp = head;
    while (temp->next->next != NULL) temp = temp->next;
    Node *todelete = temp->next;
    temp->next = NULL;
    delete todelete;
    return head;
}

Node* deleteAtrandom(Node *head, int pos) {
    if (head == NULL || pos < 1) {
        cout << "Invalid";
        return head;
    }
    if (pos == 1) return deleteAtBeginning(head);

    int count = 1;
    Node *temp = head;
    while (temp != NULL && count != pos - 1) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL || temp->next == NULL) {
        cout << "Invalid";
        return head;
    }
    Node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
    return head;
}

int main() {
    Node *head = NULL;
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter value: ";
    for (int i = 1; i <= n; i++) {
        int value;
        cin >> value;
        head = insertAtend(head, value);
    }
    cout << "\nLinkedList: " << endl;
    traverse(head);

    head = deleteAtend(head);
    
    cout << "\nModified linkedlist: " << endl;
    traverse(head);
    return 0;
}
