/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	struct node *iterator1, *new_head = NULL , *iterator2, *temp;
	if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;
	else if (head1 == NULL && head2 == NULL)
		return NULL;
	else
	{
		for (iterator1 = head1, iterator2 = head2; iterator1 != NULL && iterator2 != NULL; )
		{
			if (iterator1->num >= iterator2->num)
			{
				if (new_head == NULL)
				{
					temp = new_head = iterator2;
				}
				else
				{
					temp->next = iterator2;
					temp = iterator2;
				}
				iterator2 = iterator2->next;
			}
			else
			{
				if (new_head == NULL)
				{
					temp = new_head = iterator1;
				}
				else
				{
					temp->next = iterator1;
					temp = iterator1;
				}
				iterator1 = iterator1->next;
			}
		}
		if (iterator1 != NULL)
		{
			for (; iterator1 != NULL; temp = iterator1, iterator1 = iterator1->next)
				temp->next = iterator1;
		}
		else
			for (; iterator2 != NULL;temp = iterator2, iterator2 = iterator2->next)
				temp->next = iterator2;
	}
	return new_head;
}
