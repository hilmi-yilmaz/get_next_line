/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 12:10:32 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/12/01 20:13:18 by hyilmaz       ########   odam.nl         */
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

	i = 0;
	if (check_newline(rest, 1) == 1)
		size_array = ft_strlen(line) + ft_strlen_rest(rest);
	else
		size_array = ft_strlen(line) + ft_strlen_rest(rest) + ft_strlen(buff);
	array = (char *)malloc(sizeof(char) * size_array + 1);
	*(array + size_array) = '\0';
	if (line != NULL)
	{
		while (*(line + i) != '\0')
		{
			*(array + i) = *(line + i);
			i++;
		}
	}
	*(array + i) = '\0';
	free(line);
	return (array);
}

void	rest_to_line(char *line, char *rest)
{
	/*
	 * Fills line with rest untill \n or BUFFER_SIZE in rest
	 */

	int i;
	int j;

	i = 0;
	j = 0;
	while (i < BUFFER_SIZE)
	{
		if (*(rest + i) != '\0')
		{
			*(line + j) = *(rest + i);
			if (*(rest + i) == '\n')
			{	
				*(line + j + 1) = '\0';
				*(rest + i) = '\0';
				break ;
			}
			*(rest + i) = '\0';
			if (*(rest + i + 1) == '\0')
			{
				*(line + j + 1) = '\0';
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

	i = 0;
	j = 0;
	len_line = ft_strlen(line);
	while (*(buff + i) != '\0')
	{
		*(line + len_line + i) = *(buff + i);
		if (*(buff + i) == '\n')
		{	
			i++;
			break ;
		}
		i++;
	}
	*(line + len_line + i) = '\0';
	while (*(buff + i) != '\0')
	{
		*(rest + j) = *(buff + i);
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
