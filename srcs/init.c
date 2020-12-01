/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 02:23:27 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/01 05:00:38 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/rt.h"

o_component		init_component(void)
{
	o_component		new;

	new.ambient = false;
	new.color = false;
	new.position = false;
	new.radius = false;
	new.orientation = false;
	return (new);
}

t_node		init_node(void)
{
	t_node	new;

	new.type = -1;
	new.cmp = init_component();
	return (new);
}

t_tags			init_tab_tags(void)
{
	t_tags tags;
	
	tags.elements_o[0] = (char*)"<plane>";
	tags.elements_o[1] = (char*)"<sphere>";
	tags.elements_o[2] = (char*)"<cylinder>";
	tags.elements_o[3] = (char*)"<cone>";
	tags.elements_c[0] = (char*)"</plane>";
	tags.elements_c[1] = (char*)"</sphere>";
	tags.elements_c[2] = (char*)"</cylinder>";
	tags.elements_c[3] = (char*)"</cone>";
	tags.components_o[0] = (char*)"<position>";
	tags.components_o[1] = (char*)"<color>";
	tags.components_o[2] = (char*)"<r_a>";
	tags.components_o[3] = (char*)"<ambient>";
	tags.components_o[4] = (char*)"<orientation>";
	tags.components_c[0] = (char*)"</position>";
	tags.components_c[1] = (char*)"</color>";
	tags.components_c[2] = (char*)"</r_a>";
	tags.components_c[3] = (char*)"</ambient>";
	tags.components_c[4] = (char*)"</orientation>";
	return (tags);
}