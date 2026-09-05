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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* end1=list1;
        ListNode* end2=list2;
        if(!list1)return list2;
        if(!list2)return list1;
        ListNode* ans=list2;
        if(end1->val<end2->val){
            ans = end1;
            end1=end1->next;
            ans->next = nullptr;
        }
        else{
            //ans = end1;
            end2=end2->next;
            ans->next = nullptr;
        }
        ListNode* curr = ans;
        cout<<"hi";



        

        while(end1 && end2){
            if(end1->val < end2->val){
                curr->next = end1;
                end1 = end1->next;
                curr = curr->next;
                curr->next = nullptr;
            }
            else{
                curr->next = end2;
                end2 = end2->next;
                curr = curr->next;
                curr->next = nullptr;              

            }
        }
        if(end1){
            curr->next = end1;
        }
        if(end2){
            curr->next = end2;
        }
        return ans;

        
        
    }
};
