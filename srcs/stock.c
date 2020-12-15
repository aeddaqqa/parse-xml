/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 02:51:39 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/15 05:11:13 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/rt.h"



t_object		*stock_elements(char *str, t_tags tags, int *i, t_rt *rt)
{
	t_node		node;
	char		*elem;
	char		*new;
	int			j;
	void		*obj;

	node = init_node();
	if ((white_space(&str[*i], i)) < 0)
		return (NULL);
	if (!(elem = get_tag(&str[*i], i)))
		return(NULL);
	if ((node.type = cmp_with_objects(elem, tags.elements_o)) < 0)
	{
		ft_strdel(&elem);
		return (NULL);
	}
	obj = new_object(node.type);
	// obj->type = node.type;
	if ((stock_elements_cmp(str, tags, node, i, obj)) < 0)
	{
		ft_strdel(&elem);
		return (NULL);
	}
	j = 0;
	ft_strdel(&elem);
	if ((white_space(&str[*i], &j)) < 0)
		return (NULL);
	*i += j;
	j = *i;
	elem = get_tag(&str[*i], &j);
	if (!elem)
		return (NULL);
	j = *i;
	new = ft_strdup(&str[*i]);
	if (!ft_strcmp("</scene>", new))
	{
		ft_strdel(&elem);
		ft_strdel(&new);
		return (obj);
	}
	j = 0;
	if ((node.type = cmp_with_objects(elem, tags.elements_o)) >= 0)
	{
		ft_strdel(&elem);
		t_object *tmp;
		tmp = stock_elements(new, tags, &j, rt);
		if (!tmp)
			return (NULL);
		obj = add_front(tmp, obj);
		rt->objects = obj;
		ft_strdel(&new);
		return (obj);
	}
	return (NULL);
}