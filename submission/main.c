/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 10:49:53 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/12/05 12:28:56 by hyilmaz       ########   odam.nl         */
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
	
	fd = open("text1.txt", O_RDONLY);
	//fd = 0;
	result = 1;
	line = NULL;
	while (result != 0)
	{
		result = get_next_line(fd, &line);
		if (result == -1 || result == 0)
			break ;
		//printf("%soutput = %s%s\n", RED, line, RESET);
		printf("%s\n", line);
		//printf("result = %d\n\n", result);
		free(line);
		line = NULL;
	}
	close(fd);
	free(line);
}
