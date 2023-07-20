/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:56:20 by abali             #+#    #+#             */
/*   Updated: 2023/06/10 18:56:21 by abali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	all_destroy(t_all *all, char *errmsg, int errnum)
{
	if (all != 0)
	{
		if (all->ground != 0)
			mlx_destroy_image(all->mlx, all->ground);
		if (all->wall != 0)
			mlx_destroy_image(all->mlx, all->wall);
		if (all->coll != 0)
			mlx_destroy_image(all->mlx, all->coll);
		if (all->exit != 0)
			mlx_destroy_image(all->mlx, all->exit);
		if (all->player != 0)
			mlx_destroy_image(all->mlx, all->player);
		if (all->mlx_img != 0)
			mlx_destroy_image(all->mlx, all->mlx_img);
		if (all->mlx_win != 0)
			mlx_destroy_window(all->mlx, all->mlx_win);
		if (all->mlx != 0)
			free(all->mlx);
		if (all->status != 0)
			status_destroy(all->status);
		free(all);
	}
	kill(errmsg, errnum);
}
