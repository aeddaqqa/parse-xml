/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utilfunc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 02:51:39 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/12 04:17:09 by aeddaqqa         ###   ########.fr       */
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

t_object		*new_object()
{
	t_object	*new;

	if (!(new = malloc(sizeof(t_object))))
		return (NULL);
	new->type = -1;
	new->position = (t_point){0, 0, 0};
	new->orientation = (t_vect3){0, 0, 0};
	new->color = (t_color){0, 0, 0};
	new->r_a = 0;
	new->ambient = 0;
	new->next = NULL;
	return (new);
}

t_object		*add_front(t_object *head, t_object *new)
{
	if (new)
	{
		if (!head)
			head = new;
		else
		{
			new->next = head;
			head = new;
		}
	}
	return (head);
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