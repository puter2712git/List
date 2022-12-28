#include "list.h"

int main()
{
	struct node *head;
	char buffer[MAX_BUFFER_SIZE];

	initialize(&head);

	add_list_head(head, "abc");
	add_list_head(head, "123");

	dump_list(head);

	add_list_head(head, "head");
	add_list_tail(head, "tail");

	dump_list(head);

	del_list_head(head, buffer);

	dump_list(head);

	del_list_tail(head, buffer);

	dump_list(head);

	finalize(&head);

	return 0;
}