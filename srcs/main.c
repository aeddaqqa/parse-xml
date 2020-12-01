/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:41:44 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/01 03:19:19 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/rt.h"

int		main(int ac, char **av)
{
	char *str;
	
	if (ac == 2)
	{
		str = read_file(av[1]);
		if (!str)
			destroy(OPEN_FILE);
		if (!*str)
			destroy(EMPTY_FILE);
		printf("\n[-------------------|%d|------------------]\n", check(str));
	}
	return (0);
}
