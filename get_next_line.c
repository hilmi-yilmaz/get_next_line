/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 11:18:33 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/11/22 21:37:30 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_next_line(int fd, char **line)
{
	static int	line_nb;
	
	int			i;
	int			flag;
	int			size;
	int			count; //counts how many times BUFFER_SIZE fits in one line
	int			len_line;

	char		*arr;
	

	i = 0;
	flag = 0;
	count = 0;
	arr = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	while (flag < line + 1)
	{
		size = read(fd, arr, BUFFER_SIZE);
		while (i < BUFFER_SIZE)
		{
			if (*(arr + i) == '\n')
			{
				flag++;
				break ;	
			}
			i++;
		}
		i = 0;
		count++;
		
	}
	line_nb++;
}
