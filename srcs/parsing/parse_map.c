/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:31:42 by lleveque          #+#    #+#             */
/*   Updated: 2022/01/20 17:46:41 by lleveque         ###   ########.fr       */
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
		i++;
	}
	return (0);
}

int	check_map(t_mlx *mlx)
{
	int	i;
	int	previous_width;

	i = 0;
	previous_width = 0;
	while (mlx->map[i])
	{
		mlx->width = get_width(mlx->map[i]);
		if (mlx->width != previous_width && i != 0)
			return (not_rectangular());
		if (check_char(mlx->map[i], mlx))
			return (not_good_char());
		previous_width = mlx->width;
		i++;
	}
	return (0);
}

int	parse_map(t_mlx *mlx, char *input)
{
	if (check_input(input))
		return (wrong_input());
	if (!get_map_height_and_width(mlx, input))
		return (not_valid_map());
	parse_input(mlx, input);
	if (check_map(mlx))
		return (1);
	if (count_letters(mlx))
		return (not_good_char());
	if (check_walls(mlx))
		return (not_surrounded());
	return (0);
}
