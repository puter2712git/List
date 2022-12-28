#include "list.h"

int main()
{
	struct node *head;

	initialize(&head);

	add_list_head(head, "abc");
	add_list_head(head, "123");

	dump_list(head);

	add_list_head(head, "head");
	add_list_tail(head, "tail");

	dump_list(head);

	del_list_head(head);

	dump_list(head);

	del_list_tail(head);

	dump_list(head);

	return 0;
}