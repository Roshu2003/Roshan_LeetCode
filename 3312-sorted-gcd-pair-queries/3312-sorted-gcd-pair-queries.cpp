class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int mx = *max_element(nums.begin(),nums.end());
        vector<int> gcdCnt(mx + 1,0);
        for(auto x : nums){
            for(int i = 1; i * i <= x; i++){
                if(x % i == 0){
                    gcdCnt[i]++;
                    if(x / i != i) gcdCnt[x / i]++;
                }
            }
        }
        vector<long long> cnt(mx + 1,0);
        for(int i = mx; i >= 1; i--){
            int m = gcdCnt[i];
            cnt[i] = 1LL * m * (m - 1) / 2;
            for(int j = i * 2; j <= mx; j += i){
                cnt[i] -= cnt[j];
            }
        }
        vector<long long> pre(mx + 1,0);
        for(int i = 1; i <= mx; i++){
            pre[i] = pre[i - 1] + cnt[i];
        }
        vector<int> ans;
        for(auto it : queries){
            int lo = 1;
            int hi = mx;
            int temp = 1;
            while(lo <= hi){
                int mid = (lo + hi) / 2;
                if(pre[mid] > it){
                    temp = mid;
                    hi = mid - 1;
                }
                else{
                    lo = mid + 1;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};