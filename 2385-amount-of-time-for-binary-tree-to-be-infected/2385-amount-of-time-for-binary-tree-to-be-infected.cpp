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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>> adj;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(node->left){
                adj[node->val].push_back(node->left->val);
                adj[node->left->val].push_back(node->val);
                q.push(node->left);
            }
            if(node->right){
                adj[node->val].push_back(node->right->val);
                adj[node->right->val].push_back(node->val);
                q.push(node->right);
            }
        }
        int ans = 0;
        queue<int> pq;
        pq.push(start);
        unordered_set<int> vis;
        vis.insert(start);
        while(!pq.empty()){
            int sz = pq.size();
            while(sz--){
                auto node = pq.front();
                pq.pop();
                for(auto it : adj[node]){
                    if(!vis.count(it)){
                        vis.insert(it);
                        pq.push(it);
                    }
                }
            }
            ans++;
        }
        return ans - 1;
    }
};