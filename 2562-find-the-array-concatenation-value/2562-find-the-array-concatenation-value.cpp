class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        while(i <= j){
            if(i == j){
                ans += nums[i];
            }
            else{
                int a = nums[i];
                int b = nums[j];
                int x = log10(b) + 1;
                long long con = a * pow(10,x) + b;
                ans += con;
            }
            i++;
            j--;
        }
        return ans;
    }
};