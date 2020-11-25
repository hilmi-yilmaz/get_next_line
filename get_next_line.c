/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 11:18:33 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/11/25 19:34:29 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int		i;
	int		check;
	int		size;
	char	buff[BUFFER_SIZE + 1];

	i = 0;
	check = -1;
	while (check == -1)
	{
		printf("\n--- ENTER WHILE LOOP ---\n");

		printf("Reading file\n");
		size = read(fd, buff, BUFFER_SIZE);
		printf("Return value of read = %d\n", size);
		printf("What has been read: ");
		int k = 0;
		while (k < BUFFER_SIZE)
		{
			printf("%c", *(buff + k));
			k++;
		}
		printf("\n");
		check = check_newline(buff);
		printf("check = %d\n", check);
		*line = concat(*line, buff, i + 1, check);
		i++;
	}
	return (0);
}
