/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:00:59 by lleveque          #+#    #+#             */
/*   Updated: 2022/01/18 14:25:35 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	no_input(void)
{
	printf("Error\n--------------\nNo input file.\n");
	return (0);
}

int	wrong_input(void)
{
	printf("Error\n-----------------\nWrong input file.\n");
	return (1);
}

int	not_valid_map(void)
{
	printf("Error\n---------------\nMap isn't valid.\n");
	return (1);
}
