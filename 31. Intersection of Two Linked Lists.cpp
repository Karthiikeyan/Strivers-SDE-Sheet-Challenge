Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    if(firstHead==NULL || secondHead== NULL) return NULL;
    Node* a = firstHead;
    Node* b = secondHead;

    while(a!=b){
        a = a==NULL ? secondHead : a->next;
        b = b==NULL ? firstHead : b->next;
    }
    return a;

    //  if(head1==NULL || head2==NULL )
    //        return NULL;
        
    //     Node* l1=head1;
    //     Node* l2=head2;
    //     while(l1!=l2)
    //     {
    //         l1= l1==NULL ? head2 : l1->next;
    //         l2= l2==NULL ? head1 : l2->next;
    //     }
    //     return l1;
}