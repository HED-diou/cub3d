/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramadan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:47:14 by nramadan          #+#    #+#             */
/*   Updated: 2022/09/15 15:48:16 by nramadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	is_new_line(char *str)
{
	int	a;

	a = 0;
	while (str && str[a] && str[a] == ' ')
		a++;
	if (str[a] == 0)
		return (1);
	return (0);
}

int	is_alpha(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	free_two_d(char **str)
{
	int	a;

	a = 0;
	while (str[a])
	{
		free(str[a]);
		a++;
	}
	free(str);
}

void	delete_new_line(char ***str)
{
	int	a;

	a = 0;
	while ((*str)[a])
	{
		if (is_new_line((*str)[a]) == 1)
		{
			delete_line(str, a);
			if (a >= 1)
				a--;
		}
		a++;
	}
}

int	big_line(char *str)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	c = 0;
	while (str && str[a])
	{
		b = 0;
		while (str[a] && str[a] != '\n')
		{
			a++;
			b++;
		}
		if (b > c)
			c = b;
		if (str[a] == '\n')
			a++;
	}
	return (c);
}
