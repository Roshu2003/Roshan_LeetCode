class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int ans =0 ;
        for(auto it : items){
            if(ruleKey == "type"){
                if(it[0] == ruleValue)ans++;
            }
            else if(ruleKey == "color"){
                if(it[1] == ruleValue)ans++;
            }else{
                if(it[2] == ruleValue)ans++;
            }
        }
        return ans;
    }
};