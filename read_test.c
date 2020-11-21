#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		main(void)
{
	int		fd;
	char	*c;
	int		i;
	int		flag;
	int		count;

	fd = open("text.txt", O_RDONLY);
	c = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	i = 0;
	flag = 0;
	count = 0;
	if (fd < 0)
		exit(1);
	while (flag != 1)
	{
		read(fd, c, BUFFER_SIZE);
		//printf("%c\n", *c);
		while (i < BUFFER_SIZE)
		{
			printf("*(c + i) = %c\n", *(c + i));
			if (*(c + i) == '\n')
			{
				printf("Found newline at index = %d, break\n", i + (count * BUFFER_SIZE));
				flag = 1;
				break ;
			}
			i++;
		}
		i = 0;
		count++;
		if (flag != 1)
			printf("No newline found\n\n");
	}
	close(fd);
	free(c);
	return (0);
}
