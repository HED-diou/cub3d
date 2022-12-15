/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramadan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:45:31 by nramadan          #+#    #+#             */
/*   Updated: 2022/09/16 16:47:59 by nramadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	exit_error(void)
{
	write(2, "error\n", 6);
	exit(0);
}

int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (0);
	return (1);
}

int	is_map(char c)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W' || \
			c == '0' || c == '1' || c == ' ')
		return (1);
	return (0);
}

int	is_player(char c)
{
	if (c == 'N' || c == 'W' || c == 'E' || c == 'S')
		return (1);
	return (0);
}

void	skip_space(char **str)
{
	int	a;

	a = ft_strlen(*str) - 1;
	while (a > 0 && is_space((*str)[a]) == 0)
		a--;
	if (a >= 0)
		(*str)[a + 1] = 0;
}
