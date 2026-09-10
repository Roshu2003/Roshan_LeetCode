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
    int ans = 0;
    pair<int,int> dfs(TreeNode* node){//sum , cnt 
        if(!node)return {0,0};
        auto l = dfs(node->left);
        auto r = dfs(node->right);

        int sum = node->val + l.first + r.first;
        int n = 1 + l.second + r.second;
        if(sum / n == node->val)ans++;
        return {sum,n};
    }
    int averageOfSubtree(TreeNode* root) {
        auto l = dfs(root);
        return ans;
    }
};