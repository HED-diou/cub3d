/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nramadan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:00:28 by nramadan          #+#    #+#             */
/*   Updated: 2022/09/15 16:06:23 by nramadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*px;

	px = img->dis + ((y * img->len) + (x * (img->bpp / 8)));
	*(int *)px = color;
}

void	check_axes(float r, int *x, int *y)
{
	float	s;
	float	c;

	c = cos(r);
	s = sin(r);
	if (c == 1 || c == -1)
		*y = 0;
	if (s == 1 || s == -1)
		*x = 0;
}

void	get_derection(int *x, int *y, float r)
{
	int	a;
	int	b;

	a = 1;
	b = 1;
	if ((r >= PI / 2 && r <= PI) || \
			(r <= -1 * PI && r >= -3 * (PI / 2)))
		a = -1;
	else if ((r >= PI && r <= 3 * PI / 2) || \
				(r <= -1 * (PI / 2) && r >= -1 * PI))
	{
		a = -1;
		b = -1;
	}
	else if ((r >= 3 * PI / 2 && r <= 2 * PI) || \
			(r <= 0 && r >= -1 * (PI / 2)))
		b = -1;
	*x = a;
	*y = b;
	check_axes(r, x, y);
}

float	ft_abs(float num)
{
	if (num < 0)
		num = -num;
	return (num);
}

int	ft_atoi(char *str)
{
	int	a;
	int	sign;
	int	num;

	a = 0;
	sign = 1;
	num = 0;
	while (str[a] == '\t' || str[a] == '\n' || str[a] == '\v' || \
			str[a] == '\f' || str[a] == '\r' || str[a] == ' ')
		a++;
	while (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			sign = -sign;
		a++;
	}
	while (str[a] >= '0' && str[a] <= '9')
	{
		num = (num * 10) + str[a] - '0';
		a++;
	}
	return (num * sign);
}
