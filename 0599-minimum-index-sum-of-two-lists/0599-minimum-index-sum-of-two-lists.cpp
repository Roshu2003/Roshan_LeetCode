class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ans;
        int mn = 1e9;
        map<string,int> mp;
        for(int i = 0; i < list1.size(); i++)mp[list1[i]] = i;
        for(int i = 0; i < list2.size(); i++){
            if(mp.count(list2[i])){
                if(i + mp[list2[i]] < mn){
                    mn = i + mp[list2[i]];
                    ans.clear();
                    ans.push_back(list2[i]);
                }
                else if(i + mp[list2[i]] == mn){
                    ans.push_back(list2[i]);
                }
            }
        }
        return ans;
    }
};