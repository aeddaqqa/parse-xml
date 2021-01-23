/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 02:14:10 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/01/23 17:45:32 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static t_ocomponent			init_ocomponent(void)
{
	t_ocomponent		new;

	new.color = false;
	new.position = false;
	new.radius = false;
	new.angle = false;
	new.orientation = false;
	new.rotation = false;
	new.translation = false;
	new.height = false;
	new.dist = false;
	new.radius1 = false;
	new.radius2 = false;
	return (new);
}

static t_ccomponent			init_ccomponent(void)
{
	t_ccomponent		new;

	new.look_at = false;
	new.fov = false;
	new.origin = false;
	return (new);
}

static t_lcomponent			init_lcomponent(void)
{
	t_lcomponent		new;

	new.color = false;
	new.intensity = false;
	new.position = false;
	return (new);
}

t_node						init_node(void)
{
	t_node	new;

	new.type = -1;
	new.cmp = init_ocomponent();
	new.cam = init_ccomponent();
	new.lit = init_lcomponent();
	return (new);
}

t_tags						init_tab_tags(void)
{
	t_tags tags;

	tags.elements_o[PLANE] = (char*)"<plane>";
	tags.elements_o[SPHERE] = (char*)"<sphere>";
	tags.elements_o[CYLINDER] = (char*)"<cylinder>";
	tags.elements_o[CONE] = (char*)"<cone>";
	tags.elements_o[CAMERA] = (char*)"<camera>";
	tags.elements_o[LIGHT] = (char*)"<light>";
	tags.elements_o[ELLIPSOID] = (char*)"<ellipsoid>";
	tags.elements_o[PARABOLOID] = (char*)"<paraboloid>";

	tags.elements_c[PLANE] = (char*)"</plane>";
	tags.elements_c[SPHERE] = (char*)"</sphere>";
	tags.elements_c[CYLINDER] = (char*)"</cylinder>";
	tags.elements_c[CONE] = (char*)"</cone>";
	tags.elements_c[CAMERA] = (char*)"</camera>";
	tags.elements_c[LIGHT] = (char*)"</light>";
	tags.elements_c[ELLIPSOID] = (char*)"</ellipsoid>";
	tags.elements_c[PARABOLOID] = (char*)"</paraboloid>";
	
	tags.components_o[POSITION] = (char*)"<position>";
	tags.components_o[COLOR] = (char*)"<color>";
	tags.components_o[ANGLE] = (char*)"<angle>";
	tags.components_o[RADIUS] = (char*)"<radius>";
	tags.components_o[TRANSLATION] = (char*)"<translation>";
	tags.components_o[ROTATION] = (char*)"<rotation>";
	tags.components_o[ORIENTATION] = (char*)"<orientation>";
	tags.components_o[LOOK_AT] = (char*)"<look-at>";
	tags.components_o[ORIGIN] = (char*)"<origin>";
	tags.components_o[FOV] = (char*)"<fov>";
	tags.components_o[INTENSITY] = (char*)"<intensity>";
	tags.components_o[HEIGHT] = (char*)"<height>";
	tags.components_o[DISTANCE] = (char*)"<distance>";
	tags.components_o[RADIUS_1] = (char*)"<radius_1>";
	tags.components_o[RADIUS_2] = (char*)"<radius_2>";
	
	tags.components_c[POSITION] = (char*)"</position>";
	tags.components_c[COLOR] = (char*)"</color>";
	tags.components_c[ANGLE] = (char*)"</angle>";
	tags.components_c[RADIUS] = (char*)"</radius>";
	tags.components_c[TRANSLATION] = (char*)"</translation>";
	tags.components_c[ROTATION] = (char*)"</rotation>";
	tags.components_c[ORIENTATION] = (char*)"</orientation>";
	tags.components_c[LOOK_AT] = (char*)"</look-at>";
	tags.components_c[ORIGIN] = (char*)"</origin>";
	tags.components_c[FOV] = (char*)"</fov>";
	tags.components_c[INTENSITY] = (char*)"</intensity>";
	tags.components_c[HEIGHT] = (char*)"</height>";
	tags.components_c[DISTANCE] = (char*)"</distance>";
	tags.components_c[RADIUS_1] = (char*)"</radius_1>";
	tags.components_c[RADIUS_2] = (char*)"</radius_2>";
	return (tags);
}
