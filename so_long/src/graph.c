/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allam <allam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:57:16 by abali             #+#    #+#             */
/*   Updated: 2023/06/10 20:22:30 by allam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	draw_square(t_all *all, void *img, int x, int y)
{
	mlx_put_image_to_window(all->mlx, all->mlx_win, img, x, y);
}

static void	items(t_all *all, int i, int j)
{
	int				k;

	if (all->status->exit.x == i && all->status->exit.y == j)
		draw_square(all, all->exit, i * 40, j * 40);
	k = -1;
	while (++k < all->status->coll_number)
		if (all->status->coll[k].x == i && all->status->coll[k].y == j)
			draw_square(all, all->coll, i * 40, j * 40);
	if (all->status->player.x == i && all->status->player.y == j)
		draw_square(all, all->player, i * 40, j * 40);
}

static void	full_image(t_all *all)
{
	int				i;
	int				j;

	j = 0;
	while (j < all->status->imageheight)
	{
		i = 0;
		while (i < all->status->imagewidth)
		{
			if (all->status->map[j][i] == 1)
				draw_square(all, all->wall, i * 40, j * 40);
			else
				draw_square(all, all->ground, i * 40, j * 40);
			items(all, i, j);
			i++;
		}
		j++;
	}
}

void	graph(t_all *all)
{
	mlx_clear_window(all, all->mlx_win);
	full_image(all);
}
