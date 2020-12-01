/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 10:49:53 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/12/01 20:00:42 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char RED[] = "\033[1;31m";
char RESET[] = "\033[0m";

int		main(void)
{
	int		fd;
	int 	result;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	result = 1;
	line = NULL;
	while (result != 0)
	{
		result = get_next_line(fd, &line);
		printf("%sline = %s%s", RED, line, RESET);
		printf("result = %d\n", result);
		free(line);
		//line = NULL;
	}
	close(fd);
	free(line);
}
