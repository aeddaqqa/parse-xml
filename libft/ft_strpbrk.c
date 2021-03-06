/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 17:37:36 by nabouzah          #+#    #+#             */
/*   Updated: 2019/04/14 17:51:06 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	s = (char *)s1;
	while (s[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s[i] == s2[j])
				return (&s[i]);
			j++;
		}
		i++;
	}
	return (0);
}
