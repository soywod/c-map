#include <stdlib.h>
#include <string.h>

#include "assoc.h"

typedef struct Assoc
{
	int size;
	struct AssocItem* items;
} Assoc;

typedef struct AssocItem
{
	char* key;
	void* val;
} AssocItem;

Assoc* assocNew()
{
	Assoc* assoc;

	assoc = malloc(sizeof(Assoc));
	assoc->size = 0;
	assoc->items = NULL;

	return assoc;
}

void assocAdd(char* key, void* val, Assoc* assoc)
{
	if (assoc->size == 0)
	{
		assoc->items = malloc(sizeof(AssocItem));
		assoc->items->key = key;
		assoc->items->val = val;
	}
	else
	{
		assoc->items = realloc(assoc->items, sizeof(AssocItem) * (assoc->size + 1));
		(assoc->items + assoc->size)->key = key;
		(assoc->items + assoc->size)->val = val;
	}

	assoc->size++;
}

void* assocGet(char* key, Assoc* assoc)
{
	int i;

	for (i = 0; i < assoc->size; i++)
	{
		if (strcmp((assoc->items + i)->key, key) == 0)
		{
			return (assoc->items + i)->val;
		}
	}

	return NULL;
}

void assocClose(Assoc* assoc)
{
	free(assoc->items);
	free(assoc);
}
