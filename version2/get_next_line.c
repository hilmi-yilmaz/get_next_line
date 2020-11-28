/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 14:07:29 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/11/28 15:50:32 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int 		flag;
	int			buff_size;
	char		buff[BUFFER_SIZE + 1];
	static char	rest[BUFFER_SIZE];
	
	flag = 0;
	*line = NULL;
	while (flag == 0)
	{
		
		/* Read the data into buff and null-terminate the ending of buff.
		** If return value of read system call is 0, return (0) (EOF reached).
		*/
		buff_size = read(fd, buff, BUFFER_SIZE);
		buff[buff_size] = '\0';
		printf("buff = %s\n", buff);
		
		/* If \n in buff, flag = 1 */
		flag = check_newline(buff);

		/* Allocate memmory for *line. If rest is not empty, fill it with rest */
		*line = create(*line, buff, rest);

		/* Add buff to line and remainder of buff to rest */
		concat(*line, buff, rest);

		if (buff_size == 0)
			return (0);
	}
	return (1);
}
