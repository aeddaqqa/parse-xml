/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:47:47 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/15 02:55:12 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_name_tags
{
	char *elements_o[6];
	char *elements_c[6];
	char *components_c[9];
	char *components_o[9];
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

typedef struct		s_light
{
	t_vect3			dir;
	t_point			pos;
	double			intensity;
	double			d;
	t_color			color;
	t_vect3			light_reflected;
	struct s_light	*next;
}					t_light;

typedef struct		s_cam
{
	t_point			o;
	t_vect3			l;
	t_vect3			up;
	double			fov;
	double			ratio;
	double			plan_h;
	double			plan_w;
	struct s_cam	*next;
}					t_cam;

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
	t_cam		*cameras;
	t_light		*lights;
}				t_rt;



#endif