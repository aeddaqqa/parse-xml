/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 02:23:27 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/11/28 01:58:38 by aeddaqqa         ###   ########.fr       */
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

	new.cmp = init_component();
	return (new);
}