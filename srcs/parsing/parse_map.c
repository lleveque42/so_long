/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:31:42 by lleveque          #+#    #+#             */
/*   Updated: 2022/01/18 18:33:08 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	get_map_height_and_width(t_mlx *mlx, char *input)
{
	int		fd;
	char	*buff;

	fd = open(input, O_RDONLY);
	if (fd < 0)
		return (0);
	buff = NULL;
	mlx->height = 0;
	while (1)
	{
		buff = get_next_line(fd);
		if (!buff)
			break ;
		free(buff);
		mlx->height++;
	}
	if (mlx->height < 3)
		return (0);
	return (mlx->height);
}

int	parse_input(t_mlx *mlx, char *input)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(input, O_RDONLY);
	mlx->map = malloc(sizeof(char *) * (mlx->height + 1));
	while (i <= mlx->height)
	{
		mlx->map[i] = get_next_line(fd);
		printf("%s\n", mlx->map[i]);
		free(mlx->map[i]);
		i++;
	}
	free(mlx->map);
	return (0);
}

// int	check_map(t_mlx *mlx, char *input)

int	parse_map(t_mlx *mlx, char *input)
{
	if (check_input(input))
		return (wrong_input());
	if (!get_map_height_and_width(mlx, input))
		return (not_valid_map());
	if (parse_input(mlx, input))
		return (1);
	return (0);
	(void)mlx;
}
