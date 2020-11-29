/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 13:48:13 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/11/29 14:04:50 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//Header Guards to prevent double inclusion 

int		get_next_line(int fd, char **line);
void	concat(char *line, char *buff, char *rest);
char	*create(char *line, char *buff, char *rest);
int		check_newline(char *buff);
int		ft_strlen(char *str, int newline);