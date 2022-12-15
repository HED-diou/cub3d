/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramadan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:40:35 by nramadan          #+#    #+#             */
/*   Updated: 2022/09/15 15:43:17 by nramadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../cub3d.h"

void	get_mapsize(t_cube *game, t_cor *obj)
{
	int	a;
	int	b;

	a = 0;
	obj->x = 0;
	while (game->map[a])
	{
		b = 0;
		while (game->map[a][b])
			b++;
		if (obj->x <= b)
			obj->x = b;
		a++;
	}
	obj->y = a;
}

t_img	*open_xpm(t_cube *game, char *str)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	img->img = mlx_xpm_file_to_image(game->init, str, &img->width, \
			&img->height);
	if (!img->img)
		exit_error();
	img->dis = mlx_get_data_addr (img->img, &img->bpp, &img->len, &img->end);
	free(str);
	return (img);
}

void	open_texture(t_cube *game)
{
	game->no = (t_img *)open_xpm(game, (char *)game->no);
	game->so = (t_img *)open_xpm(game, (char *)game->so);
	game->we = (t_img *)open_xpm(game, (char *)game->we);
	game->ea = (t_img *)open_xpm(game, (char *)game->ea);
}

int	ft_exit(void)
{
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_cor	obj;
	t_cube	game;

	if (ac != 2)
		exit_error();
	set_null(&game);
	read_map(&game, av[1]);
	search_player(&game, &game.p);
	convert_rgb(&game);
	game.erea = obj.y * obj.y / 4;
	game.init = mlx_init();
	game.win = mlx_new_window(game.init, 1280, 720, "game");
	spawn(&game);
	open_texture(&game);
	mlx_hook(game.win, 17, 0, ft_exit, &game);
	ft_shoot(&game);
	mlx_hook(game.win, 2, 1L << 1, ft_mouvement, &game);
	mlx_loop(game.init);
}
