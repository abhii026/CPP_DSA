#include <iostream>
using namespace std;

const int cap = 4;

class myStack
{
public:
    int arr[cap];
    int top;

    myStack()
    {
        top = -1;
    }

    bool isFull() const
    {
        return (top == cap - 1);
    }

    bool isEmpty() const
    {
        return (top == -1);
    }

    void push(int data)
    {
        if (!isFull())
        {
            arr[++top] = data;
        }
        else
        {
            cout << "Overflow\n";
        }
    }

    void pop()
    {
        if (!isEmpty())
        {
            --top;
        }
        else
        {
            cout << "Underflow\n";
        }
    }

    int peek() const
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    void printstack() const
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return;
        }
        for (int i = top; i >= 0; --i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    myStack s;
    int choice;

    while (true)
    {
        cout << "\n----- STACK MENU -----\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Print Stack\n";
        cout << "5. Check Empty\n";
        cout << "6. Check Full\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int value;
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        }

        case 2:
            s.pop();
            break;

        case 3:
        {
            int topElement = s.peek();
            if (topElement != -1)
                cout << "Top element: " << topElement << endl;
            break;
        }

        case 4:
            s.printstack();
            break;

        case 5:
            cout << (s.isEmpty() ? "Stack is empty\n" : "Stack is not empty\n");
            break;

        case 6:
            cout << (s.isFull() ? "Stack is full\n" : "Stack is not full\n");
            break;

        case 7:
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
