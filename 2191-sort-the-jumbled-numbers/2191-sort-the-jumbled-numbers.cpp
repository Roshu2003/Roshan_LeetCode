class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<tuple<int,int,int>> v;
        vector<int> ans;
        for(auto i =0 ; i < nums.size(); i++){
            int x = 0;
            string s = to_string(nums[i]);
            for(int i = 0; i < s.size(); i++){
                x = x * 10 + mapping[s[i] - '0'];
            }
            v.push_back({x,nums[i],i});
        }
        sort(v.begin(),v.end(),[](auto a,auto b){
            auto [x,y,i] = a;
            auto [x1,y1,j] = b;
            if(x == x1)return i < j;
            return x < x1;
        });
        for(auto [x,y,i] : v)ans.push_back(y);
        return ans;
    }
};