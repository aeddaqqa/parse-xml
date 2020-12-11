/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:41:44 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/11 06:02:13 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/rt.h"

t_object		*new_object()
{
	t_object	*new;

	if (!(new = malloc(sizeof(t_object))))
		return (NULL);
	new->type = -1;
	new->position = (t_point){0, 0, 0};
	new->orientation = (t_vect3){0, 0, 0};
	new->color = (t_color){0, 0, 0};
	new->r_a = 0;
	new->ambient = 0;
	new->next = NULL;
	return (new);
}

t_object		*add_front(t_object *head, t_object *new)
{
	if (new)
	{
		if (!head)
			head = new;
		else
		{
			new->next = head;
			head = new;
		}
	}
	return (head);
}

void		print_object(t_object *obj)
{
	printf("type = {%d}\n", (int)obj->type);
	printf("position = {%lf,%lf,%lf}\n", obj->position.x, obj->position.y,obj->position.z);
	printf("color = {%lf,%lf,%lf}\n",obj->color.x, obj->color.y, obj->color.z);
	printf("orientation = {%lf,%lf,%lf}\n", obj->orientation.x, obj->orientation.y,obj->orientation.z);
	printf("raduis = %lf\n", obj->r_a);
	printf("ambient = %lf\n", obj->ambient);
}

int		get_point(char *s, t_point *p)
{
	double		tab[3];
	int			i;
	char **tmp;

	i = 0;
	tmp = ft_strsplit(s, ',');
	while (tmp[i])
	{
		if (i < 3)
			tab[i] = ft_atoi(tmp[i]);
		i++;
	}
	if (i != 3)
		return (-1);
	*p = (t_point){tab[0], tab[1], tab[2]};
	return (1);
}

int		get_ori_vect(char *s, t_vect3 *ori)
{
	char		**tmp;
	double		tab[3];
	int			i;

	i = 0;
	tmp = ft_strsplit(s, ',');
	while (tmp[i])
	{
		if (i < 3)
			tab[i] = ft_atoi(tmp[i]);
		i++;
	}
	if (i != 3)
		return (-1);
	*ori = (t_vect3){tab[0], tab[1], tab[2]};
	return (1);
}

int		get_color(char *s, t_color *color)
{
	int		r;
	int		g;
	int		b;
	int		c;

	c = ft_atoi(s);
	r = (c >> 16) & 255;
	g = (c >> 8) & 255;
	b = c  & 255;
	color->x = r;
	color->y = g;
	color->z = b;
	return (1);
}

int		get_raduis_a(char *s, int type, double *r_a)
{
	double r;

	r = ft_atoi(s);
	if (type == 3)
		*r_a = M_PI * r / 180;
	else
		*r_a = r;
	return (1);
}


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
			printf("\n[-------------------|%d|------------------]\n", check(str, rt));
		while (rt->objects)
		{
			ft_putendl("\n[-----------------------------------------------]");
			print_object(rt->objects);
			ft_putendl("\n[-----------------------------------------------]");
			rt->objects = rt->objects->next;
		}
		free(str);
	}
	return (0);
}
