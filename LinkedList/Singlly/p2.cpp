#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* insert(Node* head, int val) {
    Node* newNode = new Node{val, nullptr};
    if (!head) return newNode;
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

void findMinMax(Node* head) {
    if (!head) return;
    int minVal = head->data, maxVal = head->data;
    head = head->next;
    while (head) {
        if (head->data < minVal) minVal = head->data;
        if (head->data > maxVal) maxVal = head->data;
        head = head->next;
    }
    cout << "Min: " << minVal << ", Max: " << maxVal << endl;
}

int main() {
    Node* head = nullptr;
    int n, val;
    cout<<"Enter range: ";
    cin >> n;
    cout<<"Enter the value: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        head = insert(head, val);
    }

    findMinMax(head);
}