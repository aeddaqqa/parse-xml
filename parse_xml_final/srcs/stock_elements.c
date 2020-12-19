/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 05:21:43 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/19 05:56:38 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/rt.h"

static	int			cmp_with_objects(char *s, char **tab)
{
	int		i;
	
	i = 0;
	if (s)
		while (i < 6)
		{
			if (!ft_strcmp(s, tab[i]))
				return (i);
			i++;
		}
	return (-1);
}

int					stock_elements(char *str, t_tags tags, int *i, t_rt *rt)
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
		add_front(&rt, obj, node.type);
		return (1);
	}
	j = 0;
	if ((cmp_with_objects(elem, tags.elements_o)) >= 0)
	{
		ft_strdel(&elem);
		int tmp;
		add_front(&rt, obj, node.type);
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