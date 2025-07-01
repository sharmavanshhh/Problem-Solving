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
        vector<ListNode*> result(k, nullptr);

        ListNode* tail = head;
        int length = 0;
        while(tail!=nullptr){
            length++;
            tail = tail->next;
        }

        int size = length / k;
        int extra = length % k;
        
        ListNode* current = head;
        for(int i=0; i<k && current != nullptr; i++){
            result[i] = current;

            int part = size + (i < extra ? 1 : 0);

            for(int j = 1; j < part; j++){
                current = current->next;
            }

            ListNode* nextPart = current->next;
            current->next = nullptr;
            current = nextPart;
        }

        return result;
    }
};