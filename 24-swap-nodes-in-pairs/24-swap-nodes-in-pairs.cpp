class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        return pairSwap(head);
               
    }
public:
    ListNode* pairSwap(ListNode* head){
        if(head==NULL||head->next==NULL)
            return head;
        
        ListNode* firstNode=head;
        ListNode* secondNode=head->next;
        ListNode * temp=head;
        
        temp= pairSwap(head->next->next);
        
        firstNode->next=temp;
        secondNode->next=firstNode;
        
        return secondNode;
        
    }
};