class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        int i = 0;
        int j = m - 1;
        while(i < n && j >= 0){
            int x = mat[i][j];
            if(x == target){
                return true;
            }else if(x > target){
                j--;
            }
            else i++;
        }
        return false;
    }
};