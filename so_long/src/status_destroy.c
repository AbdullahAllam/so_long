/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allam <allam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:57:37 by abali             #+#    #+#             */
/*   Updated: 2023/06/10 20:14:59 by allam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	status_destroy(t_status *status)
{
	int				i;

	if (status != 0)
	{
		if (status->coll != 0)
			free(status->coll);
		if (status->map != 0)
		{
			i = 0;
			while (i < status->imageheight)
				free(status->map[i++]);
			free(status->map);
		}
		free(status);
	}
}
