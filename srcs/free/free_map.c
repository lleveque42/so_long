/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:05:14 by lleveque          #+#    #+#             */
/*   Updated: 2022/02/07 10:22:58 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	free_map(t_mlx *mlx)
{
	int	i;

	i = 0;
	if (!mlx->map)
		return (0);
	while (mlx->map[i])
	{
		free(mlx->map[i]);
		i++;
	}
	free(mlx->map);
	return (0);
}
