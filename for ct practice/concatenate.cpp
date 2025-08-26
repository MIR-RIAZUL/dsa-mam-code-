#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* newNode(int val) {
    Node* node = new Node;
    node->data = val;
    node->next = NULL;
    return node;
}

// Function to print a linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to concatenate two lists into a new list
Node* concatenateNewList(Node* l1, Node* l2) {
    Node* newHead = NULL;
    Node* tail = NULL;

    // Copy nodes from l1
    while (l1 != NULL) {
        Node* new_node = newNode(l1->data);
        if (newHead == NULL) newHead = tail = new_node;
        else {
            tail->next = new_node;
            tail = new_node;
        }
        l1 = l1->next;
    }

    // Copy nodes from l2
    while (l2 != NULL) {
        Node* new_node = newNode(l2->data);
        if (newHead == NULL) newHead = tail = new_node;
        else {
            tail->next = new_node;
            tail = new_node;
        }
        l2 = l2->next;
    }

    return newHead;
}

// Driver code
int main() {
    // First linked list: 1 -> 2 -> 3 -> 8
    Node* list1 = newNode(1);
    list1->next = newNode(2);
    list1->next->next = newNode(3);
    list1->next->next->next = newNode(8);

    // Second linked list: 4 -> 9 -> 6 -> 5
    Node* list2 = newNode(4);
    list2->next = newNode(9);
    list2->next->next = newNode(6);
    list2->next->next->next = newNode(5);

    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);

    Node* newList = concatenateNewList(list1, list2);
    cout << "\nNew Concatenated List: ";
    printList(newList);

    return 0;
}

//even index removal



#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* newNode(int val) {
    Node* node = new Node;
    node->data = val;
    node->next = NULL;
    return node;
}

// Function to print a linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to remove nodes at even indices (0-based index)
Node* removeEvenIndices(Node* head) {
    if (head == NULL) return NULL;

    Node* current = head;
    Node* prev = NULL;
    int index = 0;

    while (current != NULL) {
        if (index % 2 == 0) {  // Even index
            Node* temp = current;
            if (prev != NULL) prev->next = current->next;
            else head = current->next;  // If head is at even index
            current = current->next;
            delete temp;
        } else {
            prev = current;
            current = current->next;
        }
        index++;
    }

    return head;
}

// Driver code
int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    cout << "Original List: ";
    printList(head);

    head = removeEvenIndices(head);

    cout << "After Removing Even-Indexed Nodes: ";
    printList(head);

    return 0;
}

