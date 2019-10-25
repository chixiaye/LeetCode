#include<stdio.h>
#include<stdlib.h>
struct ListNode {
      int val;
      struct ListNode *next;
  };

typedef struct ListNode  ListNode;
struct ListNode* swapPairs(struct ListNode* head) {
	ListNode* p1 = head;
	if (p1 == NULL) return head;
	ListNode* p2 = head->next;
	ListNode* res = p2;
	if (p2 == NULL) return head;
	p1->next = p2->next;
	p2->next = p1;
	p1 = p1->next;
	if (p1 == NULL)
		return res;
	p2 = p1->next;
	if (p2 == NULL)
		return res;
	ListNode* p3 = head;
	while (true)
	{
		p3->next = p2;
		p1->next = p2->next;
		p2->next = p1;
		p3 = p1;
		p1 = p1->next;
		if (p1 == NULL)
			break;
		p2 = p1->next;
		if (p2 == NULL)
			break;
	}
	return res;
}

