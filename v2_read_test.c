#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	get_next_line(int fd);
void	print_array(char *array);
void	print_new_array(char *array, int count);
char	*create_line(char *array, int count); //fill array with count bytes

int		main(void)
{
	int		fd;
	//char	*line;

	//line = (char *)malloc(sizeof(char) * 25);

	fd = open("text.txt", O_RDONLY);

	printf("\nFirst Call\n");
	get_next_line(fd);

	//printf("\nSecond Call\n");
	//get_next_line(fd);
	close(fd);
	//free(line):
	return (0);
}

void	get_next_line(int fd)
{
	int			i;
	int			flag;
	int			count;
	int			read_output;
	static int	line;
	char		*array;
	char		*new_array;

	i = 0;
	flag = 0;
	count = 0;
	array = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	new_array = NULL;
	while (flag < line + 1)
	{
		read_output = read(fd, array, BUFFER_SIZE);
		if (read_output == 0)
		{
			printf("EOF\n");
			break ;
		}
		print_array(array);
		while (i < BUFFER_SIZE)
		{
			if (*(array + i) == '\n')
			{
				flag++;
				printf("Found newline at index %d\n", count * BUFFER_SIZE + i);
				new_array = create_line(array, count * BUFFER_SIZE + i);
				print_new_array(new_array, count * BUFFER_SIZE + i);
				break ;
			}
			i++;
		}
		count++;
		i = 0;
	}
	free(array);
	free(new_array);
}

char	*create_line(char *array, int count) //fill array with count bytes
{
	int		i;
	char	*line_array;
	
	i = 0;
	line_array = (char *)malloc(sizeof(char) * count);
	while (i < count)
	{
		*(line_array + i) = *(array + i);
		i++;
	}
	return (line_array);
}

void	print_array(char *array)
{
	int i;

	i = 0;
	printf("\n--- Start array ---\n");
	while (i < BUFFER_SIZE)
	{
		printf("%c", *(array + i));
		i++;
	}
	printf("\n--- End array ---\n");
}

void	print_new_array(char *array, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		printf("%c", *(array + i));
		i++;
	}
	printf("\n");
}
