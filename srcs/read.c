/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 03:18:43 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/10 23:32:35 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/rt.h"

char	*read_file(char *path)
{
	char	*line;
	int		fd;
	char	*str;
	char	*tmp;
	DIR		*dirent;

	fd = open(path, O_RDONLY);
	dirent = NULL;
	if (fd < 0 || (dirent = opendir(path)))
	{
		if (dirent)
			closedir(dirent);
		return (NULL);
	}
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