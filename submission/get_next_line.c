/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 15:56:23 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/12/01 20:13:15 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int			size;
	char		buff[BUFFER_SIZE + 1];
	static char	rest[BUFFER_SIZE];

	*line = NULL;
	while (check_newline(*line, 0) == 0) //while no /n in *line
	{

		// If \n in rest --> Fill *line with rest untill \n, no  other opeations required, return size = 1;
		if (check_newline(rest, 1) == 1)
		{		
			*line = create_array(*line, buff, rest);
			rest_to_line(*line, rest);
			size = 1;
			return (size);
		}
		// else --> read data into buff. Fill *line with rest untill /0, then fill *line with buff untill \n or \0
		// if \n is found in buff, add remainder of buff to rest
		else
		{
			size = read(fd, buff, BUFFER_SIZE);
			if (size == 0)
				return (0);	
			buff[size] = '\0';
			*line = create_array(*line, buff, rest);
			if (size == -1)
				return (-1);
			rest_to_line(*line, rest);
			buff_to_line_and_rest(*line, buff, rest);
		}
	}
	return (1);
}
