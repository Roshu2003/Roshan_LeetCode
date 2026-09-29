class Solution {
public:
    bool isValid(int l,int r,vector<int> &nums){ // o(n2)
        int len = r - l + 1;
        if(len < 3)return true;
        set<int> st;
        for(int i = l; i <= r; i++)st.insert(nums[i]);
        // 3 5 3 k
        // x + y != k -> 
        // (x + k != y || y + k != x) -> 
        int k = nums[r];
        map<int,int> mp;// 2 -> 2 // 2 2  4   k = 4
        for(int i = l ; i < r; i++){ // x + y = k -> x = k - y; 2 2 3  k = 4
            mp[nums[i]]++;
            int temp = k - nums[i]; // 4 - 2 = 2
            if(mp.count(temp)){
                if(temp == nums[i] && mp[temp] > 1)return false;
                else if(temp != nums[i])return false;
            }
        }

        for(int i = l ; i < r; i++){
            if(mp.count(nums[i] + k))return false;
        }

        return true;
    }
    int maxSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2)return n; 
        int ans = 2;
        int st = 0;
        for(int l = 0; l < n; l++){
            while(st <= l && !isValid(st,l,nums)){
                st++;
            }
            if(l - st + 1 > 2 && isValid(st,l,nums)){
                ans = max(ans,l - st + 1);
            }
        }
        return ans;
    }
};
/*

*/