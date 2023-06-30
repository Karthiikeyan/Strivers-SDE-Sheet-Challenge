#include <bits/stdc++.h> 

struct Node {
    Node* linked[26];
    int cnt_prefix = 0;
    int cnt_end = 0;

    bool contains_key(char ch){
        return (linked[ch-'a']!=NULL);
    }

    Node* get(char ch){
        return linked[ch-'a'];
    }
    void put(char ch, Node* node){
        linked[ch-'a'] = node;
    }
    void inc_prefix(){
        cnt_prefix++;
    }
    void inc_end(){
        cnt_end++;
    }
    void dec_prefix(){
        cnt_prefix--;
    }
    void dec_end(){
        cnt_end--;
    }
    int get_prefix(){
        return cnt_prefix;
    }
    int get_end(){
        return cnt_end;
    }

};
class Trie{
    private: Node* root;

    public:

    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->contains_key(word[i])){
                node->put(word[i], new Node());
            }
            node =  node->get(word[i]);
            node->inc_prefix();
        }
        node->inc_end();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(node->contains_key(word[i]))
                node = node->get(word[i]);
            else
                return 0;
        }
        return node->get_end();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(node->contains_key(word[i]))
                node = node->get(word[i]);
            else
                return 0;
        }
        return node->get_prefix();

    }

    void erase(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(node->contains_key(word[i])){
                node = node->get(word[i]);
                node->dec_prefix();
            }else return; 
        }
        node->dec_end();
    }
};
