/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 17:11:32 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/12/09 16:31:30 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

typedef struct	s_remains
{
	int			i;
	char		rest[BUFFER_SIZE];
}				t_remains;

int				get_next_line(int fd, char **line);
char			*create(char *line, char *buff, t_remains *re);
void			oldline_to_line(char *array, char *line);
int				rest_to_line(char *line, char *buff, t_remains *re, int flag);
void			buff_to_line_and_rest(char *line, char *buff, t_remains *re);
int				ft_strchr(char *s, int c);
int				ft_strlen(char *s, char c);
void			set_values(char *buff, int *flag, int *size);

#endif
