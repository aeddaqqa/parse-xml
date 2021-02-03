/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farwila <farwila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 23:16:14 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/02/03 20:42:54 by farwila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

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
		if (!(file = load_file(av[1])))
			exit(0);
		if (!(rt = init_rt(ac - 2)))
			destroy(MALLOC_ERROR);
		if (!(parse(file, rt)))
			destroy(SYNTAX_ERROR);
		while (rt->objects)
		{
			printf("\n|********************Object*********************|\n");
			printf("type => %d \n", rt->objects->type);
			printf("position => (%lf, %lf, %lf)\n", rt->objects->position.x, rt->objects->position.y, rt->objects->position.z);
			printf("point_a => (%lf, %lf, %lf)\n", rt->objects->point_a.x, rt->objects->point_a.y, rt->objects->point_a.z);
			printf("point_b => (%lf, %lf, %lf)\n", rt->objects->point_b.x, rt->objects->point_b.y, rt->objects->point_b.z);
			printf("point_c => (%lf, %lf, %lf)\n", rt->objects->point_c.x, rt->objects->point_c.y, rt->objects->point_c.z);
			printf("point_d => (%lf, %lf, %lf)\n", rt->objects->point_d.x, rt->objects->point_d.y, rt->objects->point_d.z);
			printf("corner[0] => (%lf, %lf, %lf)\n", rt->objects->corner[0].x, rt->objects->corner[0].y, rt->objects->corner[0].z);
			printf("corner[1] => (%lf, %lf, %lf)\n", rt->objects->corner[1].x, rt->objects->corner[1].y, rt->objects->corner[1].z);
			printf("orientation => (%lf, %lf, %lf)\n", rt->objects->orientation.x, rt->objects->orientation.y, rt->objects->orientation.z);
			printf("rotation => (%lf, %lf, %lf)\n", rt->objects->rotation.x, rt->objects->rotation.y, rt->objects->rotation.z);
			printf("translation => (%lf, %lf, %lf)\n", rt->objects->translation.x, rt->objects->translation.y, rt->objects->translation.z);
			printf("color => (%lf, %lf, %lf)\n", rt->objects->color.x, rt->objects->color.y, rt->objects->color.z);
			printf("radius => %lf \n", rt->objects->radius);
			printf("angle => %lf \n", rt->objects->angle);
			printf("distance => %lf \n", rt->objects->dist);
			printf("radius_1 => %lf \n", rt->objects->radius1);
			printf("radius_2 => %lf \n", rt->objects->radius2);
			printf("height => %lf \n", rt->objects->height);
			rt->objects = rt->objects->next;
		}
		while (rt->cameras)
		{
			printf("origin => (%lf, %lf, %lf)\n", rt->cameras->o.x, rt->cameras->o.y, rt->cameras->o.z);
			printf("look-at => (%lf, %lf, %lf)\n", rt->cameras->l.x, rt->cameras->l.y, rt->cameras->l.z);
			printf("fov => %lf \n", rt->cameras->fov);
			rt->cameras = rt->cameras->next;
		}
		while (rt->lights)
		{
			printf("origin => (%lf, %lf, %lf)\n", rt->lights->pos.x, rt->lights->pos.y, rt->lights->pos.z);
			printf("color => (%lf, %lf, %lf)\n", rt->lights->color.x, rt->lights->color.y, rt->lights->color.z);
			printf("intensity => %lf \n", rt->lights->intensity);
			rt->lights = rt->lights->next;
		}
		free_rt(&rt);
		free(file);
	}
	else
		ft_putendl("./rt [fileName]");
	return (1);
}
