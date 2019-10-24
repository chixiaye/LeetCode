struct ListNode {
	int val;
	struct ListNode* next;
};

typedef struct ListNode ListNode;
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	ListNode* front = head;
	ListNode* behind = head;
	while (front != NULL) {
		front = front->next;
		if (n-- < 0) behind = behind->next;
	}
	if (n == 0) head = head->next;
	else behind->next = behind->next->next;
	return head;
}

/*
initial
--------------------------------------------------------------------------
typedef struct ListNode ListNode;
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	ListNode* p[100];
	p[0] = head;
	int i = 1;
	while (p[i - 1] != NULL)
	{
		p[i] = p[i - 1]->next;
		i++;
	}
	i--;
	//    printf("%d\n",i);
	if (i == 1)
	{
		free(head);
		return NULL;
	}
	else if (i == n)
	{
		free(head);
		return p[1];
	}
	else
	{
		p[i - n - 1]->next = p[i - n + 1];
		free(p[i - n]);
	}
	return p[0];
}

*/