/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_xml.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farwila <farwila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 03:15:56 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/01 18:53:19 by farwila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/rt.h"

int		cmp_with_objects(char *s, char **tab)
{
	int		i;
	
	i = 0;
	while (i < 4)
	{
		if (!ft_strcmp(s, tab[i]))
			return (i);
		i++;
	}
	return (-1);
}

int		check_openning_elem(char *s, char **tab)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		if (!ft_strcmp(s, tab[i]))
			return (i);
		i++;
	}
	return (-1);
}

void		white_space(char *s, int *i)
{
	while (s[*i] && (s[*i] == ' ' || s[*i] == '\t' || s[*i] == '\n'))
		(*i)++;
} 

char		*get_tag(char *s, int *i)
{
	char	*tag;
	int		j;

	j = 0;
	if (!s || !s[j] || s[j] != '<')
		return (NULL);
	while (s[j] && s[j] != '>')
		j++;
	tag = ft_strsub(s, 0, ++j);
	*i += j;
	return (tag);
}

int		check_closing_elem(char *s, int n, char **tab, int *i)
{
	char	*tag;

	if (!(tag = get_tag(s, i)))
		return (-1);
	if (!ft_strcmp(tab[n], tag))
		return (1);
	return (-1);
}

char		*inner_text(char *s, int *j)
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


int		check_components_exist(t_node n, int type)
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

void		valid_cmp(t_node *n, int type)
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

int		stock_elements_cmp(char *s, t_tags tags, t_node n)
{
	int			i;
	int			r;
	char		*comp;
	char		*content;

	i = 0;
	white_space(s, &i);
	if (!(comp = get_tag(&s[i], &i)))
		return (-1);
	if (!ft_strcmp(comp, tags.elements_c[n.type]))
		return (1);
	ft_putendl(comp);
	if ((r = check_openning_elem(comp, tags.components_o)) < 0)
		return (-1);
	if ((check_components_exist(n, r)) == -1)
		return (-1);
	valid_cmp(&n, r);
	content = inner_text(&s[i], &i);
	ft_putendl(content);
	if (check_closing_elem(&s[i], r, tags.components_c, &i) < 0)
		return (-1);
	return (stock_elements_cmp(&s[i], tags, n));
}

int		stock_elements(char *str, t_tags tags)
{
	t_node		node;
	char		*elem;
	int			i;

	i = 0;
	node = init_node();
	white_space(&str[i], &i);
	elem = get_tag(&str[i], &i);
	if ((node.type = cmp_with_objects(elem, tags.elements_o)) < 0)
		return (-1);
	if ((stock_elements_cmp(str + i, tags, node)) < 0)
		return (-1);
	return (node.type);
}

int		check(char *str)
{
	int		i,r;
	char	*elem;
	t_tags	tags;

	tags = init_tab_tags();
	if (str[0] != '<')
		return (-1);
	i = 0;
	while (str[i] && str[i] != '>')
		i++;
	if (!str[i])
		return (-1);
	elem = ft_strsub(str, 0, i + 1);
	if (ft_strcmp(elem, "<scene>"))
		return (-1);
	if ((r = stock_elements(str + i + 1 , tags)) < 0)
		return (-1);
	return (r);
}