#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef struct NODE
{
	int value;
	struct NODE *link;
} Node;

Node* newnode( int value )
{
	Node *new;

	new = (Node*)malloc(sizeof(Node));
	assert( new != 0);
	new->value = value;
	return new;
}

main()
{
	Node *head;

	head = newnode( 5 );
	head->link = newnode( 10 );
	head->link->link = newnode( 15 );
	head->link->link->link = 0;
}