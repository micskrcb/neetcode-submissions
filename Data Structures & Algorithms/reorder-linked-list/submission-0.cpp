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
    void reorderList(ListNode* head) {
        if(head==nullptr || head->next == nullptr ||head->next->next==nullptr)return;
        ListNode* concernednode=head,* tobenxtofcn=head->next,*prev=nullptr;

        while(concernednode->next){
            prev = concernednode;
            ListNode* temp = concernednode->next;
            //concernednode->next=nullptr;
            concernednode=temp;

        }
        head->next = concernednode;
        concernednode->next =  tobenxtofcn; 
        prev->next = nullptr;  
        reorderList(tobenxtofcn);     
    }
};
