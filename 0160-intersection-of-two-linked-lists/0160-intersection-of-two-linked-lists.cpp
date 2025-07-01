/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;

        ListNode* start1 = headA;
        ListNode* start2 = headB;

        while(start1 != start2){
            start1 = (start1 != nullptr) ? start1->next : headB;
            start2 = (start2 != nullptr) ? start2->next : headA;
       }

       return start1;
    }
};