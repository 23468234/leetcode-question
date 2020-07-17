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
    ListNode* deleteDuplicates(ListNode* head) {
        if (nullptr == head){
            return head;
        }

        ListNode*dummy = new ListNode(0);
        dummy->next = head;

        ListNode* p_cur = dummy;
        while(nullptr != p_cur){
            bool delete_flag = false;
            while (nullptr !=  p_cur->next 
                && nullptr != p_cur->next->next 
                && p_cur->next->val == p_cur->next->next->val){
                    p_cur->next->next = p_cur->next->next->next;
                    delete_flag = true;
            }

            if (delete_flag){
                p_cur->next = p_cur->next->next;
            }
            else{
                p_cur = p_cur->next; 
            }
        }

        return dummy->next;
    }
};