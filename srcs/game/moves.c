/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:33:46 by lleveque          #+#    #+#             */
/*   Updated: 2022/02/02 18:51:45 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_move(t_mlx *mlx, int dir)
{
	int	i;
	int	j;

	i = get_i(mlx, dir);
	j = get_j(mlx, dir);
	if (mlx->map[i][j] == '1')
		return (1);
	else if (mlx->map[i][j] == 'C')
	{
		mlx->letters.c--;
		mlx->map[i][j] = '0';
		return (0);
	}
	else if (mlx->map[i][j] == 'E')
	{
		if (mlx->letters.c <= 0)
			ft_exit(mlx);
		return (1);
	}
	else
		return (0);
}

int	move_up(t_mlx	*mlx)
{
	if (check_move(mlx, 1))
		return (0);
	mlx->img = mlx_xpm_file_to_image(mlx->ptr, "sprites/ground.xpm",
			&mlx->sprites.width, &mlx->sprites.height);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img,
		mlx->vector.x, mlx->vector.y);
	mlx_destroy_image(mlx->ptr, mlx->img);
	mlx->vector.y -= 64;
	mlx->img = mlx_xpm_file_to_image(mlx->ptr, "sprites/player_back.xpm",
			&mlx->sprites.width, &mlx->sprites.height);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img,
		mlx->vector.x, mlx->vector.y);
	mlx_destroy_image(mlx->ptr, mlx->img);
	mlx->moves++;
	printf("You've done %d moves.\n", mlx->moves);
	return (1);
}

int	move_down(t_mlx	*mlx)
{
	if (check_move(mlx, 2))
		return (0);
	mlx->img = mlx_xpm_file_to_image(mlx->ptr, "sprites/ground.xpm",
			&mlx->sprites.width, &mlx->sprites.height);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img,
		mlx->vector.x, mlx->vector.y);
	mlx_destroy_image(mlx->ptr, mlx->img);
	mlx->vector.y += 64;
	mlx->img = mlx_xpm_file_to_image(mlx->ptr, "sprites/player.xpm",
			&mlx->sprites.width, &mlx->sprites.height);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img,
		mlx->vector.x, mlx->vector.y);
	mlx_destroy_image(mlx->ptr, mlx->img);
	mlx->moves++;
	printf("You've done %d moves.\n", mlx->moves);
	return (1);
}

int	move_left(t_mlx	*mlx)
{
	if (check_move(mlx, 3))
		return (0);
	mlx->img = mlx_xpm_file_to_image(mlx->ptr, "sprites/ground.xpm",
			&mlx->sprites.width, &mlx->sprites.height);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img,
		mlx->vector.x, mlx->vector.y);
	mlx_destroy_image(mlx->ptr, mlx->img);
	mlx->vector.x -= 64;
	mlx->img = mlx_xpm_file_to_image(mlx->ptr, "sprites/player_left.xpm",
			&mlx->sprites.width, &mlx->sprites.height);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img,
		mlx->vector.x, mlx->vector.y);
	mlx_destroy_image(mlx->ptr, mlx->img);
	mlx->moves++;
	printf("You've done %d moves.\n", mlx->moves);
	return (1);
}

int	move_right(t_mlx	*mlx)
{
	if (check_move(mlx, 4))
		return (0);
	mlx->img = mlx_xpm_file_to_image(mlx->ptr, "sprites/ground.xpm",
			&mlx->sprites.width, &mlx->sprites.height);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img,
		mlx->vector.x, mlx->vector.y);
	mlx_destroy_image(mlx->ptr, mlx->img);
	mlx->vector.x += 64;
	mlx->img = mlx_xpm_file_to_image(mlx->ptr, "sprites/player_right.xpm",
			&mlx->sprites.width, &mlx->sprites.height);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img,
		mlx->vector.x, mlx->vector.y);
	mlx_destroy_image(mlx->ptr, mlx->img);
	mlx->moves++;
	printf("You've done %d moves.\n", mlx->moves);
	return (1);
}
