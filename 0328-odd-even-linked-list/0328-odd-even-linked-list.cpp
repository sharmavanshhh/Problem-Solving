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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddDummy = new ListNode(0);
        ListNode* evenDummy = new ListNode(0);
        int i = 1;
        ListNode* oddCurr = oddDummy;
        ListNode* evenCurr = evenDummy;

        while(head){
            ListNode* nextNode = head->next;
            head->next = nullptr;
            if(i % 2 == 0){
                evenCurr->next = head;
                evenCurr = evenCurr->next;
            }
            else{
                oddCurr->next = head;
                oddCurr = oddCurr->next;
            }
            i++;
            head = nextNode;
        }

        oddCurr->next = evenDummy->next;
        return oddDummy->next;
    }
};