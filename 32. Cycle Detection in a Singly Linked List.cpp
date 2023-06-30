bool detectCycle(Node *head)
{
	//	Write your code here
    // if(head==NULL || head->next==NULL) return false;

    // Node *fast = head;
    // Node *slow = head;

    // while(fast->next->next!=NULL && fast->next==NULL){
    //     slow = slow->next;
    //     fast = fast->next;
    //     if(slow == fast)
    //     return true;
    // }
    // return false;

    if(head == NULL || head->next == NULL){
        return false;
    }
    Node *slow = head;
    Node *fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return true;
        }
    }
    return false;

    // if(head==NULL || head->next==NULL) return false;

    // Node* slow = head;
    // Node* fast = head;
    // while(fast->next!=NULL && fast!=NULL){
    //     slow = slow->next;
    //     fast = fast->next->next;
    //     if(slow == fast){
    //         return true;
    //     }
    // }
    // return false;
}