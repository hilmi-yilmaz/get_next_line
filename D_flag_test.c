/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   D_flag_test.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 21:45:38 by hyilmaz       #+#    #+#                 */
/*   Updated: 2020/11/21 11:28:01 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main(void)
{
	#ifdef DEBUG
		printf("DEGUB defined, DEBUG = %d\n", DEBUG);
	#else
		printf("DEBUG not defined\n");
	#endif
}
