#include <stdlib.h>
#include <string.h>

#include "map.h"

#define MAP_BY_VAL 0
#define MAP_BY_REF 1

typedef struct mapitem
{
	char* key;
	void* val;
	int type;
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
	char* newkey;

	newkey = malloc(strlen(key) + 1);
	strcpy(newkey, key);

	if (map->size == 0)
	{
		map->items = malloc(sizeof(MI));
	}
	else
	{
		map->items = realloc(map->items, sizeof(MI) * (map->size + 1));
	}

	(map->items + map->size)->key = newkey;
	(map->items + map->size)->val = val;
	(map->items + map->size++)->type = MAP_BY_VAL;
}

void mapDynAdd(char* key, void* val, M* map)
{
	mapAdd(key, val, map);
	(map->items + map->size - 1)->type = MAP_BY_REF;
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
	int i = 0;

	for(; i < map->size; i++)
	{
		free((map->items + i)->key);

		if ((map->items + i)->type == MAP_BY_REF)
		{
			free((map->items + i)->val);
		}
	}

	free(map->items);
	free(map);
}
