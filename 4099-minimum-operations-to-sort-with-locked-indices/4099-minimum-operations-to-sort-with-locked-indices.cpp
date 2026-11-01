class Solution {
public:
    vector<int> bit;
    void update(int i,int n){
        while(i <= n){
            bit[i]++;
            i += (i & -i);
        }
    }
    int query(int i){
        int ans = 0;
        while(i > 0){
            ans += bit[i];
            i -= (i & -i);
        }
        return ans;
    }
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n = nums.size();
        int mx = -1;
        int ans = 0;
        for(int i = 0; i < n; i++){
            mx = max(mx,nums[i]);
            if(locked[i] == 1){
                if(nums[i] == i + 1 && mx == i + 1)continue;
                ans++;
            }
        }
        if(ans > k)return -1;
        // for(int i = 0; i < n; i++){//Inversions Count
        //     for(int j = i + 1; j < n; j++){
        //         if(nums[i] > nums[j])ans++;
        //     }
        // }
        bit.assign(n + 1,0);
        for(int i = 0; i < n; i++){
            int smaller = query(nums[i]);
            ans += i - smaller;
            update(nums[i],n);
        }
        return ans;
    }
};