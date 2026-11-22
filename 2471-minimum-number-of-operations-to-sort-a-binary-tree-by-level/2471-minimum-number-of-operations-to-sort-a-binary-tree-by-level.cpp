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
    int find(vector<int> v){
        int n = v.size();
        vector<pair<int,int>> p;
        for(int i = 0; i < n; i++){
            p.push_back({v[i],i});
        }
        sort(p.begin(),p.end());
        vector<int> vis(n,0);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(vis[i] || p[i].second == i)continue;

            int cnt = 0;
            int j = i;
            while(!vis[j]){
                vis[j] = 1;
                j = p[j].second;
                cnt++;
            }
            ans += cnt - 1;
        }
        return ans;
    }
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int> v;
            while(sz--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                v.push_back(node->val);
            }
            int count = find(v);
            cout<<count<<endl;
            ans += count;
        }
        return ans;
    }
};