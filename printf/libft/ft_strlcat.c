/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:48:58 by yiken             #+#    #+#             */
/*   Updated: 2023/12/01 15:15:17 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	to_append;
	size_t	i;
	size_t	j;

	src_len = ft_strlen(src);
	if (!dst && dstsize == 0)
		return (dstsize + src_len);
	dst_len = ft_strlen(dst);
	if (dst_len >= dstsize)
		return (dstsize + src_len);
	to_append = dstsize - dst_len - sizeof(char);
	i = 0;
	j = dst_len;
	while (src[i] && i < to_append)
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[i + j] = '\0';
	return (dst_len + src_len);
}
