#include<stdlib.h>
#include<stdio.h>
struct ListNode {
	int val;
	struct ListNode* next;
};

typedef struct ListNode ListNode;
ListNode* reorderList(struct ListNode* head) {
	ListNode* p = head;
	ListNode* q = p;
	if (!head) return head;
	while (q->next != NULL)
	{
		p = p->next;
		q = q->next;
		if (q->next) q = q->next;
	}
	ListNode* next = p->next;//= p->next;
	ListNode* cur = p->next;
	ListNode* pre = NULL;
	while (cur)
	{
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	ListNode* s = head;
	p->next = NULL;
	while (p != q && s && q)
	{
		ListNode* temp1 = s->next;
		ListNode* temp2 = q->next;
		s->next = q;
		q->next = temp1;
		s = temp1;
		q = temp2;
	}
	return head;
}
