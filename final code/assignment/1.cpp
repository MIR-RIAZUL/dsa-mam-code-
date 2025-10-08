#include<iostream>
using namespace std;

int push(int stack[], int x, int top, int n)
{
    if(top == n)
    {
        cout << "Stack overflow! Cannot push " << x << endl;
        return top;
    }
    stack[top] = x;
    top++;
    return top;
}

int pop(int stack[], int top)
{
    if(top == 0)
    {
        cout << "The stack is empty" << endl;
        return top;
    }
    else
    {
        top--;
        return top;
    }
}

void display(int stack[], int top)
{
    if(top == 0)
    {
        cout << "The stack is empty" << endl;
    }
    else
    {
        cout<<"stacksize:"<<top<<endl;
        cout << "Stack elements: ";
        for(int i = top - 1; i >= 0; i--)
        {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

void menu()
{
    cout << "\n1. Push\n2. Pop\n3. Display\nEnter your choice: ";
}

int main()
{
    int n, x;
    int top = 0;
    cout << "Enter stack size: ";
    cin >> n;
    int stack[n];

    while(true)
    {
        menu();
        int ch;
        cin >> ch;

        switch(ch)
        {
            case 1:
                cout << "Enter the value: ";
                cin >> x;
                top = push(stack, x, top, n);
                break;
            case 2:
                top = pop(stack, top);
                break;
            case 3:
                display(stack, top);
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}
