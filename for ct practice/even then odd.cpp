//odd then even

Node* odd_Even_List(Node* head) {
    if (!head) return head;

    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even;

    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead;
    return head;
}




First linked list: 9 7 5 3 1 
Second linked list: 10 8 6 4 2 
Merged linked list: 9 10 7 8 5 6 3 4 1 2
void merge_alternate_Nodes(Node** head1_ref, Node** head2_ref) {
    Node* p1 = *head1_ref;
    Node* p2 = *head2_ref;

    while (p1 != NULL && p2 != NULL) {
        Node* temp = p1->next;
        p1->next = p2;
        p2 = p2->next;
        p1->next->next = temp;
        p1 = temp;
    }

    *head2_ref = p2; // Remaining nodes of second list
}