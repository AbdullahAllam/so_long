/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allam <allam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:57:46 by abali             #+#    #+#             */
/*   Updated: 2023/06/10 20:16:44 by allam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	matrix_free(t_all *all, char *file, int **m, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(m[i++]);
	free(m);
	all->status->map = 0;
	free(file);
	all_destroy(all, "matrix error(): malloc()", errno);
}

static void	coord(t_all *all, char *file, int k, int *collect)
{
	if (file[k] == 'P')
	{
		all->status->player.x = k % (all->status->imagewidth + 1);
		all->status->player.y = k / (all->status->imagewidth + 1);
		file[k] = '0';
	}
	else if (file[k] == 'E')
	{
		all->status->exit.x = k % (all->status->imagewidth + 1);
		all->status->exit.y = k / (all->status->imagewidth + 1);
		file[k] = '0';
	}
	else if (file[k] == 'C')
	{
		all->status->coll[*collect].x = k % (all->status->imagewidth + 1);
		all->status->coll[*collect].y = k / (all->status->imagewidth + 1);
		file[k] = '0';
		(*collect)++;
	}
}

void	build_map_matrix(t_all *all, char *file)
{
	int				i;
	int				j;
	int				k;
	int				obj;

	obj = 0;
	k = 0;
	j = -1;
	while (++j < all->status->imageheight)
	{
		all->status->map[j] = malloc(sizeof(int) * all->status->imagewidth);
		if (all->status->map[j] == 0)
			matrix_free(all, file, all->status->map, j);
		i = 0;
		while (i < all->status->imagewidth)
		{
			coord(all, file, k, &obj);
			all->status->map[j][i++] = file[k++] - 48;
		}
		k++;
	}
}
