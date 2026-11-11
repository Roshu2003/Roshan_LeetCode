class Solution {
public:
    string getSmallestString(string s) {
        for(int i = 1; i < s.size(); i++){
            int a = s[i] - '0';
            int b = s[i - 1] - '0';
            // cout<<a<<" "<<b<<endl;
            if(a < b){
                if(a % 2 == b % 2){
                    swap(s[i],s[i - 1]);
                    return s;
                }
            }
        }
        return s;
    }
};