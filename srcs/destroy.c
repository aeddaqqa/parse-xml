/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 01:15:34 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/11/28 01:17:08 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/rt.h"

void		destroy(t_error type)
{
	if (type == OPEN_FILE)
		ft_putstr("file open error\n");
	else if (type == EMPTY_FILE)
		ft_putstr("empty file\n");
	exit(1);
}