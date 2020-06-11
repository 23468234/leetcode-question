class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (nullptr == l1) {
      return l2;
    }
    if (nullptr == l2) {
      return l1;
    }

    ListNode* ret_head = nullptr;
    ListNode* ret_tail = nullptr;

    while (l1 != nullptr && l2 != nullptr) {
      ListNode* p_tmp = nullptr;
      if (l1->val < l2->val) {
        p_tmp = l1;
        l1 = l1->next;
      } else {
        p_tmp = l2;
        l2 = l2->next;
      }

      if (nullptr == ret_head) {
        ret_head = p_tmp;
        ret_tail = p_tmp;
      } else{
        ret_tail->next = p_tmp;
        ret_tail = p_tmp;
        p_tmp->next = nullptr;
      }
    }

    if (nullptr != l1) {
      ret_tail->next = l1;
    }
    if (nullptr != l2) {
      ret_tail->next = l2;
    }

    return ret_head;
  }
};

作者：shan-qiu-zhi-wang
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists/solution/21-he-bing-liang-ge-you-xu-lian-biao-by-shan-qiu-z/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。