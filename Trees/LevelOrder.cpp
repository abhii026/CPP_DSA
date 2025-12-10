#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* buildTreeLevelOrder() {
    int d;
    cin >> d;
    if (d == -1) return NULL;

    Node* root = new Node(d);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        int l, r;
        cin >> l;
        if (l != -1) {
            temp->left = new Node(l);
            q.push(temp->left);
        }

        cin >> r;
        if (r != -1) {
            temp->right = new Node(r);
            q.push(temp->right);
        }
    }
    return root;
}

void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelorder(Node* root) {
    if (root == NULL) return;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";

        if (temp->left != NULL) q.push(temp->left);
        if (temp->right != NULL) q.push(temp->right);
    }
}

int main() {
    Node* root = buildTreeLevelOrder();

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    cout << "Levelorder: ";
    levelorder(root);
    cout << endl;

    return 0;
}
