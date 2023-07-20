/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allam <allam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:59:06 by abali             #+#    #+#             */
/*   Updated: 2023/06/10 20:25:44 by allam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# include <fcntl.h>
# include <string.h>
# include <errno.h>

typedef struct TwoD_Cord
{
	int				x;
	int				y;
}	t_cord;

typedef struct game_status
{
	int				coll_number;
	int				exit_number;
	int				player_number;
	int				**map;
	int				imageheight;
	int				imagewidth;
	t_cord			player;
	t_cord			exit;
	t_cord			*coll;
	int				up;
	int				down;
	int				left;
	int				right;
	int				move;
	int				collected_number;
	int				index;
}	t_status;

typedef struct mainstruct
{
	void			*mlx;
	void			*mlx_win;
	void			*mlx_img;
	t_status		*status;
	void			*player;
	void			*exit;
	void			*coll;
	void			*wall;
	void			*ground;
}				t_all;

int				checkvalidpath(t_all *all);
int				checkvalidpathobject(t_all *all);
int				checkber(char *name);
t_all			*all_initialize(char *name);
int				press(int key, t_all *all);
int				release(int key, t_all *all);
int				destroy_hook(int key, t_all *all);
void			all_destroy(t_all *all, char *errmsg, int errnum);
void			status_destroy(t_status *status);
void			kill(char *errmsg, int errnum);
void			map_initialize(t_all *all, char *name);
void			map_dimensions(t_all *all, char *file);
void			map_get(t_all *all, char *file);
void			check_map(t_all *all, char *file);
void			build_map_matrix(t_all *all, char *file);
void			modify(t_all *all);
void			move_up(t_all *all, int x, int y);
void			move_down(t_all *all, int x, int y);
void			move_left(t_all *all, int x, int y);
void			move_right(t_all *all, int x, int y);
void			graph(t_all *all);

#endif
