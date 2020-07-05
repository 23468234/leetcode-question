/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 #if 0
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (nullptr == head){
            return head;
        }
        ListNode *dummy = new ListNode();
        dummy->next = head;

        //找分界点
        ListNode *tmp = dummy;
        while(tmp != nullptr &&tmp->next != nullptr&& tmp->next->val < x){
            tmp = tmp->next;
        }
        ListNode *insert_point = tmp;

        while (tmp != nullptr && tmp->next != nullptr){
            if (tmp->next->val < x){
                // delete
                ListNode * target = tmp->next;
                tmp->next = tmp->next->next;

                // insert
                target->next = insert_point->next;
                insert_point->next = target;
                insert_point = target;
            }
            else{
                tmp = tmp->next;
            }
        }

        return dummy->next;
    }
};
#endif

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr){
            return head;
        }

        ListNode *before = new ListNode();
        ListNode *cur_before = before;
        ListNode *last = new ListNode();
        ListNode *cur_last = last;

        ListNode * tmp = head;
        while(tmp != nullptr){
            ListNode *target = tmp;
            tmp = tmp->next;
            if (target->val < x){
                cur_before->next = target;
                cur_before = target;
                cur_before->next = nullptr;
            }
            else{
                cur_last->next = target;
                cur_last = target;
                cur_last->next = nullptr;
            }
        }

        cur_before->next = last->next;
        return before->next;
    }
};