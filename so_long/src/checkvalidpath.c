/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkvalidpath.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allam <allam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:56:20 by abali             #+#    #+#             */
/*   Updated: 2023/07/16 19:54:17 by allam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	**initialize_path(t_all *all)
{
	int	**path;
	int	j;
	int	i;

	path = malloc(all->status->imageheight * sizeof(int *));
	if (!path)
		return (NULL);
	j = -1;
	while (++j < all->status->imageheight)
	{
		path[j] = malloc(all->status->imagewidth * sizeof(int));
		if (!path[j])
		{
			i = 0;
			while (i++ < j)
				free(path[i]);
			free(path);
			return (NULL);
		}
		i = 0;
		while (i++ < all->status->imagewidth)
			path[j][i] = 0;
	}
	return (path);
}

static void	freepath(int **path, t_all *all)
{
	int	j;

	j = 0;
	while (j < all->status->imageheight)
	{
		free(path[j]);
		j++;
	}
	free(path);
}

static int	find_path(t_all *all, int **path, int i, int j)
{
	int	**map;

	map = all->status->map;
	if (j == all->status->exit.y && i == all->status->exit.x)
	{
		path[j][i] = 1;
		return (1);
	}
	if (map[j][i] == 0 && path[j][i] == 0)
	{
		path[j][i] = 1;
		if (find_path(all, path, i, j + 1) == 1)
			return (1);
		if (find_path(all, path, i + 1, j) == 1)
			return (1);
		if (find_path(all, path, i, j - 1) == 1)
			return (1);
		if (find_path(all, path, i - 1, j) == 1)
			return (1);
		path[j][i] = 2;
	}
	return (0);
}

int	checkvalidpath(t_all *all)
{
	int	**path;
	int	flag;
	int	i;
	int	j;

	i = all->status->player.x;
	j = all->status->player.y;
	flag = 0;
	path = initialize_path(all);
	if (!(path))
		all_destroy(all, "Checking path allocation failed", 0);
	if (find_path(all, path, i, j) == 1)
		flag = 1;
	freepath(path, all);
	return (flag);
}
