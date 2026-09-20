class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        int i = 1;
        for(auto it:s){
            sum += i * (26 - (it - 'a'));
            i++;
        }
        return sum;
    }
};