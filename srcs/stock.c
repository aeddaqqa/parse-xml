/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 02:51:39 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/17 05:39:19 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/rt.h"



int		stock_elements(char *str, t_tags tags, int *i, t_rt *rt)
{
	t_node		node;
	char		*elem;
	char		*new;
	int			j;
	void		*obj;

	node = init_node();
	if ((white_space(&str[*i], i)) < 0)
		return (0);
	if (!(elem = get_tag(&str[*i], i)))
		return(0);
	if ((node.type = cmp_with_objects(elem, tags.elements_o)) < 0)
	{
		ft_strdel(&elem);
		return (0);
	}
	obj = new_object(node.type);
	if ((stock_elements_cmp(str, tags, node, i, obj)) < 0)
	{
		free(obj);
		ft_strdel(&elem);
		return (0);
	}
	j = 0;
	ft_strdel(&elem);
	if ((white_space(&str[*i], &j)) < 0)
	{
		if (obj)
			free(obj);
		 return (0);
	}
	*i += j;
	j = *i;
	elem = get_tag(&str[*i], &j);
	if (!elem)
	{
		if (obj)
			free(obj);
		return (0);
	}
	j = *i;
	new = ft_strdup(&str[*i]);
	if (!ft_strcmp("</scene>", new))
	{
		ft_strdel(&elem);
		ft_strdel(&new);
		if (node.type == 4)
			add_front_cam(&rt->cameras, obj);
		else if (node.type == 5)
			add_front_light(&rt->lights, obj);
		else
			add_front_obj(&rt->objects, obj);
		return (1);
	}
	j = 0;
	if ((cmp_with_objects(elem, tags.elements_o)) >= 0)
	{
		ft_strdel(&elem);
		int tmp;
		if (node.type == 4)
			add_front_cam(&rt->cameras, obj);
		else if (node.type == 5)
			add_front_light(&rt->lights, obj);
		else
			add_front_obj(&rt->objects, obj);
		tmp = stock_elements(new, tags, &j, rt);
		if (!tmp)
		{
			ft_strdel(&new);
			return (0);
		}
		ft_strdel(&new);
		return (1);
	}
	return (0);
}