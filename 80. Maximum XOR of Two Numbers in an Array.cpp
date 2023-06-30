#include <bits/stdc++.h> 

struct Node{
    Node* linked[2];

    bool containsKey(int bit){
        return (linked[bit]!=NULL);
    }
    Node* get(int bit){
        return linked[bit];
    }
    void put(int bit, Node* node){
        linked[bit] = node;
    }
};

class Trie {
    private: Node* root;

    public:
    Trie(){
        root = new Node();
    }

    void insert(int num){
        Node* node = root;
        for(int i=31;i>=0;i--){
            int bit = (num>>i) & 1;
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int findMax(int num){
        Node* node = root;
        int max_ans = 0;
        for(int i=31;i>=0;i--){
            int bit = (num>>i) & 1;
            if(node->containsKey(!bit)){
                max_ans = max_ans | (1<<i);
                node = node->get(!bit);
            }else
                node = node->get(bit);
        }
        return max_ans;
    }
};

int maximumXor(vector<int> A)
{
    // Write your code here. 
    Trie trie;
    for(auto it:A){
        trie.insert(it);
    }  

    int ans = 0;
    for(auto it: A){
        ans = max(ans, trie.findMax(it));
    }
    return ans;
}