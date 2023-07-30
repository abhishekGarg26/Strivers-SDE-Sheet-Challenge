#include <bits/stdc++.h> 
using namespace std;

class trieNode{
    public:
   trieNode *child[26];
   bool isEnding;
    trieNode(){
        this->isEnding=false;
        for(int i=0;i<26;i++){
            this->child[i]=NULL;
        }
    }
};
void insert(trieNode *root,string str){
    int len=str.length();
    trieNode *pCrawl=root;
    for(int level=0;level<len;level++){
        int index=str[level]-'a';
        if(!pCrawl->child[index])
            pCrawl->child[index]=new trieNode();
            pCrawl=pCrawl->child[index];
    }
    pCrawl->isEnding=true;
}
bool allPrefixed(trieNode *root,string word){
    trieNode *pCrawl=root;
    for(char c:word){
        int i=c-'a';
        pCrawl=pCrawl->child[i];
        if(pCrawl==NULL || pCrawl->isEnding==false){
            return false;
        }
    }
    return true;
}
string completeString(int n, vector<string> &a){
    // Write your code here.
    string ans="";
    trieNode *root=new trieNode();
    for(string word:a){
        insert(root,word);
    }
    for(string word:a){
        if(!allPrefixed(root,word))
        continue;
        if(ans.size()<word.size()){
            ans=word;
        }
        else if(ans.size()==word.size() && word<ans){
            ans=word;
        }
    }
    if(ans.size()==0){
        ans="None";
    }
    return ans;
}