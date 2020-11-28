/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 13:48:13 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/11/28 15:22:34 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		get_next_line(int fd, char **line);
void	concat(char *line, char *buff, char *rest);
char	*create(char *line, char *buff, char *rest);
int		check_newline(char *buff);
int		ft_strlen(char *str);
