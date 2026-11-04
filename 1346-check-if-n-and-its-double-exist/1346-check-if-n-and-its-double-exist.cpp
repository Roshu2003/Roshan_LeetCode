class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int> mp;
        for(auto it : arr)mp[it]++;
        for(auto it : arr){
            if(it == 0){
                if(mp[it] > 1 && mp.count(it * 2))return true;
            }
            else{
                if(mp.count(it * 2))return true;
            }
        }
        return false;
    }
};