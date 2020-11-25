/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 10:49:53 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/11/25 19:34:33 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		get_next_line(int fd, char **line);
char	*fill_array(char **line, char *arr, int count);

int		main(void)
{
	int		i;
	int		fd;
	int 	result;
	char	*line = NULL;

	i = 0;
	fd = open("text.txt", O_RDONLY);
	result = get_next_line(fd, &line);
	printf("result = %d\n", result);
	printf("OUTPUT MAIN FUNCTION *LINE = ");
	while (*(line + i) != '\0')
	{
		printf("%c", *(line + i));
		i++;
	}
	printf("\n");
	close(fd);
	free(line);
}
