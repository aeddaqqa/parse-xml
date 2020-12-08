/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:41:44 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/08 10:11:15 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/rt.h"

// t_object		*new_object()
// {
// 	t_object	*new;

// 	if (!(new = malloc(sizeof(t_object))))
// 		return (NULL);
// 	new->type = -1;
// 	new->position = (t_point){0, 0, 0};
// 	new->orientation = (t_vect3){0, 0, 0};
// 	new->color = (t_color){0, 0, 0};
// 	new->r_a = 0;
// 	new->ambient = 0;
// 	new->next = NULL;
// 	return (new);
// }

// void		add_front(t_object *obj, t_object *new)
// {
// 	if (!obj)
// 		obj = new;
// 	new->next = obj;
// 	obj = new;
// }

// t_point		get_point(char *s)
// {
// 	t_point		p;

// 	p = (t_point){0, 0, 0};
// 	return (p);
// }

// t_vect3		get_ori_vect(char *s)
// {
// 	t_vect3		v;

// 	v = (t_point){0, 0, 0};
// 	return (v);
// }

// t_color		get_color(char *s)
// {
// 	t_vect3		c;

// 	c = (t_point){0, 0, 0};
// 	return (c);
// }

// double		get_raduis_a(char *s, t_type type)
// {
// 	double	r;

// 	r = 0;
// 	return (r);
// }

// void		fill_components(int n,char *s, t_object *obj, t_type type)
// {
// 	if (obj->type == -1)
// 		obj->type = type;
// 	if (n == 0)
// 		obj->position = get_point(s);
// 	else if (n == 1)
// 		obj->color = get_color(s);
// 	else if (n == 2)
// 		obj->orientation = get_ori_vect(s);
// 	else if (n == 3)
// 		obj->r_a = get_raduis_a(s, type);
// }

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
