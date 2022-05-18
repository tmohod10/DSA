Node* pairwiseSwapUsingRef(Node *head){
    if(head == NULL || head->next == NULL) {
        return head;
    }
    Node *curr = head->next->next;
    Node *prev = head;
    head = head->next;
    head->next = prev;
    while(curr &&curr->next){
        prev->next = curr->next;
        prev = curr;
        Node *next = curr->next->next;
        curr->next->next = curr;
        curr = next;
    }
    prev->next = curr;
    return head;
}