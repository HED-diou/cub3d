/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramadan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:43:22 by nramadan          #+#    #+#             */
/*   Updated: 2022/09/15 20:44:18 by nramadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	sample_angle(float *r)
{
	int	a;

	a = 1;
	if (*r > 0)
		a = -1;
	while (ft_abs(*r) >= 2 * PI)
		*r += (a * 2 * PI);
}

int	skip_emptyline(char *str, int a, char c)
{
	while (str[a] && str[a] == c)
		a++;
	return (a);
}

void	round_angle(float *r)
{
	if (cos(*r) == 0)
		*r = 0;
}

void	check_player_error(t_cube *game, int a, int b)
{
	if (game->map[a][b] == 'N' && a - 1 >= 0 && game->map[a - 1][b])
	{
		game->p.x += 8;
		game->p.y += 8;
	}
}

void	search_player(t_cube *game, t_cor *p)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (game->map[a])
	{
		b = 0;
		while (game->map[a][b])
		{
			if (is_player(game->map[a][b]))
			{
				p->x = b * 32;
				p->y = a * 32;
				check_player_error(game, a, b);
				return ;
			}
			b++;
		}
		a++;
	}
}
