LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    if(head==NULL) return NULL;
    LinkedListNode<int> *newNode = NULL;
    LinkedListNode<int> *temp = head;
    while(head!=NULL){
        temp = head->next;
        head->next = newNode;
        newNode = head;
        head = temp;
    }
    return newNode;
}