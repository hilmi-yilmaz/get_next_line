/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 11:18:55 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/11/24 18:04:59 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		check_for_newline_in_arr(char *arr)
{
	int		i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (*(arr + i) == '\n')
			return (i);
		i++;	
	}
	return (-1);
}

char	*concat(char **line, char *buff, int factor)
{
	int		i;
	
	i  = 0;
	*line = (char *)malloc(sizeof(char) * BUFFER_SIZE * factor);
	
}
