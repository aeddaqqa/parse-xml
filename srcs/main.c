/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:41:44 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/16 05:06:20 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/rt.h"


t_rt	*init_rt()
{
	t_rt	*new;

	if (!(new = malloc(sizeof(t_rt))))
		return (NULL);
	new->cameras = NULL;
	new->lights = NULL;
	new->objects = NULL;
	return (new);
}

int		main(int ac, char **av)
{
	char	*str;
	char	*tmp;
	t_rt	*rt;

	if (ac == 2)
	{
		tmp = read_file(av[1]);
		str = ft_strtrim(tmp);
		free(tmp);
		if (!str)
			destroy(OPEN_FILE);
		if (!*str)
			destroy(EMPTY_FILE);
		rt = init_rt();
		if (rt)
			check(str, rt);
		if (!rt->objects)
			ft_putendl("\nkamehameha\n");
		while (rt->objects)
		{
			ft_putendl("\n[-----------------------------------------------]");
			ft_putendl("\n[---------------------Object----------------------]");
			print_object(rt->objects);
			ft_putendl("\n[-----------------------------------------------]");
			rt->objects = rt->objects->next;
		}
		while (rt->cameras)
		{
			ft_putendl("\n[-----------------------------------------------]");
			ft_putendl("\n[-----------------Camera---------------------]");
			printf("position = {%lf,%lf,%lf}\n", rt->cameras->o.x, rt->cameras->o.y,rt->cameras->o.z);
			ft_putendl("\n[-----------------------------------------------]");
			rt->cameras = rt->cameras->next;
		}
		while (rt->lights)
		{
			ft_putendl("\n[-----------------------------------------------]");
			ft_putendl("\n[-----------------Light---------------------]");
			printf("position = {%lf,%lf,%lf}\n", rt->lights->pos.x, rt->lights->pos.y, rt->lights->pos.z);
			ft_putendl("\n[-----------------------------------------------]");
			rt->lights = rt->lights->next;
		}
		free(str);
	}
	return (0);
}
