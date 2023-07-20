/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:55:47 by abali             #+#    #+#             */
/*   Updated: 2023/06/10 18:55:49 by abali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	isborder(t_all *all, int i)
{
	if (i < all->status->imagewidth
		|| i > (all->status->imagewidth + 1) * (all->status->imageheight - 1)
		|| i % (all->status->imagewidth + 1) == 0
		|| i % (all->status->imagewidth + 1) == all->status->imagewidth - 1)
		return (1);
	return (0);
}

static void	count_and_valid(t_all *all, char *file, int i)
{
	if (file[i] == 'P')
		all->status->player_number++;
	else if (file[i] == 'E')
		all->status->exit_number++;
	else if (file[i] == 'C')
		all->status->coll_number++;
	else if (file[i] == '1' || file[i] == '0')
		return ;
	else
	{
		free(file);
		all_destroy(all, "map content is invalid", 0);
	}
}

void	check_map(t_all *all, char *file)
{
	int				i;

	i = -1;
	while (file[++i] != 0)
	{
		if (file[i] == '\n')
			continue ;
		if (isborder(all, i))
		{
			if (file[i] != '1')
			{
				free(file);
				all_destroy(all, "map isn't surrounded by walls", 0);
			}
		}
		else
			count_and_valid(all, file, i);
	}
	if (all->status->player_number != 1
		|| all->status->exit_number != 1
		|| all->status->coll_number < 1)
	{
		free(file);
		all_destroy(all, "map configuration is invalid", 0);
	}
}
