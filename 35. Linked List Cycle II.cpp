Node *firstNode(Node *head)
{
    //    Write your code here.
    // Code 1:
    // if(head==NULL || head->next == NULL) return NULL;

    // Node* slow = head;
    // Node* fast = head;
    // while(fast!=NULL && fast->next==NULL){
    //     slow = slow->next;
    //     fast = fast->next;
        
    //     if(slow == fast){
    //         fast = head;
    //         while(fast!=slow){
    //             slow = slow->next;
    //             fast = fast->next;
    //         }
    //         return slow;
    //         break;
    //     }
    // }
    // return NULL;

    // Code 2:
    Node* slow = head;
    Node* fast = head;

     while  (fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
          if (slow == fast) {
            fast = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
              // First node of the cycle
        }
    }

    return NULL;
}