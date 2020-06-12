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
    ListNode* swapPairs(ListNode* head) {
        if (nullptr == head || nullptr == head->next)
        {
            return head;
        }

        ListNode* p = head->next;
        head->next = p->next;
        p->next = head;
        head = p;
        p = p->next;
        
        while(nullptr != p->next && nullptr != p->next->next ){
             ListNode* tmp = p->next;
             p->next = tmp->next;
             tmp->next = p->next->next ;
             p->next->next = tmp;
             p = tmp;
        }

        return head;
    }
};


class Solution2 {
public:
    ListNode* swapPairs(ListNode* head) {
        if (nullptr == head || nullptr == head->next)
        {
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p = dummy;
        
        while(nullptr != p->next && nullptr != p->next->next ){
             ListNode* tmp = p->next;
             p->next = tmp->next;
             tmp->next = p->next->next ;
             p->next->next = tmp;
             p = tmp;
        }

        head = dummy->next;
        delete dummy;
        dummy = nullptr;
        return head;
    }
};

