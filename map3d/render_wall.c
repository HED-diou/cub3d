/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramadan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:10:33 by nramadan          #+#    #+#             */
/*   Updated: 2022/09/15 17:29:19 by nramadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	back_ground(t_cube *game)
{
	int	b;
	int	a;

	a = 0;
	while (a <= 720)
	{
		b = 0;
		while (b <= 1280)
		{
			if (a <= 360)
				my_pixel_put(game->img, b, a, *(int *)game->c);
			else
				my_pixel_put(game->img, b, a, *(int *)game->f);
			b++;
		}
		a++;
	}
}

int	get_texture(t_img *txtur, float y, int ray)
{
	int		x;
	int		r;
	char	*px;

	r = round(y);
	ray = 0;
	r = r % (int)txtur->height;
	x = (int)txtur->y_s % txtur->width;
	px = txtur->dis + ((r * txtur->len) + (x * (txtur->bpp / 8)));
	return (*(int *)px);
}

int	calc_texture(t_img *texture, t_cor o, float y, int ray)
{
	int	color;

	color = 0;
	if (o.f == 1)
	{
		texture->y_s = fmod(o.y, 32) * 45;
		color = get_texture(texture, y, ray);
	}
	else if (o.f == 2)
	{
		texture->y_s = fmod(o.x, 32) * 45;
		color = get_texture(texture, y, ray);
	}
	return (color);
}

int	get_square_face(t_cube *game, t_cor o, float y, int ray)
{
	int	a;
	int	b;
	int	color;

	color = 0;
	get_derection(&a, &b, game->ray_r);
	if (o.f == 1 && a == 1)
		color = calc_texture(game->ea, o, y, ray);
	else if (o.f == 1 && a == -1)
		color = calc_texture(game->we, o, y, ray);
	else if (o.f == 2 && b == 1)
		color = calc_texture(game->so, o, y, ray);
	else if (o.f == 2 && b == -1)
		color = calc_texture(game->no, o, y, ray);
	return (color);
}

void	render_wall(t_cube *game, t_cor s, t_cor o, int ray)
{
	float	a;
	float	b;
	float	c;
	float	size;

	game->destance = sqrt(pow(o.x - s.x, 2) + pow(o.y - s.y, 2));
	game->destance *= cos(game->r - game->ray_r);
	size = round((720 * 15) / game->destance);
	a = (360 - size / 2);
	b = 720 - a;
	c = 0;
	if (b > 720)
	{
		b = 720;
		c = ft_abs(a) * (float)(game->destance / 15);
		a = 0;
	}
	while (a <= b)
	{
		my_pixel_put(game->img, ray, a, get_square_face(game, o, c, ray));
		c += (float)(game->destance / 15);
		a++;
	}
}
