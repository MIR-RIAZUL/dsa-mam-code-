#include<iostream>
using namespace std;
#define MAx_SIZE 5

int q[MAx_SIZE];
int front=-1,rear=-1,current_size=0;


void enqueue(int x)
{
    if(current_size==MAx_SIZE)
    {
        cout<<"overflow"<<endl;
    }
    else
    {
        if(current_size==0)
        {
            front=0;
        }
        rear=(rear+1)%MAx_SIZE;
        q[rear]=x;
        current_size++;
    }
}

int dequeue()
{
    if(current_size==0)
    cout<<"underflow"<<endl;
    else
    {
        int temp=q[front];
        q[front]=-1000;
        front=(front+1)%MAx_SIZE;
        current_size--;
        return temp;
    }
}

void display()
{
    for(int i=0;i<current_size;i++)
    {
        int index=(front+i)% MAx_SIZE;
        cout<<q[index]<<" ";
    }
    cout<<endl;
}

void menu()
{
    cout<<"enter your choice"<<endl;
    cout<<"1. enqueue in the liist:"<<endl;
    cout<<"2. dequeue from the liist:"<<endl;
    cout<<"3.print the list"<<endl;
    cout<<"enter your choice:"<<endl;

}

int main()
{

    int n,m,x;
    int ch;
    while(1)
    {
        menu();
        cin>>ch;
        if(ch==1)
        {
            cout<<"enter your number:";
            cin>>x;
            enqueue(x);

        }
        else if (ch==2)
        {
            dequeue();
        }
        else if (ch==3)
        {
            display();
        }
        
        

    }

    return 0;
}