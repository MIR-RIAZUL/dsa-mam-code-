#include <iostream>

using namespace std;

struct node
{
    int val;
    node *next;
    node *prev;
};

node *head = NULL;

node *createNode(int x)
{
    node *newitem = new node();
    newitem->val = x;
    newitem->next = NULL;
    newitem->prev = NULL;
    return newitem;
}

void insertBegin(int x)
{
    node *newitem = createNode(x);

    if (head == NULL)
    {
        head = newitem;
    }
    else
    {
        newitem->next = head;
        head->prev = newitem;
        head = newitem;
    }
}

void insertlast(int x)
{
    node* newitem= createNode(x);

    node* temp=head;

    if(head==NULL)
    {
        cout<<"the list is empty"<<endl;
        insertBegin(x);
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    newitem->next =temp->next;
    temp->next=newitem;
    newitem->prev=temp;
}

void display()
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{

    insertBegin(12);
    insertBegin(13);
    display();
    insertlast(10);
    display();

    return 0;
}
