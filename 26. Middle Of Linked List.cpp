
Node *findMiddle(Node *head) {
    // Write your code here
    // if(head->next==NULL) return head;

    // Node* slow = head;
    // Node* fast = head;
    // while(fast->next != NULL && fast!=NULL){
    //     fast = fast->next->next;
    //     slow = slow->next;
    // }
    // return slow;

    if(head->next==NULL) return head;
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;

    
}