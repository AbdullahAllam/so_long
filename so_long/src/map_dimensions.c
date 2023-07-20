/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dimensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allam <allam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:55:59 by abali             #+#    #+#             */
/*   Updated: 2023/06/10 20:09:39 by allam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	map_width(t_all *all, char *file)
{
	all->status->imagewidth = 0;
	while (file[all->status->imagewidth]
		&& file[all->status->imagewidth] != '\n')
		all->status->imagewidth++;
	if (all->status->imagewidth == 0 || file[all->status->imagewidth] == 0)
	{
		free(file);
		all_destroy(all, "map width file is invalid", 0);
	}
}

void	map_dimensions(t_all *all, char *file)
{
	int		i;
	int		j;

	map_width(all, file);
	all->status->imageheight = 1;
	i = all->status->imagewidth + 1;
	while (file[i] != 0)
	{
		j = 0;
		while (file[i + j] != 0 && file[i + j] != '\n')
			j++;
		if (all->status->imagewidth != j)
		{
			free(file);
			all_destroy(all, "map format is invalid", 0);
		}
		i += all->status->imagewidth + 1;
		all->status->imageheight++;
	}
}
