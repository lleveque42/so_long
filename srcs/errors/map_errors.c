/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:00:59 by lleveque          #+#    #+#             */
/*   Updated: 2022/01/20 18:17:29 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	not_valid_map(void)
{
	printf("Error\n---------------\nMap isn't valid.\n");
	return (1);
}

int	not_rectangular(void)
{
	printf("Error\n-----------------------\nMap must be rectangular.\n");
	return (1);
}

int	not_good_char(void)
{
	printf("Error\n-----------------------------------------------------------\
-------------------------------------------\nMap must contain \
only 1, 0, X and at least one exit (E), one collectibles (C) and \
only one player (P).\n");
	return (1);
}

int	not_surrounded(void)
{
	printf("Error\n--------------------------------\nMap must be surrounded by \
walls.");
	return (1);
}
