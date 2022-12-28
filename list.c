#include "list.h"

void initialize(struct node **_head)
{
	*_head = (struct node*)malloc(sizeof(struct node));
	(*_head)->data = NULL;
	(*_head)->left = NULL;
	(*_head)->right = NULL;

	return;
}


void finalize(struct node **_head)
{
	free(*_head);

	return;
}


bool is_empty(struct node *_head)
{
	return !_head->left && !_head->right;
}


void add_list_head(struct node *_head, char *_item)
{
	struct node *new = (struct node*)malloc(sizeof(struct node));
	new->data = _item;

	/* If the list is empty */
	if (is_empty(_head)) {
		_head->right = new;
		_head->left = new;

		new->left = _head;
		new->right = _head;

		return;
	}
	
	new->left = _head;
	new->right = _head->right;

	_head->right = new;

	new->right->left = new;

	return;
}


void add_list_tail(struct node *_head, char *_item)
{
	struct node *new = (struct node*)malloc(sizeof(struct node));
	new->data = _item;

	/* If the list is empty */
	if (is_empty(_head)) {
		_head->right = new;
		_head->left = new;

		new->left = _head;
		new->right = _head;

		return;
	}

	new->right = _head;
	new->left = _head->left;

	_head->left = new;

	new->left->right = new;

	return;
}


char *del_list_head(struct node *_head)
{
	assert(!is_empty(_head));

	struct node *del = _head->right;
	char *del_item = (char*)malloc(sizeof(char) * strlen(del->data));

	strcpy(del_item, del->data);

	_head->right = del->right;
	del->right->left = _head;

	return del_item;
}


char *del_list_tail(struct node *_head)
{
	assert(!is_empty(_head));

	struct node *del = _head->left;
	char *del_item = (char*)malloc(sizeof(char) * strlen(del->data));

	strcpy(del_item, del->data);

	_head->left = del->left;
	del->left->right = _head;

	return del_item;
}


void dump_list(struct node *_head)
{
	assert(!is_empty(_head));

	struct node *temp = _head->right;
	int index = 1;

	printf("==============================\n");
	printf("Print the data of the list.\n");
  
	while (temp->data) {
		printf("[%2d] : %s\n", index, temp->data);

		temp = temp->right;
		index++;
	}

	printf("==============================\n");

  return;
}