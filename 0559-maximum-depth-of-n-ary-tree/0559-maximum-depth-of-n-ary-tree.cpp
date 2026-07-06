/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        queue<Node*> q;
        if(!root)return 0;
        q.push(root);
        int cnt = 0;
        while(!q.empty()){
            auto sz = q.size();
            while(sz--){
                auto it = q.front();
                q.pop();
                // if()
                for(auto i : it -> children){
                    if(i)
                    q.push(i);
                }
            }
            cnt++;
        }
        return cnt;
    }
};