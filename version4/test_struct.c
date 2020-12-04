#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "get_next_line.h"

typedef struct node {
		int		offset;
		char 	rest[BUFFER_SIZE];
} node;

void	test_func(char c, int index)
{
	/*
	 * Place a character at position index
	 */

	printf("Entered test_func\n");
	int i;
	static node *rest;
	node yo;

	rest = &yo;

	*(rest->rest + index) = c;
	i = 0;
	printf("Entering loop\n");
	while (i < BUFFER_SIZE)
	{
		if (*(rest->rest + i) == '\0')
			printf("\\0");
		else
			printf("%c", *(rest->rest + i));
		i++;
	}
	printf("\n");
}

int	main(void)
{	
	test_func('p', 2);
	test_func('M', 5);
	return (0);
}
