#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};
node *head = NULL;

node *createnode(int num)
{
    node *newnode = new node();
    newnode->data = num;
    newnode->next = NULL;
    return newnode;
}

void inserthead(int num)
{
    node *newnode = createnode(num);
    newnode->next = head;
    head = newnode;
}
void print()
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->"; // Fixed: prints values in a single line with arrows
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insertTail(int x)
{
    node *newnode = createnode(x);

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
void insert_nth_node(int pos,int x)
{
    node* newnode=createnode(x);
    node* temp=head;

    for(int i =1;i<pos;i++)
    {
        temp=temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void after_value(int x,int val)
{
     node* newnode= createnode(x);

     node* temp=head;

     while(temp->data !=val)
     {
        temp=temp->next;
     }
     newnode->next =temp->next;
     temp->next=newnode;
}
void deletHead()
{
    node* temp= head;
    head=head->next;
    delete temp;

}

void deleteTail()
{
    node* temp= head;
    while(temp->next->next !=NULL)
    {
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;

}
void deletNth(int num)
{
    node* temp=head;
    for(int i=0;i<num-1;i++)
    {
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;

}

void deleteAfter(int x)
{
    node* temp=head;

    while(temp->data !=x)
    {
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}

void reverseList()
{
    node* pre =NULL;
    node* current =head;
    node* next =NULL;
    while(current!=NULL)
    {
        next= current->next;
        current ->next=pre;
        pre =current;
        current=next;
    }
    head=pre;

}
node* findMiddle()
{
    node* slow=head;
    node* fast=head;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}


void choice()
{
    cout << "1. Insert at head" << endl;
    cout << "2. insert at tail" << endl;
    cout << "3. Insert at position" << endl;
    cout << "33.Insert after the value" << endl;
    cout << "4. Delete at head" << endl;
    cout << "5. Delete at tail" << endl;
    cout << "6. Delete at position" << endl;
    cout << "66.Delete after the value" << endl;
    cout << "7. Search" << endl;
    cout << "8. Print list" << endl;
    cout << "88.prent reversed list" << endl;
    cout << "9. Find middle element" << endl;
    cout << "10. Count nodes" << endl;
    cout << "11. Insert at middle" << endl;
    cout << "12.printNthnode" << endl;
    cout << "13.nthNodefromMiddle" << endl;
    cout << "0. Exit" << endl;

    cout << "Enter your choice: ";
    cout << endl;
}

int main()
{
    while (true)
    {
        choice();

        int ch;
        cin >> ch;

        if (ch == 1)
        {
            int num;
            cout << "enter your number:" << endl;
            cin >> num;
            inserthead(num);
        }
        else if (ch == 2)
        {

            int num;
            cout << "enter your number:" << endl;
            cin >> num;
            insertTail(num);
        }
        else if (ch == 3)
        {
             int num;
             int pos;
            cout << "enter your number:" << endl;
            cin >> num;
            cout<<"enter yout position that you =want to add"<<endl;
            cin>>pos;
            insert_nth_node( pos,num);
    
        }
        else if (ch == 33)
        {
            int x,val;

            cout<<"enter the data"<<endl;
            cin>>x;
            cout<<"enter the number that you want to place to the next"<<endl;
            cin>>val;

            after_value( x,val);
        }
        else if (ch == 4)
        {
            deletHead();
        }
        else if (ch == 5)
        {
            deleteTail();
        }
        else if (ch == 6)
        {
            cout<<"enter the position you want to delete"<<endl;
            int pos;
            cin>>pos;
         deletNth(pos);

        }
        else if (ch == 66)
        {
            cout<<"enter the value,that you want to delete After"<<endl;
            int x;
            cin>>x;
            deleteAfter(x);
        }
        else if (ch == 7)
        {

        }
        else if (ch == 8)
        {
            print();
        }
        else if (ch == 88)
        {
            reverseList();
        }
        else if (ch == 9)
        {
         cout<<findMiddle()->data<<endl;

        }
        else if (ch == 10)
        {
        }
        else if (ch == 11)
        {
        }
        else if (ch == 12)
        {
        }
        else if (ch == 13)
        {
        }

        else if (ch == 0)
        {
            break; // Exit the loop
        }
        else
        {
            cout << "Invalid choice, please try again." << endl;
        }
    }
    cout << "Exiting program." << endl;
    return 0;
}
//linklist to array


// // Function to convert a singly linked list into an array
// void To_Array(struct node *head, int *array) {
//     struct node *current = head;
//     int i = 0;
//     // Traverse the linked list and copy elements to the array
//     while (current != NULL) {
//         array[i] = current->num;
//         current = current->nextptr;
//         i++;
//     }
// }



