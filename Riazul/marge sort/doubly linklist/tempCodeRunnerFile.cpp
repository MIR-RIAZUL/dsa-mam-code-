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
        newitem->next = head;
        head->prev = newitem;
    }
    head = newitem;
}

void display()
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->val << "->";
    }
    cout << "NULL" << endl;
}

int main()
{

    insertBegin(12);
    insertBegin(13);
    display();

    return 0;
}