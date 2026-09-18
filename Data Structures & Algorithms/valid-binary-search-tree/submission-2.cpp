class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode* prev = nullptr;
        bool isValid = true;
        
        while (curr) {
            if (!curr->left) {
                if (prev && curr->val <= prev->val) isValid = false;
                prev = curr;
                curr = curr->right;
            } else {
                TreeNode* predecessor = curr->left;
                while (predecessor->right && predecessor->right != curr) {
                    predecessor = predecessor->right;
                }
                
                if (!predecessor->right) {
                    predecessor->right = curr;
                    curr = curr->left;
                } else {
                    predecessor->right = nullptr;
                    if (prev && curr->val <= prev->val) isValid = false;
                    prev = curr;
                    curr = curr->right;
                }
            }
        }
        return isValid;
    }
};