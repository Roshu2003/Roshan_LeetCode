class Solution {
public:
    bool areNumbersAscending(string s) {
        int last = -1;
        int num = 0;
        s += ' ';
        for(auto it : s){
            if(it >= '0' && it <= '9'){
                num = num * 10 + (it - '0');
            }
            else if(it == ' '){
                if(num != 0){
                    if(num <= last)return false;
                    last = num;
                }
                num = 0;
            }
        }
        return true;
    }
};