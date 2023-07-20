/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_initialize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allam <allam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:57:06 by abali             #+#    #+#             */
/*   Updated: 2023/06/10 20:19:41 by allam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	status_init(t_all *all, char *name)
{
	all->status = (t_status *)malloc(sizeof(t_status));
	if (all->status == 0)
		all_destroy(all, "status_init(): malloc()", errno);
	all->status->map = 0;
	all->status->coll = 0;
	all->status->coll_number = 0;
	all->status->exit_number = 0;
	all->status->player_number = 0;
	all->status->move = 0;
	all->status->collected_number = 0;
	all->status->up = 0;
	all->status->down = 0;
	all->status->left = 0;
	all->status->right = 0;
	all->status->index = 0;
	map_initialize(all, name);
}

static void	window_init(t_all *all)
{
	all->mlx = mlx_init();
	if (all->mlx == 0)
		all_destroy(all, "Initilaization error: can't load mlx", 0);
	all->mlx_win = mlx_new_window(all->mlx, all->status->imagewidth * 40,
			all->status->imageheight * 40, "game window");
	if (all->mlx_win == 0)
		all_destroy(all, "Error: can't create a window", 0);
	all->mlx_img = mlx_new_image(all->mlx, all->status->imagewidth * 40,
			all->status->imageheight * 40);
	if (all->mlx_img == 0)
		all_destroy(all, "Error: can't create an image", 0);
}

static void	texture_load(t_all *all, void **img, char *path)
{
	int				width;
	int				height;

	*img = mlx_xpm_file_to_image(all->mlx, path, &width, &height);
	if (*img == 0)
		all_destroy(0, "texture_init(): can't load texture", 0);
}

static void	link_image(t_all *all)
{
	texture_load(all, &all->player, "./images/player.xpm");
	texture_load(all, &all->exit, "./images/exit.xpm");
	texture_load(all, &all->coll, "./images/teemo.xpm");
	texture_load(all, &all->wall, "./images/wall.xpm");
	texture_load(all, &all->ground, "./images/ground.xpm");
}

t_all	*all_initialize(char *name)
{
	t_all	*all;

	all = (t_all *)malloc(sizeof(t_all));
	if (all == 0)
		all_destroy(0, "all_init(): malloc()", errno);
	all->status = 0;
	all->mlx = 0;
	all->mlx_win = 0;
	all->mlx_img = 0;
	all->player = 0;
	all->exit = 0;
	all->coll = 0;
	all->wall = 0;
	all->ground = 0;
	status_init(all, name);
	window_init(all);
	link_image(all);
	return (all);
}
