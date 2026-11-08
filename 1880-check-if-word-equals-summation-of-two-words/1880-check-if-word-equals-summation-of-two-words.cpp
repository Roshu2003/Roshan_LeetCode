class Solution {
public:
    int find(string s){
        int num = 0;
        for(auto it : s){
            num = num * 10 + (it - 'a');
        }
        return num;
    }
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return find(firstWord) + find(secondWord) == find(targetWord);
    }
};