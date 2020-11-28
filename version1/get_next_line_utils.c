/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 13:41:26 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/11/28 15:08:34 by hyilmaz       ########   odam.nl         */
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

	printf("Entered concat function\n");
	printf("buff = %s\n", buff);
	printf("line = %s\n", line);
	i = 0;
	j = 0;
	//Fill line with rest
	//fill_remainder(line, rest);
	len_line = ft_strlen(line);
	printf("len_line = %d\n", len_line);
	while (*(buff + i) != '\0')
	{
		if (*(buff + i) == '\n')
			break ;
		*(line + i + len_line) = *(buff + i);
		printf("Filling result with buff: i = %d, %c\n", i + len_line, *(line + i + len_line));
		i++;
	}
	*(line + i + len_line) = '\0';
	printf("Added \\0 to back of line at i = %d\n", i + len_line);
	while (*(buff + i + 1) != '\0' && *(buff + i + 1) != '\n')
	{
		*(rest + j) = *(buff + i + 1);
		printf("Filling rest with remainder of buff: i = %d, %c\n", j, *(rest + j));
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

	printf("Entered transfer function with index = %d\n", index);
	printf("line = %s\n", line);
	i = 0;
	len_line = ft_strlen(line);
	printf("len_line = %d\n", len_line);
	printf("len_rest = %d\n", ft_strlen(rest));
	size_result = len_line + ft_strlen(buff) + ft_strlen(rest);
	result = (char *)malloc(sizeof(char) * size_result + 1);
	*result = '\0';
	printf("Allocated memory = %d bytes\n", size_result + 1);
	printf("result before fill_remainder= %s\n", result);
	fill_remainder(result, rest);
	printf("result after fill_remainder= %s\n", result);
	//Fill result with old line
	while (i < len_line)
	{
		*(result + i) = *(line + i);
		printf("Filling result with old line: i = %d, %c\n", i, *(result + i));
		i++;
	}
	if (i > 0)
	{
		*(result + i) = '\0';
		printf("Added \\0 at i = %d\n", i);
	}
	if (index >= 2)
	{
		printf("Freeing old line\n");
		free(line);
	}
	return (result);
}

void	fill_remainder(char *line, char *rest)
{
	int i;
	printf("Entered fill_remainder function\n");
	printf("Checking whether there is content in rest\n");

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (*(rest + i) != '\0')
			break ;
		i++;
	}
	if (i == BUFFER_SIZE)
	{
		printf("No content in rest, leaving fill_remainder function\n");
		return ;
	}
	i = 0;
	while (*(rest + i) != '\0')
	{
		*(line + i) = *(rest + i);
		printf("Filling line and setting rest to 0, i = %d, %c\n", i, *(line + i));
		*(rest + i) = '\0';
		i++;
	}
	*(line + i) = '\0';
	printf("Leave fill_remainder function\n");
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
