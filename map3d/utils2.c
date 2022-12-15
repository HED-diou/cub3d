/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramadan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:06:37 by nramadan          #+#    #+#             */
/*   Updated: 2022/09/15 16:08:59 by nramadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	check_space_beween(char *str)
{
	int	a;
	int	b;

	a = 0;
	while (str[a])
	{
		b = a;
		while (str[b] && !is_space(str[b]))
			b++;
		if (a > 0 && b > a && is_alpha(str[a - 1]) && is_alpha(str[b]))
			exit_error();
		a++;
	}
}

void	count_colors(char *str)
{
	int	a;
	int	b;

	a = 0;
	b = 1;
	while (str[a])
	{
		if (str[a] == ',')
			b++;
		if (b > 3)
			exit_error();
		a++;
	}
}

void	comma_error(char *str, int a)
{
	while (str[a] && is_space(str[a]) == 0)
		a++;
	if (!str[a] || str[a] == ',')
		exit_error();
}
