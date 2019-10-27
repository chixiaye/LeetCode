#include<stdlib.h>
struct ListNode {
	int val;
	struct ListNode* next;
};

typedef struct ListNode ListNode;
struct ListNode* partition(struct ListNode* head, int x) {	
	ListNode* res = (ListNode *)malloc(sizeof(ListNode));
	res->next = head;
	res->val = x;
	ListNode* p1 = res;
	ListNode* p2 = res;
	while (p1->next)
	{
		while (p1&&p1->next&&p1->next->val < x)
		{
			p1 = p1->next;
		}
		p2 = p1->next;
		while (p2 && p2->next && p2->next->val >= x)
		{
			p2 = p2->next;
		}
		if (!p2 || !p2->next) break;
		ListNode* p3 = p2->next;
		p2->next = p3->next;
		p3->next = p1->next;
		p1->next = p3;
		p1 = p1->next;
	}
	ListNode* ans = res->next;
	free(res);
	return ans;
}

