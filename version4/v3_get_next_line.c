/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 17:08:31 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/12/05 12:03:13 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "get_next_line.h"


void	print_rest(remains *re)
{
	int i;

	i = 0;
	printf("rest = ");
	while (i < BUFFER_SIZE)
	{
		if (*(re->rest + i) == '\0')
			printf("\\0");
		else if (*(re->rest + i) == '\n')
			printf("\\n");
		else
			printf("%c", *(re->rest + i));
		i++;
	}
	printf("---re->i = %d\n", re->i);
	printf("\n");
}

int		get_next_line(int fd, char **line)
{
	int				size;
	int				flag;
	char			buff[BUFFER_SIZE + 1];
	static remains	re;
	
	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (-1);
	flag = 0;
	buff[0] = '\0';
	*line = NULL;
	size = BUFFER_SIZE;
	printf("re.i = %d\n", re.i);
	print_rest(&re);
	while (flag == 0)
	{
		printf("ENTER WHILE LOOP\n");
		//If there is a no newline in rest, read data into buffer
		if (ft_strchr(re.rest + re.i, '\n') == 0)
		{
			printf("No \\n in rest, read data\n");
			size = read(fd, buff, BUFFER_SIZE);
			buff[size] = '\0';
		}
		printf("buff = %s\n", buff);
		if (size == -1)
			return (-1);
		if (size == 0)
			return (0);
		*line = create(*line, buff, &re);
		flag = rest_to_line(*line, buff, &re);
		buff_to_line_and_rest(*line, buff, &re);
		printf("flag = %d\n", flag);
	}
	return (1);
}

char	*create(char *line, char *buff, remains *re)
{
	int		size;
	char	*array;
	
	printf("\nENTER CREATE FUNCTION\n");
	printf("re->i = %d\n", re->i);
	printf("re->rest + re->i = %s\n", re->rest + re->i);
	size = ft_strlen(line, '\0') + ft_strlen(buff, '\n') + ft_strlen(re->rest + re->i, '\n');
	array = (char *)malloc(sizeof(char) * size + 1);
	printf("Allocated %d bytes, len_line = %d, len_buff = %d, len_rest = %d\n", size + 1, ft_strlen(line, '\0'), ft_strlen(buff, '\n'), ft_strlen(re->rest + re->i, '\n'));
	if (array == NULL)
		return (NULL);
	*(array + 0) = '\0';
	*(array + size) = '\0';
	oldline_to_line(array, line);
	printf("LEAVE CREATE FUNCTION\n");
	return (array);
}

void	oldline_to_line(char *array, char *line)
{
	int i;

	printf("Enter OLDLINE_TO_LINE FUNCTION\n");

	if (line == NULL)
		return ;
	i = 0;
	while (*(line + i) != '\0')
	{
		*(array + i) = *(line + i);
		printf("Filling line with old line --> *(line + %d) = %c\n", i, *(array + i));
		i++;
	}
	*(array + i) = '\0';
	printf("Added \\0 at *(line + %d)\n", i);
	free(line);
	printf("LEAVE OLDLINE_TO_LINE FUNCTION\n");	
}

int		rest_to_line(char *line, char *buff, remains *re)
{
	//only give buff as input to use for the flag
	int i;
	int flag;
	int len_line;

	printf("\nENTER REST_TO_LINE FUNCTION\n");
	print_rest(re);

	i = 0;
	flag = ft_strchr(buff, '\n') + ft_strchr(re->rest + re->i, '\n');
	len_line = ft_strlen(line, '\0');
	printf("len_line = %d\n", len_line);
	while (i < BUFFER_SIZE)
	{
		if (*(re->rest + re->i + i) == '\n')
		{
			*(re->rest + re->i + i) = '\0';
			re->i = re->i + i + 1;
			printf("Found \\n in rest, stop filling\n");
			break ;
		}
		else if (*(re->rest + re->i + i) == '\0')
		{
			re->i = 0;
			printf("Found \\0 in rest, stop filling and set re->i = 0\n");
			break ;
		}
		*(line + len_line + i) = *(re->rest + re->i + i);
		printf("Filling line with rest --> *(line + %d + %d) = %c\n", len_line, i, *(line + len_line + i));
		*(re->rest + re->i + i) = '\0';
		//re->i = re->i + 1; // CHECK THIS
		i++;
	}
	*(line + len_line + i) = '\0';
	printf("Added \\0 at *(line + %d + %d)\n", len_line, i);
	print_rest(re);
	printf("LEAVE REST_TO_LINE FUNCTION\n");
	return (flag);
}

void	buff_to_line_and_rest(char *line, char *buff, remains *re)
{
	int i;
	int j;
	int	len_line;

	printf("\nENTER BUFF_TO_LINE_AND_REST FUNCTION\n");
	print_rest(re);
	
	i = 0;
	j = 0;
	len_line = ft_strlen(line, '\0');
	printf("len_line = %d\n", len_line);
	while (*(buff + i) != '\0' && *(buff + i) != '\n')
	{
		*(line + len_line + i) = *(buff + i);
		printf("Filling line with buff --> *(line + %d + %d) = %c\n", len_line, i, *(line + len_line + i));
		i++;
	}
	*(line + len_line + i) = '\0';
	printf("Added \\0 at *(line + %d + %d)\n", len_line, i);
	while (i < BUFFER_SIZE && *(buff + i) != '\0')
	{
		*(re->rest + re->i + j) = *(buff + i + 1);
		printf("Filling rest with remainder of buff --> *(re->rest + %d + %d) = %c\n", re->i, j, *(re->rest + re->i + j));
		i++;
		j++;
	}
	printf("LEAVE BUFF_TO_LINE_AND_REST FUNCTION\n");
	print_rest(re);
}
