
LinkedListNode<int> *reverselist(LinkedListNode<int> *head){
    if(head==NULL) return NULL;
    LinkedListNode<int> *newNode = NULL;
    LinkedListNode<int> *temp = NULL;
    while(head!=NULL){
        temp = head->next;
        head->next = newNode;
        newNode = head;
        head = temp;
    }

    return newNode;
    // if(head == NULL || head->next==NULL){
    //     return NULL;
    // }
    // LinkedListNode<int> *prev = NULL;
    // LinkedListNode<int> *curr = head;
    // LinkedListNode<int> *next = head->next;

    // while(curr != NULL){
    //     next = curr->next;
    //     curr->next = prev;
    //     prev = curr;
    //     curr = next;
    // }
    // return prev;

}

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.

    // Code 1 :
    if(head!=NULL || head->next==NULL) return true;
    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head;

    while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = reverselist(slow->next);
    slow = slow->next;

    while(slow!=NULL){
        if(head->data!=slow->data){
            return false;
        }
        head = head->next;
        slow = slow->next;
    }

    return true;
    
    // Code 2 :
    // if(head == NULL || head->next == NULL)return true;

    // LinkedListNode<int> *slow = head;
    // LinkedListNode<int> *fast = head;

    // while(fast->next != NULL && fast->next->next != NULL){
    //     slow = slow->next;
    //     fast = fast->next->next;
    // }

    // slow->next = reverselist(slow->next);
    // slow = slow->next;

    // while(slow!=NULL){
    //     if(head->data != slow->data){
    //         return false;
    //     }
    //     head = head->next;
    //     slow = slow->next;
    // }
    // return true;

}