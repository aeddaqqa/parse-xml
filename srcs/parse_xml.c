/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_xml.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farwila <farwila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 03:15:56 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/10 16:06:30 by farwila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/rt.h"

int		check(char *str)
{
	int		i;
	int		r;
	int		*z;
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
	{
		free(elem);
		return (-1); 
	}
	free(elem);
	z = malloc(sizeof(int));
	*z = 0;
	if ((r = stock_elements(str + i + 1 , tags, z)) < 0)
	{
		free(z);
		return (-1);
	}
	// else
	free(z);
	return (r);
}