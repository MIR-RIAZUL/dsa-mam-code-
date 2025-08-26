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



//palindrome

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

// Reverse a list
Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Check palindrome
bool isPalindrome(Node* head) {
    if (!head || !head->next) return true;

    // Step 1: Find middle
    Node* slow = head;
    Node* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse second half
    Node* secondHalf = reverse(slow->next);

    // Step 3: Compare first and second half
    Node* firstHalf = head;
    Node* tempSecond = secondHalf;
    bool palindrome = true;

    while (tempSecond) {
        if (firstHalf->data != tempSecond->data) {
            palindrome = false;
            break;
        }
        firstHalf = firstHalf->next;
        tempSecond = tempSecond->next;
    }

    // (Optional) Restore list
    slow->next = reverse(secondHalf);

    return palindrome;
}

int main() {
    Node* head = NULL;

    // Example: Palindrome list
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 2);
    insert(head, 1);

    cout << "Linked List: ";
    printList(head);

    if (isPalindrome(head))
        cout << "Yes, it is a Palindrome\n";
    else
        cout << "No, it is NOT a Palindrome\n";

    return 0;
}


//reomve duplicat

void removeDuplicates(Node* head) {
    Node* curr = head;
    while (curr && curr->next) {
        if (curr->data == curr->next->data) {
            Node* dup = curr->next;
            curr->next = curr->next->next;
            delete dup;
        } else {
            curr = curr->next;
        }
    }
}

//intersection finder

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

// Get length of list
int getLength(Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

// Find intersection
Node* getIntersection(Node* head1, Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    // Align both lists
    Node* p1 = head1;
    Node* p2 = head2;

    if (len1 > len2) {
        int diff = len1 - len2;
        while (diff--) p1 = p1->next;
    } else {
        int diff = len2 - len1;
        while (diff--) p2 = p2->next;
    }

    // Move together until intersection found
    while (p1 && p2) {
        if (p1 == p2) return p1;
        p1 = p1->next;
        p2 = p2->next;
    }
    return NULL; // No intersection
}

int main() {
    // Create first list: 10 -> 20 -> 30 -> 70 -> 80
    Node* head1 = new Node(10);
    head1->next = new Node(20);
    head1->next->next = new Node(30);

    // Create second list: 15 -> 25 -> (join at 70)
    Node* head2 = new Node(15);
    head2->next = new Node(25);

    // Common part: 70 -> 80
    Node* common = new Node(70);
    common->next = new Node(80);

    // Connect common part
    head1->next->next->next = common; // 30 -> 70
    head2->next->next = common;       // 25 -> 70

    Node* intersection = getIntersection(head1, head2);

    if (intersection)
        cout << "Intersection at node with value: " << intersection->data << endl;
    else
        cout << "No intersection found" << endl;

    return 0;
}


//add list

Node* addLists(Node* list1, Node* list2) {
    Node* res = nullptr;
    Node* temp, *prev = nullptr;
    int carry = 0, sum;

    // Traverse both lists and perform addition
    while (list1 != nullptr || list2 != nullptr) {
        sum = carry + (list1 ? list1->data : 0) + (list2 ? list2->data : 0);

        // Calculate carry
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;

        // Create new node with sum
        temp = new Node(sum);

        if (res == nullptr)
            res = temp;
        else
            prev->next = temp;

        prev = temp;

        // Move to next nodes
        if (list1) list1 = list1->next;
        if (list2) list2 = list2->next;
    }

    // If carry remains
    if (carry > 0)
        temp->next = new Node(carry);

    return res;
}




