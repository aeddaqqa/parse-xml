/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utilfunc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 02:51:39 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/15 23:08:32 by aeddaqqa         ###   ########.fr       */
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

void		*new_object(int type)
{
	t_object	*n_obj;
	t_cam		*n_cam;
	t_light		*n_light;

	n_obj = NULL;
	n_cam = NULL;
	n_light = NULL;
	if (type == 4)
	{
		if (!(n_cam = malloc(sizeof(t_cam))))
			return (NULL);
		n_cam->fov = -1;
		n_cam->ratio = -1;
		n_cam->plan_h = -1;
		n_cam->plan_w = -1;
		n_cam->o = (t_point){0, 0, 0};
		n_cam->l = (t_vect3){0, 0, 0};
		n_cam->up = (t_color){0, 0, 0};
		n_cam->next = NULL;
		return (n_cam);
	}
	else if (type == 5)
	{
		if (!(n_light = malloc(sizeof(t_light))))
			return (NULL);
		n_light->d = -1;
		n_light->intensity = -1;
		n_light->dir = (t_vect3){0, 0, 0};
		n_light->light_reflected = (t_vect3){0, 0, 0};
		n_light->color = (t_color){0, 0, 0};
		n_light->pos = (t_point){0, 0, 0};
		n_light->next = NULL;
		return (n_light);
	}
	else
	{	
		if (!(n_obj = malloc(sizeof(t_object))))
			return (NULL);
		n_obj->type = -1;
		n_obj->position = (t_point){0, 0, 0};
		n_obj->orientation = (t_vect3){0, 0, 0};
		n_obj->color = (t_color){0, 0, 0};
		n_obj->r_a = 0;
		n_obj->ambient = 0;
		n_obj->next = NULL;
		return (n_obj);
	}
	return (NULL);
}

void		add_front_obj(t_object **head, t_object *new)
{
	if (new)
	{
		if (!*head)
			*head = new;
		else
		{
			new->next = *head;
			*head = new;
		}
	}
}
void		add_front_cam(t_cam **head, t_cam *new)
{
	if (new)
	{
		if (!*head)
			*head = new;
		else
		{
			new->next = *head;
			*head = new;
		}
	}
}
void		add_front_light(t_light **head, t_light *new)
{
	if (new)
	{
		if (!*head)
			*head = new;
		else
		{
			new->next = *head;
			*head = new;
		}
	}
}

void		print_object(t_object *obj)
{
	printf("type = {%d}\n", (int)obj->type);
	printf("position = {%lf,%lf,%lf}\n", obj->position.x, obj->position.y,obj->position.z);
	printf("color = {%lf,%lf,%lf}\n",obj->color.x, obj->color.y, obj->color.z);
	printf("orientation = {%lf,%lf,%lf}\n", obj->orientation.x, obj->orientation.y,obj->orientation.z);
	printf("raduis = %lf\n", obj->r_a);
	printf("ambient = %lf\n", obj->ambient);
}