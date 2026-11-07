class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size();
        int ans = 0;

        for(int j = 1; j < n - 1; j++) {
            int i = 0, k = j + 1;

            while(i < j && k < n) {
                int left = nums[j] - nums[i];
                int right = nums[k] - nums[j];
                if(left == diff && right == diff) {
                    ans++;
                    break;
                }
                else if(left < diff) {
                    i++;
                }
                else if(right < diff) {
                    k++;
                }
                else {
                    i++;
                }
            }
        }

        return ans;
    }
};