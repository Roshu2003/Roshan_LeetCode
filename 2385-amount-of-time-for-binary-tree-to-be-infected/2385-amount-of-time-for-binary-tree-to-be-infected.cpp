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
    int st;
    int ans = 0;
    int solve(TreeNode* node){
        if(!node)return 0;

        int lh = solve(node->left);
        int rh = solve(node->right);
        if(node->val == st){
            ans = max(lh,rh);
            return -1;
        }
        else if(lh >= 0 && rh >= 0){
            return max(rh,lh) + 1;
        }
        else{
            int d = abs(rh) + abs(lh);
            ans = max(ans,d);
            return min(rh,lh) - 1;
        }
        return 0;
    }
    int amountOfTime(TreeNode* root, int start) {
        st = start;
        solve(root);
        return ans;
    }
};