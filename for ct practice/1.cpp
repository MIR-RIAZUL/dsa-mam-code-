#include <iostream>
using namespace std;

struct node

{
    int val;
    node *next;
};

node *head = NULL;

void inserthead(int x)
{
    node *newitem = new node();
    newitem->val = x;
    newitem->next = head;
    head = newitem;
}

void insertend(int x)
{
    node* newitem= new node();
    newitem->val = x;
    newitem->next = NULL;
    if(head == NULL)
    {
        head = newitem;
        return;
    }
    node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newitem;
}

void insert_in_position(int x,int pos)
{
    node *newitem = new node();
    newitem->val = x;
    if (pos == 0) // Insert at head
    {
        newitem->next = head;
        head = newitem;
        return;
    }
    node *temp = head;
   for(int i=0;i<pos-1;i++)
   {
    temp = temp->next;
   }
   newitem->next= temp->next;
   temp->next = newitem;
}

void printlist()
{
    cout<<endl;
    cout<< "List: ";
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }  
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

}

void choice()
{
    cout << "1.Insert at head" << endl;
    cout << "2.insert at tail" << endl;
    cout << "3. Insert at position" << endl;
    cout << "4. Delete at head" << endl;
    cout << "5. Delete at tail" << endl;
    cout << "6. Delete at position" << endl;
    cout << "7. Search" << endl;
    cout << "8. Print list" << endl;
    cout << "9. Exit" << endl;
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
            int x;
            cout << "Enter value to insert at head: ";
            cin >> x;
            inserthead(x);
        }
        else if (ch == 2)
        {
            int x;
            cout << "Enter value to insert at tail: ";
            cin >> x;
            insertend(x);
        }
        else if (ch == 3)
        {
            int x;
            int pos;
            cout << "Enter value to insert and position: ";
            cin >> x >> pos;
            insert_in_position(x, pos);
        }
        else if (ch == 4)
        {
            // Delete at head logic can be added here
        }
        else if (ch == 5)
        {
            // Delete at tail logic can be added here
        }
        else if (ch == 6)
        {
            // Delete at position logic can be added here
        }
        else if (ch == 7)
        {
            // Search logic can be added here
        }
        else if (ch == 8)
        {
            printlist();
            cout << endl;
        }
        else if (ch == 9)
        {
            break; // Exit the loop
        }
        else
        {
            cout << "Invalid choice, please try again." << endl;
        }
    }
    cout << "Exiting program." << endl;
    printlist();
    return 0;
}
