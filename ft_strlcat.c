/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:25:20 by gmachado          #+#    #+#             */
/*   Updated: 2022/04/06 22:27:35 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const char	*src_start;
	const char	*dst_start;
	size_t		dst_len;

	src_start = src;
	dst_start = dst;
	dst_len = 0;
	if (size != 0)
	{
		while (*dst != '\0')
			dst++;
		dst_len = dst - dst_start;
		while (--size > dst_len && *src != '\0')
			*dst++ = *src++;
		*dst = '\0';
	}
	while (*src != '\0')
		src++;
	return (dst_len + src - src_start);
}
