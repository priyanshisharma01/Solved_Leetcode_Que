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
    bool findTarget(TreeNode* root, int k) {
        TreeNode* MyRoot = root;
        return fun(root, k, MyRoot);
    }
    
    bool fun(TreeNode* root, int k, TreeNode* MyRoot)
    {
        if(!root)return false;
        TreeNode* temp = MyRoot;

        while(temp)
        {
            if(temp==root) temp = temp->val + root->val < k ? temp->right : temp->left;
            else if(root->val + temp->val == k) return true;
            else temp = temp->val + root->val < k ? temp->right : temp->left;
        }
        return (fun(root->left, k, MyRoot) || fun(root->right, k, MyRoot));
    }
};