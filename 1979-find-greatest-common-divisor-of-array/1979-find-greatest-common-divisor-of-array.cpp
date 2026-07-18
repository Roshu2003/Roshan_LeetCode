class Solution {
public:
    int find(int a,int b){
        if(!b)return a;
        return find(b,a % b);
    }
    int findGCD(vector<int>& nums) {
        int a = -1;
        int b = 10001;
        for(auto it : nums){
            a=  max(a,it);
            b = min(b,it);
        }
        return find(a,b);
    }
};