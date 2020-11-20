/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   D_flag_test.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 21:45:38 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/11/20 21:49:14 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main(void)
{
	#ifdef DEBUG
		printf("DEGUB defined, DEBUG = %s\n", DEBUG);
	#else
		printf("DEBUG not defined\n");
	#endif
}
