class Solution {
public:
    vector<int> arr;
    bool solve(int i,int j,int s1,int s2,int f){
        if(i > j){
            return s1 >= s2;
        }
        if(f){
            return solve(i + 1,j,s1 + arr[i],s2,0) || solve(i,j - 1,s1 + arr[j],s2,0);
        }
        else{
           return solve(i + 1,j,s1,s2 + arr[i],1) && solve(i,j - 1,s1,s2 + arr[j],1);
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        arr = nums;
        return solve(0,nums.size() - 1,0,0,1);
    }
};