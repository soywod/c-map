#include <stdio.h>

#include "map.h"

void callback()
{
	printf("Hello World !\n");
}

int main()
{
	struct map* m;

	char* strval;
	int intval;
	void (*funcval)();

	m = mapNew();

	mapAdd("key 1", "value", m);
	mapAdd("key 2", (int*) 21, m); // Casted to avoid warning
	mapAdd("key 3", callback, m);

	strval = mapGet("key 1", m);
	intval = (long) mapGet("key 2", m); // Casted to avoid warning
	funcval = mapGet("key 3", m);

	printf("%s\n", strval);
	printf("%d\n", intval);
	funcval();

	mapClose(m);

	return 0;
}
