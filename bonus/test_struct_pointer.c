/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_struct_pointer.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/09 12:19:19 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/12/09 14:13:18 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

typedef struct			s_remains
{
	int					i;
	char				rest[BUFFER_SIZE];
}						t_remains;

int main(void)
{
	int					i;
	int					j;
	static t_remains	head[10];

	i = 0;
	j = 0;
	head[0].i = 5;
	strcpy(head[0].rest, "hilmi");

	while (i < 10)
	{
		printf("head[%d].i = %d\n", i, head[i].i);
		printf("head[%d].rest = ", i);
		while (j < BUFFER_SIZE)
		{
			if (head[i].rest[j] == '\0')
				printf("\\0");
			else
				printf("%c", head[i].rest[j]);
			j++;
		}
		j = 0;
		printf("\n");
		i++;
	}
	return (0);

}
