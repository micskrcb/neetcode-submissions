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
    ListNode* reverse(ListNode* head ){
        if(head==nullptr || head->next == nullptr ) return head;
        ListNode* prev =nullptr;
        auto curr = head;
        auto next = head->next;

        while(curr){
            curr->next = prev;
            if(next==nullptr)break;
            prev = curr;
            curr=next;
            next = next->next;
        }
        return curr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr||head->next ==nullptr)return head;
        int i =0;
        auto ptr = head;
        while(i<k-1 && ptr){
            ptr=ptr->next;
            i++;            
        }
        cout<<i<<endl;
        if(!ptr){cout<<head->val<<endl;return head;}
        ListNode* temp =nullptr;
        if(ptr!=nullptr){
        cout<<ptr->val;
        temp = ptr->next;
        ptr->next =nullptr;}
        
        auto ans = reverse(head);
        head->next = reverseKGroup(temp,k);
        return ans;
        

    }
};
