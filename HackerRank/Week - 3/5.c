SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode* previous = NULL;
    SinglyLinkedListNode* current = llist;
    SinglyLinkedListNode* next = NULL;
    while(current != NULL ){
        next = current -> next;
        current -> next = previous;
        previous = current;
        current = next;
    }
    return previous;
}
