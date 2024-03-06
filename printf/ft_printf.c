/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:02:59 by yiken             #+#    #+#             */
/*   Updated: 2023/12/22 21:55:14 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	catch(int status, int *counter)
{
	*counter += status;
	return (status);
}

int	ft_putstr(const char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

int	ft_putarg(va_list args, int c)
{
	int		count;

	count = 0;
	if (c == 'c')
		count = ft_putchar(va_arg(args, int));
	if (c == 's')
		count = ft_putstr(va_arg(args, char *));
	if (c == 'p')
		count = ft_putptr(va_arg(args, uintptr_t));
	if (c == 'd' || c == 'i')
		count = ft_putnbr(va_arg(args, int));
	if (c == 'u')
		count = ft_put_uint(va_arg(args, unsigned int));
	if (c == 'x' || c == 'X')
		count = ft_put_hexa(va_arg(args, unsigned int), c);
	if (c == '%')
		count = write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *format, ...) //hello
{
	va_list	args;
	int		i;
	int		acc;

	va_start(args, format);
	acc = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (catch(ft_putarg(args, format[i + 1]), &acc) == -1)
				return (-1);
			if (format[i + 1] != 0)
				i++;
		}
		else if (catch(ft_putchar(format[i]), &acc) == -1)
			return (-1);
		i++;
	}
	va_end(args);
	return (acc);
}
