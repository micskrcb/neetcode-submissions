/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if(head==nullptr || head->next == nullptr)return false;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && slow){
            if(slow->next == nullptr) return false;
            slow=slow->next;
            if(fast->next ==nullptr || fast->next->next==nullptr) return false;
            fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;

    }
};
