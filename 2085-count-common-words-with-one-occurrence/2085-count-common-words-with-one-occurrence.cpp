class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int>mp1,mp2;
        for(auto it : words1)mp1[it]++;
        for(auto it : words2)mp2[it]++;
        int count = 0;
        for(auto [it,cnt] : mp1){
            if(mp2.count(it) && cnt == mp2[it] && cnt == 1)count++;
        }
        return count;
    }
};