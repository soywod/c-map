#include <stdlib.h>
#include <string.h>

#include "map.h"

typedef struct mapitem
{
	char* key;
	void* val;
} MI;

typedef struct map
{
	int size;
	MI* items;
} M;

M* mapNew()
{
	M* map;

	map = malloc(sizeof(M));
	map->size = 0;
	map->items = NULL;

	return map;
}

void mapAdd(char* key, void* val, M* map)
{
	if (map->size == 0)
	{
		map->items = malloc(sizeof(MI));
		map->items->key = key;
		map->items->val = val;
	}
	else
	{
		map->items = realloc(map->items, sizeof(MI) * (map->size + 1));
		(map->items + map->size)->key = key;
		(map->items + map->size)->val = val;
	}

	map->size++;
}

void* mapGet(char* key, M* map)
{
	int i;

	for (i = 0; i < map->size; i++)
	{
		if (strcmp((map->items + i)->key, key) == 0)
		{
			return (map->items + i)->val;
		}
	}

	return NULL;
}

void mapClose(M* map)
{
	free(map->items);
	free(map);
}
