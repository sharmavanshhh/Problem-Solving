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
        ListNode* ans = lists[0];
        for(int i=1; i<lists.size(); i++){
            ans = mergeLists(ans, lists[i]);
        }
        return ans;
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
};