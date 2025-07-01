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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        long long num1 = 0, num2 = 0;

        while(l1){
            num1 = num1 * 10 + l1->val;
            l1 = l1->next;
        }
        while(l2){
            num2 = num2 * 10 + l2->val;
            l2 = l2->next;
        }
        long long rnum1 = 0, rnum2 = 0;
        while(num1 > 0){
            int temp = num1 % 10;
            rnum1 = rnum1 * 10 + temp;
            num1 /= 10;
        }
        while(num2 > 0){
            int temp = num2 % 10;
            rnum2 = rnum2 * 10 + temp;
            num2 /= 10;
        }

        int sum = rnum1 + rnum2;

        ListNode* dummy = new ListNode(0,nullptr);
        ListNode* current = dummy;

        if(sum == 0){
            return dummy;
        }

        while(sum > 0){
            ListNode* newNode = new ListNode(sum % 10);
            current->next = newNode;
            current = newNode;
            sum /= 10;
        }
        
        return dummy->next;
    }
};