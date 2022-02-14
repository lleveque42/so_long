/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:00:59 by lleveque          #+#    #+#             */
/*   Updated: 2022/02/14 14:22:33 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	not_valid_map(void)
{
	printf("Error\nMap isn't valid.\n");
	return (1);
}

int	not_rectangular(void)
{
	printf("Error\nMap must be rectangular.\n");
	return (1);
}

int	not_good_char(void)
{
	printf("Error\nMap must contain only 1, 0, X and at least one exit (E), \
one collectibles (C) and only one player (P).\n");
	return (1);
}

int	not_surrounded(void)
{
	printf("Error\nMap must be surrounded by walls.\n");
	return (1);
}

int	too_big(void)
{
	printf("Error\nMap is too wide or too high.\n");
	return (1);
}
