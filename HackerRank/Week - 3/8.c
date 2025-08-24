SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    SinglyLinkedListNode* result;
    if (head1->data <= head2->data) {
        result = head1;
        head1 = head1->next;
    } else {
        result = head2;
        head2 = head2->next;
    }

    SinglyLinkedListNode* current = result;
    while (head1 && head2) {
        if (head1->data <= head2->data) {
            current->next = head1;
            head1 = head1->next;
        } else {
            current->next = head2;
            head2 = head2->next;
        }
        current = current->next;
    }

    if (head1) current->next = head1;
    if (head2) current->next = head2;

    return result;
}
