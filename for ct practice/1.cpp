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
   for(int i=1;i<pos-1;i++)
   {
    temp = temp->next;
   }
   newitem->next= temp->next;
   temp->next = newitem;
}
 void insert_after_value(int x, int value)
 {
    node* newitem = new node();
    newitem->val = x;
    if (head == NULL) // If list is empty
    {
        cout << "List is empty, cannot insert after value." << endl;
        return;
    }
    node* temp = head;
    while(temp != NULL && temp->val != value)
    {
        temp = temp->next;
    }
    newitem->next = temp->next;
    temp->next = newitem;

 }

 void deletehead()
 {
    if (head == NULL)
    {
        cout << "List is empty, cannot delete head." << endl;
        return;
    }
    node* temp=head;
    head = head->next;
    delete temp;   
 }
 void deletetail()
 {
    if(head == NULL)
    {
        cout << "List is empty, cannot delete tail." << endl;
        return;
    }
    if(head->next == NULL) // Only one element
    {
        delete head;
        head = NULL;
        return;
    }
    node* temp = head;
    while(temp->next->next != NULL) // Traverse to the second last node
    {
        temp = temp->next;
    }
    delete temp->next; // Delete the last node
     temp->next = NULL; // Set the second last node's next to NULL
}

void delete_at_position(int pos)
{ 
    if(head == NULL)
    {
        cout << "List is empty, cannot delete at position." << endl;
        return;
    }
    else if(pos==0)
    {
        deletehead();
        return;
    }
    node* temp = head;
    for(int i=0; i<pos-1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    node* t0delete = temp->next;
    temp->next = temp->next->next;
    delete t0delete; // Delete the node at position
    
    
}
void deleteAfrer(int value)
{
    if(head == NULL)
    {
        cout << "List is empty, cannot delete after value." << endl;
        return;
    }
    node* temp = head;
    while(temp->val !=value)
    {
        if(temp->next == NULL)
        {
            cout << "Value not found in the list." << endl;
            return;
        }
        temp = temp->next;
    }
    node* t0delete = temp->next;
    temp->next = temp->next->next;
    delete t0delete; // Delete the node after the value
}
void printReversed(node* head)
{
    if (head == NULL)
    {
        cout<< "List is empty." << endl;
        return;
    }

    node* current = head;
    node* prev = NULL;
    node* next = NULL;
    while (current != NULL)
    {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the link
        prev = current; // Move prev to current
        current = next; // Move to the next node
    }
    head = prev; // Update head to the new first node
    cout << "Reversed List: ";
    node* temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    
}

void search(int value)
{
    if(head == NULL)
    {
        cout << "List is empty, cannot search." << endl;
        return;
    }
    node* temp = head;
    int count=0;
    while(temp != NULL)
    {
      
        if(temp->val == value)
        {
            cout << "Value " << value << " found in the list." << endl;
            cout << "Position: " << count << endl;
            return;
        }
        temp = temp->next;
        count++;
    }
    cout << "Value " << value << " not found in the list." << endl;
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
    cout << "1. Insert at head" << endl;
    cout << "2. insert at tail" << endl;
    cout << "3. Insert at position" << endl;
    cout << "33.Insert after the value"<< endl;
    cout << "4. Delete at head" << endl;
    cout << "5. Delete at tail" << endl;
    cout << "6. Delete at position" << endl;
    cout << "66.Delete after the value" << endl;
    cout << "7. Search" << endl;
    cout << "8. Print list" << endl;
    cout<<"88.prent reversed list"<<endl;
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
        else if (ch == 33)
        {
            int x, value;
            cout << "Enter value to insert and the value after which to insert: ";
            cin >> x >> value;
            insert_after_value(x, value);
        }
        else if (ch == 4)
        {
            deletehead();
        }
        else if (ch == 5)
        {
            deletetail();
        }
        else if (ch == 6)
        {
            int pos;
            cout << "Enter position to delete: ";
            cin >> pos;
            delete_at_position(pos);
        }
        else if (ch == 66)
        {
            int value;
            cout << "Enter value after which to delete: ";
            cin >> value;
            deleteAfrer(value);
        }
        else if (ch == 7)
        {
            int value;
            cout << "Enter value to search: ";
            cin >> value;
            search(value);
        }
        else if (ch == 8)
        {
            printlist();
            cout << endl;
        }
        else if (ch == 88)
        {
            printReversed(head);
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
