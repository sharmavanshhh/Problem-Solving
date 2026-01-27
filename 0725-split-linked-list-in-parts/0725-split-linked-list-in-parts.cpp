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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k, nullptr);

        ListNode* tail = head;
        int length = 0;
        while(tail){
            length++;
            tail = tail->next;
        }

        int size = length / k;
        int rem = length % k;

        ListNode* current = head;
        for(int i=0; i<k; i++){
            if(!current){
                ans[i] = nullptr;
                continue;
            }
            ans[i] = current;
            int partSize = size + (i < rem ? 1 : 0);
            for(int j=1; j<partSize; j++){
                current = current->next;
            }
            ListNode* next = current->next;
            current->next = nullptr;
            current = next;
        }

        return ans;
    }
};