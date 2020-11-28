/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 13:48:25 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/11/28 15:49:41 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

void	concat(char *line, char *buff, char *rest)
{
	/* 
	** Adds buff to line. 
	** If buff has a remainder after the \n, the remainder gets added to rest.
	** Returns rest.
	*/

	int i;
	int j;
	int	len_line;
	int	len_buff;

	j = 0;
	len_line = ft_strlen(line);
	len_buff = ft_strlen(buff);
	printf("len_buff = %d\n", len_buff);
	i = len_line;

	/* Add buff to line */
	while (i < len_line + len_buff)
	{
		*(line + i) = *(buff + i - len_line);
		printf("Filling line with buff, i = %d, %c\n", i, *(line + i));
		i++;
	}
	*(line + i) = '\0';
	
	/* Add remainder of buff to rest */
	//printf("buff + i + 1 = %s\n", buff + i + 1);
	while (*(buff + i - len_line + 1) != '\0')
	{
		*(rest + j) = *(buff + i - len_line + 1);
		printf("Filling rest with remainder of buff, i = %d, %c\n", j, *(rest + j));
		i++;
		j++;
	}
	*(rest + j) = '\0';	
}

char	*create(char *line, char *buff, char *rest)
{
	/*
	** Allocates exactly enough memmory to store
	** line, buff and rest. 
	** Returns the allocated string filled with rest and line.
	*/

	int		i;
	int		len_rest;
	int		size_array;
	char	*array;
	
	i = 0;
	len_rest = ft_strlen(rest);
	/* Determine the size of the array and allocate memmory accordingly. +1 for null terminator */
	size_array = ft_strlen(line) + ft_strlen(buff) + ft_strlen(rest);
	array = (char *)malloc(sizeof(char) * size_array + 1);
	printf("Allocated memory = %d bytes\n", size_array + 1);
	/* Fill array with rest if rest isn't empty. Also empty rest again */
	while (i < len_rest)
	{
		*(array + i) = *(rest + i);
		printf("Filling line with rest, i = %d, %c\n", i, *(array + i));
		*(rest + i) = '\0';
		i++;
	}
	
	/* Fill array with line, if line isn't empty */
	while (i < ft_strlen(line))
	{
		*(array + i) = *(line + i - ft_strlen(rest));
		printf("Filling line with old line, i = %d, %c\n", i, *(array + i));
		i++;
	}
	*(array + i) = '\0';

	/* Free old line */
	free(line);

	return (array);
}

int		check_newline(char *buff)
{
	/*
	** Return 1 if \n is found in buff, 0 if not
	*/

	int i;

	i = 0;
	while (*(buff + i) != '\0')
	{
		if (*(buff + i) == '\n')
			return (1);
		i++;
	}
	return (0);
}

int		ft_strlen(char *str)
{
	/*
	** Return the length of str. If str == NULL, returns 0.
	** A newline also acts as a terminating character. 
	*/

	int i;

	if (str == NULL)
		return (0);
	i = 0;
	while (*(str + i) != '\0' && *(str + i) != '\n')
		i++;
	return (i);
}
