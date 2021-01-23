/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 05:54:16 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/01/23 17:44:38 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int				check_openning_elem(char *s, char **tab)
{
	int		i;

	i = 0;
	while (i < LIMIT_CMP)
	{
		if (!ft_strcmp(s, tab[i]))
			return (i);
		i++;
	}
	return (-1);
}

int				check_closing_elem(char *s, int n, char **tab, int *i)
{
	char	*tag;

	if (!(tag = get_tag(s, i)))
		return (-1);
	if (!ft_strcmp(tab[n], tag))
	{
		ft_strdel(&tag);
		return (1);
	}
	ft_strdel(&tag);
	return (-1);
}

static int		check_cmp_exist_forcam(t_node n, int type)
{
	if (type != ORIGIN && type != LOOK_AT && type != FOV)
		return (-1);
	if (type == ORIGIN && n.cam.origin == true)
		return (-1);
	else if (type == LOOK_AT && n.cam.look_at == true)
		return (-1);
	else if (type == FOV && n.cam.fov == true)
		return (-1);
	return (1);
}

int		check_for_sphere(int type, t_node n)
{
	if (type != POSITION && type != COLOR && type != RADIUS && type != ROTATION
		&& type != TRANSLATION)
		return (-1);
	if (type == POSITION && n.cmp.position == true)
		return (-1);
	else if (type == COLOR && n.cmp.color == true)
		return (-1);
	else if (type == RADIUS && n.cmp.radius == true)
		return (-1);
	else if (type == ROTATION && n.cmp.rotation == true)
		return (-1);
	else if (type == TRANSLATION && n.cmp.translation == true)
		return (-1);
	return (1);
}

int		check_for_plane(int type, t_node n)
{
	if (type != POSITION && type != ORIENTATION && type != ROTATION
		&& type != TRANSLATION && type != COLOR)
		return (-1);
	if (type == POSITION && n.cmp.position == true)
		return (-1);
	else if (type == COLOR && n.cmp.color == true)
		return (-1);
	else if (type == ORIENTATION && n.cmp.orientation == true)
		return (-1);
	else if (type == ROTATION && n.cmp.rotation == true)
		return (-1);
	else if (type == TRANSLATION && n.cmp.translation == true)
		return (-1);
	return (1);
}

int		check_for_cone(int type, t_node n)
{
	if (type != POSITION && type != ORIENTATION && type != ROTATION
		&& type != TRANSLATION && type != COLOR && type != HEIGHT && type != ANGLE)
		return (-1);
	if (type == POSITION && n.cmp.position == true)
		return (-1);
	else if (type == COLOR && n.cmp.color == true)
		return (-1);
	else if (type == ORIENTATION && n.cmp.orientation == true)
		return (-1);
	else if (type == ROTATION && n.cmp.rotation == true)
		return (-1);
	else if (type == TRANSLATION && n.cmp.translation == true)
		return (-1);
	else if (type == HEIGHT && n.cmp.height == true)
		return (-1);
	else if (type == ANGLE && n.cmp.angle == true)
		return (-1);
	return (1);
}

int		check_for_cylinder(int type, t_node n)
{
	if (type != POSITION && type != ORIENTATION && type != ROTATION
		&& type != TRANSLATION && type != COLOR && type != HEIGHT && type != RADIUS)
		return (-1);
	if (type == POSITION && n.cmp.position == true)
		return (-1);
	else if (type == COLOR && n.cmp.color == true)
		return (-1);
	else if (type == ORIENTATION && n.cmp.orientation == true)
		return (-1);
	else if (type == ROTATION && n.cmp.rotation == true)
		return (-1);
	else if (type == TRANSLATION && n.cmp.translation == true)
		return (-1);
	else if (type == HEIGHT && n.cmp.height == true)
		return (-1);
	else if (type == RADIUS && n.cmp.radius == true)
		return (-1);
	return (1);
}

int		check_for_paraboloid(int type, t_node n)
{
	if (type != POSITION && type != ORIENTATION && type != ROTATION
		&& type != TRANSLATION && type != COLOR && type != DISTANCE)
		return (-1);
	if (type == POSITION && n.cmp.position == true)
		return (-1);
	else if (type == COLOR && n.cmp.color == true)
		return (-1);
	else if (type == ORIENTATION && n.cmp.orientation == true)
		return (-1);
	else if (type == ROTATION && n.cmp.rotation == true)
		return (-1);
	else if (type == TRANSLATION && n.cmp.translation == true)
		return (-1);
	else if (type == DISTANCE && n.cmp.dist == true)
		return (-1);
	return (1);
}

int		check_for_ellipsoid(int type, t_node n)
{
	if (type != POSITION && type != DISTANCE && type != ROTATION
		&& type != TRANSLATION && type != COLOR && type != ORIENTATION
		&& type != RADIUS_1 && type != RADIUS_2)
		return (-1);
	if (type == POSITION && n.cmp.position == true)
		return (-1);
	else if (type == COLOR && n.cmp.color == true)
		return (-1);
	else if (type == ORIENTATION && n.cmp.orientation == true)
		return (-1);
	else if (type == ROTATION && n.cmp.rotation == true)
		return (-1);
	else if (type == TRANSLATION && n.cmp.translation == true)
		return (-1);
	else if (type == DISTANCE && n.cmp.dist == true)
		return (-1);
	else if (type == RADIUS_1 && n.cmp.radius1 == true)
		return (-1);
	else if (type == RADIUS_2 && n.cmp.radius2 == true)
		return (-1);
	return (1);
}

static int		check_cmp_exist_forobj(t_node n, int type)
{
	if (n.type == SPHERE)
		return(check_for_sphere(type, n));
	else if (n.type == PLANE)
		return(check_for_plane(type,n));
	else if (n.type == CONE)
		return(check_for_cone(type,n));
	else if (n.type == CYLINDER)
		return(check_for_cylinder(type,n));
	else if (n.type == ELLIPSOID)
		return(check_for_ellipsoid(type,n));
	else if (n.type == PARABOLOID)
		return(check_for_paraboloid(type,n));
	return (1);
}

int				check_components_exist(t_node n, int type)
{
	if (n.type == CAMERA)
		return (check_cmp_exist_forcam(n, type));
	else if (n.type == LIGHT)
	{
		if (type != POSITION && type != INTENSITY && type != COLOR)
			return (-1);
		if (type == POSITION && n.lit.position == true)
			return (-1);
		else if (type == INTENSITY && n.lit.intensity == true)
			return (-1);
		else if (type == COLOR && n.lit.color == true)
			return (-1);
	}
	else
		return (check_cmp_exist_forobj(n, type));
	return (1);
}
