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

void peek(int stack[],int top)
{
    if(top==0)
    {
        cout<<"the list is empty"<<endl;
    }
    else 
    {
        cout<<"the top value is:"<<stack[top-1]<<endl;
    }
}

void sizee(int stack[],int top)
{
    if(top==0)
    {
        cout<<"the stack is empty"<<endl;
    }
    else
    {
        cout<<"the size is:"<<top<<endl;
    }
}

int clear(int top)
{
    if(top==0)
    {
        cout<<"nothing to clear.. its already empty"<<endl;
    }
    else 
    {
        cout<<"the stack is enpty now"<<endl;
        return 0;
    }
}

void search(int stack[],int top,int n)
{
    int idx=0;
    
    if(top==0)
    {
        cout<<"the list is empty"<<endl;
    }
    for(int i=top-1;i>=0;i--)
    {
        if(n==stack[i])
        {
            cout<<"find at index:"<<idx<<endl;
        }
        idx++;
    }

}

void menu()
{
    cout<<"\nChoose an operation:\n";
    cout<<"1. Push in stack\n";
    cout<<"2. Pop from stack\n";
    cout<<"3. Print the stack\n";
    cout<<"4. Show top item (peek)\n";
    cout<<"5. Check stack size\n";
    cout<<"6. Check if stack is full\n";
    cout<<"7. Clear the stack\n";
    cout<<"8. Search a number\n";
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
            top=pop(stack,top);
        }
        else if (ch==3)
        {
            print(stack,top);
        }
        else if (ch==4)
        {
            peek(stack,top);
        }
        else if (ch==5)

        {
            sizee(stack,top);
        }
        else if (ch==6)
        {
            if(top==size)
            {
                cout<<"the stack is full"<<endl;
            }
            else
            {
                cout<<"the stack is not  full"<<endl;
            }
        }
        else if (ch==7)
        {
            top=clear(top);
        }
        else if (ch==8)
        {
            cout<<"what number,you want to search"<<endl;
            cin>>n;
            search(stack,top,n);
        }
        
        
        
        
        
        
    }
    
}