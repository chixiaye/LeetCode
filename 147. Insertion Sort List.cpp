#include<stdlib.h>
#include<stdio.h>
struct ListNode {
      int val;
      struct ListNode *next;
};

typedef struct ListNode ListNode;
struct ListNode* insertionSortList(struct ListNode* head) {
	ListNode* p = head;
	ListNode* res = (ListNode*)malloc(sizeof(ListNode));
	res->next = head;
	while (p && p->next)
	{
		ListNode* q = res->next;
		ListNode* pn = p->next;
		if (q->val > pn->val)
		{
			p->next = pn->next;
			pn->next = res->next;
			res->next = pn;
			continue;
		}
		while (q != p && q->next)
		{
			if (q->next->val > pn->val)
			{
				p->next = pn->next;
				pn->next = q->next;
				q->next = pn;
				break;
			}
			q = q->next;
		}
		if (q == p || q->next == NULL)
			p = p->next;
	}
	return res->next;
}




