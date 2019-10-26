#include<stdio.h>
struct ListNode {
	 int val;
	 struct ListNode* next; 
}; 

typedef struct ListNode ListNode;
struct ListNode* rotateRight(struct ListNode* head, int k) {
	int len = 1;
	ListNode *p = head;
	ListNode* q1=head ;
	ListNode* q2 = head;
	if (p == NULL) return head;
	while (p->next!= NULL)
	{
		p = p->next;
		len++;
	}
	k = k % len;
	int t = len - k+1;//t-th is the head node;
	p->next = head;
	while (t--)
	{
		q2 = q1;
		q1 = q1->next;
	}
	q2->next = NULL;
	return q1; 
}
