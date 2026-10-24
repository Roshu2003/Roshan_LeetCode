/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int idx = 1;
        int last = -1;
        int first = -1;
        int mn = INT_MAX;
        int mx = INT_MIN;
        if(!head -> next)return {-1,-1};
        ListNode* curr = head -> next;
        ListNode* prev = head;
        while(curr -> next){
            int a = prev -> val;
            int b = curr -> val;
            int c = curr -> next -> val;
            // cout<<a << " "<<b<<" "<<c<<endl;
            if((a < b && b > c) || (a > b && b < c)){
                // cout<<"Yes"<<endl;
                if(first == -1){
                    first = idx;
                    last = idx;
                }
                if(last != idx)
                    mn = min(mn,idx - last);
                mx = max(mx,idx - first);
                last = idx;
            }
            idx++;
            prev = curr;
            curr = curr -> next;
        }
        if(mn == INT_MAX || mx == INT_MIN)return {-1,-1};
        return {mn,mx};
    }
};