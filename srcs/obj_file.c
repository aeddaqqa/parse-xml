/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:26:11 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/02/04 17:43:39 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_object		*stock_points(int nb, char *path)
{
	t_point		tab[nb];
	t_object	*obj;
	t_object	*tmp;
	char		**split;
	char		*line;
	int			fd;
	int			i;
	int			j;
	int			z;

	i = 0;
	z = 0;
	obj = NULL;
	tmp = NULL;
	split = NULL;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (*line && (*line == 's' || *line == '#'))
			continue;
		if (z < nb)
		{
			split = ft_strsplit(line, ' ');
			j = 0;
			while (split[j])
				j++;
			if (j != 4 || ft_strcmp(split[0], "v"))
				return (NULL);
			tab[z] = (t_point){ft_atod(split[1]), ft_atod(split[2]), ft_atod(split[3])};
			z++;
		}
		else
		{
			split = ft_strsplit(line, ' ');
			j = 0;
			while (split[j])
			{
				if (j != 0)
					if (ft_atoi(split[j]) > nb || ft_atoi(split[j]) < 0)
					{
						printf("%s", split[j]);
						return (NULL);
					}
				j++;
			}
			if (!*split)
				continue;
			if (j != 4 || ft_strcmp(split[0], "f") || *line == 's' || *line == '#')
				return (NULL);
			if (!obj)
			{
				obj = (t_object*)new_object(TRIANGLE);
				obj->point_a = tab[ft_atoi(split[1]) - 1];
				obj->point_b = tab[ft_atoi(split[2]) - 1];
				obj->point_c = tab[ft_atoi(split[3]) - 1];
				tmp = obj;
			}
			else
			{
				tmp->next = (t_object*)new_object(TRIANGLE);
				tmp->next->point_a = tab[ft_atoi(split[1]) - 1];
				tmp->next->point_b = tab[ft_atoi(split[2]) - 1];
				tmp->next->point_c = tab[ft_atoi(split[3]) - 1];
				tmp = tmp->next;
			}
		}
		 while (obj)
		 {
		 	printf("%lf    %lf       %lf |        ", obj->point_a.x, obj->point_a.y, obj->point_a.z);
		 	printf("%lf    %lf       %lf |        ", obj->point_b.x, obj->point_b.y, obj->point_b.z);
		 	printf("%lf    %lf       %lf \n", obj->point_c.x, obj->point_c.y, obj->point_c.z);
		 	obj = obj->next;
		 }
	}
	return (obj);
}

t_object	*load_fileobj(char *path)
{
	char	*line;
	int		fd;
	int		nb;

	nb = 0;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (*line && (*line == 's' || *line == '#'))
			continue;
		else if (*line == 'v')
			nb++;
	}
	close(fd);
	if (!nb)
		return (NULL);
	return (stock_points(nb, path));
}
