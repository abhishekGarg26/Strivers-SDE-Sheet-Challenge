#include <bits/stdc++.h> 
using namespace std;

class LRUCache {
public:
    class Node{
        public:
            int key;
            int val;
            Node* next;
            Node* prev;
            Node(int _key,int _val){
                key=_key;
                val=_val;
                next=NULL;
                prev=NULL;
            }
    };
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    unordered_map<int,Node*> mp;
    int size;
    LRUCache(int capacity) {
        size=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void addNode(Node* newNode){
        Node* headNext=head->next;
        newNode->next=headNext;
        newNode->prev=head;
        head->next=newNode;
        headNext->prev=newNode;
    }
    void deleteNode(Node* nodeToDel){
        Node* delprev=nodeToDel->prev;
        Node* delNext=nodeToDel->next;
        delprev->next=delNext;
        delNext->prev=delprev;
    }

    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node* result=mp[key];
            int val=result->val;
            mp.erase(key);
            deleteNode(result); 
            addNode(result);
            mp[key]=head->next;
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* existingNode=mp[key];
            mp.erase(key);
            deleteNode(existingNode);
        }
        if(size==mp.size()){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node* newNode=new Node(key,value);
        addNode(newNode);
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */