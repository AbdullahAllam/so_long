/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_initialize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:57:26 by abali             #+#    #+#             */
/*   Updated: 2023/06/10 18:57:28 by abali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static char	*file_initialize(t_all *all, int fd)
{
	char			*file;

	file = ft_calloc(1, 1);
	if (file == 0)
	{
		close(fd);
		all_destroy(all, "map_init(): ft_calloc()", errno);
	}
	return (file);
}

static void	file_process(t_all *all, char **file, char buffer[], int fd)
{
	char			*tmp;

	tmp = ft_strjoin(*file, buffer);
	free(*file);
	*file = tmp;
	if (*file == 0)
	{
		close(fd);
		all_destroy(all, "map_init(): ft_strjoin()", errno);
	}
}

static void	ft_read(t_all *all, char **file, char buffer[], int fd)
{
	int	numberread;

	numberread = 1;
	while (numberread != 0)
	{
		numberread = read(fd, buffer, 1024);
		if (numberread == -1)
		{
			free(*file);
			close(fd);
			all_destroy(all, "Error: ft_read map", errno);
		}
		else
		{
			buffer[numberread] = 0;
			file_process(all, file, buffer, fd);
		}
	}
}

void	map_initialize(t_all *all, char *name)
{
	int				fd;
	char			*file;
	char			buffer[1024 + 1];

	fd = open(name, O_RDONLY);
	if (fd == -1)
		all_destroy(all, "Can't access map file", errno);
	file = file_initialize(all, fd);
	ft_read(all, &file, buffer, fd);
	close(fd);
	map_get(all, file);
	free(file);
}
