/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:47:31 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/11 03:29:48 by aeddaqqa         ###   ########.fr       */
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
t_object		*stock_elements(char *str, t_tags tags, int *i);
int				stock_elements_cmp(char *s, t_tags tags, t_node n, int *i, t_object *obj);

/*
**				Init
*/
t_node			init_node(void);
t_tags			init_tab_tags(void);

t_object		*new_object();
t_object		*add_front(t_object *head, t_object *new);
void			print_object(t_object *obj);
int		get_point(char *s, t_point *p);
int		get_ori_vect(char *s, t_vect3 *orit);
int		get_color(char *s, t_color *color);
int		get_raduis_a(char *s, int type, double *r_a);

#endif