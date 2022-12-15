/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-diou <hed-diou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 21:25:26 by nramadan          #+#    #+#             */
/*   Updated: 2022/09/17 16:10:10 by hed-diou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_realloc(char **str, int size)
{
	char	*p;
	int		a;
	int		len;

	a = 0;
	len = ft_strlen(*str) + 1;
	p = malloc(len + size + 1);
	if (!p)
		return ;
	while (*str && (*str)[a])
	{
		p[a] = (*str)[a];
		a++;
	}
	while (a < len + size)
		p[a++] = '\0';
	free(*str);
	*str = malloc(len + size + 1);
	a = -1;
	while (++a < len + size)
		(*str)[a] = p[a];
	free(p);
}

int	words(char *str, char c)
{
	int	a;
	int	b;

	a = 0;
	b = 1;
	while (str[a])
	{
		if (str[a] == c)
			b++;
		a++;
	}
	return (b);
}

int	ft_if(int b, int s)
{
	if (b != 0)
		s++;
	return (s);
}

char	**ft(char *str, char **strs, char c, int n)
{
	int	b;
	int	a;
	int	s;

	a = 0;
	s = 0;
	while (str[a])
	{
		b = 0;
		strs[s] = NULL;
		while (str[a] != c && str[a])
		{
			ft_realloc((strs + s), 1);
			strs[s][b++] = str[a++];
		}
		while (b <= n)
		{
			ft_realloc((strs + s), 1);
			strs[s][b++] = ' ';
		}
		a = skip_emptyline(str, a, c);
		s = ft_if(b, s);
	}
	strs[s] = NULL;
	return (strs);
}

char	**ft_split(char *str, char c, int n)
{
	char	**strs;

	strs = malloc(sizeof(char *) * (words(str, c) + 1));
	return (ft(str, strs, c, n));
}
