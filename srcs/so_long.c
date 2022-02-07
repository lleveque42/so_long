/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:38:34 by lleveque          #+#    #+#             */
/*   Updated: 2022/02/07 11:39:26 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_exit(t_mlx *mlx)
{
	mlx_clear_window(mlx->ptr, mlx->win);
	mlx_destroy_window(mlx->ptr, mlx->win);
	mlx_destroy_display(mlx->ptr);
	free_map(mlx);
	free(mlx->ptr);
	exit (0);
}

int	test_xpm_files(void)
{
	if (open("sprites/collectibles.xpm", O_RDONLY) <= -1)
		return (1);
	else if (open("sprites/door_closed.xpm", O_RDONLY) <= -1)
		return (1);
	else if (open("sprites/door_opened.xpm", O_RDONLY) <= -1)
		return (1);
	else if (open("sprites/ground.xpm", O_RDONLY) == -1)
		return (1);
	else if (open("sprites/player.xpm", O_RDONLY) == -1)
		return (1);
	else if (open("sprites/player_back.xpm", O_RDONLY) == -1)
		return (1);
	else if (open("sprites/player_right.xpm", O_RDONLY) == -1)
		return (1);
	else if (open("sprites/player_left.xpm", O_RDONLY) == -1)
		return (1);
	else if (open("sprites/wall.xpm", O_RDONLY) == -1)
		return (1);
	return (0);
}

void	init_mlx(t_mlx *mlx)
{
	mlx->ptr = NULL;
	mlx->win = NULL;
	mlx->map = NULL;
	mlx->sprites.height = 64;
	mlx->sprites.width = 64;
	mlx->height = 0;
	mlx->width = 0;
	mlx->moves = 0;
	mlx->letters.c = 0;
	mlx->letters.p = 0;
	mlx->letters.e = 0;
}

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac != 2)
		return (no_input());
	init_mlx(&mlx);
	if (test_xpm_files())
		return (no_xpm());
	if (parse_map(&mlx, av[1]))
		return (free_map(&mlx));
	init_window(&mlx);
	mlx_key_hook(mlx.win, &keyhook, &mlx);
	mlx_hook(mlx.win, 17, 17, &ft_exit, &mlx);
	mlx_loop(mlx.ptr);
}
