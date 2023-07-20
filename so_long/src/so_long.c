/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allam <allam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:56:54 by abali             #+#    #+#             */
/*   Updated: 2023/06/10 20:29:31 by allam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_all	*all;

	if (argc == 2)
	{
		if (checkber(argv[1]) != 1)
			ft_putendl_fd("Invalid map file (<name>.ber)", 2);
		all = all_initialize(argv[1]);
		graph(all);
		mlx_hook(all->mlx_win, 2, 1L << 0, press, all);
		mlx_hook(all->mlx_win, 3, 1L << 1, release, all);
		mlx_hook(all->mlx_win, 17, 0, destroy_hook, all);
		mlx_loop(all->mlx);
	}
	else
	{
		ft_putendl_fd("Invalid number of arguments", 2);
	}
	return (0);
}
