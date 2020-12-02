/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 02:51:39 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/02 02:52:12 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/rt.h"

int		stock_elements(char *str, t_tags tags, int *i)
{
	t_node		node;
	char		*elem;
	int			j;

	node = init_node();
	if ((white_space(&str[*i], i)) < 0)
		return (-1);
	elem = get_tag(&str[*i], i);
	if ((node.type = cmp_with_objects(elem, tags.elements_o)) < 0)
		return (-1);
	if ((stock_elements_cmp(str, tags, node, i)) < 0)
		return (-1);
	j = 0;
	white_space(&str[*i], &j);
	*i += j;
	j = *i;
	elem = get_tag(&str[*i], &j);
	if (!elem)
		return (1);
	j = *i;
	char *new = ft_strdup(&str[*i]);
	if (!ft_strcmp("</scene>", new))
		return (1);
	j = 0;
	if ((node.type = cmp_with_objects(elem, tags.elements_o)) >= 0)
		return (stock_elements(new, tags, &j));
	return (-1);
}