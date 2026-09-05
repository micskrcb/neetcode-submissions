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
     int goodNodes(TreeNode* root,int& ans,int maxelement) {
        if(root == nullptr) return 0;
        if(root->val >= maxelement){
            maxelement = root->val;
            ans++;
        }
        goodNodes(root->left,ans,maxelement);
       return goodNodes(root->right,ans,maxelement);
    

        
        
    }

    int goodNodes(TreeNode* root) {
        int ans = 0;
        if(root == nullptr) return 0;
        goodNodes(root,ans,root->val);
        return ans;

        
        
    }
};
