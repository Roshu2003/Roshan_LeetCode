// class Solution {
// public:
//     bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
//         int st = 0;
//         int m = nums.size();
//         for(auto v  : groups){
//             int n = v.size();
//             bool ok = true;
//             int i = st;
//             int j = 0;
//             while(j < n && i < m){
//                 if(nums[i] == v[j]){
//                     j++;
//                     i++;
//                 }
//                 else{
//                     i = st + 1;
//                     st++;
//                     j = 0;
//                 }
//             }
//             if(j != n)return false;
//             st = i;
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int st = 0;
        int m = nums.size();

        for (auto &v : groups) {
            int n = v.size();
            bool found = false;

            while (st + n <= m) {
                int j = 0;

                while (j < n && nums[st + j] == v[j]) {
                    j++;
                }

                if (j == n) {
                    st += n;
                    found = true;
                    break;
                }
                st++;
            }

            if (!found) return false;
        }

        return true;
    }
};