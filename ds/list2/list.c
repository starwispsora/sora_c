#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

static Node *createNode(int data, Node *next)
{
	Node *ptr = malloc(sizeof(Node));
	assert(ptr );
	ptr->data = data;
	ptr->next = next;
	
	return ptr;
}

void initList(List *pList)
{
	//pList->ptr = malloc(sizeof(Node));		// dummy
	//assert(pList->ptr );
	//pList->ptr->data = ???;
	//pList->ptr->next = NULL;
	pList->ptr = createNode(-1, NULL);
}

void cleanupList(List *pList)
{
	Node *ptr = pList->ptr;
	while (ptr ) {
		Node *tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
}

void printList(const List *pList)
{
	Node *ptr = pList->ptr->next;
	printf("[");
	while (ptr ) {
		printf("%d", ptr->data);
		printf( (ptr->next ) ? ", " : "");
		ptr = ptr->next;
	}
	printf("]\n");
}

void insertFirstNode(List *pList, int data)
{
	//Node *tmp = malloc(sizeof(Node));
	//assert(tmp );
	//tmp->data = data;
	//tmp->next = pList->ptr->next;
	//pList->ptr->next = tmp;
	pList->ptr->next = createNode(data, pList->ptr->next);
}

void insertNode(List *pList, int prevData, int data)
{
	Node *ptr = pList->ptr->next;
	while (ptr ) {
		if (ptr->data == prevData)
			break;
			
		ptr = ptr->next;
	}
	
	if (ptr ) {
		//Node *tmp = malloc(sizeof(Node));
		//assert(tmp );
		//tmp->data = data;
		//tmp->next = ptr->next;
		//ptr->next = tmp;
		ptr->next = createNode(data, ptr->next);
	}
}

void deleteNode(List *pList, int data)
{
	Node *ptr = pList->ptr->next;
	Node *ptr2 = pList->ptr;
	
	while (ptr ) {
		if (ptr->data == data)
			break;	
	
		ptr = ptr->next;
		ptr2 = ptr2->next;
	}
	
	if (ptr ) {
		ptr2->next = ptr->next;
		free(ptr);	
	}
}
