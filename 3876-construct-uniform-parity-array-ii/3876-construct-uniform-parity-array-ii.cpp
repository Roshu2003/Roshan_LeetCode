class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n = nums.size();
        int mnOdd = INT_MAX;
        int mnEven = INT_MAX;
        for(auto it : nums){
            if(it % 2 == 0){
                mnEven = min(mnEven,it);
            }
            else mnOdd = min(mnOdd,it);
        }
        if(mnOdd == INT_MAX || mnEven == INT_MAX)return true;
        cout<<mnOdd <<" "<<mnEven<<endl;
        function<bool(int)> check = [&](int k) -> bool {
            // odd min = 1 -> want to make the array as 1 of parity
            int p = k % 2; // 1
            for(auto it : nums){
                if(it % 2 == !p){
                    if(it >= k + 1 && (it - k) % 2 == p)continue;
                    return false;
                }
            }
            return true;
        };
        if(check(mnOdd) || check(mnEven))return true;
        return false;
    }
};