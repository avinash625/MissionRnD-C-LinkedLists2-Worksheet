/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	struct node *temp, *temp1, *new_head = NULL , *next_element;
	if (head == NULL)
		return NULL;
	else
	{
		next_element = head;
		for (temp = head; next_element != NULL; temp = next_element)
		{
			next_element = temp->next;
			temp1 = temp;
			temp1->next = new_head;
			new_head = temp;
		}
	}
	return new_head;
}
