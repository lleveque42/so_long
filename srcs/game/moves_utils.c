/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:45:59 by lleveque          #+#    #+#             */
/*   Updated: 2022/02/09 12:56:26 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	open_door(t_mlx *mlx)
{
	int	i;
	int	j;

	i = -1;
	if (mlx->letters.c <= 0)
	{
		while (mlx->map[++i])
		{
			j = 0;
			while (mlx->map[i][j])
			{
				if (mlx->map[i][j] == 'E')
				{
					mlx->img = mlx_xpm_file_to_image(mlx->ptr, \
"sprites/door_opened.xpm", &mlx->sprites.width, &mlx->sprites.height);
					if (!mlx->img)
						ft_exit(mlx, 0);
					mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img,
						j * 64, i * 64);
					mlx_destroy_image(mlx->ptr, mlx->img);
				}
				j++;
			}
		}
	}
}

int	get_j(t_mlx *mlx, int dir)
{
	int	j;

	if (dir == 1 || dir == 2)
		j = mlx->vector.x / 64;
	else if (dir == 3)
		j = (mlx->vector.x - 64) / 64;
	else
		j = (mlx->vector.x + 64) / 64;
	return (j);
}

int	get_i(t_mlx *mlx, int dir)
{
	int	i;

	if (dir == 1)
		i = (mlx->vector.y - 64) / 64;
	else if (dir == 2)
		i = (mlx->vector.y + 64) / 64;
	else
		i = mlx->vector.y / 64;
	return (i);
}
