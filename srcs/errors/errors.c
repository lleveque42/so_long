/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:31:45 by lleveque          #+#    #+#             */
/*   Updated: 2022/01/20 18:17:36 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	no_xpm(void)
{
	printf("Error\n--------------------\nXPM files not found.\n");
	return (0);
}

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
