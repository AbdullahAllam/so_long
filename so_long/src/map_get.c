/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:56:45 by abali             #+#    #+#             */
/*   Updated: 2023/06/10 18:56:47 by abali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	map_get(t_all *all, char *file)
{
	map_dimensions(all, file);
	check_map(all, file);
	all->status->coll
		= (t_cord *)malloc(sizeof(t_cord) * all->status->coll_number);
	if (all->status->coll == 0)
	{
		free(file);
		all_destroy(all, "no coll(): malloc()", errno);
	}
	all->status->map = (int **)malloc(sizeof(int *) * all->status->imageheight);
	if (all->status->map == 0)
	{
		free(file);
		all_destroy(all, "map_getting(): malloc()", errno);
	}
	build_map_matrix(all, file);
	if (checkvalidpath(all) == 0 || checkvalidpathobject(all) == 0)
	{
		free(file);
		all_destroy(all, "No valid path for one of the elements", 0);
	}
}
