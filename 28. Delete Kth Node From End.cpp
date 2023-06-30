
Node* removeKthNode(Node* head, int K)
{
    // Write your code here.
    if(head==NULL) return NULL;
    Node* fast = head;
    Node* slow = head;

    while(K--){
        fast = fast->next;
    }

    if(fast==NULL){
        slow = head->next;
        head = slow;
        return head;
    }

    while(fast->next!=NULL && fast!=NULL){
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;

    return head;



}