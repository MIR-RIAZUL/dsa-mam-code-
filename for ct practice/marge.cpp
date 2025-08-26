#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->next = nullptr;
    return node;
}

// Function to merge two sorted linked lists
Node* mergeTwoLists(Node* head1, Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    Node dummy;
    Node* tail = &dummy;
    dummy.next = nullptr;

    while (head1 && head2) {
        if (head1->data < head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    tail->next = head1 ? head1 : head2;

    return dummy.next;
}

// Function to display a linked list
void displayList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function
int main() {
    // Create first sorted list: 1 -> 3 -> 5 -> 7
    Node* list1 = newNode(1);
    list1->next = newNode(3);
    list1->next->next = newNode(5);
    list1->next->next->next = newNode(7);

    // Create second sorted list: 2 -> 4 -> 6
    Node* list2 = newNode(2);
    list2->next = newNode(4);
    list2->next->next = newNode(6);

    cout << "Two sorted singly linked lists:\n";
    displayList(list1);
    displayList(list2);

    Node* result = mergeTwoLists(list1, list2);
    cout << "\nAfter merging the two sorted lists:\n";
    displayList(result);

    return 0;
}



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
    node->next = NULL;  // Use NULL instead of nullptr
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

// Function to merge two sorted linked lists iteratively
Node* mergeTwoLists(Node* l1, Node* l2) {
    Node dummy;
    Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data < l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // Append remaining nodes
    if (l1 != NULL) tail->next = l1;
    if (l2 != NULL) tail->next = l2;

    return dummy.next;
}

// Driver code
int main() {
    // First sorted linked list: 1 -> 3 -> 5
    Node* list1 = newNode(1);
    list1->next = newNode(3);
    list1->next->next = newNode(5);

    // Second sorted linked list: 2 -> 4 -> 6
    Node* list2 = newNode(2);
    list2->next = newNode(4);
    list2->next->next = newNode(6);

    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);

    Node* merged = mergeTwoLists(list1, list2);
    cout << "\nMerged Sorted List: ";
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

//remove odd index

void removeOddIndices(Node*& head) {
    Node* current = head;
    Node* prev = nullptr;
    int count = 1;  // Start index from 1

    while (current != nullptr) {
        if (count % 2 == 1) {  // Odd index
            if (prev == nullptr) {  // Removing head
                head = current->next;
            } else {
                prev->next = current->next;
            }
            Node* temp = current;
            current = current->next;
            delete temp;  // C++ uses delete instead of free
        } else {
            prev = current;
            current = current->next;
        }
        count++;
    }
}
//odd value remove

void removeOddValues(Node*& head) {
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->data % 2 == 1) {  // Odd value
            if (prev == nullptr) {  // Removing head
                head = current->next;
            } else {
                prev->next = current->next;
            }
            Node* temp = current;
            current = current->next;
            delete temp;
        } else {
            prev = current;
            current = current->next;
        }
    }
}

//roteate list

void rotateList(Node*& head, int k) {
    if (!head || k == 0) return;

    Node* current = head;
    int count = 1;

    // Find the last node and count total nodes
    while (current->next) {
        current = current->next;
        count++;
    }

    // Connect last node to head → make it circular
    current->next = head;

    // Find (count - k % count)th node
    for (int i = 0; i < count - (k % count); i++) {
        current = current->next;
    }

    // New head will be next node
    head = current->next;

    // Break circular link
    current->next = nullptr;
}

//sweaping node


void swapKthNode(Node* head, int k) {
    if (!head) return;

    // Count total nodes
    int n = 0;
    Node* temp = head;
    while (temp) {
        n++;
        temp = temp->next;
    }

    // Check if k is valid or middle node
    if (k > n || 2 * k - 1 == n) return;

    // Find kth node from beginning
    Node* a = head;
    for (int i = 1; i < k; i++)
        a = a->next;

    // Find kth node from end
    Node* b = head;
    for (int i = 1; i < n - k + 1; i++)
        b = b->next;

    // Swap data
    int t = a->data;
    a->data = b->data;
    b->data = t;
}



