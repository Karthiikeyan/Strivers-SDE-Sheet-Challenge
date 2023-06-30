#include<bits/stdc++.h>

struct Node{
    Node* linked[26];
    bool flag = false;

    bool is_contains(char ch){
        return (linked[ch-'a']!=NULL);
    }
    void put(char ch, Node* node){
        linked[ch-'a'] = node;
    }
    Node* get(char ch){
        return linked[ch-'a'];
    }
    bool is_end(){
        return flag;
    }
    void make_end(){
        flag = true;
    }
};

class Trie {
    Node* root;

public:

    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->is_contains(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->make_end();
    }

    bool search(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->is_contains(word[i])){
                return false;   
            }
            node = node->get(word[i]);
            
        }
        return node->is_end();

    }

    bool check_prefix(string prefix) {
        bool flag = true;
        Node* node = root;
        for(int i=0;i<prefix.size();i++){
            if(!node->is_contains(prefix[i])){
                return false;
            }else{
                node = node->get(prefix[i]);
                if(node->is_end()==false)
                    return false;
            }
            
        }
        return true;
    }
};
string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie trie;
    for(auto it:a){
        trie.insert(it);
    }

    string maxi = "";
    for(auto it: a){
        if(trie.check_prefix(it)){
            if(it.size()>maxi.size()){
                maxi = it;
            }
            else if(it.size()==maxi.size()){
                if(it<maxi)
                    maxi = it;
            }
        }
    }
    if(maxi=="") return "None";
    return maxi;
}