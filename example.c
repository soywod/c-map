#include <stdio.h>

#include "assoc.h"

void callback()
{
	printf("Hello World !\n");
}

int main()
{
	Assoc* a = assocNew();

	assocAdd("key 1", "my value", a);
	assocAdd("key 2", 21, a);
	assocAdd("key 3", callback, a);

	printf("%s\n", assocGet("key 1", a));
	printf("%d\n", assocGet("key 2", a));
	((void (*)()) assocGet("key 3", a))();

	assocClose(a);

	return 0;
}
