/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* ans;
    typedef pair<bool,bool> pbb;

    pbb helper(TreeNode* root,TreeNode* p,TreeNode*q){
        if(root==nullptr) return{0,0};
        bool lhp,rhp,lhq,rhq;
        pbb l = helper(root->left,p,q);
        pbb r = helper(root->right,p,q);
        lhp=l.first;
        lhq=l.second;
        rhp=r.first;
        rhq=r.second;
        if(ans==nullptr){
            if(lhp&&rhq)ans=root;
            if(lhq&&rhp)ans=root;
            if(root==p && (lhq||rhq))ans=root;
            if(root==q && (lhp||rhp))ans=root;
        }
        return {root==p||lhp||rhp,root==q||lhq||rhq};

    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //       
        ans=nullptr;
        helper(root,p,q);
        return ans;

        
    }
};
