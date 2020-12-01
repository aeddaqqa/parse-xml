/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:47:31 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/01 03:20:58 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H


/*
**				Destroy
*/

void			destroy(t_error type);

/*
**				Read
*/

char			*read_file(char *path);

/*
**				Parse
*/

int				check(char *str);

/*
**				Init
*/
t_node			init_node(void);
t_tags			init_tab_tags(void);

#endif