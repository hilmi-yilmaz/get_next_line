#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


void	get_line(void)
{
	char		*c;
	int			i;
	int			flag;
	int			count;
	static int	line;
	int			fd;

	printf("line = %d\n", line);
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
		printf("%c\n", *c);
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
	line++;
	free(c);
	close(fd);
}

int		main(void)
{

	get_line();
	get_line();
	return (0);

}
