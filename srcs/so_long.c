/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:38:34 by lleveque          #+#    #+#             */
/*   Updated: 2022/02/14 14:53:16 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	close_all(int	*fd)
{
	int	i;

	i = 0;
	while (i < 9)
	{
		if (fd[i] >= 0)
			close(fd[i]);
		i++;
	}
}

int	test_xpm_files(t_mlx *mlx)
{
	int	i;

	i = 0;
	mlx->fd[0] = open("sprites/collectibles.xpm", O_RDONLY);
	mlx->fd[1] = open("sprites/door_closed.xpm", O_RDONLY);
	mlx->fd[2] = open("sprites/door_opened.xpm", O_RDONLY);
	mlx->fd[3] = open("sprites/ground.xpm", O_RDONLY);
	mlx->fd[4] = open("sprites/player.xpm", O_RDONLY);
	mlx->fd[5] = open("sprites/player_back.xpm", O_RDONLY);
	mlx->fd[6] = open("sprites/player_right.xpm", O_RDONLY);
	mlx->fd[7] = open("sprites/player_left.xpm", O_RDONLY);
	mlx->fd[8] = open("sprites/wall.xpm", O_RDONLY);
	while (i < 9)
	{
		if (mlx->fd[i] == -1)
		{
			close_all(mlx->fd);
			return (1);
		}
		close(mlx->fd[i]);
		i++;
	}
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

int	ft_exit(t_mlx *mlx, int error)
{
	if (mlx->ptr && mlx->win)
		mlx_clear_window(mlx->ptr, mlx->win);
	if (mlx->ptr && mlx->img)
		mlx_destroy_window(mlx->ptr, mlx->win);
	if (mlx->ptr)
	{
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
	}
	free_map(mlx);
	if (!error)
		display_went_wrong();
	exit (0);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac != 2)
		return (no_input());
	init_mlx(&mlx);
	if (test_xpm_files(&mlx))
		return (no_xpm());
	if (parse_map(&mlx, av[1]))
		return (free_map(&mlx));
	init_window(&mlx);
	mlx_key_hook(mlx.win, &keyhook, &mlx);
	mlx_hook(mlx.win, 17, 17, &ft_exit, &mlx);
	mlx_loop(mlx.ptr);
}
