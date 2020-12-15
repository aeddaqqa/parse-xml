/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_components.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 02:45:32 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/15 05:41:15 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/rt.h"

static	char		*inner_text(char *s, int *j)
{
	char	*new;
	int		i;

	if (!s || !*s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '<')
		i++;
	if (!s[i])
		return (NULL);
	new = ft_strsub(s, 0, i);
	*j += i;
	return (new);
}

static	int		check_components_exist(t_node n, int type)
{
	if (n.type == 4)
	{
		if (type == 6 && n.cam.origin == true)
			return (-1);
		else if (type == 5 && n.cam.look_at == true)
			return (-1);
		else if (type == 7 && n.cam.fov == true)
			return (-1);
	}
	else if (n.type == 5)
	{
		if (type == 0 && n.lit.position == true)
			return (-1);
		else if (type == 8 && n.lit.intensity == true)
			return (-1);
		else if (type == 1 && n.lit.color == true)
			return (-1);
	}
	else
	{
		if (type == 0 && n.cmp.position == true)
			return (-1);
		else if (type == 1 && n.cmp.color == true)
			return (-1);
		else if (type == 2 && n.cmp.radius == true)
			return (-1);
		else if (type == 3 && n.cmp.ambient == true)
			return (-1);
		else if (type == 4 && n.cmp.orientation == true)
			return (-1);
	}
	return (1);
}

static	void		valid_cmp(t_node *n, int type)
{
	if (n->type == 4)
	{
		if (type == 6) 
				n->cam.origin = true;
		else if (type == 5)
				n->cam.look_at = true;
		else if (type == 7)
				n->cam.fov = true;
		
	}
	else if (n->type == 5)
	{
		if (type == 0 )
			n->lit.position = true;
		else if (type == 8)
			n->lit.intensity = true;
		else if (type == 1)
			n->lit.color = true;
	}
	else
	{
		if (type == 0) 
			n->cmp.position = true;
		else if (type == 1)
			n->cmp.color = true;
		else if (type == 2)
			n->cmp.radius = true;
		else if (type == 3)
			n->cmp.ambient = true;
		else if (type == 4)
			n->cmp.orientation = true;
	}
}

static	int		all_cmp_valid(t_node n)
{
	if (n.type == 4) 
	{
		if ((n.cam.fov == false || n.cam.look_at == false ||
		n.cam.origin == false))
			return (-1);
	}
	else if (n.type == 5)
	{
		if ((n.lit.color == false || n.lit.intensity == false
		|| n.lit.position == false))
			return (-1);
	}
	else if (n.cmp.ambient == false || n.cmp.color == false ||
	n.cmp.orientation == false ||n.cmp.radius == false ||
	n.cmp.position == false)
		return (-1);
	return (1);
}

int			stock_cmp(void **object, char *str, int r, int type)
{
	t_object	*obj;
	t_cam		*cam;
	t_light		*light;

	obj = NULL;
	light = NULL;
	cam = NULL;
	if (type == 4)
	{
		cam = (t_cam*)*object;
		if (r == 6)
		{
			if ((get_point(str, &cam->o)) < 0)
				return(-1);
		}
		else if (r == 5)
		{
			if((get_point(str, &cam->l)) < 0)
				return (-1);
		}
		else if (r == 3)
			cam->fov = ft_atoi(str);
	}
	else if (type == 5)
	{
		light = (t_light*)*object;
		if (r == 0)
		{
			if ((get_point(str, &light->pos)) < 0)
				return(-1);
		}
		else if (r == 1)
		{
			if((get_color(str, &light->color)) < 0)
				return (-1);
		}
		else if (r == 8)
			light->intensity = ft_atoi(str);
	}
	else
	{
		obj = (t_object*)*object;
		obj->type = type;
		if (r == 0)
		{
			if ((get_point(str, &obj->position)) < 0)
				return(-1);
		}
		else if (r == 1)
		{
			if((get_color(str, &obj->color)) < 0)
				return (-1);
		}
		else if (r == 2)
		{
			if ((get_raduis_a(str, obj->type, &obj->r_a)) < 0)
				return (-1);
		}
		else if (r == 3)
			obj->ambient = ft_atoi(str);
		else if (r == 4)
		{
			if ((get_ori_vect(str, &obj->orientation)) < 0)
				return (-1);
		}
	}
	return (1);
}

int		stock_elements_cmp(char *s, t_tags tags, t_node n, int *i, void *obje)
{
	int			r;
	char		*comp;
	char		*content;
	t_object	*obj;

	white_space(s, i);
	obj = NULL;
	if (n.type < 5)
		obj = (t_object*)obje;
	obj->type = n.type;
	if (!(comp = get_tag(&s[*i], i)))
		return (-1);
	if (!ft_strcmp(comp, tags.elements_c[n.type]))
	{
		ft_strdel(&comp);
		return (all_cmp_valid(n));
	}
	if ((r = check_openning_elem(comp, tags.components_o)) < 0)
	{
		ft_strdel(&comp);
		return (-1);
	}
	if ((check_components_exist(n, r)) == -1)
	{
		ft_strdel(&comp);
		return (-1);
	}
	valid_cmp(&n, r);
	ft_strdel(&comp);
	content = inner_text(&s[*i], i);
	if (stock_cmp(&obje, content, r, n.type) < 0)
		return(-1);
	free(content);
	if (check_closing_elem(&s[*i], r, tags.components_c, i) < 0)
		return (-1);
	return (stock_elements_cmp(s, tags, n, i, obj));
}