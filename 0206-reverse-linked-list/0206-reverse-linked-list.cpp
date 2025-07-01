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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }

        ListNode* Prev = nullptr;
        ListNode* current = head;

        while(current){
            ListNode* Next = current->next;
            current->next = Prev;
            Prev = current;
            current = Next;
        }
        return Prev;
    }
};