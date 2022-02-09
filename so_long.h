/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:04:41 by lleveque          #+#    #+#             */
/*   Updated: 2022/02/09 12:52:33 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include "gnl/get_next_line.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_check
{
	int	c;
	int	p;
	int	e;
}	t_check;

typedef struct s_sprites
{
	int	width;
	int	height;
}	t_sprites;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_mlx
{
	void		*ptr;
	void		*win;
	void		*img;
	char		**map;
	int			width;
	int			height;
	int			moves;
	t_sprites	sprites;
	t_vector	vector;
	t_check		letters;
	int			fd[9];
}	t_mlx;

int		parse_map(t_mlx *mlx, char *input);
int		no_input(void);
int		no_xpm(void);
int		wrong_input(void);
int		not_valid_map(void);
int		not_rectangular(void);
int		not_surrounded(void);
int		not_good_char(void);
void	display_went_wrong(void);
int		get_width(char *s);
int		check_input(char *input);
int		check_char(char *s, t_mlx *mlx);
int		count_letters(t_mlx *mlx);
int		check_walls(t_mlx *mlx);
int		init_window(t_mlx *mlx);
int		keyhook(int keycode, void *mlx);
int		get_i(t_mlx *mlx, int dir);
int		get_j(t_mlx *mlx, int dir);
int		move_down(t_mlx *mlx);
int		move_left(t_mlx *mlx);
int		move_up(t_mlx *mlx);
int		move_right(t_mlx *mlx);
void	open_door(t_mlx *mlx);
int		free_map(t_mlx *mlx);
int		ft_exit(t_mlx *mlx, int error);

#endif
