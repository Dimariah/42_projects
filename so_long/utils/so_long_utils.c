/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 11:51:56 by yiken             #+#    #+#             */
/*   Updated: 2024/04/21 14:32:19 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

void	fill_str(char *str, int num, int len)
{
	char	c;

	if (num > 9)
	{
		fill_str(str, num / 10, len - 1);
		fill_str(str, num % 10, len);
	}
	else
	{
		c = '0' + num;
		str[len] = c;
	}
}

void	get_num_len(int num, int *len)
{
	if (num > 9)
	{
		get_num_len(num / 10, len);
		get_num_len(num % 10, len);
	}
	else
		(*len)++;
}

char	*ft_itoa(int num)
{
	int		len;
	char	*str;

	len = 0;
	get_num_len(num, &len);
	str = malloc(len + 1);
	if (!str)
		return (0);
	fill_str(str, num, len - 1);
	str[len] = 0;
	return (str);
}

void	putnbr(int num)
{
	char	c;

	if (num > 9)
	{
		putnbr(num / 10);
		putnbr(num % 10);
	}
	else
	{
		c = '0' + num;
		write(1, &c, 1);
	}
}

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
