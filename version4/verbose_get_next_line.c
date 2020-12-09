/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 17:08:31 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/12/09 20:34:00 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

void	print_rest(t_remains *re)
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

/*
** The get_next_line-function uses the helper function to read a line
** from a file descripter and stores the result in *line.
** First some variables are set:
** --> flag is used to indicate whether a newline is found and stops the
** while loop.
** --> *line is set to NULL.
** --> size is set to BUFFER_SIZE. This is done because size needs to be
** initialized even if we don't read, because we have \n in our remainder.
** --> Also, if no data is read, buff[0] = '\0'. Also the in the case that
** there is a \n in remainder
** ------------------------------------------------------------------------
** Then data is read and the other functions are being called to fill *line.
*/

int		get_next_line(int fd, char **line)
{
	int					size;
	int					flag;
	char				buff[BUFFER_SIZE + 1];
	static t_remains	re;

	printf("Checking fd, BUFFER_SIZE and line\n");
	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
	{
		printf("One of fd, BUFFER_SIZE and line is wrong, return -1\n");
		return (-1);
	}
	//flag = 0;
	//buff[0] = '\0';
	*line = NULL;
	//size = BUFFER_SIZE;
	set_values(buff, &flag, &size);
	printf("*line = %s\n", *line);
	printf("buff = %s\n", buff);
	printf("flag = %d\n", flag);
	printf("size = %d\n", size);
	print_rest(&re);
	while (flag == 0)
	{
		printf("ENTER WHILE LOOP\n");
		if (ft_strchr(re.rest + re.i, '\n') == 0)
		{
			size = read(fd, buff, BUFFER_SIZE);
			printf("size = %d\n", size);
		}
		if (size == -1)
			return (-1);
		buff[size] = '\0';
		*line = create(*line, buff, &re);
		if (*line == NULL)
			return (-1);
		flag = rest_to_line(*line, buff, &re, flag);
		buff_to_line_and_rest(*line, buff, &re);
		if (size == 0)
			return (0);
	}
	return (1);
}

/*
** The create-function allocates exactly enough memmory for *line.
** It also fill line with old line, in case of BUFFERS_SIZE being
** smaller than the length of the line.
*/

char	*create(char *line, char *buff, t_remains *re)
{
	int		size;
	char	*array;

	printf("\nENTER CREATE FUNCTION\n");
	size = ft_strlen(line, '\0') + ft_strlen(buff, '\n') \
			+ ft_strlen(re->rest + re->i, '\n');
	array = (char *)malloc(sizeof(char) * size + 1);
	printf("Allocate %d bytes for line\n", size + 1);
	if (array == NULL)
		return (NULL);
	*(array + 0) = '\0';
	*(array + size) = '\0';
	oldline_to_line(array, line);
	printf("LEAVE CREATE FUNCTION\n");
	return (array);
}

/*
** The oldline_to_line-function is used in the create-function
** to fill line with oldline
** in the case of BUFFER_SIZE being smaller than the length of the line
*/

void	oldline_to_line(char *array, char *line)
{
	int i;
	
	printf("\nENTER OLDLINE_TO_LINE FUNCTION\n");
	if (line == NULL)
	{
		printf("line == NULL\nLEAVE OLDLINE_TO_LINE FUNCTION\n");
		return ;
	}
	i = 0;
	while (*(line + i) != '\0')
	{
		*(array + i) = *(line + i);
		printf("Filling line with oldline --> *(line + %d) = %c\n", i, *(array + i));
		i++;
	}
	*(array + i) = '\0';
	printf("Added \\0 at *(line + %d)\n", i);
	free(line);
	printf("Freed old line\n");
	printf("LEAVE OLDLINE_TO_LINE FUNCTION\n");
}

/*
** The rest_to_line-function fills line with rest if rest is not empty
** Each time a character from rest is transferred to line
** that character is converted to a \0 in rest.
** Also the i variable of the struct is used to remember the offset
** For example:
** re->rest = [h i l m i \n y i l m a z \0 \0 \0]
** After this function, rest looks like this:
** re->rest = [\0 \0 \0 \0 \0 \0 y i l m a z \0 \0 \0]
** re->i = 6.
*/

int		rest_to_line(char *line, char *buff, t_remains *re, int flag)
{
	int i;
	int len_line;

	printf("\nENTER REST_TO_LINE FUNCTION\n");
	
	i = 0;
	flag = ft_strchr(buff, '\n') + ft_strchr(re->rest + re->i, '\n');
	len_line = ft_strlen(line, '\0');
	while (i < BUFFER_SIZE)
	{
		if (*(re->rest + re->i + i) == '\n')
		{
			printf("Found \\n in rest, break loop\n");
			*(re->rest + re->i + i) = '\0';
			re->i = re->i + i + 1;
			break ;
		}
		else if (*(re->rest + re->i + i) == '\0')
		{
			printf("Found \\0 in rest, break loop and reset re->i = 0\n");
			re->i = 0;
			break ;
		}
		*(line + len_line + i) = *(re->rest + re->i + i);
		printf("Filling line with rest --> *(line + %d + %d) = %c\n", len_line, i,  *(line + len_line + i));
		*(re->rest + re->i + i) = '\0';
		i++;
	}
	*(line + len_line + i) = '\0';
	printf("Added \\0 at *(line + %d + %d)\n", len_line, i);
	printf("LEAVE REST_TO_LINE FUNCTION\n");
	return (flag);
}

/*
** The buff_to_line_and_rest-function fills line with buff.
** The remainder of buff is added to rest if needed.
*/

void	buff_to_line_and_rest(char *line, char *buff, t_remains *re)
{
	int i;
	int j;
	int	len_line;

	printf("\nENTER BUFF_TO_LINE_AND_REST FUNCTION\n");

	i = 0;
	j = 0;
	len_line = ft_strlen(line, '\0');
	while (*(buff + i) != '\0' && *(buff + i) != '\n')
	{
		*(line + len_line + i) = *(buff + i);
		printf("Filling line with buff --> *(line + %d + %d) = %c\n", len_line, i, *(line + len_line + i));
		i++;
	}
	*(line + len_line + i) = '\0';
	printf("Addded \\0 at *(line + %d + %d)\n", len_line, i);
	while (i < BUFFER_SIZE && *(buff + i) != '\0')
	{
		*(re->rest + re->i + j) = *(buff + i + 1);
		printf("Filling rest with remainder of buff --> *(re->rest + %d + %d) = %c\n", re->i, j, *(re->rest + re->i + j));
		i++;
		j++;
	}
	printf("LEAVE BUFF_TO_LINE_AND_REST FUNCTION\n");
}
