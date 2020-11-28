/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:41:44 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/11/28 02:21:30 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/rt.h"

char	*read_file(char *path)
{
	char	*line;
	int		fd;
	char	*str;
	char	*tmp;

	fd = open(path, O_RDONLY);
	if (fd < 0 || opendir(path))
		return (NULL);
	str = ft_strnew(0);
	while (get_next_line(fd, &line))
	{
		/*
		** directory opendir..
		*/
		tmp = str;
		str = ft_strjoin(str, line);
		free(tmp);
		free(line);
	}
	return (str);
}

int		cmp_with_objects(char *s, char **tab)
{
	int		i;
	
	i = 0;
	while (i < 4)
	{
		if (!ft_strcmp(s, tab[i]))
			return (i);
		i++;
	}
	return (-1);
}

int		check_openning_elem(char *s)
{
	char	*tab[5];
	int		i;

	tab[0] = (char*)"<position>";
	tab[1] = (char*)"<color>";
	tab[2] = (char*)"<r_a>";
	tab[3] = (char*)"<ambient>";
	tab[4] = (char*)"<orientation>";
	i = 0;
	// ft_putendl("[");
	// ft_putendl(s);
	// ft_putendl("]");
	while (i < 4)
	{
		if (!ft_strcmp(s, tab[i]))
			return (i);
		i++;
	}
	return (-1);
}

int		check_closing_elem(char *s)
{
	char	*tab[5];
	int		i;

	tab[0] = (char*)"</position>";
	tab[1] = (char*)"</color>";
	tab[2] = (char*)"</r_a>";
	tab[3] = (char*)"</ambient>";
	tab[4] = (char*)"</orientation>";
	i = 0;
	// ft_putendl("[");
	// ft_putendl(s);
	// ft_putendl("]");
	while (i < 4)
	{
		if (!ft_strcmp(s, tab[i]))
			return (i);
		i++;
	}
	return (-1);
}

t_object		*stock_elements_cmp(char *s, t_node n)
{
	t_object	*obj;
	int			i;
	char		*comp;

	obj = NULL;
	i = 0;
	while (s[i] && s[i] != '>')
		i++;
	comp = ft_strsub(s, 0, i + 1);
	// check_openning_elem(comp);
	ft_putnbr(check_openning_elem(comp));
	// ft_putnbr(n.type);
	n.type = n.type;
	return (obj);
}

int		stock_elements(char *str, char **tab)
{
	t_node		node;
	int			i;
	char		*elem;

	node = init_node();
	if (!str || !*str)
		return (-1);	
	if (str[0] != '<')
		return (-1);
	i = 0;
	while (str[i] && str[i] != '>')
		i++;
	if (!str[i])
		return (-1);
	i++;
	elem = ft_strsub(str, 0, i);
	if ((node.type = cmp_with_objects(elem, tab)) < 0)
		return (-1);
	stock_elements_cmp(str + i, node);
	return (node.type);
}

int		check(char *str)
{
	int i, r;
	char *elem;
	char	*tab[4];

	tab[0] = (char*)"<plane>";
	tab[1] = (char*)"<sphere>";
	tab[2] = (char*)"<cylinder>";
	tab[3] = (char*)"<cone>";
	if (str[0] != '<')
		return (-1);
	i = 0;
	while (str[i] && str[i] != '>')
		i++;
	if (!str[i])
		return (-1);
	elem = ft_strsub(str, 0, i + 1);
	if (ft_strcmp(elem, "<scene>"))
		return (-1);
	if ((r = stock_elements(str + i + 1 , tab)) < 0)
		return (-1);
	return (r);
}

int		main(int ac, char **av)
{
	char *str;
	
	if (ac == 2)
	{
		str = read_file(av[1]);
		if (!str)
			destroy(OPEN_FILE);
		if (!*str)
			destroy(EMPTY_FILE);
		printf("\n[-------------------%d------------------]\n", check(str));
	}
	return (0);
}
