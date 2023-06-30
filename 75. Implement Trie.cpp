#include<bits/stdc++.h>
/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
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

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
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

    /** Returns if the word is in the trie. */
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

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0;i<prefix.size();i++){
            if(!node->is_contains(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};