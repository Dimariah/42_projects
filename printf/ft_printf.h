/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:48:00 by yiken             #+#    #+#             */
/*   Updated: 2023/12/19 18:21:44 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int	ft_putchar(const char c);
int	ft_putptr(uintptr_t n);
int	ft_putnbr(int n);
int	ft_put_uint(unsigned int n);
int	ft_put_hexa(unsigned int n, const char c);
int	ft_printf(const char *format, ...);

#endif