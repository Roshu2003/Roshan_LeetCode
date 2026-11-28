class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int n = num.size();
        bool ok = true;
        int idx = -1;
        for(int i = 0; i < n; i++){
            int x = num[i] - '0';
            int c = change[x];
            if(c > x){
                idx = i;
                break;
            }
        }
        if(idx == -1)return num;
        while(idx < n){
            int x = num[idx] - '0';
            int c = change[x];
            if(c >= x){
                num[idx] = (c + '0');
            }
            else break;
            idx++;
        }
        return num;
    }
};