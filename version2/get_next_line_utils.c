/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 13:48:25 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/11/29 17:40:55 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "get_next_line.h"

void	concat(char *line, char *buff, char *rest)
{
	/* 
	** Adds buff to line. 
	** If buff has a remainder after the \n, the remainder gets added to rest.
	** Returns rest.
	*/

	printf("--- CONCAT FUNCTION\n");

	int i;
	int j;
	int	len_line;
	int	len_buff;

	j = 0;
	len_line = ft_strlen(line, 0);
	len_buff = ft_strlen(buff, 1);
	i = len_line;

	/* Add buff to line */
	while (i < len_line + len_buff)
	{
		*(line + i) = *(buff + i - len_line);
		printf("Filling line with buff --> *(line + %d) = %c", i, *(line + i));
		printf(" --- *(buff + %d) = %c\n", i - len_line, *(buff + i - len_line));
		i++;
	}
	*(line + i) = '\0';
	printf("Add \\0 at  the end of line at i = %d\n", i);
	
	/* Add remainder of buff to rest */
	while (*(buff + i - len_line) != '\0')
	{
		*(rest + j) = *(buff + i - len_line + 1);
		printf("Filling rest with remainder of buff --> *(rest + %d) = %c", j, *(rest + j));
		printf(" --- *(buff + %d) = %c\n", i - len_line + 1, *(buff + i - len_line + 1));
		i++;
		j++;
	}
	//*(rest + j) = '\0';
	printf("END OF CONCAT FUNCTION\n");
}

char	*create(char *line, char *buff, char *rest)
{
	/*
	** Allocates exactly enough memmory to store
	** line, buff and rest. 
	** Returns the allocated string filled with rest and line.
	*/

	printf("--- CREATE FUNCTION\n");

	int		i;
	int		size_array;
	char	*array;
	
	i = 0;
	/* Determine the size of the array and allocate memmory accordingly. +1 for null terminator */
	size_array = ft_strlen(line, 0) + ft_strlen(buff, 1) + ft_strlen(rest, 0);
	array = (char *)malloc(sizeof(char) * size_array + 1);
	printf("Allocated memory = %d bytes, len_line = %d, len_buff = %d, len_rest = %d\n", size_array + 1, ft_strlen(line, 0), ft_strlen(buff, 1), ft_strlen(rest, 0));
	/* Fill array with rest if rest isn't empty. Also empty rest again */
	while (*(rest + i) != '\0')
	{
		*(array + i) = *(rest + i);
		printf("Filling line with rest --> *(line + %d) = %c", i, *(array + i));
		printf(" --- *(rest + %d) = %c\n", i, *(rest + i));
		*(rest + i) = '\0';
		i++;
	}
	
	/* Fill array with line, if line isn't empty */
	while (i < ft_strlen(line, 1))
	{
		*(array + i) = *(line + i - ft_strlen(rest, 1));
		i++;
	}
	*(array + i) = '\0';

	/* Free old line */
	free(line);
	
	printf("END OF CREATE FUNCTION\n");

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

int		ft_strlen(char *str, int newline)
{
	/*
	** Return the length of str. If str == NULL, returns 0.
	** If newline = 1, a \n also acts as a terminating character. 
	** If newline = 0, only \0 a acts as terminating character
	*/

	int i;

	if (str == NULL)
		return (0);
	i = 0;
	if (newline == 1)
	{
		while (*(str + i) != '\0' && *(str + i) != '\n')
			i++;
		return (i);
	}
	while (*(str + i) != '\0')
		i++;
	return (i);
}
























