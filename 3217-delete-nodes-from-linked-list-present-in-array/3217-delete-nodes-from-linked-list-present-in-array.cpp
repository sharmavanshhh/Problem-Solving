class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // ListNode* dummy = new ListNode(0, head);

        // for (int i = 0; i < nums.size(); i++) {
        //     ListNode* current = dummy->next;
        //     ListNode* prev = dummy;

        //     while (current) {
        //         if (current->val == nums[i]) {
        //             prev->next = current->next;
        //             current = prev->next;
        //         } else {
        //             prev = current;
        //             current = current->next;
        //         }
        //     }
        // }

        // return dummy->next;

        unordered_set<int> toDelete(nums.begin(), nums.end());
        ListNode* dummy = new ListNode(0, head);
        ListNode* current = dummy;

        while(current && current->next){
            if(toDelete.count(current->next->val)){
                ListNode* temp = current->next;
                current->next = temp->next;
            }
            else{
                current = current->next;
            }
        }

        return dummy->next;
    }
};
