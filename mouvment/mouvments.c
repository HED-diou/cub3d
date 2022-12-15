/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramadan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:30:20 by nramadan          #+#    #+#             */
/*   Updated: 2022/09/15 20:42:40 by nramadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	search_for_comp(t_cube *game, t_cor *obj, char c)
{
	int	a;
	int	b;

	a = 0;
	while (game->map[a])
	{
		b = 0;
		while (game->map[a][b])
		{
			if (game->map[a][b] == c)
			{
				obj->x = b * 32;
				obj->y = a * 32;
				return ;
			}
			b++;
		}
		a++;
	}
}

void	mouve_player(t_cube *game, t_cor temp)
{
	if (allow_move(game, temp, 2) == 0)
		return ;
	game->p.x = temp.x;
	game->p.y = temp.y;
	ft_shoot(game);
}

void	do_mouve(t_cube *game, t_cor temp, int key)
{
	if (key == 13)
	{
		temp.x += (cos(game->r) * 4);
		temp.y += (sin(game->r) * 4);
	}
	else if (key == 1)
	{
		temp.x -= (cos(game->r) * 4);
		temp.y -= (sin(game->r) * 4);
	}
	else if (key == 2)
	{
		temp.x += (cos(game->r - (PI / 2)) * 4);
		temp.y += (sin(game->r - (PI / 2)) * 4);
	}
	else if (key == 0)
	{
		temp.x += (cos(game->r + (PI / 2)) * 4);
		temp.y += (sin(game->r + (PI / 2)) * 4);
	}
	mouve_player(game, temp);
}

void	retation(t_cube *game, int key)
{
	if (key == 123 || key == 126)
		game->r -= PI / 32;
	else if (key == 124 || key == 125)
		game->r += PI / 32;
	ft_shoot(game);
}

int	ft_mouvement(int key, t_cube *game)
{
	t_cor	temp;

	temp.x = game->p.x;
	temp.y = game->p.y;
	round_angle(&game->r);
	game->move = 1;
	retation(game, key);
	do_mouve(game, temp, key);
	if (key == 49)
		game->flag = 1;
	else if (key == 53)
		exit(0);
	game->move = 0;
	return (0);
}
