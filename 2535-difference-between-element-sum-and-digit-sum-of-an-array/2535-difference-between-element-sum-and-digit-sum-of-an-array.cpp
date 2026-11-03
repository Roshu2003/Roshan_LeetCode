class Solution {
public:
    int find(int n){
        int sum = 0;
        while(n > 0){
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int differenceOfSum(vector<int>& nums) {
        int sum = 0;
        for(auto it : nums){
            sum += it;
            sum -= find(it);
        }
        return abs(sum);
    }
};