/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:38:34 by lleveque          #+#    #+#             */
/*   Updated: 2022/01/25 17:52:43 by lleveque         ###   ########.fr       */
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

// int	test_xpm_files(void)
// {
// 	if (open("sprites/collectibles.xpm", O_RDONLY) <= -1)
// 		return (1);
// 	else if (open("sprites/ennemies.xpm", O_RDONLY) <= -1)
// 		return (1);
// 	else if (open("sprites/exit.xpm", O_RDONLY) == -1)
// 		return (1);
// 	else if (open("sprites/free_space.xpm", O_RDONLY) == -1)
// 		return (1);
// 	else if (open("sprites/player_01.xpm", O_RDONLY) == -1)
// 		return (1);
// 	else if (open("sprites/wall_light.xpm", O_RDONLY) == -1)
// 		return (1);
// 	else if (open("sprites/free_wall.xpm", O_RDONLY) == -1)
// 		return (1);
// 	return (0);
// }

void	init_mlx(t_mlx *mlx)
{
	mlx->sprites.height = 64;
	mlx->sprites.width = 64;
	mlx->height = 0;
	mlx->width = 0;
	mlx->moves = 0;
	mlx->letters.c = 0;
	mlx->letters.p = 0;
	mlx->letters.e = 0;
}

int	main(int ac, char **av, char **envp)
{
	t_mlx	mlx;

	if (ac != 2)
		return (no_input());
	(void)envp;
	if (envp[0] == NULL)
		return (0);
	init_mlx(&mlx);
	// if (test_xpm_files())
	// 	return (no_xpm());
	if (parse_map(&mlx, av[1]))
		return (0);
	init_window(&mlx);
	mlx_key_hook(mlx.win, &keyhook, &mlx);
	mlx_hook(mlx.win, 17, 17, &ft_exit, &mlx);
	mlx_loop(mlx.ptr);
}
