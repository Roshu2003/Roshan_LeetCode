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
    void solve(TreeNode* &ans,TreeNode* node){
        if(!node)return;
        solve(ans,node->left);
        ans -> right = new TreeNode(node->val);
        ans = ans -> right;
        solve(ans,node->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* ans = new TreeNode();
        TreeNode* temp;
        temp = ans;
        solve(ans,root);
        return temp -> right;
    }
};