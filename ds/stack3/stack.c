#include <assert.h>
#include "stack.h"

void initStack(Stack *ps)
{
	ps->tos = 0;
}

void push(Stack *ps, int data)
{
	// full???
	assert(ps->tos != STACKSIZE);

	ps->array[ps->tos] = data;
	++ps->tos;
}

int pop(Stack *ps)
{
	// empty??
	assert(ps->tos /* != 0 */);
	
	--ps->tos;
	return ps->array[ps->tos];
}

