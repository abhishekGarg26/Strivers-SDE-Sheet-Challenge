#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* links[2];

    bool containsKey(int bit){
        return (links[bit]!=NULL);
    }

    Node* get(int bit){
        return links[bit];
    }

    void put(int bit,Node* node){
        links[bit]=node;
    }
};

class Trie{
    private: 
        Node* root;
    public:
        Trie(){
            root=new Node();
        }
        void insert(int num){
            Node* node=root;
            for(int i=31;i>=0;i--){
                int bit= (num>>i) & 1;
                if(!node->containsKey(bit)){
                    node->put(bit,new Node());
                }
                node=node->get(bit);
            }
        }
        int getMax(int num){
            Node* node=root;
            int maxNum=0;
            for(int i=31;i>=0;i--){
                int bit= (num>>i) & 1;
                if(node->containsKey(1-bit)){
                    maxNum= maxNum | (1<<i);
                    node=node->get(1-bit);
                }else{
                    node=node->get(bit);
                }
            }
            return maxNum;
        }

};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        // O(nlogn)
        sort(nums.begin(),nums.end());
        vector<pair<int , pair<int,int>>> oQ;
        int q=queries.size();
        // O(q)
        for(int i=0;i<q;i++){
            oQ.push_back({queries[i][1],{queries[i][0],i}});
        }
        // O(qlogq)
        sort(oQ.begin(),oQ.end());
        vector<int> ans(q,0);
        int ind=0;
        int n=nums.size();
        Trie trie;
        // O(q*32 + n*32)
        for(int i=0;i<q;i++){
            int ai= oQ[i].first;
            int xi= oQ[i].second.first;
            int qInd= oQ[i].second.second;
            while(ind < n && nums[ind]<=ai){
                trie.insert(nums[ind]);
                ind++;
            }
            if(ind ==0 ) ans[qInd]=-1;
            else ans[qInd] = trie.getMax(xi);
        }
        return ans;
    }
};