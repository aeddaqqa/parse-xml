/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 23:16:14 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/19 03:08:06 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include	"../includes/rt.h"

int		main(int ac, char **av)
{
	char	*file;
	t_rt	*rt;

	file = NULL;
	if (ac == 2 || ac == 3)
	{
		if (ac == 3 && ft_strcmp(av[2], "--save"))
		{
			destroy(FLAG_SAVE);
			return (0);
		}
		file = load_file(av[1]);
		if (!(rt = init_rt(ac - 2)))
			destroy(MALLOC_ERROR);
		if (!(parse(file, rt)))
			destroy(SYNTAX_ERROR);
		free_rt(&rt);
		free(file);
	}
	return (1);
}