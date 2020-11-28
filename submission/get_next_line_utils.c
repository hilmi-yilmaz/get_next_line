/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 13:41:26 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/11/28 12:11:45 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

void	concat(char *line, char *buff, char *rest)
{
	int			i;
	int			j;
	int			len_line;

	i = 0;
	j = 0;
	len_line = ft_strlen(line);
	while (*(buff + i) != '\0')
	{
		if (*(buff + i) == '\n')
			break ;
		*(line + i + len_line) = *(buff + i);
		i++;
	}
	*(line + i + len_line) = '\0';
	while (*(buff + i + 1) != '\0' && *(buff + i + 1) != '\n')
	{
		*(rest + j) = *(buff + i + 1);
		j++;
		i++;
	}
	*(rest + j) = '\0';
}

char	*transfer(char *line, char *buff, char *rest, int index) //index = how many times looped 
{
	int 	i;
	int		len_line;
	int		size_result;
	char	*result;

	i = 0;
	len_line = ft_strlen(line);
	size_result = len_line + ft_strlen(buff) + ft_strlen(rest);
	result = (char *)malloc(sizeof(char) * size_result + 1);
	*result = '\0';
	fill_remainder(result, rest);
	while (i < len_line)
	{
		*(result + i) = *(line + i);
		i++;
	}
	if (i > 0)
		*(result + i) = '\0';
	if (index >= 2)
		free(line);
	return (result);
}

void	fill_remainder(char *line, char *rest)
{
	int i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (*(rest + i) != '\0')
			break ;
		i++;
	}
	if (i == BUFFER_SIZE)
		return ;
	i = 0;
	while (*(rest + i) != '\0')
	{
		*(line + i) = *(rest + i);
		*(rest + i) = '\0';
		i++;
	}
	*(line + i) = '\0';
}

int		ft_strlen(char *str)
{
	int i;
	
	if (str == NULL)
		return (0);
	i = 0;
	while (*(str + i) != '\0' && *(str + i) != '\n')
		i++;
	return (i);
}

int		check_newline(char *buff)
{
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
