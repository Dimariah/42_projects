/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:30:34 by yiken             #+#    #+#             */
/*   Updated: 2023/12/19 18:00:43 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_ptr(uintptr_t n, int *count)
{
	char	*base;

	base = "0123456789abcdef";
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
			ft_print_ptr(n / 16, count);
			ft_print_ptr(n % 16, count);
		}
	}
}

int	ft_putptr(uintptr_t n)
{
	int	count;
	int	status;

	count = write(1, "0x", 2);
	if (count == -1)
		return (-1);
	if (n == 0)
	{
		status = write(1, "0", 1);
		if (status == -1)
			return (-1);
		count += status;
	}
	else
		ft_print_ptr(n, &count);
	return (count);
}
