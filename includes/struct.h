/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:47:47 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/01 23:57:54 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_name_tags
{
	char *elements_o[4];
	char *elements_c[4];
	char *components_c[5];
	char *components_o[5];
}				t_tags;

typedef struct	s_vect3
{
	double		x;
	double		y;
	double		z;
}				t_vect3;

typedef	t_vect3 t_point;
typedef	t_vect3 t_color;

typedef struct	s_ocomponent
{
	bool	position;
	bool	color;
	bool	orientation;
	bool	radius;
	bool	ambient;
}				o_component;

typedef struct	s_node
{
	int				type;
	o_component		cmp;
}				t_node;

typedef struct	s_object
{
	t_type				type;
	t_point				position;
	t_color				color;
	t_vect3				orientation;
	double				r_a;
	double				ambient;
	struct s_object		*next;
}				t_object;

typedef struct	s_rt
{
	t_object	*objects;
}				t_rt;



#endif