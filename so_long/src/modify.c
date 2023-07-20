/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allam <allam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:58:00 by abali             #+#    #+#             */
/*   Updated: 2023/06/10 20:14:53 by allam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	check_moved(t_all *all, int x, int y)
{
	if (all->status->player.x != x || all->status->player.y != y)
	{
		all->status->move++;
		ft_putnbr_fd(all->status->move, 1);
		ft_putendl_fd("", 1);
	}
}

static void	iscollectable(t_all *all)
{
	int				k;

	k = 0;
	while (k < all->status->coll_number)
	{
		if (all->status->coll[k].x == all->status->player.x
			&& all->status->coll[k].y == all->status->player.y)
		{
			all->status->coll[k].x = -1;
			all->status->coll[k].y = -1;
			all->status->collected_number++;
		}
		k++;
	}
}

void	modify(t_all *all)
{
	int				old_x;
	int				old_y;

	old_x = all->status->player.x;
	old_y = all->status->player.y;
	if (all->status->up != 0)
		move_up(all, old_x, old_y);
	else if (all->status->down != 0)
		move_down(all, old_x, old_y);
	else if (all->status->left != 0)
		move_left(all, old_x, old_y);
	else if (all->status->right != 0)
		move_right(all, old_x, old_y);
	check_moved(all, old_x, old_y);
	iscollectable(all);
	graph(all);
	if (all->status->exit.x == all->status->player.x
		&& all->status->exit.y == all->status->player.y)
		if (all->status->coll_number == all->status->collected_number)
			all_destroy(all, 0, 0);
}
