// class Solution {
// public:
//     int minimumLengthEncoding(vector<string>& words) {
//         int n = words.size();
//         for(string& w : words){
//             reverse(w.begin(),w.end());
//         }
//         sort(words.begin(),words.end(),[](const string& a, const string& b){
//             return a < b;
//         });
//         int res = 0;
//         for(int i = 0;i<n;i++){
//             if(i+1<n && words[i+1].substr(0,words[i].size()) == words[i]){
//                 continue;
//             }else{
//                 res += words[i].size() + 1;
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    struct Node {
        Node* child[26];
        Node() {
            for (int i = 0; i < 26; i++)
                child[i] = NULL;
        }
    };
    int minimumLengthEncoding(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        sort(words.begin(), words.end(), [](string& a, string& b) {
            return a.size() > b.size();
        }); Node* root = new Node();
        for (auto it : words) {
            Node* curr = root;
            int isNew = 0;
            for (int i = it.size() - 1; i >= 0; i--) {
                int idx = it[i] - 'a';
                if (curr->child[idx] == NULL) {
                    curr->child[idx] = new Node();
                    isNew = 1;
                }
                curr = curr->child[idx];
            }
            if (isNew)
                ans += it.size() + 1;
        }
        return ans;
    }
};