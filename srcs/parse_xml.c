/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_xml.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 03:15:56 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/11 06:01:58 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/rt.h"

int		check(char *str, t_rt *rt)
{
	int		i;
	int		*z;
	char	*elem;
	t_tags	tags;
	t_object *obj;

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
	obj = NULL;
	if (!(obj = stock_elements(str + i + 1 , tags, z)))
	{
		free(z);
		return (-1);
	}
	*z = 0;
	rt->objects = obj;
	free(z);
	return (*z);
}