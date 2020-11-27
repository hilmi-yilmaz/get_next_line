/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 13:41:47 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/11/27 22:24:12 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int			i;
	int			flag;
	int			buff_size;
	char		buff[BUFFER_SIZE + 1];
	static char	rest[BUFFER_SIZE];
	
	i = 1;
	flag = 0;
	*line = NULL;
	while (flag == 0)
	{
		//Read the data into buff
		buff_size = read(fd, buff, BUFFER_SIZE);

		//Add terminating character to buff
		buff[buff_size] = '\0';

		//Check for newline in buff
		flag = check_newline(buff);

		//Transfer old line to newer line, which is a bigger array
		*line = transfer(*line, buff, rest, i);

		//Concat line with buff. Save the remainder of buff in the static variable rest
		concat(*line, buff, rest);

		i++;
	}
	return (0);
}
