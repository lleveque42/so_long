/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:54:29 by lleveque          #+#    #+#             */
/*   Updated: 2022/02/14 14:52:14 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	keyhook(int keycode, void *mlx)
{
	if (keycode == 65307)
		return (ft_exit(mlx, 1));
	else if (keycode == 119 || keycode == 65362)
		return (move_up(mlx));
	else if (keycode == 115 || keycode == 65364)
		return (move_down(mlx));
	else if (keycode == 97 || keycode == 65361)
		return (move_left(mlx));
	else if (keycode == 100 || keycode == 65363)
		return (move_right(mlx));
	return (0);
}
