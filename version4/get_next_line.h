/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 17:11:32 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/12/05 11:51:28 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

typedef struct remains {
		int		i;
		char 	rest[BUFFER_SIZE];
} remains;


int		get_next_line(int fd, char **line);
char	*create(char *line, char *buff, remains *re);
void	oldline_to_line(char *array, char *line);
int		rest_to_line(char *line, char *buff, remains *re);
void	buff_to_line_and_rest(char *line, char *buff, remains *re);
int		ft_strchr(char *s, int c);
int		ft_strlen(char *s, char c);