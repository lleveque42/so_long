/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:32:34 by lleveque          #+#    #+#             */
/*   Updated: 2022/02/07 12:07:37 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_walls(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (mlx->map[0][i])
	{
		if (mlx->map[0][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (mlx->map[i])
	{
		if (mlx->map[i][0] != '1' || mlx->map[i][mlx->width - 1] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (mlx->map[mlx->height - 1][i])
	{
		if (mlx->map[mlx->height - 1][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	count_letters(t_mlx *mlx)
{
	if (mlx->letters.c == 0)
		return (1);
	else if (mlx->letters.p != 1)
		return (1);
	else if (mlx->letters.e == 0)
		return (1);
	return (0);
}

int	check_letters(char c)
{
	if (c == 'C')
		return (0);
	else if (c == 'P')
		return (0);
	else if (c == 'E')
		return (0);
	else if (c == '1')
		return (0);
	else if (c == '0')
		return (0);
	else
		return (1);
}

int	check_char(char *s, t_mlx *mlx)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 'C')
			mlx->letters.c++;
		else if (s[i] == 'E')
			mlx->letters.e++;
		else if (s[i] == 'P')
			mlx->letters.p++;
		if (check_letters(s[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_input(char *input)
{
	int		i;
	int		j;
	char	*to_find;
	int		fd;

	i = 0;
	j = 0;
	to_find = "reb.";
	fd = open(input, O_RDONLY);
	if (fd < 0)
		return (1);
	while (input[i])
		i++;
	i--;
	while (j < 4)
	{
		if (input[i] != to_find[j])
			return (1);
		j++;
		i--;
	}
	close(fd);
	return (0);
}
