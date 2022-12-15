/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramadan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:03:57 by nramadan          #+#    #+#             */
/*   Updated: 2022/09/16 16:04:38 by nramadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	set_space(t_cube *game)
{
	int	a;

	skip_space((char **)&game->no);
	skip_space((char **)&game->so);
	skip_space((char **)&game->we);
	skip_space((char **)&game->ea);
	skip_space((char **)&game->f);
	skip_space((char **)&game->c);
	a = 0;
	while (game->map[a])
		skip_space(&game->map[a++]);
}

t_img	*open_image(t_cube *game, int x, int y)
{
	t_img	*img;

	img = malloc(sizeof(t_cube));
	img->img = mlx_new_image(game->init, x, y);
	img->dis = mlx_get_data_addr (img->img, &img->bpp, &img->len, &img->end);
	return (img);
}

void	set_image(t_cube *game)
{
	mlx_clear_window(game->init, game->win);
	if (game->img != NULL)
	{
		mlx_destroy_image(game->init, game->img->img);
		free(game->img);
	}
	game->img = open_image(game, 2000, 1000);
	back_ground(game);
}

void	ft_shoot(t_cube *game)
{
	float	r;
	t_cor	o;
	float	a;
	int		ray;

	a = PI / 6;
	round_angle(&game->r);
	r = game->r - a;
	ray = 0;
	o.x = game->p.x + 2;
	o.y = game->p.y + 2;
	set_image(game);
	while (r <= game->r + a)
	{
		draw_colusion(game, o, r, ray);
		r += PI / 3840;
		ray++;
	}
	mlx_put_image_to_window(game->init, game->win, game->img->img, 0, 0);
}
