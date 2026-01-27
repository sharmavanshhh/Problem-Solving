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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* temp = dummy;
        ListNode* current = head;

        for(int i=1; i<left; i++){
            temp = temp->next;
            current = current->next;
        }

        ListNode* subHead = current;
        ListNode* prev = nullptr;
        for(int i=0; i<=right-left; i++){
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        temp->next = prev;
        subHead->next = current;
        return dummy->next;
    }
};