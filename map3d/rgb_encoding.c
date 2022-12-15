/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_encoding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramadan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:07:41 by nramadan          #+#    #+#             */
/*   Updated: 2022/09/15 16:09:18 by nramadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	parce_color(char *str, int *b)
{
	char	*temp;
	int		a;
	int		c;

	a = 0;
	c = 0;
	temp = malloc(ft_strlen(str) + 1);
	while (str[a] && str[a] != ',')
	{
		if (!is_alpha(str[a]) && is_space(str[a]))
			exit_error();
		temp[a] = str[a];
		a++;
	}
	temp[a] = 0;
	*b += a;
	a = ft_atoi(temp);
	free(temp);
	return (a);
}

int	*get_int_value(char *str)
{
	int	*arr;
	int	a;
	int	b;

	a = 0;
	b = 0;
	arr = malloc(4 * 4);
	check_space_beween(str);
	count_colors(str);
	while (str[a])
	{
		while (str[a + 1] && is_space(str[a]) == 0)
			a++;
		comma_error(str, a);
		arr[b++] = parce_color(&str[a], &a);
		if (!str[a])
			break ;
		a++;
	}
	return (arr);
}

int	encode_rgb(int *arr)
{
	int	a;
	int	rgb;

	a = 0;
	rgb = ((arr[0] << 16) | (arr[1] << 8) | arr[2]);
	return (rgb);
}

void	num_protect(int *arr)
{
	int	a;

	a = 0;
	while (a <= 2)
	{
		if (arr[a] > 255)
			exit_error();
		if (arr[a] < 0)
			exit_error();
		a++;
	}
}

void	convert_rgb(t_cube *game)
{
	int	*arr2;
	int	*arr1;

	arr1 = get_int_value((char *)game->c);
	arr2 = get_int_value((char *)game->f);
	num_protect(arr1);
	num_protect(arr2);
	*(int *)game->c = encode_rgb(arr1);
	*(int *)game->f = encode_rgb(arr2);
	free(arr1);
	free(arr2);
}
