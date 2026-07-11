class Solution {
public:
    vector<int> lastVisitedIntegers(vector<int>& nums) {
        vector<int> ans,seen;
        int k = 0;
        for(auto it : nums){
            if(it > 0){
                seen.push_back(it);
                k = 0;
            }
            else{
                k++;
                if(k > seen.size()){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(seen[(seen.size() - k)]);
                }
            }
        }
        return ans;
    }
};