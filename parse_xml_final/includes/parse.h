/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 23:14:56 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/19 05:57:58 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

/*
**-----------------------------{structers}---------------------
*/

typedef struct	s_name_tags
{
	char *elements_o[6];
	char *elements_c[6];
	char *components_c[9];
	char *components_o[9];
}				t_tags;

typedef struct	s_ocomponent
{
	bool	position;
	bool	color;
	bool	orientation;
	bool	radius;
	bool	ambient;
}				o_component;

typedef struct	s_lcomponent
{
	bool	position;
	bool	color;
	bool	intensity;
}				l_component;

typedef struct	s_ccomponent
{
	bool	origin;
	bool	look_at;
	bool	fov;
}				c_component;

typedef struct	s_node
{
	int				type;
	o_component		cmp;
	c_component		cam;
	l_component		lit;
}				t_node;

/*
** ------------------------------{****}-------------------------
*/
int				parse(char *file, t_rt *rt);
char			*load_file(char *path);
char			*get_tag(char *s, int *i);
int				white_space(char *s, int *i);
void			*new_object(int type);
void			add_front(t_rt **head, void *new, int type);
/*
** ------------------------------{Init}-------------------------
*/

t_rt			*init_rt(bool save);
t_tags			init_tab_tags(void);
t_node			init_node(void);

/*
** ------------------------------{Free}-------------------------
*/

void			free_rt(t_rt **rt);
void			destroy(t_error type);

/*
** ------------------------------{Check}-------------------------
*/

int				check_openning_elem(char *s, char **tab);
int				check_closing_elem(char *s, int n, char **tab, int *i);

/*
** ------------------------------{****}-------------------------
*/

/*
**{--------------------------------------------------------------}
*/


#endif