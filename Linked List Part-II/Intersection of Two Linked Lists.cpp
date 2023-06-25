#include <bits/stdc++.h>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

// Approach-1  

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tmp1=headA;
        ListNode* tmp2=headB;
        int cnt1=0,cnt2=0;
        while(tmp1 || tmp2){
            if(tmp1!=NULL){
                tmp1=tmp1->next;
                cnt1++;
            }
            if(tmp2!=NULL){
                tmp2=tmp2->next;
                cnt2++;
            }
            
        }
        int diff=abs(cnt1-cnt2);
        tmp1=headA;
        tmp2=headB;
        while(diff--){
        if(cnt1>cnt2){
                tmp1=tmp1->next;
        }else{
                tmp2=tmp2->next;
            }
        }
        while(tmp1!=tmp2){
            tmp1=tmp1->next;
            tmp2=tmp2->next;
        }
        return tmp1;
        
    }

    // Approach-2

    ListNode *getIntersectNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL) return NULL;
        ListNode* a=headA;
        ListNode* b=headB;
        
        while(a!=b){
            a= a==NULL?headB:a->next;
            b= b==NULL?headA:b->next;
        }

        return a;
        
    }
};