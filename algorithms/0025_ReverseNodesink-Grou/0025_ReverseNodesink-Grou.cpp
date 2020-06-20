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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // judge valid
        if (nullptr == head || k <= 1){
            return head;
        }
        auto judgeLength = [](ListNode* head, int k)->bool{
            while(k > 0 && head != nullptr){
                head = head->next;
                k--;
            }
            return k > 0 ? false :true;
        };
        if (!judgeLength(head, k)){
            return head;
        }

        // 旋转
        int count = 0;
        ListNode* i = head;
        ListNode* j = i->next;
        while (i != nullptr && j != nullptr &&count < k - 1) {
            ListNode* m = j->next;
            j->next = i;
            i = j;
            j = m;
            count++;
        }
        head->next = reverseKGroup(j,  k);
        return i;
    }
};