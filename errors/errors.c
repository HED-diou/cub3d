/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramadan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:43:45 by nramadan          #+#    #+#             */
/*   Updated: 2022/09/15 15:45:03 by nramadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	elements_error(t_cube *game, char **str)
{
	int	a;
	int	b;

	a = 0;
	if (!game->ea || !game->no || !game->so || !game->we || \
			!game->c || !game->f)
		exit_error();
	while (str[a])
	{
		b = 0;
		while (str[a][b])
		{
			if (is_map(str[a][b]) == 0)
				exit_error();
			b++;
		}
		a++;
	}
}

void	map_error(char **str, char *temp)
{
	char	*tab;
	int		a;

	a = 0;
	tab = ft_strstr(temp, str[a]);
	while (tab && tab[a])
	{
		if (tab[a] == '\n' && (tab[a + 1] == 0 || tab[a + 1] == '\n'))
			exit_error();
		a++;
	}
}

void	check_boarder(char **strs, int a, int b)
{
	while (strs[0][b])
	{
		if (strs[0][b] != '1' && strs[0][b] != ' ')
			exit_error();
		b++;
	}
	while (strs[a])
	{
		b = ft_strlen(strs[a]) - 1;
		if ((strs[a][b] != '1' && strs[a][b] != ' ') ||
				(strs[a][0] != '1' && strs[a][0] != ' '))
			exit_error();
		a++;
	}
	b = 0;
	a--;
	while (strs[a][b])
	{	
		if (strs[a][b] != '1' && strs[a][b] != ' ')
			exit_error();
		b++;
	}
}

void	zero_suround(char **strs, int a, int b)
{
	if (strs[a - 1][b] == ' ' || strs[a + 1][b] == ' ' ||
			strs[a][b - 1] == ' ' || strs[a][b + 1] == ' ')
		exit_error();
}

void	valid_map(char *str, char *temp)
{
	int		a;
	int		b;
	char	*tab;
	char	**strs;

	a = 1;
	tab = ft_strstr(temp, str);
	strs = ft_split(tab, '\n', big_line(tab));
	check_boarder(strs, 0, 0);
	while (strs[a + 1])
	{
		b = 1;
		while (strs[a][b + 1])
		{
			if (strs[a][b] == '0' || is_player(strs[a][b]) == 1)
				zero_suround(strs, a, b);
			b++;
		}
		a++;
	}
	free_two_d(strs);
}
