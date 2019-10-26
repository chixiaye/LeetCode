#include<stdio.h>
#include<stdlib.h>
struct ListNode {
	int val;
	struct ListNode* next;

};

typedef struct ListNode ListNode;
struct ListNode* deleteDuplicates(struct ListNode* head) {
	ListNode* p1 = head;
	if (p1 == NULL) return p1; 
	ListNode* p2;
	ListNode* p0 = NULL;
	while (p1 != NULL)
	{
		 p1->val;
		p2 = p1->next;
		if (p2 == NULL)
			break;
		bool duplicate = false;
		while (p2 != NULL && p1->val == p2->val)
		{
			duplicate = true;
			ListNode* p3 = p2;
			p2 = p2->next;
			p1->next = p2;
			free(p3);
		}
		if (duplicate)
		{
			ListNode* p3 = p1;
			p1 = p1->next;
			if (p0 == NULL) 
			{
				head=p1;
			}
			else 
				p0->next = p1;
			free(p3);
		}
		else
		{
			p0 = p1;
			p1 = p1->next;
		}
	}
	return head;
}
