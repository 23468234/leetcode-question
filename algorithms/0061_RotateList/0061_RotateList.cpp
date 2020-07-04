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
    ListNode* rotateRight(ListNode* head, int k) {
        if (nullptr == head || k == 0){
            return head;
        }

        // Get the list count
        ListNode* tmp = head;
        int count = 1;
        while(tmp->next != nullptr){
            tmp = tmp->next;
            count ++;
        }   
        ListNode* old_tail = tmp;

        // Just the full circle
        if (0 == k % count){
            return head;
        }

        // Get the splite node
        tmp = head;
        int splite_index = count - k % count - 1;
        while (splite_index > 0){
            splite_index--;
            tmp = tmp->next;
        }

        // Change the link
        ListNode* new_tail = tmp;        
        ListNode* new_head = tmp->next;
        new_tail->next = nullptr;
        old_tail->next = head;
        return new_head;        
    }
};