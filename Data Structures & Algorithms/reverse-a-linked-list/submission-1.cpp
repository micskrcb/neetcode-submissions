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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr ) return head;
        ListNode* nxt = head->next->next,* curr = head->next,* temp = nullptr;
        curr->next = head;
        head->next = nullptr;
        while(nxt!=nullptr){
            ListNode* new_nxt = nxt->next;
            nxt->next = curr;
            curr = nxt;
            nxt = new_nxt;
        }
        return curr;

    }
};
