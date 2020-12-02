/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utilfunc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 02:51:39 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/02 02:53:35 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/rt.h"

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

int		white_space(char *s, int *i)
{
	while (s[*i] && (s[*i] == ' ' || s[*i] == '\t' || s[*i] == '\n'))
		(*i)++;
	if (!s[*i])
		return (-1);
	return (1);
}