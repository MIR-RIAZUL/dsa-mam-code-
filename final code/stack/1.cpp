#include<iostream>

using namespace std;

int push(int stack[],int m,int top)
{
    stack[top]=m;
    top++;
    return top;

}

int pop(int stack[],int top)
{
    if(top==0)
    {
        cout<<"the stack is empty"<<endl;
        return top;
    }
    else
    {
        top--;
        cout<<"popped"<<endl;
        return top;
    }

}
void print(int stack[],int top)
{
    if(top==0)
    {
        cout<<"the stack is empty"<<endl;
    }
    else 
    {
        for(int i=top-1; i>=0;i--)
        {
            cout<<stack[i]<<",";
        }
    }
    cout<<endl;
}

void menu()
{
    cout<<"\nChoose an operation:\n";
    cout<<"1. Push in stack\n";
    cout<<"2. Pop from stack\n";
    cout<<"3. Print the stack\n";
    cout<<"4. Show top item (peek)\n";
    cout<<"5. Check if stack is empty\n";
    cout<<"6. Check stack size\n";
    cout<<"7. Check if stack is full\n";
    cout<<"8. Clear the stack\n";
    cout<<"9. Search a number\n";
    cout<<"-----------------------------------\n";
}

int main()
{
    int size;
    cout<<"enter your stack size:";
    cin>>size;
    int stack[size];
    int top=0;
    int ch,m,n;
    while (1)
    {
        menu();
        cin>>ch;
        if(ch==1)
        {
            if(top<size)
            {
            cout<<"enter the number:"<<endl;
            cin>>m;
            top=push(stack,m,top);
            }
            else
            {
                cout<<"the stack is full deaa one"<<endl;
            }
        }
        else if (ch==2)
        {
            /* code */
        }
        else if (ch==3)
        {
            print(stack,top);
        }
        
        

    }
    
}