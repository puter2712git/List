#ifndef __LIST_H_
#define __LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

/* Node data structure of list which store string */
struct node {
	char *data;
	struct node *left;
	struct node *right;
};


/* Initialize node */
void initialize(struct node **_head);


/* Finalize node */
void finalize(struct node **_head);


/* Check the list is empty */
bool is_empty(struct node *_head);


/* Add the @_item into the head of the list */
void add_list_head(struct node *_head, char *_item);


/* Add the @_item into the tail of the list */
void add_list_tail(struct node *_head, char *_item);


/* Delete the data of the head of the list */
char *del_list_head(struct node *_head);


/* Delete the data of the tail of the list */
char *del_list_tail(struct node *_tail);


/* Show data of the list */
void dump_list(struct node *_head);

#endif