/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 11:18:55 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/11/22 21:37:28 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*fill_array(char **line, char *arr, int start, int count)
{
	//append values of arr to line
	//start is the index from which to start appending.
	//count is how many times we went through BUFFER_SIZE without finding a \n
	//the size of the malloc should then be: BUFFER_SIZE * count
	int		i;
	char	*temp;
	char	*line_ptr;

	i = 0;
	*line = (char *)malloc(sizeof(char) * BUFFER_SIZE * count);	
	temp = (char *)malloc(sizeof(char) * BUFFER_SIZE * count);
	line_ptr = *line;
	while (i < BUFFER_SIZE * count)
	{
		if (i < (count - 1) * BUFFER_SIZE)
			*(line_ptr + i) = *(temp + i);
		else
			*(line_ptr + i) = *(arr + i);
		i++;
	}

}
