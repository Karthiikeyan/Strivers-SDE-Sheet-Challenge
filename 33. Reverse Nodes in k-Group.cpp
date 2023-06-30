#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
int length(Node* node){
	if(node==NULL) return 0;
	int len = 0;
	while(node!=NULL){
		len++;
		node = node->next;
	}
	return len;
}

Node* reverse(Node* head){
	Node* curr = head, *nxt, *prev = NULL;
	while(curr){
		nxt = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nxt;
	}
	return prev;
}

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
	Node* dummy = new Node(0);
	dummy->next = head;

	Node* prev = dummy, *nxt, *curr;
	int len = length(head);

	for(int i=0;i<n;i++){
		if(len==0) break;
		if(b[i] <= len){
			curr = prev->next;
			nxt = curr->next;
			if(b[i]==0) continue;

			for(int j=1;j<b[i];j++){
				curr->next = nxt->next;
				nxt->next = prev->next;
				prev->next = nxt;
				nxt = curr->next;
			}
			len -= b[i];
			prev = curr;
		}else if(len<= b[i]){
			prev->next = reverse(prev->next);
			len = 0;
		}
	}
	return dummy->next;

}