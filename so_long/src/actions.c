/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allam <allam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:55:17 by abali             #+#    #+#             */
/*   Updated: 2023/06/10 20:14:28 by allam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	press(int key, t_all *all)
{
	if (key == 53)
		all_destroy(all, 0, 0);
	if (key == 13)
		all->status->up = 1;
	if (key == 1)
		all->status->down = 1;
	if (key == 0)
		all->status->left = 1;
	if (key == 2)
		all->status->right = 1;
	modify(all);
	return (0);
}

int	release(int key, t_all *all)
{
	if (key == 13)
		all->status->up = 0;
	if (key == 1)
		all->status->down = 0;
	if (key == 0)
		all->status->left = 0;
	if (key == 2)
		all->status->right = 0;
	modify(all);
	return (0);
}

int	destroy_hook(int key, t_all *all)
{
	(void)key;
	(void)all;
	kill(0, 0);
	return (0);
}
