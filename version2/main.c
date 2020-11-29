/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 10:49:53 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/11/29 15:49:46 by hyilmaz       ########   odam.nl         */
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
		//printf("result = %d\n", result);
		//printf("%s", RED);
		printf("%sline = %s%s\n", RED, line, RESET);
		//printf("%s", RESET);
		free(line);
		line = NULL;
		if (result == 0)
			break ;
	}
	close(fd);
	free(line);
}
