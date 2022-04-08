class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* cursor = head;
    for(int i = 0; i < k; i++){
        if(cursor == nullptr) return head;
        cursor = cursor->next;
    }
    ListNode* current = head;
    ListNode* next = NULL;
    ListNode* prev = NULL;
    int count = 0;
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    head->next = reverseKGroup(next, k);
    return prev;
    }
};
