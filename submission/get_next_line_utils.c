/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 17:08:54 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/12/05 14:24:55 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		ft_strchr(char *s, int c)
{
	int i;

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

int		ft_strlen(char *s, int c)
{
	size_t i;

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
