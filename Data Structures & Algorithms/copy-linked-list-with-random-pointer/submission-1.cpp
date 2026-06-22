/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)return head;
        auto ptr = head;
        while(ptr){
            auto temp = new Node(ptr->val);
            temp->next = ptr->next;
            ptr->next = temp;
            ptr=temp->next;
        }
        ptr = head;
        while(ptr){
            auto temp = ptr->random;
            if(temp!=nullptr)
            ptr->next->random=ptr->random->next;
            ptr=ptr->next->next;
        }
        ptr= head->next;

        while(ptr){
            if(ptr->next)
            ptr->next = ptr->next->next;
            ptr=ptr->next;
        }
        ptr= head->next;
        head->next =nullptr;
        return ptr;

        
    }
};
