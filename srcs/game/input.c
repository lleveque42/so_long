/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:54:29 by lleveque          #+#    #+#             */
/*   Updated: 2022/02/09 12:58:04 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	keyhook(int keycode, void *mlx)
{
	if (keycode == 65307)
		return (ft_exit(mlx, 1));
	else if (keycode == 119)
		return (move_up(mlx));
	else if (keycode == 115)
		return (move_down(mlx));
	else if (keycode == 97)
		return (move_left(mlx));
	else if (keycode == 100)
		return (move_right(mlx));
	return (0);
}
