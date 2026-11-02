class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return head;
        ListNode* temp = head;
        while (temp != nullptr && temp->next != nullptr) {
            if (temp->next->val == temp->val)
                temp->next = temp->next->next;
            else
                temp = temp->next;
        }

        return head;
    }
};