#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Insert at end
void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

// Print list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Merge two sorted lists
Node* mergeSorted(Node* l1, Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    if (l1->data < l2->data) {
        l1->next = mergeSorted(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeSorted(l1, l2->next);
        return l2;
    }
}

// Split list for merge sort
void splitList(Node* source, Node*& front, Node*& back) {
    Node* slow = source;
    Node* fast = source->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    front = source;
    back = slow->next;
    slow->next = NULL;
}

// Merge sort for linked list
Node* mergeSort(Node* head) {
    if (!head || !head->next) return head;

    Node* front;
    Node* back;
    splitList(head, front, back);

    front = mergeSort(front);
    back = mergeSort(back);

    return mergeSorted(front, back);
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;

    // Example input
    insert(list1, 7);
    insert(list1, 2);
    insert(list1, 9);

    insert(list2, 5);
    insert(list2, 3);
    insert(list2, 8);

    cout << "List 1 before sort: ";
    printList(list1);
    cout << "List 2 before sort: ";
    printList(list2);

    // Sort both lists
    list1 = mergeSort(list1);
    list2 = mergeSort(list2);

    cout << "List 1 after sort: ";
    printList(list1);
    cout << "List 2 after sort: ";
    printList(list2);

    // Merge sorted lists
    Node* merged = mergeSorted(list1, list2);

    cout << "Merged Sorted List: ";
    printList(merged);

    return 0;
}
