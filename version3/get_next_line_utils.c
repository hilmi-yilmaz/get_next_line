/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 12:10:32 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/12/01 19:47:38 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

char	*create_array(char *line, char *buff, char *rest)
{
	int		i;
	int		size_array;
	char	*array;

	printf("Creating array...\n");
	i = 0;
	if (check_newline(rest, 1) == 1)
	{
		size_array = ft_strlen(line) + ft_strlen_rest(rest);
	}
	else
	{
		size_array = ft_strlen(line) + ft_strlen_rest(rest) + ft_strlen(buff);
		printf("len_line = %d, len_rest = %d, len_buff = %d\n", ft_strlen(line), ft_strlen_rest(rest), ft_strlen(buff));
	}
	array = (char *)malloc(sizeof(char) * size_array + 1);
	*(array + size_array) = '\0';
	printf("Allocated %d bytes for *line\n", size_array + 1);

	if (line != NULL)
	{
		while (*(line + i) != '\0')
		{
			*(array + i) = *(line + i);
			printf("Filling line with old line --> *(line + %d) = %c\n", i, *(array + i));
			i++;
		}
	}
	*(array + i) = '\0';
	free(line);
	printf("Added \\0 at *(array + %d)\n", i);
	return (array);
}

void	rest_to_line(char *line, char *rest)
{
	/*
	 * Fills line with rest untill \n or BUFFER_SIZE in rest
	 */

	printf("Enter rest_to_line function\n");

	int i;
	int j;

	i = 0;
	j = 0;
	while (i < BUFFER_SIZE)
	{
		//printf("*(rest + %d) = %c\n", i, *(rest + i));
		if (*(rest + i) != '\0')
		{
			*(line + j) = *(rest + i);
			printf("Filling line with rest --> *(line + %d) = %c\n", j, *(line + j));
			if (*(rest + i) == '\n')
			{	
				printf("Found \\n, add \\0 at *(line + %d + 1)\n", j);
				*(line + j + 1) = '\0';
				printf("*(rest + %d) = \\0\n", i);
				*(rest + i) = '\0';
				break ;
			}
			*(rest + i) = '\0';
			printf("*(rest + %d) = \\0\n", i);
			if (*(rest + i + 1) == '\0')
			{
				*(line + j + 1) = '\0';
				printf("Added \\0 at *(line + %d + 1)\n", j);
				break ;
			}
			j++;
		}
		i++;
	}
}

void	buff_to_line_and_rest(char *line, char *buff, char *rest)
{
	int i;
	int j;
	int len_line;

	printf("Enter buff_to_line_and_rest function\n");

	i = 0;
	j = 0;
	len_line = ft_strlen(line);
	printf("len_line = %d\n", len_line);
	while (*(buff + i) != '\0')
	{
		*(line + len_line + i) = *(buff + i);
		printf("Filling line with buff --> *(line + %d + %d) = %c\n", len_line, i, *(line + len_line + i));
		if (*(buff + i) == '\n')
		{	
			i++;
			break ;
		}
		i++;
	}
	*(line + len_line + i) = '\0';
	printf("Added \\0 at *(line + %d + %d)\n", len_line, i);
	while (*(buff + i) != '\0')
	{
		*(rest + j) = *(buff + i);
		printf("Filling rest with remainder of buff --> *(rest + %d) = %c\n", j, *(rest + j));
		i++;
		j++;
	}
}

int		check_newline(char *str, int rest)
{
	/*
	 * Return 1 if \n is found, 0 if not
	 */
	
	int i;

	if (str == NULL)
		return (0);
	i = 0;
	if (rest == 1)
	{
		while (i < BUFFER_SIZE)
		{
			if (*(str + i) == '\n')
				return (1);
			i++;
		}
		return (0);
	}
	while (*(str + i) != '\0')
	{
		if (*(str + i) == '\n')
			return (1);
		i++;
	}
	return (0);
}

int		ft_strlen(char *str)
{
	int i;

	if (str == NULL)
		return (0);
	i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) == '\n')
			return (i + 1);
		i++;
	}	
	return (i);
}

int		ft_strlen_rest(char *rest)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < BUFFER_SIZE)
	{
		if (*(rest + i) != '\0')
			count++;
		if (*(rest + i) == '\n')
			return (count);
		i++;
	}
	return (count);
}
