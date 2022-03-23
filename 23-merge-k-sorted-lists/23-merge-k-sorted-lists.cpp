class Solution {
public:

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* prev = new ListNode(0,list1);
    ListNode* ans = prev;
    ListNode* temp;
    if(!list1) return list2;
    if(!list2) return list1;
    while(list1){
        if(list2 && list1->val >= list2->val){
           temp = list2->next;
           prev->next = list2;
           prev->next->next = list1;
           list2 = temp;
        }else{
            list1 = list1->next;
        }
        prev = prev->next;
    }
    if(list2) prev->next = list2;
    return ans->next;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.size()==0) return {};
    int k = lists.size();
    while(k > 1){
        int cnt = 0;
        for(int i = 0 ;  i < k ; i+=2){
            if(i+1 < k){
                lists[cnt]=mergeTwoLists(lists[i],lists[i+1]);
            }else{
                lists[cnt]=lists[i];
            }
            cnt++;
        }
        k = cnt;
    }
    return lists[0];
}
};