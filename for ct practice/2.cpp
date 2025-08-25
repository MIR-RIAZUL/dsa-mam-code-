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
     b   
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
        }
        else if (ch == 4)
        {
        }
        else if (ch == 5)
        {
        }
        else if (ch == 6)
        {
        }
        else if (ch == 66)
        {
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
        }
        else if (ch == 9)
        {
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
