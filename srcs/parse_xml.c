/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_xml.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 03:15:56 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/01 06:13:38 by aeddaqqa         ###   ########.fr       */
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
	white_space(s, i);
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


int		stock_elements_cmp(char *s, t_tags tags, t_node n)
{
	int			i;
	int			r;
	char		*comp;
	char		*content;

	i = 0;
	if (!(comp = get_tag(s, &i)))
		return (-1);
	if (!ft_strcmp(comp, tags.elements_c[n.type]))
		return (1);
	ft_putendl(comp);
	if ((r = check_openning_elem(comp, tags.components_o)) < 0)
		return (-1);
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