/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:57:27 by yiken             #+#    #+#             */
/*   Updated: 2023/12/11 12:48:39 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	c;

	if (fd != -1)
	{
		nb = n;
		if (nb < 0)
		{
			write(fd, "-", sizeof(char));
			nb = -nb;
		}
		if (nb < 10)
		{
			c = '0' + nb;
			write(fd, &c, sizeof(char));
		}
		else
		{
			ft_putnbr_fd(nb / 10, fd);
			ft_putnbr_fd(nb % 10, fd);
		}
	}
}
