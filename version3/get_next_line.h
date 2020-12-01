/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 13:19:26 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/12/01 19:41:45 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		get_next_line(int fd, char **line);
char	*create_array(char *line, char *buff, char *rest);
void	rest_to_line(char *line, char *rest);
void	buff_to_line_and_rest(char *line, char *buff, char *rest);
int		check_newline(char *str, int rest);
int		ft_strlen(char *str);
int		ft_strlen_rest(char *rest);;
