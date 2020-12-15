/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 02:48:58 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/15 02:42:58 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/rt.h"

int		cmp_with_objects(char *s, char **tab)
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

int		check_openning_elem(char *s, char **tab)
{
	int		i;

	i = 0;
	while (i < 9)
	{
		if (!ft_strcmp(s, tab[i]))
			return (i);
		i++;
	}
	return (-1);
}

int		check_closing_elem(char *s, int n, char **tab, int *i)
{
	char	*tag;

	if (!(tag = get_tag(s, i)))
		return (-1);
	if (!ft_strcmp(tab[n], tag))
	{
		ft_strdel(&tag);
		return (1);
	}
	ft_strdel(&tag);
	return (-1);
}