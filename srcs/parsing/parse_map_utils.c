/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:32:34 by lleveque          #+#    #+#             */
/*   Updated: 2022/01/18 14:31:57 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

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
	return (0);
}

int	get_width(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
