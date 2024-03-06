/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:40:41 by yiken             #+#    #+#             */
/*   Updated: 2023/12/19 18:03:56 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_nbr(int n, int *count)
{
	long	nb;

	nb = n;
	if (n < 0)
	{
		*count = ft_putchar('-');
		nb = -nb;
	}
	if (*count != -1)
	{
		if (nb < 10)
		{
			if (ft_putchar('0' + nb) == -1)
				*count = -1;
			else
				*count = *count + 1;
		}
		else
		{
			ft_print_nbr(nb / 10, count);
			ft_print_nbr(nb % 10, count);
		}
	}
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	ft_print_nbr(n, &count);
	return (count);
}
