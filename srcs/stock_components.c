/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_components.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 02:45:32 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/08 11:57:13 by aeddaqqa         ###   ########.fr       */
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
	return (1);
}

static	void		valid_cmp(t_node *n, int type)
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

static	int		all_cmp_valid(t_node n)
{
	if (n.cmp.ambient == false || n.cmp.color == false ||
	n.cmp.orientation == false ||n.cmp.radius == false ||
	n.cmp.position == false)
		return (-1);
	return (1);
}

int		stock_elements_cmp(char *s, t_tags tags, t_node n, int *i)
{
	int			r;
	char		*comp;
	char		*content;

	white_space(s, i);
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
	if (check_closing_elem(&s[*i], r, tags.components_c, i) < 0)
		return (-1);
	return (stock_elements_cmp(s, tags, n, i));
}