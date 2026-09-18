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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root==nullptr)return ans;
        q.push(root);
        while(q.size()!=0){
            int n = q.size();
            vector<int> temp;
            while(n--){
                temp.push_back(q.front()->val);
                if(q.front()->left!=nullptr)q.push(q.front()->left);
                if(q.front()->right!=nullptr)q.push(q.front()->right);
                q.pop();
            }
            ans.push_back(temp);
        }
        return ans;

    }
};
