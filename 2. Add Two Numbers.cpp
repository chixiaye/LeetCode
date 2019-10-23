#include<stdlib.h>
struct ListNode {
	int val;
	struct ListNode* next;
};
typedef struct ListNode ListNode;
//优化 可以用 abc 来表示 相加的过程 这样就不用分别写三种情况了
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	ListNode* res = (ListNode*)malloc(sizeof(ListNode));
	res->val = 0;
	res->next = NULL;
	ListNode* p1 = l1, * p2 = l2, * p3 = res;
	int jinwei = 0;
	while (p1 != NULL || p2 != NULL)
	{
		p3->next = (ListNode*)malloc(sizeof(ListNode));;
		p3->next->val = jinwei;
		p3->next->next = NULL;
		jinwei = 0;
		if (p1 == NULL)
		{
			p3->next->val += p2->val;
			if (p3->next->val > 9) p3->next->val -= 10, jinwei = 1;
			else jinwei = 0;
			p3 = p3->next;
			p2 = p2->next;
		}
		else if (p2 == NULL)
		{
			p3->next->val += p1->val;
			if (p3->next->val > 9) p3->next->val -= 10, jinwei = 1;
			else jinwei = 0;
			p3 = p3->next;
			p1 = p1->next;
		}
		else
		{
			p3->next->val += p1->val + p2->val;
			if (p3->next->val > 9) p3->next->val -= 10, jinwei = 1;
			else jinwei = 0;
			p3 = p3->next;
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	if (jinwei)
	{
		p3->next = (ListNode*)malloc(sizeof(ListNode));;
		p3->next->val = jinwei;
		p3->next->next = NULL;
	}
	return res->next;
}

