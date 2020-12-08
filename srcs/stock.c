/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 02:51:39 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/08 11:52:59 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/rt.h"

int		stock_elements(char *str, t_tags tags, int *i)
{
	t_node		node;
	char		*elem;
	char		*new;
	int			j;
	int			r;

	node = init_node();
	if ((white_space(&str[*i], i)) < 0)
		return (-1);
	if (!(elem = get_tag(&str[*i], i)))
		return(-1);
	if ((node.type = cmp_with_objects(elem, tags.elements_o)) < 0)
	{
		ft_strdel(&elem);
		return (-1);
	}
	if ((stock_elements_cmp(str, tags, node, i)) < 0)
	{
		ft_strdel(&elem);
		return (-1);
	}
	j = 0;
	if ((white_space(&str[*i], &j)) < 0)
	{
		ft_strdel(&elem);
		return (-1);
	}
	*i += j;
	j = *i;
	elem = get_tag(&str[*i], &j);
	if (!elem)
		return (-1);
	j = *i;
	new = ft_strdup(&str[*i]);
	if (!ft_strcmp("</scene>", ft_strtrim(new)))
	{
		ft_strdel(&new);
		return (1);
	}
	j = 0;
	if ((node.type = cmp_with_objects(elem, tags.elements_o)) >= 0)
	{
		if ((r = stock_elements(new, tags, &j)) == -1)
			ft_strdel(&new);
		return (r);
	}
	return (-1);
}