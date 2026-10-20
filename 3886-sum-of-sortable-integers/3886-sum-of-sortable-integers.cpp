class Solution {
public:
    long long sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        vector<int> divisors;

        for (int i = 1; 1LL * i * i <= n; i++) {
            if (n % i == 0) {
                divisors.push_back(i);
                if (i != n / i)
                    divisors.push_back(n / i);
            }
        }

        long long ans = 0;

        for (int k : divisors) {
            bool ok = true;

            for (int start = 0; start < n; start += k) {
                vector<int> a(nums.begin() + start,
                              nums.begin() + start + k);
                vector<int> b(sortedNums.begin() + start,
                              sortedNums.begin() + start + k);
                
                int m = a.size();
                for(int i = 0; i < m; i++)a.push_back(a[i]);

                int i = 0;
                int j = 0;
                while(i < a.size() && j < b.size()){
                    if(a[i] == b[j]){
                        i++;
                        j++;
                    }else{
                        i++;
                        j = 0;
                    }
                }
                if (j != b.size()) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                ans += k;
        }

        return ans;
    }
};