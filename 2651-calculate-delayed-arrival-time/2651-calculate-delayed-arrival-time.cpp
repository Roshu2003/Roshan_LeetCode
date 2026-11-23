class Solution {
public:
    int findDelayedArrivalTime(int a, int b) {
        int x = a + b;
        return x % 24;
    }
};