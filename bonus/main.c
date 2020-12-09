/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 10:49:53 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/12/09 14:26:00 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

char RED[] = "\033[1;31m";
char RESET[] = "\033[0m";

int		main(void)
{
	int		i;
	int		fd_1;
	int		fd_2;
	int 	result_1;
	int 	result_2;
	char	*line;
	
	i = 0;
	fd_1 = open("text_1.txt", O_RDONLY);
	fd_2 = open("text_2.txt", O_RDONLY);
	result_1 = 1;
	result_2 = 1;
	line = NULL;
	while (result_1 == 1 && result_2 == 1)
	{
		if (i % 2 == 0)
		{
			result_1 = get_next_line(fd_1, &line);
			printf("result_1 = %d\n\n", result_1);
		}
		if (i % 2 == 1)
		{
			result_2 = get_next_line(fd_2, &line);
			printf("result_2 = %d\n\n", result_2);
		}
		printf("%soutput = %s%s\n", RED, line, RESET);
		if (result_1 == -1 || result_2 == -1)
			break ;
		if (result_1 == 0 || result_2 == 0)
			break ;
		free(line);
		line = NULL;
		i++;
	}
	close(fd_1);
	close(fd_2);
	free(line);
}
