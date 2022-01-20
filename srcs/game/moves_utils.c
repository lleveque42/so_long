/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:45:59 by lleveque          #+#    #+#             */
/*   Updated: 2022/01/20 17:23:15 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

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
