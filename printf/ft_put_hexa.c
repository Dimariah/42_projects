/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:50:32 by yiken             #+#    #+#             */
/*   Updated: 2023/12/19 18:06:25 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hexa(unsigned int n, const char *base, int *count)
{
	if (*count != -1)
	{
		if (n < 16)
		{
			if (ft_putchar(base[n]) == -1)
				*count = -1;
			else
				*count = *count + 1;
		}
		else
		{
			ft_print_hexa(n / 16, base, count);
			ft_print_hexa(n % 16, base, count);
		}
	}
}

int	ft_put_hexa(unsigned int n, const char c)
{
	int	count;

	count = 0;
	if (c == 'x')
		ft_print_hexa(n, "0123456789abcdef", &count);
	if (c == 'X')
		ft_print_hexa(n, "0123456789ABCDEF", &count);
	return (count);
}
