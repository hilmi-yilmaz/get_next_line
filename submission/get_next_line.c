/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 17:08:31 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/12/05 13:28:19 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int				size;
	int				flag;
	char			buff[BUFFER_SIZE + 1];
	static remains	re;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	flag = 0;
	buff[0] = '\0';
	*line = NULL;
	size = BUFFER_SIZE;
	while (flag == 0)
	{
		if (ft_strchr(re.rest + re.i, '\n') == 0)
			size = read(fd, buff, BUFFER_SIZE);
		if (size == -1)
			return (-1);
		if (size == 0)
			return (0);
		buff[size] = '\0';
		*line = create(*line, buff, &re);
		flag = rest_to_line(*line, buff, &re, flag);
		buff_to_line_and_rest(*line, buff, &re);
	}
	return (1);
}

char	*create(char *line, char *buff, remains *re)
{
	int		size;
	char	*array;

	size = ft_strlen(line, '\0') + ft_strlen(buff, '\n') \
			+ ft_strlen(re->rest + re->i, '\n');
	array = (char *)malloc(sizeof(char) * size + 1);
	if (array == NULL)
		return (NULL);
	*(array + 0) = '\0';
	*(array + size) = '\0';
	oldline_to_line(array, line);
	return (array);
}

void	oldline_to_line(char *array, char *line)
{
	int i;

	if (line == NULL)
		return ;
	i = 0;
	while (*(line + i) != '\0')
	{
		*(array + i) = *(line + i);
		i++;
	}
	*(array + i) = '\0';
	free(line);
}

int		rest_to_line(char *line, char *buff, remains *re, int flag)
{
	int i;
	int len_line;

	i = 0;
	flag = ft_strchr(buff, '\n') + ft_strchr(re->rest + re->i, '\n');
	len_line = ft_strlen(line, '\0');
	while (i < BUFFER_SIZE)
	{
		if (*(re->rest + re->i + i) == '\n')
		{
			*(re->rest + re->i + i) = '\0';
			re->i = re->i + i + 1;
			break ;
		}
		else if (*(re->rest + re->i + i) == '\0')
		{
			re->i = 0;
			break ;
		}
		*(line + len_line + i) = *(re->rest + re->i + i);
		*(re->rest + re->i + i) = '\0';
		i++;
	}
	*(line + len_line + i) = '\0';
	return (flag);
}

void	buff_to_line_and_rest(char *line, char *buff, remains *re)
{
	int i;
	int j;
	int	len_line;

	i = 0;
	j = 0;
	len_line = ft_strlen(line, '\0');
	while (*(buff + i) != '\0' && *(buff + i) != '\n')
	{
		*(line + len_line + i) = *(buff + i);
		i++;
	}
	*(line + len_line + i) = '\0';
	while (i < BUFFER_SIZE && *(buff + i) != '\0')
	{
		*(re->rest + re->i + j) = *(buff + i + 1);
		i++;
		j++;
	}
}
