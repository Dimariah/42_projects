/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:16:37 by yiken             #+#    #+#             */
/*   Updated: 2023/12/01 15:14:22 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	if (n == 0)
		return (2);
	while (n)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static void	fill_str(int n, char *str, int i)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	if (nbr < 10)
		str[i] = '0' + nbr;
	else
	{
		fill_str(nbr % 10, str, i);
		fill_str(nbr / 10, str, i - 1);
	}
}

char	*ft_itoa(int n)
{
	char	*str;

	str = (char *)malloc(get_size(n) * sizeof(char));
	if (!str)
		return (0);
	str[get_size(n) - 1] = '\0';
	fill_str(n, str, get_size(n) - 2);
	return (str);
}
