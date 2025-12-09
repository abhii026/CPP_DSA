#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class myStack
{
public:
    Node *head;
    myStack()
    {
        head = NULL;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    void push(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    int peek()
    {
        if (isEmpty())
            return -1;
        return head->data;
    }

    void printStack()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int prec(char c)
{
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

string infixToPostfix(string s, myStack st)
{
    string post = "";
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        char c = s[i];

        if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
            post += c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (!st.isEmpty() && st.peek() != '(')
            {
                post += st.peek();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.isEmpty() && ((c == '+' || c == '-' || c == '*' || c == '/' || c == '^') && ((c != '^' && prec(st.peek()) >= prec(c)) || (c == '^' && prec(st.peek()) > prec(c)))))
            {
                post += st.peek();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.isEmpty())
    {
        post += st.peek();
        st.pop();
    }

    return post;
}

int evalPostExp(string s, myStack st)
{
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if (c >= '0' && c <= '9')
        {
            st.push(c - '0');
        }
        else
        {
            int op2 = st.peek();
            st.pop();
            int op1 = st.peek();
            st.pop();

            switch (c)
            {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            }
        }
    }
    return st.peek();
}

int main()
{
    myStack s;

    while (true)
    {
        cout << "\n1. Push element\n";
        cout << "2. Pop element\n";
        cout << "3. Peek element\n";
        cout << "4. Check if stack is empty\n";
        cout << "5. Print stack\n";
        cout << "6. Evaluate Postfix Expression\n";
        cout << "7. Convert Infix to Postfix\n";
        cout << "8. Exit\n";
        cout << "Choose (1-8): ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int x;
            cout << "Enter value to push: ";
            cin >> x;
            s.push(x);
            break;
        }

        case 2:
            s.pop();
            break;

        case 3:
            if (s.isEmpty())
                cout << "Stack is empty.\n";
            else
                cout << "Peek element is: " << s.peek() << endl;
            break;

        case 4:
            cout << (s.isEmpty() ? "Stack is empty\n" : "Stack is not empty\n");
            break;

        case 5:
            s.printStack();
            break;

        case 6:
        {
            string exp;
            cout << "Enter postfix expression: ";
            cin >> exp;
            cout << "Result = " << evalPostExp(exp, s) << endl;
            break;
        }

        case 7:
        {
            string exp;
            cout << "Enter infix expression: ";
            cin >> exp;
            cout << "Postfix = " << infixToPostfix(exp, s) << endl;
            break;
        }

        case 8:
            cout << "!!Thankyou!!";
            return 0;

        default:
            cout << "Invalid choice\n";
        }
    }
}
