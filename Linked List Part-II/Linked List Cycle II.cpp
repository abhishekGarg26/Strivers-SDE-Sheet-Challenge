#include <bits/stdc++.h>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* entry=head;
        while(fast->next && fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow) {                            // There is a cycle, found entry location
                while(slow!=entry){
                    entry=entry->next;
                    slow=slow->next;
                }
                return entry;
            }
        }
        
        return NULL;
    }
};