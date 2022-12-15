/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_funs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramadan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:54:37 by nramadan          #+#    #+#             */
/*   Updated: 2022/09/15 15:57:00 by nramadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	get_vue(t_cube *game, t_cor *temp, t_cor o, float r)
{
	int	a;
	int	b;
	int	x;
	int	y;

	get_derection(&a, &b, r);
	get_square(game, &x, &y, o);
	x *= 32;
	y *= 32;
	if (o.x == x || a == -1)
		temp->x = (float)x;
	else
		temp->x = (float)x + (a * 32);
	if (o.y == y || b == -1)
		temp->y = (float)y;
	else
		temp->y = (float)y + (b * 32);
}

void	get_destance(t_cor *temp, t_cor *o, float r, t_cor s)
{
	int		a;
	int		b;
	t_cor	h;
	t_cor	v;

	h.x = temp->x;
	v.y = temp->y;
	get_derection(&a, &b, r);
	h.y = ((tan(r) * (h.x - o->x)) + o->y);
	v.x = (((v.y - o->y) / tan(r)) + o->x);
	if (ft_abs(h.x - s.x) <= ft_abs(v.x - s.x))
	{
		temp->x += (32 * a);
		o->x = h.x;
		o->y = h.y;
		o->f = 1;
	}
	else
	{
		temp->y += (32 * b);
		o->f = 2;
		o->x = v.x;
		o->y = v.y;
	}
}

int	check_lim(t_cube *game, t_cor temp, float r)
{
	int		a;
	int		b;
	t_cor	s;

	get_derection(&a, &b, r);
	if ((a == -1 && temp.x < 0) || (b == -1 && temp.y < 0))
		return (0);
	get_mapsize(game, &s);
	if (temp.x > s.x * 32 || temp.y > s.y * 32)
		return (0);
	return (1);
}

void	draw_colusion(t_cube *game, t_cor o, float r, int ray)
{
	t_cor	temp;
	t_cor	s;

	s.x = o.x;
	s.y = o.y;
	sample_angle(&r);
	get_vue(game, &temp, o, r);
	while (!check_colusion(game, o))
	{
		get_destance(&temp, &o, r, s);
		if (check_lim(game, temp, r) == 0)
			break ;
	}
	game->ray_r = r;
	render_wall(game, s, o, ray);
}
