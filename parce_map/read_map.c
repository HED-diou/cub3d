/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-diou <hed-diou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 10:06:01 by nramadan          #+#    #+#             */
/*   Updated: 2022/09/15 21:17:09 by nramadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	**get_map(char **str, int fd)
{
	char	**strs;
	char	*temp;
	int		a;
	int		b;

	temp = NULL;
	a = 1;
	b = 0;
	while (a == 1)
	{
		ft_realloc(&temp, 1);
		a = read(fd, temp + b, 1);
		b += a;
		temp[b] = 0;
	}
	strs = ft_split(temp, '\n', big_line(temp));
	delete_new_line(&strs);
	*str = temp;
	return (strs);
}

void	get_colors(t_cube *game, char ***strs)
{
	int	a;
	int	c;
	int	b;

	a = 0;
	c = 1;
	while ((*strs)[a] && c <= 2)
	{
		b = 0;
		while ((*strs)[a][b] && is_space((*strs)[a][b]) == 0)
			b++;
		if (!game->c && is_rgb(&(*strs)[a][b], 'C') == 1)
			game->c = ft_fillelement(strs, a, b + 1);
		b = 0;
		while ((*strs)[a][b] && is_space((*strs)[a][b]) == 0)
			b++;
		if (!game->f && is_rgb(&(*strs)[a][b], 'F') == 1)
			game->f = ft_fillelement(strs, a, b + 1);
		else
			a++;
		c++;
	}
}

void	get_elemets(t_cube *game, char ***str)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	c = 1;
	while ((*str)[a] && c <= 6)
	{
		b = 0;
		while ((*str)[a][b] && is_space((*str)[a][b]) == 0)
			b++;
		if (!game->no && is_element(&(*str)[a][b], "NO") == 1)
			game->no = ft_fillelement(str, a, b + 2);
		else if (!game->so && is_element(&(*str)[a][b], "SO") == 1)
			game->so = ft_fillelement(str, a, b + 2);
		else if (!game->we && is_element(&(*str)[a][b], "WE") == 1)
			game->we = ft_fillelement(str, a, b + 2);
		else if (!game->ea && is_element(&(*str)[a][b], "EA") == 1)
			game->ea = ft_fillelement(str, a, b + 2);
		else
			a++;
		c++;
	}
}

void	read_map(t_cube *game, char *str)
{
	char	*temp;
	char	**strs;
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd <= 0)
		exit_error();
	strs = get_map(&temp, fd);
	get_elemets(game, &strs);
	get_colors(game, &strs);
	elements_error(game, strs);
	check_exetention(str);
	check_number_player(strs);
	game->map = strs;
	delete_new_line(&game->map);
	set_space(game);
	delete_element(game, &temp);
	valid_map(game->map[0], temp);
	map_error(strs, temp);
	free(temp);
}
