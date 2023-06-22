#include <bits/stdc++.h>
using namespace std;
 
//Design Hash set using Linked List Chaining to avoid hashing collisions
 class MyHashSet {
public:

    vector<list<int>> m;
    int siz;
    MyHashSet() {
        siz=5;
        m.resize(siz);
    }
    int hash(int key){
       return key%siz;
    }
    list<int> ::iterator search(int key){
        int i=hash(key);
       return find(m[i].begin(),m[i].end(),key);
    }
    void add(int key) {
        if(!contains(key)){
            int i=hash(key);
            m[i].push_back(key);
        }
    }
    
    void remove(int key) {
        if(contains(key)){
            int i=hash(key);
            m[i].remove(key);
        }
    }
    
    bool contains(int key) {
        int i=hash(key);
        if(search(key)!=m[i].end()) return 1;
        else return 0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */