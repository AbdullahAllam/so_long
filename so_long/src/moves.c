/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allam <allam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:56:08 by abali             #+#    #+#             */
/*   Updated: 2023/06/10 20:13:58 by allam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_up(t_all *all, int x, int y)
{
	if (all->status->map[y - 1][x] == 0)
		all->status->player.y -= 1;
}

void	move_down(t_all *all, int x, int y)
{
	if (all->status->map[y + 1][x] == 0)
		all->status->player.y += 1;
}

void	move_left(t_all *all, int x, int y)
{
	if (all->status->map[y][x - 1] == 0)
		all->status->player.x -= 1;
}

void	move_right(t_all *all, int x, int y)
{
	if (all->status->map[y][x + 1] == 0)
		all->status->player.x += 1;
}
