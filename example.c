#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "map.h"

void callback()
{
	printf("Hello World !\n");
}

int main()
{
	struct map* m;

	char *strval;
	int intval;
	void (*funcval)();
	char* dynval = malloc(7);

	m = mapNew();
	strcpy(dynval, "dynval");

	mapAdd("key 1", "value", m);
	mapDynAdd("key 2", dynval, m);
	mapAdd("key 3", (int*) 21, m); // Casted to avoid warning
	mapAdd("key 4", callback, m);

	strval = mapGet("key 1", m);
	intval = (long) mapGet("key 3", m); // Casted to avoid warning
	funcval = mapGet("key 4", m);

	printf("%s\n", strval);
	printf("%d\n", intval);
	funcval();

	mapClose(m);

	return 0;
}
