/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramadan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:24:17 by nramadan          #+#    #+#             */
/*   Updated: 2022/09/16 16:50:45 by nramadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../cub3d.h"

int	is_accessible(t_cube *game, t_cor obj)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	get_square(game, &b, &a, obj);
	if (game->map[a][b] == '1')
		return (0);
	return (1);
}

int	check_colusion(t_cube *game, t_cor obj)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	reverse_check(game, &b, &a, obj);
	if (game->map[a][b] == '1')
		return (1);
	reverse(game, &b, &a, obj);
	if (game->map[a][b] == '1')
		return (1);
	return (0);
}

int	half_check_move(t_cube *game, t_cor obj, int s)
{
	t_cor	temp;

	temp.x = obj.x - s;
	temp.y = obj.y;
	if (!is_accessible(game, temp))
		return (0);
	temp.x = obj.x;
	temp.y = obj.y - s;
	if (!is_accessible(game, temp))
		return (0);
	temp.x = obj.x - s;
	if (!is_accessible(game, temp))
		return (0);
	return (1);
}

int	check_move(t_cube *game, t_cor obj, int s)
{
	t_cor	temp;

	if (!is_accessible(game, obj))
		return (0);
	temp.x = obj.x + s * 2;
	temp.y = obj.y;
	if (!is_accessible(game, temp))
		return (0);
	temp.x = obj.x;
	temp.y = obj.y + s * 2;
	if (!is_accessible(game, temp))
		return (0);
	temp.x = obj.x + s * 2;
	if (!is_accessible(game, temp))
		return (0);
	return (half_check_move(game, obj, s));
}

int	allow_move(t_cube *game, t_cor obj, int s)
{
	int	a;

	a = 0;
	while (a <= s)
	{
		if (check_move(game, obj, a) == 0)
			return (0);
		a++;
	}
	return (1);
}
