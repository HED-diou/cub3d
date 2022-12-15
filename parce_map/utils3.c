/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramadan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:32:02 by nramadan          #+#    #+#             */
/*   Updated: 2022/09/16 16:50:23 by nramadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../cub3d.h"

int	ft_strlen(char *str)
{
	int	a;

	a = 0;
	if (!str)
		return (0);
	while (str[a])
		a++;
	return (a);
}

void	enitial_angle(t_cube *game, int *x, int *y)
{
	int	a;
	int	b;

	a = 0;
	while (game->map[a])
	{
		b = 0;
		while (game->map[a][b])
		{
			if (is_player(game->map[a][b]))
			{
				*x = a;
				*y = b;
				return ;
			}
			b++;
		}
		a++;
	}
}

void	spawn(t_cube *game)
{
	int	a;
	int	b;

	enitial_angle(game, &a, &b);
	if (game->map[a][b] == 'S')
		game->r = PI / 2;
	if (game->map[a][b] == 'W')
		game->r = PI;
	if (game->map[a][b] == 'E')
		game->r = 0;
	if (game->map[a][b] == 'N')
		game->r = PI / -2;
}

char	*ft_strstr(char *s1, char *s2)
{
	int	a;
	int	b;

	a = 0;
	if (!s1 || !s2 || !s1[a] || !s2[a])
		return (s1);
	while (s1[a])
	{
		b = 0;
		while (s2[b] == s1[a + b])
		{
			b++;
			if (s2[b] == 0)
				return (s1 + a);
		}
		a++;
	}
	return (NULL);
}

char	*ft_strdup(char *str)
{
	unsigned int	x;
	char			*p;

	x = 0;
	while (str[x])
		x++;
	p = (char *)malloc(sizeof(char) * x + 1);
	if (!p)
		return (NULL);
	x = 0;
	while (str[x])
	{
		p[x] = str[x];
		x++;
	}
	p[x] = '\0';
	return (p);
}
