/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:47:18 by yiken             #+#    #+#             */
/*   Updated: 2023/12/12 14:46:32 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_uint(unsigned int n, int *count)
{
	if (*count != -1)
	{
		if (n < 10)
		{
			if (ft_putchar('0' + n) == -1)
				*count = -1;
			else
				*count = *count + 1;
		}
		else
		{
			ft_print_uint(n / 10, count);
			ft_print_uint(n % 10, count);
		}
	}
}

int	ft_put_uint(unsigned int n)
{
	int	count;

	count = 0;
	ft_print_uint(n, &count);
	return (count);
}
