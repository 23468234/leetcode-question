class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode *p = head;
        ListNode *q = head;
        for (int i = 0; i < n; ++i)
        {
            q = q->next;
        }

        if (q == nullptr)
        {
            ListNode* del_node = head;
            head = head->next;
            delete del_node;
            del_node = nullptr;
            return head;
        }

        while(q->next != nullptr){
            q = q->next;
            p = p->next;
        }

        
        ListNode* del_node = p->next;
         p->next =  p->next->next;
        delete del_node;
        del_node = nullptr;
        return head;
        
    }
};