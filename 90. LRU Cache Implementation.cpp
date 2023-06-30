#include<bits/stdc++.h>
using namespace std;
class LRUCache
{
    int capacity;
    unordered_map<int,list<pair<int,int>>::iterator>m;
    list<pair<int,int>> l;
public:
    LRUCache(int capacity)
    {
        // Write your code here
        this->capacity = capacity;
    }

    int get(int key)
    {
        // Write your code here
        if(m.find(key)==m.end()) return -1;
        else{
            auto element = m[key];
            int val = element->second;
            l.erase(element);
            l.push_front({key, val});
            m[key] = l.begin();
            return val;
        }
    }

    void put(int key, int value)
    {
        // Write your code here
        if(m.find(key)!=m.end()){
            l.erase(m[key]);
            m.erase(key);
        }
        if(capacity == l.size()){
            pair<int,int> last = l.back();
            l.erase(m[last.first]);
            m.erase(last.first);
        }
        l.push_front({key, value});
        m[key] = l.begin();
    }
};
