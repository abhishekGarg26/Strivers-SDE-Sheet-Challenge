#include <bits/stdc++.h> 
using namespace std;

struct Node{
    int cnt;
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int _key,int _val){
        key=_key;
        val=_val;
        cnt=1;
    }
};
struct List{
    Node* head;
    Node* tail;
    int size;
    List(){
        size=0;
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->next=head;
    }
    void addFront(Node* newNode){
        Node* headNext=head->next;
        newNode->next=headNext;
        newNode->prev=head;
        head->next=newNode;
        headNext->prev=newNode;
        size++;
    }
    void removeNode(Node* delNode){
        Node* delPrev=delNode->prev;
        Node* delNext=delNode->next;
        delPrev->next=delNext;
        delNext->prev=delPrev;
        size--;
    }
};
class LFUCache {
public:
    int maxSizeCache;
    int curSize;
    int minFreq;
    map<int,Node*> keyNode;
    map<int,List*> freqListMap;
    LFUCache(int capacity) {
        maxSizeCache=capacity;
        curSize=0;
        minFreq=0;
    }
    void updateFreqListMap(Node* node){
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        if(node->cnt==minFreq && freqListMap[node->cnt]->size==0){
            minFreq++;
        }
        List* newHigherFreqList=new List();
        if(freqListMap.find(node->cnt+1)!=freqListMap.end())
            newHigherFreqList=freqListMap[node->cnt+1];
        node->cnt+=1;
        newHigherFreqList->addFront(node);
        freqListMap[node->cnt]=newHigherFreqList;
        keyNode[node->key]=node;
    }
    
    int get(int key) {
        if(keyNode.find(key)!=keyNode.end()){
            Node* node=keyNode[key];
            int val=node->val;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxSizeCache==0) return;
        if(keyNode.find(key)!=keyNode.end()){
            Node* node=keyNode[key];
            node->val=value;
            updateFreqListMap(node);
        }
        else{
            if(curSize==maxSizeCache){
                List* list=freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->removeNode(list->tail->prev);
                curSize--;
            }
            curSize++;
            minFreq=1;
            List* ListFreq=new List();
            if(freqListMap.find(minFreq)!=freqListMap.end())
                ListFreq=freqListMap[minFreq];
            Node* node=new Node(key,value);
            ListFreq->addFront(node);
            keyNode[key]=node;
            freqListMap[minFreq]=ListFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */