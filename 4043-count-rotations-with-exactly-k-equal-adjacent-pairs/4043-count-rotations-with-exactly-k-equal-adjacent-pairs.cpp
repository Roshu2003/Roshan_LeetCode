class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();
        int total =0 ;
        for(int i = 1; i < n; i++){
            if(s[i - 1] == s[i])total++;
        }

        if(s[n - 1] == s[0]){
            total++;
        }

        if(k == total)return n - total;
        if(k + 1 == total)return total;
        return 0;
    }
};