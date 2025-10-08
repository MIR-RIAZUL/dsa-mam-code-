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

void display()
{
    for(int i=0;i<MAx_SIZE;i++)
    {
        cout<<q[i]<<" ";
    }
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
            /* code */
        }
        else if (ch==3)
        {
            
        }
        
        

    }

    return 0;
}