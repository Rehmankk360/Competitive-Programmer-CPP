class Solution {
public:
    
    ListNode* removeNthFromEndHelper(ListNode* head, int n, int& index){
        if(head == nullptr)
            return nullptr;
        
        ListNode* t = removeNthFromEndHelper(head->next, n, index);
        index += 1;
        
        if(index == n){
            delete head;
            return t;
        }
        
        head->next = t;
        return head;  
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i = 0;
        return removeNthFromEndHelper(head, n, i);
    }
};