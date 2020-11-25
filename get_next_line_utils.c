/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 11:18:55 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/11/25 19:34:25 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		check_newline(char *buff)
{
	int		i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (*(buff + i) == '\n')
			return (i);
		i++;	
	}
	return (-1);
}

char	*concat(char *line, char *buff, int factor, int newline_index)
{
	int			i;
	int			j;
	char		*result;
	static char	rest[BUFFER_SIZE];
	
	printf("Enter concat function with factor = %d & newline_index = %d\n", factor, newline_index);
	i = 0;
	j = 0;
	if (newline_index == -1)
	{
		result = (char *)malloc(sizeof(char) * BUFFER_SIZE * factor + 1);
		printf("Length of result = %d\n", BUFFER_SIZE * factor + 1);
	}
	else
	{
		result = (char *)malloc(sizeof(char) * BUFFER_SIZE * (factor - 1) + newline_index + 1);
		printf("Length of result = %d\n", BUFFER_SIZE * (factor - 1) + newline_index + 1);
	}
	//+1 for null terminator
	//printf("Length of rest = %d\n", newline_index + 1);
	//printf("BUFFER_SIZE * (factor - 1) = %d\n", BUFFER_SIZE * (factor - 1));
	//printf("BUFFER_SIZE * factor = %d\n", BUFFER_SIZE * factor);
	while (i < BUFFER_SIZE * (factor - 1))
	{
		*(result + i) = *(line + i);
		printf("Filling result with old line: i = %d, %c\n", i, *(result + i));
		i++;
	}
	if (factor >= 2)
	{
		printf("Freeing old line\n");
		free(line);
	}
	while (i < BUFFER_SIZE * factor)
	{
		if (*(buff + i - (BUFFER_SIZE * (factor - 1))) == '\n')
			break ;
		*(result + i) = *(buff + i - (BUFFER_SIZE * (factor - 1)));
		//else append to static char
		printf("Filling result with new buff: i = %d, %c\n", i, *(result + i));
		i++;
	}
	*(result + i) = '\0';
	while (i < BUFFER_SIZE * factor - 1)
	{
		*(rest + j) = *(buff + i - (BUFFER_SIZE * (factor - 1)) + 1); //plus one so newline doesnt get added
		printf("Filling rest with remainder of buff: i = %d, %c\n", i, *(rest + j));
		i++;
		j++;
	}

	int k = 0;
	printf("result = ");
	while (*(result + k) != '\0')
	{
		printf("%c", *(result + k));
		k++;
	}
	printf("\n");
	printf("Leave concat function\n");
	return (result);
}
