/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:31:45 by lleveque          #+#    #+#             */
/*   Updated: 2022/02/14 14:26:29 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	no_xpm(void)
{
	printf("Error\nXPM files not found.\n");
	return (0);
}

int	no_input(void)
{
	printf("Error\nNo input file.\n");
	return (0);
}

int	wrong_input(void)
{
	printf("Error\nWrong input file.\n");
	return (1);
}

void	display_went_wrong(void)
{
	printf("Error\nDisplay went wrong.\n");
	exit (2);
}
