/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 11:18:33 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/11/24 18:04:48 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int		i;
	int		flag;
	int		size;
	char	arr[BUFFER_SIZE + 1];

	i = 0;
	flag = -1;
	while (flag == -1)
	{
		printf("Reading file\n");
		size = read(fd, arr, BUFFER_SIZE);
		arr[BUFFER_SIZE] = '\0';
		flag = check_for_newline_in_arr(arr);
		printf("Check for \\n, flag = %d (flag = -1 means no \\n found)\n", flag);
		/* If no newline is found in the buffer */
			
		i++;
	}
	return (0);
}
