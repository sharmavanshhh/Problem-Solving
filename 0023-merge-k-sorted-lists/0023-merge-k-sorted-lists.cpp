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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return nullptr;
        }
        int n = lists.size();
        
        while(n > 1){
            int i = 0;
            int j = n - 1;
            
            while(i < j){
                lists[i] = mergeLists(lists[i], lists[j]);
                i++;
                j--;
            }
            
            n = (n + 1) / 2;
        }
        
        return lists[0];
    }

    ListNode* mergeLists(ListNode* start, ListNode* list){
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while(start && list){
            if(start->  val < list->val){
                tail->next = start;
                start = start->next;
            }
            else{
                tail->next = list;
                list = list->next;
            }
            tail = tail->next;
        }
        tail->next = start ? start : list;
        return dummy->next;
    }

    /*Optimal Solution is using Heap*/
};