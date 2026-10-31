class RLEIterator {
public:
    queue<pair<int,int>> q;
    RLEIterator(vector<int>& nums) {
        for(int i = 0; i  < nums.size(); i+=2){
            if(nums[i] != 0)
                q.push({nums[i],nums[i + 1]});
        }
    }
    
    int next(int n) {
        int ans = -1;
        while(!q.empty() && n > 0){
            auto [cnt,x] = q.front();
            if(cnt >= n){// 3 >= 2
                ans = x; // 8
                int rem = cnt - n;
                q.front().first = rem;
                return x;
            }
            else{
                n -= cnt;
                q.pop();
            }
            cout<<x<<" "<<cnt<<endl;
        }
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */