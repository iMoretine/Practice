#include <stdio.h>
struct list
{
	int value;
	struct list *link;
};
typedef struct list Node;

void 
sll_traverse( Node *current, void (*func)(Node *node) )
{
	while( current != NULL )
	{
		func( current );
		current = current->link;
	}
}

int main()
{
	return 0;
}