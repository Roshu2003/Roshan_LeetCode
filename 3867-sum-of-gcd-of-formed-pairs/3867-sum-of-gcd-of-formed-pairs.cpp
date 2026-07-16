class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<long long> pr;
        int mx = 0;
        for(auto it : nums){
            mx = max(mx,it);
            pr.push_back(gcd(mx,it));
        }
        sort(pr.begin(),pr.end());
        long long sum = 0;
        int n = pr.size();
        // for(auto it : pr)cout<<it<<" ";
        for(int i = 0; i < pr.size() / 2; i++){
            // cout<<pr[i]<<" "<<pr[n - 1 - i]<<endl;
            sum += gcd(pr[i],pr[n - i - 1]);
        }
        return sum;
    }
};
// 2  3 4
// n = 3 / 2 = 1;