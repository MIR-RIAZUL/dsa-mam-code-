
#include<iostream>

using namespace std;
struct node
{
int val;
node *next;
};
node* head=NULL;

void insrtinstart(int x)
{
    node* newitem=new node();
    newitem->val=x;
    newitem->next=head;
    head= newitem;
}
void insertlast(int val)
{
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    node* newitem = new node;
    newitem->val=val;
    temp->next= newitem;
    newitem->next=NULL;

   
}

void after(int val,int target)
{
    node* temp=head;
    while(temp!=NULL)
    {
       
        if(temp->val==target)
        {

    node* newitem = new node;
    newitem->val=val;
    
    newitem->next = temp->next;
    temp->next= newitem;
    return;
        }
         temp=temp->next;
    }

}

void deltefirst()
{
    if(head==NULL)
    {
        cout<<"the list is emlty"<<endl;

    }
    node* temp=head;
    head=head->next;
    delete(temp);

}

void deletelast() {
    if (head == NULL) {
        cout << "Nothing to delete" << endl;
        return;
    }

    if (head->next == NULL) {
        // Only one node
        delete head;
        head = NULL;
        return;
    }

    node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}


void print()
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}


int main()
{
insrtinstart(4);
insrtinstart(5);
insrtinstart(6);
insertlast(10);
print();
cout<<endl;
deletelast();
print();
}
