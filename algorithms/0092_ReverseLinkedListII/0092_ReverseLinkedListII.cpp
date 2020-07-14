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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(nullptr == head || m >= n){
            return head;
        }
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *p1 = dummy;
        int index = 0;
        while(index < m - 1){
            p1 = p1->next;
            index++;
        }


        ListNode *section_before  = p1;
        ListNode *section_tail  = section_before->next;
        
        p1  = section_before->next;
        ListNode *p2  = p1->next;
        ListNode *p3 = p2->next;

        for (int i = 0; i < n - m; ++i){
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            if (p3 == nullptr){
                break;
            }

            p3 = p3->next;
        }

        ListNode *section_head = p1;
        section_before->next = section_head;
        section_tail->next = p2;

        return dummy->next;        
    }
};