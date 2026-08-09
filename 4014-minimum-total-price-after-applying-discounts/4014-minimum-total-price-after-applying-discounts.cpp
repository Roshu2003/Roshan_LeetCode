class Solution {
public:
    double minPrice(vector<int>& p, vector<int>& d) {
        sort(p.rbegin(),p.rend());
        sort(d.rbegin(),d.rend());
        double ans = 0;
        int j = 0;
        int n = p.size();
        for(int i = 0; i < n; i++){
            if(j < d.size()){
                ans += (p[i]*(100 - d[j])) / 100.0;
                j++;
            }
            else ans += p[i];
        }
        return ans;
    }
};