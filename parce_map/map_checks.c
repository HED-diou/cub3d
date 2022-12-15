/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramadan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 21:17:23 by nramadan          #+#    #+#             */
/*   Updated: 2022/09/15 21:23:33 by nramadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	*ft_fillelement(char ***str, int a, int b)
{
	char	*temp;

	while ((*str)[a][b] && is_space((*str)[a][b]) == 0)
		b++;
	temp = ft_strdup(&(*str)[a][b]);
	delete_line(str, a);
	return (temp);
}

void	check_exetention(char *str)
{
	int	j;

	j = ft_strlen(str) - 1;
	if (str[j] == 'b' && str[j - 1] == 'u' && str[j - 2] == 'c')
	{
		if (str[j - 3] == '.')
			return ;
	}
	exit_error();
}

void	check_number_player(char **str)
{
	int	c;
	int	i;
	int	j;

	c = 0;
	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (is_player(str[i][j]) == 1)
				c++;
			j++;
		}
		i++;
	}
	if (c != 1)
		exit_error();
}

void	delete_from_str(char **s1, char *s2)
{
	int		a;
	int		b;
	char	*tab;

	b = 0;
	tab = ft_strstr(*s1, s2);
	a = tab - *s1;
	b = a + ft_strlen(s2);
	while ((*s1)[b])
		(*s1)[a++] = (*s1)[b++];
	(*s1)[a] = 0;
}

void	delete_element(t_cube *game, char **str)
{
	delete_from_str(str, (char *)game->c);
	delete_from_str(str, (char *)game->f);
	delete_from_str(str, (char *)game->we);
	delete_from_str(str, (char *)game->no);
	delete_from_str(str, (char *)game->so);
	delete_from_str(str, (char *)game->ea);
}
