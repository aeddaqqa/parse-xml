/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:47:31 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/02 02:56:21 by aeddaqqa         ###   ########.fr       */
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
int				cmp_with_objects(char *s, char **tab);
int				check_openning_elem(char *s, char **tab);
int				check_closing_elem(char *s, int n, char **tab, int *i);
int				white_space(char *s, int *i);
char			*get_tag(char *s, int *i);
int				check(char *str);
int				stock_elements(char *str, t_tags tags, int *i);
int				stock_elements_cmp(char *s, t_tags tags, t_node n, int *i);

/*
**				Init
*/
t_node			init_node(void);
t_tags			init_tab_tags(void);

#endif