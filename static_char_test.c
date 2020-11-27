#include <stdio.h>

int		main(void)
{
	static char buff[5];
	int i = 0;

	while (i < 5)
	{
		if (*(buff + i) == '\0')
			printf("Null Terminator\n");
		i++;
	}
}
