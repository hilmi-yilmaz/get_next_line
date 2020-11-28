int		get_next_line(int fd, char **line);
void	concat(char *line, char *buff, char *rest);
void	fill_remainder(char *line, char *buff);
char	*transfer(char *line, char *buff, char *rest, int index);
int		ft_strlen(char *str);
int		check_newline(char *buff);
