/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramadan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:26:57 by nramadan          #+#    #+#             */
/*   Updated: 2022/09/16 15:31:35 by nramadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../cub3d.h"

int	is_element(char *s1, char *s2)
{
	int	a;

	a = 0;
	if (!s1[a] || !s1[a + 1])
		return (0);
	if (s1[a] == s2[a] && s1[a + 1] == s2[a + 1])
		return (1);
	return (0);
}

int	is_rgb(char *s, char c)
{
	if (!s[0] || !s[1])
		return (0);
	if (s[0] == c && is_space(s[1]) == 0)
		return (1);
	return (0);
}

void	set_null(t_cube *game)
{
	game->p.x = 0;
	game->press = 0;
	game->move = 0;
	game->mouse.x = 0;
	game->mouse.y = 0;
	game->n = 0;
	game->flag = 0;
	game->r = 0;
	game->p.y = 0;
	game->map = NULL;
	game->img = NULL;
	game->no = NULL;
	game->so = NULL;
	game->we = NULL;
	game->ea = NULL;
	game->f = NULL;
	game->c = NULL;
}

void	delete_line(char ***str, int a)
{
	char	*temp;

	temp = (*str)[a];
	while ((*str)[a + 1])
	{
		(*str)[a] = (*str)[a + 1];
		a++;
	}
	(*str)[a] = NULL;
	free(temp);
	temp = NULL;
}
