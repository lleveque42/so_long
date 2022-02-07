/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:31:45 by lleveque          #+#    #+#             */
/*   Updated: 2022/02/07 14:02:20 by lleveque         ###   ########.fr       */
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
