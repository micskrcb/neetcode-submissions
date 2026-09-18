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
    int K = -1;
    int kthSmallest(TreeNode* root, int k) {
        if(K==-1) K=k;
        if(root==nullptr)return INT_MIN;
        if(K==0)return root->val;
        int a = INT_MIN;
        a = kthSmallest(root->left,K);
        K--;
        if(K==0)return root->val;
        int b = kthSmallest(root->right,K);
        if(a!=INT_MIN)return a;
        return b;      

        

    }
};
