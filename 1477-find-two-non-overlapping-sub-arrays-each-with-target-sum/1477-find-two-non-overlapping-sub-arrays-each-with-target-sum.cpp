class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int sum = 0;
        int st = 0;
        int ans = INT_MAX;
        int bestMin = INT_MAX;
        int n = arr.size();
        vector<int> v(n,INT_MAX);
        for(int i = 0; i < n; i++){
            sum += arr[i];
            while(sum > target){
                sum -= arr[st++];
            }
            if(target == sum){
                int len = i - st + 1;
                if(st > 0 && v[st - 1] != INT_MAX){
                    ans = min(ans,len + v[st - 1]);
                }
                bestMin = min(bestMin,len);
            }
            v[i] = bestMin;
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};