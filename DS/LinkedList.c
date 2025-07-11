#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void printlnf(const char print_line[], ...)
{
	va_list args;
	va_start(args, print_line);
	vprintf(print_line, args);
	printf("\n");
}

typedef struct node
{
	int data;
	struct node *next;
} node;
typedef struct List
{
	unsigned int size;
	struct node *head;
	struct node *tail;
} List;

void push(List *self, int data)
{
	node *newNode = malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL;

	if (self->tail != NULL)
	{
		self->tail->next = newNode;
		self->tail = newNode;
	}
	else
	{
		self->head = newNode;
		self->tail = newNode;
	}
	self->size = self->size + 1;
};
List createList(int data)
{
	List newList;
	newList.size = 0;
	newList.head = NULL;
	newList.tail = NULL;
	if (data != 0)
	{
		push(&newList, data);
	}
	return newList;
};

void main()
{
	List newList = createList(0);

	push(&newList, 10);
	push(&newList, 40);
	push(&newList, 20);

	node *p = newList.head;
	for (size_t i = 0; i < newList.size; i++)
	{
		printf("%i ", p->data);
		p = p->next;
	}

	printlnf("\n%i ", newList.size);
}