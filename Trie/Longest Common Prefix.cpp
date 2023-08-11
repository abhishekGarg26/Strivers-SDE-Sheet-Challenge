#include <bits/stdc++.h> 
using namespace std;
struct Node{
    Node *links[26];
    int childCount=0;
    bool flag=false;
    
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    void put(char ch,Node* node){
        links[ch-'a']=node;
        childCount++;
    }
    
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};
class Trie{
    private: 
        Node* root;
    public:
        Trie(){
            root=new Node();
        }
        void insert(string word){
            Node* node=root;
            for(int i=0;i<word.size();i++){
                if(!node->containsKey(word[i])){
                    node->put(word[i],new Node());
                }
                node=node->get(word[i]);
            }
            node->setEnd();
        }
        // checking count of each node's value that do not have null links
        // if the count is greater than one, then break and ans stores lcp
        void lcp(string word,string &ans){
            Node* node=root;
            for(int i=0;i<word.size();i++){
                if(node->childCount==1){
                    ans+=word[i];
                    node=node->get(word[i]);
                }else{
                    break;
                }
            }
        }
        
};
// TC-> O(m*n), SC->(m*n) [space complexity is very high for worst case when all words and their chars are unique]
string longestCommonPrefix(vector<string> &a, int n)
{
    // Write your code here
    Trie trie;
    for(auto &it: a){
        trie.insert(it);
    }
    string ans="";
    trie.lcp(a[0],ans);
    return ans;
}


