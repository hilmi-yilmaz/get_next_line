/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 17:08:54 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/03/10 18:01:20 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
** The ft_strchr function searches for the character c in the string s.
** If found, it returns 1, else returns 0.
*/

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == c)
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

/*
** The ft_strlen function calculates the length of a string up untill char c.
** It string points to NULL, the length is 0.
*/

int	ft_strlen(char *s, int c)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == c)
			break ;
		i++;
	}
	return (i);
}

/*
** The set_values function sets some initial values
*/

void	set_values(char *buff, int *flag, int *size)
{
	buff[0] = '\0';
	*flag = 0;
	*size = BUFFER_SIZE;
}
