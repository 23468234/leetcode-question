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
        auto cur=head;
        while(cur&&cur->next){
            if(cur->next->val==cur->val){
                cur->next=cur->next->next;
            }
            else{
                cur=cur->next;
            }
        }
        
        return head;
    }
};
