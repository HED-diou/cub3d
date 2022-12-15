/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramadan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:36:34 by nramadan          #+#    #+#             */
/*   Updated: 2022/09/16 16:38:32 by nramadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	reverse(t_cube *game, int *x, int *y, t_cor obj)
{
	int	a;
	int	b;

	a = 0;
	while (game->map[a])
		a++;
	a--;
	while (a >= 0)
	{
		b = ft_strlen(game->map[a]);
		while (b >= 0)
		{
			if (obj.x >= (b * 32) && obj.x < ((b + 1) * 32) && \
					obj.y >= (a * 32) && obj.y < ((a + 1) * 32))
			{
				*x = b;
				*y = a;
				return ;
			}
			b--;
		}
		a--;
	}
}

void	get_square(t_cube *game, int *x, int *y, t_cor obj)
{
	int	a;
	int	b;

	a = 0;
	while (game->map[a])
	{
		b = 0;
		while (game->map[a][b])
		{
			if (obj.x >= (b * 32) && obj.x < ((b + 1) * 32) && \
					obj.y >= (a * 32) && obj.y < ((a + 1) * 32))
			{
				*x = b;
				*y = a;
				return ;
			}
			b++;
		}
		a++;
	}
}

void	reverse_check(t_cube *game, int *x, int *y, t_cor obj)
{
	int	a;
	int	b;

	a = 0;
	while (game->map[a])
	{
		b = 0;
		while (game->map[a][b])
		{
			if (obj.x >= (b * 32) && obj.x <= ((b + 1) * 32) && \
					obj.y >= (a * 32) && obj.y <= ((a + 1) * 32))
			{
				*x = b;
				*y = a;
				return ;
			}
			b++;
		}
		a++;
	}
}
