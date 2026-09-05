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
        map<Node*,Node*> mp;
        mp[nullptr]=nullptr;
        Node* curr = head;
        while(curr!=nullptr){
            if(mp.find(curr)==mp.end()){
                mp[curr]=new Node(curr->val);
            }
             if(mp.find(curr->next)==mp.end()){
                mp[curr->next]=new Node(curr->next->val);
            }
            mp[curr]->next=mp[curr->next];
            curr = curr->next;
        }
        curr = head;
        while(curr!=nullptr){            
            mp[curr]->random=mp[curr->random];
            curr = curr->next;
        }
        return mp[head];
        
        
    }
};
