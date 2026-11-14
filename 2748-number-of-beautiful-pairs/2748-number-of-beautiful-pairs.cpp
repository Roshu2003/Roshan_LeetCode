class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int f_len = log10(nums[i]);
                int x = pow(10,f_len);
                int first = nums[i] / x;
                // cout<<nums[i]<< " " <<first<<endl;
                int last = nums[j] % 10;
                if(gcd(first,last) == 1){
                    ans++;
                }
            }
        }
        return ans;
    }
};