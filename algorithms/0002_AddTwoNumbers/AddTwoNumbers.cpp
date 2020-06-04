/*
2. 两数相加
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/
#include <vector>
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (nullptr == l1 || nullptr == l2)
		{
			return nullptr;
		}

		ListNode *lst_ret = nullptr;
		ListNode *l1_cur = l1;
		ListNode *l2_cur = l2;
		ListNode *ret_cur = nullptr;
		int extra_num = 0;
		while (l1_cur != nullptr || l2_cur != nullptr)
		{
            int x = (nullptr != l1_cur) ? l1_cur->val: 0;
            int y = (nullptr != l2_cur) ? l2_cur->val: 0;;
			int i_value = (x + y + extra_num) % 10;
			extra_num = (x + y + extra_num) / 10;

			if (nullptr == ret_cur)
			{
				ret_cur = new ListNode(i_value);
				lst_ret = ret_cur;
			}
			else
			{
				ret_cur->next = new ListNode(i_value);
				ret_cur = ret_cur->next;
			}

			if (nullptr != l1_cur)l1_cur = l1_cur->next;
			if (nullptr != l2_cur)l2_cur = l2_cur->next;
		}

        if (extra_num != 0)
        {
            ret_cur->next = new ListNode(extra_num);
            ret_cur = ret_cur->next;
        }

		return lst_ret;
	}
};


int main()
{
	//输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
	//	输出：7 -> 0 -> 8
	//	原因：342 + 465 = 807
	int nums1[] = { 0 };
	ListNode *lst1 = nullptr;
	ListNode *lst1_cur = nullptr;
	for (int i = sizeof(nums1) / sizeof(nums1[0]) - 1; i >= 0; --i)
	{
		lst1_cur = new ListNode(nums1[i]);
		lst1_cur->next = lst1 ;
		lst1 = lst1_cur;
	}

	int nums2[] = { 3,7 };
	ListNode *lst2 = nullptr;
	ListNode *lst2_cur = nullptr;
	for (int i = sizeof(nums2) / sizeof(nums2[0]) -1; i >= 0 ; -- i)
	{
		lst2_cur = new ListNode(nums2[i]);
		lst2_cur->next = lst2;
		lst2 = lst2_cur;
	}

	Solution().addTwoNumbers(lst1, lst2);
	return 0;
}