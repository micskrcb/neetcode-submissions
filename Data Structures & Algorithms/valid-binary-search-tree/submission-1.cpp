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
    typedef TreeNode* node;
public:
    bool helper(node root,int ll,int ul){
        if(root==nullptr)return true;
        if(root->val<=ll)return false;
        if(root->val>=ul)return false;
        return helper(root->left,ll,min(ul,root->val))&&helper(root->right,max(ll,root->val),ul);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root,INT_MIN,INT_MAX);
        
    }
};
